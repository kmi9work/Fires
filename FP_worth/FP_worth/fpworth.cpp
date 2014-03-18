#include "fpworth.h"
#include "ui_fpworth.h"
#include "unistd.h"
#include <iostream>
#include "alglib/dataanalysis.h"
#include "alglib/interpolation.h"
#include <stdlib.h>     /* srand, rand */


#define FIRE_COUNT 3
#define DELTA_ADD 0.3
#define min(a,b) ((a)<(b) ? (a) : (b))
#define max(a,b) ((a)>(b) ? (a) : (b))

FPWorth::FPWorth(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FPWorth)
{
    ui->setupUi(this);
    ui->lvarSettings->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->lvarSettings, SIGNAL(customContextMenuRequested(const QPoint&)),
            this, SLOT(ShowContextMenu(const QPoint&)));
    first = ui->termCountFirst->text().toInt();
    last = ui->termCountLast->text().toInt();
    rulesListIndex_prev = -1;
    plot = new Plot();
    layout = new QHBoxLayout( ui->plotWidget );
    layout->setContentsMargins( 0, 0, 0, 0 );
    layout->addWidget( plot );
    epsf = ui->epsfEdit->text().toDouble();
    epsx = ui->epsxEdit->text().toDouble();
    maxits = ui->maxitsEdit->text().toDouble();
    diffstep = ui->diffstepEdit->text().toDouble();
}



FPWorth::~FPWorth()
{
    delete ui;
}

bool bySupports(const struct term &p1, const struct term &p2){
    return p1.support > p2.support;
}
bool bySupportPattern(const struct pattern &p1, const struct pattern &p2){
    return p1.support > p2.support;
}
bool byFirst (const QVector<double> &v1, const QVector<double> &v2){
    return v1[0] > v2[0];
}
struct ByColumn {
    ByColumn(int index) : i(index) {}
    bool operator()(const QVector<struct numCluster> &col1, const QVector<struct numCluster> &col2) {
        return col1[i].number < col2[i].number;
    }
    int i;
};

/*
void FPWorth::splitColumns(){
    int i,j,k,l;
    for (k = 0; k < lvar_size; k++){
        for (i = 0; i < rows[k]; i++){
            for (j = cols/lvar_size - 1; j >= 0; j--){
                for (l = lvar_size - 1; l >= 0; l--){
                    if (l == numbers[k][i][j]){
                        numbers[k][i][j*lvar_size + l] = 1;
                    }else{
                        numbers[k][i][j*lvar_size + l] = 0;
                    }
                }
            }
        }
    }
}
*/
void FPWorth::printNumbers(QTableWidget *table, int max_rows, int add, int start_x = 0, int start_y = 0){
    int i,j,k;
    QTableWidgetItem *item;
    int r_sum = 0;
    table->setColumnCount(cols + 1);
    table->setRowCount(max_rows);
    for (i = 0; i < cols + 1; i++){
        item = new QTableWidgetItem(names[i]);
        table->setHorizontalHeaderItem(i, item);
    }
    for (k = 0; k < lvar_size; k++){
        for (i = 0; i < rows[k]; i++){
            for (j = 0; j < cols; j++){
                item = new QTableWidgetItem(QString::number(numbers[k][i][j] + add));
                table->setItem(start_x + r_sum, start_y + j, item);
            }
            item = new QTableWidgetItem(QString::number(k + add));
            table->setItem(start_x + r_sum, start_y + j, item);
            r_sum += 1;
        }
    }
}

void FPWorth::printQVector(QVector< QVector<struct numCluster> > v, int start_x, int start_y){
    int i,j;
    QTableWidgetItem *item;
    for (i = 0; i < v.size(); i++){
        for (j = 0; j < v[i].size(); j++){
            item = new QTableWidgetItem(QString::number(v[i][j].cluster));
            ui->normalTable->setItem(start_x + i, start_y + j, item);
            if ((i == 0 && j == 0) || (i == v.size() - 1 && j == v[i].size() - 1)){
                item->setBackgroundColor(QColor(255,0,0));
            }
        }
    }
}

QStringList FPWorth::readFileToStringList(QString fileName){
    int i;
    QFile csvFile;
    QStringList ret;
    QTableWidgetItem *item;
    sep = ui->sepEdit->text();


    csvFile.setFileName(fileName);
    if (!csvFile.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
        return ret;
    }
    // -- Read from file to inputStrList --
    QTextStream in(&csvFile);
    names = in.readLine().split(sep);
    ui->inputNnpsTable->setColumnCount(names.size() - 1);

    for (i = 0; i < names.size() - 1; i++){
        item = new QTableWidgetItem(names[i]);
        ui->inputNnpsTable->setItem(0,i,item);
        ui->plotNamesCombo->addItem(names[i]);
    }
    ui->plotNamesCombo->addItem(names[i]);
    cols = names.size() - 1; // -Fires
    in.readLine(); // Second line is lvar sizes. Not ready yet.
    while (!in.atEnd()){
        ret.append(in.readLine());
    }
    csvFile.close();
    //== End read file ==
    return ret;
}

// -- Open files --
void FPWorth::on_openFuzzyButton_clicked(){
    QString fileName;
    int i,j,k;
    int buf_size = 0;
    int stop_messages = 0;
    QStringList inputStrList, splitList;
    int max_rows;

    sep = ui->sepEdit->text();
    lvar_size = ui->termSizeEdit->text().toInt();
    ui->progressBar->setValue(0);
    fileName = QFileDialog::getOpenFileName(this, tr("Open File"), tr("../.."),
                                            tr("CSV Files (*.csv);;Text Files (*.txt)"));
    if (!fileName.isEmpty()) {
        ui->fuzzyFileLabel->setText(fileName);
    }else{
        return;
    }
    ui->progressBar->setValue(10);
    inputStrList = readFileToStringList(fileName);
    ui->progressBar->setValue(25);
    if (inputStrList.empty()) return;
    max_rows = inputStrList.size();
    fuzzyTableIndexes_prev.reserve(max_rows);
    fuzzyTableIndexes_prev.resize(0);
    rows = new int[lvar_size];
    for (i = 0; i < lvar_size; i++) rows[i] = 0;
    // -- input of numeric --
    numbers = new int**[lvar_size];
    string_numbers = new int*[lvar_size];
    for (i = 0; i < lvar_size; i++){
        numbers[i] = new int*[max_rows];
        string_numbers[i] = new int[max_rows];
        for (j = 0; j < max_rows; j++){
            numbers[i][j] = new int[cols];
        }
    }

    stop_messages = 0;
    for (i = 0; i < max_rows; i++){
        ui->progressBar->setValue(30 + ((double)i/max_rows)*50);
        splitList = inputStrList.at(i).split(sep);
        k = splitList.last().toInt() - 1;
        std::cout << k << "----------\n";
        if (splitList.size() != names.size() && stop_messages < 5){
            QMessageBox::warning(this, tr("Error"), tr("Wrong size of %1'th row.").arg(i));
            stop_messages += 1;
        }
        if (splitList.size() - 1 > cols){
            return;
        }
        buf_size = splitList.size();
        for (j = 0; j < splitList.size() - 1; j++){
            numbers[k][rows[k]][j] = splitList.at(j).toInt() - 1;
            string_numbers[k][rows[k]] = i;
        }
        rows[k] += 1;
    }
    // == End input of numeric ==
    printNumbers(ui->fuzzyTable,max_rows, 0);
    ui->progressBar->setValue(100);
}

void FPWorth::on_openNormalButton_clicked(){
    int i,j,k;
    QFile csvFile;
    QString fileName;

    QStringList inputStrList, splitList;
    alglib::real_2d_array workplace;
    struct numCluster buf_nc;
    int max_rows = 0;
    int buf_int, term_num;
    QTableWidgetItem *item;
    ui->progressBar->setValue(0);
    lvar_size = ui->termSizeEdit->text().toInt();
    fileName = QFileDialog::getOpenFileName(this, tr("Open File"), tr("../.."),
                                            tr("CSV Files (*.csv);;Text Files (*.txt)"));
    ui->progressBar->setValue(15);
    if (!fileName.isEmpty()){
        csvFile.setFileName(fileName);
        ui->normalFileLabel->setText(fileName);
    }else{
        return;
    }
    inputStrList = readFileToStringList(fileName);
    ui->progressBar->setValue(30);
    if (inputStrList.empty()) return;
    max_rows = inputStrList.size();

    data.resize(max_rows);
    fuzzyTableIndexes_prev.reserve(max_rows);
    fuzzyTableIndexes_prev.resize(0);
    for (i = 0; i < max_rows; i++){
        ui->progressBar->setValue(30 + ((double)i/max_rows)*30);
        splitList = inputStrList[i].split(sep);
        if (splitList.size() != cols + 1){
            QMessageBox::critical(this, tr("Error in line size"),
                                  tr("Wrong size of %1'th row. Cols: %2, Size: %3")
                                  .arg(i).arg(cols).arg(splitList.size()));
            return;
        }
        for (j = 0; j < splitList.size(); j++){
            buf_nc.number = splitList[j].toDouble();
            buf_nc.cluster = 0;
            data[i].append(buf_nc);
        }
    }
    ui->progressBar->setValue(60);
    // -- Print normal data to normalTable --
    ui->normalTable->setColumnCount(cols + 1); // + Fires
    ui->normalTable->setRowCount(max_rows);
    for (i = 0; i < names.size(); i++){
        item = new QTableWidgetItem(names[i]);
        ui->normalTable->setHorizontalHeaderItem(i, item);
    }
    for (i = 0; i < max_rows; i++){
        for (j = 0; j < cols + 1; j++){
            item = new QTableWidgetItem(QString::number(data[i][j].number));
            ui->normalTable->setItem(i, j, item);
        }
    }
    // == Print normal data to normalTable ==

    alglib::clusterizerstate s;
    alglib::kmeansreport rep;

    alglib::clusterizercreate(s);
    alglib::clusterizersetkmeanslimits(s, 100, 0);
    workplace.setlength(max_rows, 1);
    means.resize(cols + 1);
    count_cluster.resize(cols+1);
    for (i = 0; i < cols + 1; i++) count_cluster[i].resize(lvar_size);
    for (i = 0; i < cols + 1; i++){
        ui->progressBar->setValue(60 + ((double)i/cols + 1)*30);
        qSort(data.begin(), data.end(), ByColumn(i));// !!!
        for (j = 0; j < max_rows; j++){
            workplace[j][0] = data[j][i].number;
        }

        //std::cout << names[i].toStdString() << std::endl;
        //std::cout << workplace.tostring(1) << std::endl;
        alglib::clusterizersetpoints(s, workplace, 2);
        alglib::clusterizerrunkmeans(s, lvar_size, rep);
        buf_int = rep.cidx[0];
        for (j = 0; j < lvar_size; j++){
            means[i].append(rep.c[j][0]);
        }
        // /////////////////////// string_numbers = new int*[lvar_size]; !!!
        qSort(means[i].begin(), means[i].end());
        term_num = 0;
        count_cluster[i][term_num] = 0;
        for (j = 0; j < max_rows; j++){
            if (buf_int != rep.cidx[j]){
                term_num++;
                buf_int = rep.cidx[j];
                count_cluster[i][term_num] = 0;
            }
            data[j][i].cluster = term_num;
            count_cluster[i][term_num] += 1;
        }
        //std::cout << rep.cidx.tostring() << std::endl;
        //std::cout << "=====================" << std::endl;// Print out the clusters !!!
    }


    string_numbers = new int*[lvar_size];
    numbers = new int**[lvar_size];
    for (i = 0; i < lvar_size; i++){
        numbers[i] = new int*[max_rows];
        string_numbers[i] = new int[max_rows];
        for (j = 0; j < max_rows; j++){
            numbers[i][j] = new int[cols];
        }
    }
    rows = new int[lvar_size];
    for (i = 0; i < lvar_size; i++) rows[i] = 0;

    for (i = 0; i < max_rows; i++){
        ui->progressBar->setValue(90 + ((double)i/max_rows)*10);
        k = data[i][cols].cluster;
        for (j = 0; j < cols; j++){
            numbers[k][rows[k]][j] = data[i][j].cluster;
            string_numbers[k][rows[k]] = i;
        }
        rows[k] += 1;
    }
    printNumbers(ui->fuzzyTable,max_rows, 1);
    ui->progressBar->setValue(100);
}
// == End open files ==

// -- Main functions --

void FPWorth::makeTerms(int **numbers, int rows, int k){
    int i,j;
    for (i = 0; i < cols*lvar_size; i++){
        terms[i].number = i;
        terms[i].support = 0;
    }
    for (i = 0; i < cols; i++){
        for (j = 0; j < rows; j++){
            terms[i*lvar_size + numbers[j][i]].support += 1;
        }
    }
    ui->termsTable->setRowCount(lvar_size);
    ui->termsTable->setColumnCount(cols*lvar_size);
    QTableWidgetItem *item;
    for (i = 0; i < cols*lvar_size; i++){
        item = new QTableWidgetItem(tr("%1_%2")
                                    .arg(names[i/lvar_size])
                                    .arg(i % lvar_size));
        ui->termsTable->setHorizontalHeaderItem(i, item);
    }
    for (i = 0; i < cols*lvar_size; i++){
        item = new QTableWidgetItem(QString::number(terms[i].support));
        ui->termsTable->setItem(k, i, item);
    }

    std::sort(&terms[0], &terms[cols*lvar_size], bySupports);
/*
    struct level lev_buf;
    levels.reserve(cols*lvar_size);
    for (i = 0; i < cols*lvar_size; i++){
        lev_buf.number = terms[i].number;
        levels.append(lev_buf);
    }
*/
}

void FPWorth::makeCTree(int **numbers, int rows){
    // add first level
    int i;
    QVector<int> buf;
    buf.append(-1);
    for (i = 0; i < cols*lvar_size; i++){
        rootCTree->addChild(terms[i], 0, buf);
    }
    rootCTree->makeTree(numbers, rows, lvar_size);
}

void FPWorth::findRules(int first, int last, int step){
    frequentPatterns = rootCTree->assocRules(first, last, step);
    std::sort(frequentPatterns.begin(),frequentPatterns.end(),bySupportPattern);
}

void FPWorth::printRules(QVector<pattern> frequentPatterns){
    int i, j;
    QString str;
    for (i = 0; i < frequentPatterns.size(); i++){
        str = tr("Если ");
        for (j = 0; j < frequentPatterns[i].word.size() - 1; j++){
            str += names[frequentPatterns[i].word[j].number / lvar_size] + tr("{%1} и ").arg(frequentPatterns[i].word[j].number % lvar_size + 1);
        }
        str += names[frequentPatterns[i].word[j].number / lvar_size] + tr("{%1}").arg(frequentPatterns[i].word[j].number % lvar_size + 1);
        str += tr(", то %1{%2} / %3% : %4 из %5. ")
                .arg(names.last())
                .arg(frequentPatterns[i].cluster+1)
                .arg(QString::number(((double)frequentPatterns[i].support / frequentPatterns[i].count) * 100.0, 'f', 1))
                .arg(QString::number(frequentPatterns[i].support))
                .arg(QString::number(frequentPatterns[i].count));
        str += tr("Номера строк: ");
        for (j = 0; j < frequentPatterns[i].str_numbers.size() - 1; j++){
            str += tr("%1, ").arg(frequentPatterns[i].str_numbers[j] + 1);
        }
        str += tr("%1;").arg(frequentPatterns[i].str_numbers[j] + 1);
        new QListWidgetItem(str, ui->rulesListWidget);
    }
}

void FPWorth::on_makeRulesAprioriButton_clicked()
{
    int i;
    QVector<CandidateTree*> rootsCTree;
    terms = new term[cols*lvar_size];
    ui->rulesListWidget->clear();
    fpList.clear();
    //Reading deltas
    deltas.clear();
    deltas.resize(last);
    if (ui->supportTable->rowCount() == 0){
        for (i = 0; i < last; i++){
            deltas[i] = 0;
        }
    }else{
        for (i = 0; i < first; i++){
            deltas[i] = 0;
        }
        for (i = 0; i < ui->supportTable->rowCount(); i ++){
            deltas[i + first - 1] = ui->supportTable->item(i,0)->text().toDouble();
        }
    }
    //--- end --- deltas

    for (i = 0; i < lvar_size; i++){
        /*switch (i) {
        case 0:
            new QListWidgetItem(tr("---------------------------------"), ui->rulesListWidget);
            new QListWidgetItem(tr("Пожаров мало или они отсутствуют:"), ui->rulesListWidget);
            break;
        case 1:
            new QListWidgetItem(tr("---------------------------------"), ui->rulesListWidget);
            new QListWidgetItem(tr("Среднее количество пожаров:"), ui->rulesListWidget);
            break;
        case 2:
            new QListWidgetItem(tr("---------------------------------"), ui->rulesListWidget);
            new QListWidgetItem(tr("Большое количество пожаров:"), ui->rulesListWidget);
            break;
        case 3:
            new QListWidgetItem(tr("---------------------------------"), ui->rulesListWidget);
            new QListWidgetItem(tr("Очень большое количество пожаров:"), ui->rulesListWidget);
            break;
        case 4:
            new QListWidgetItem(tr("---------------------------------"), ui->rulesListWidget);
            new QListWidgetItem(tr("Катастрофическое количество пожаров:"), ui->rulesListWidget);
            break;
        }*/
        memset(terms,0,sizeof(term)*cols*lvar_size);
        //levels.clear();
        CandidateTree::levels.clear();
        frequentPatterns.clear();
        rootCTree = new CandidateTree(deltas, rows[i]);
        makeTerms(numbers[i], rows[i], i);
        makeCTree(numbers[i], rows[i]);
        findRules(first, last, i);
        fpList += frequentPatterns;
        //Вывести разделения между правилами и пожары.
        rootsCTree.append(rootCTree);
    }
    printRules(fpList);
    delete[] terms;
    rootsCTree.clear();
}


// == End Main functions ==

// -- Plot --
void FPWorth::on_makePlotButton_clicked(){
    int i,j;
    epsf = ui->epsfEdit->text().toDouble();
    epsx = ui->epsxEdit->text().toDouble();
    maxits = ui->maxitsEdit->text().toDouble();
    diffstep = ui->diffstepEdit->text().toDouble();
    j = 0;
    fs = approxGauss(data);
    plot->clear();
    for (i = 0; i < lvar_size; i++){
        plot->drawGauss(fs[0][i].mu, fs[0][i].a, fs[0][i].type, i);
        plot->drawDots(data, means[0][i], fs[0][i].k, i, lvar_size,j);
    }
    ui->plotNamesCombo->setCurrentIndex(0);

    /*for(j = 0; j < lvar_size; j++){
        m = means[i][j];
        max = 0;
        for (k = 0; k < data.size(); k++){
            if (data[k][i].cluster == j && fabs(data[k][i].number - m) > max){
                max = fabs(data[k][i].number - m);
            }
        }

    }*/
    //plot->detachItems();
    //
}

double funcGauss (double x, double sigma, double mu = 0){
    return exp(-sigma*(x-mu)*(x-mu));
}

void function_cx_G_func(const alglib::real_1d_array &c, const alglib::real_1d_array &x, double &func, void *ptr)
{
    // this callback calculates f(c,x)=exp(-c0*sqr(x0))
    // where x is a position on X-axis and c is adjustable parameter
    func = exp(-(x[0]-c[0])*(x[0]-c[0])/(2*c[1]*c[1]));
}

void function_cx_E_func(const alglib::real_1d_array &c, const alglib::real_1d_array &x, double &func, void *ptr)
{
    // this callback calculates f(c,x)=exp(-c0*sqr(x0))
    // where x is a position on X-axis and c is adjustable parameter
    func = 1/(1 + exp(-c[1]*(x[0]-c[0])));
}

void function_cx_NE_func(const alglib::real_1d_array &c, const alglib::real_1d_array &x, double &func, void *ptr)
{
    // this callback calculates f(c,x)=exp(-c0*sqr(x0))
    // where x is a position on X-axis and c is adjustable parameter
    func = 1/(1 + exp(c[1]*(x[0]-c[0])));
}
/*
void function_NEW_func(const alglib::real_1d_array &c, const alglib::real_1d_array &x, double &func, void *ptr)
{
    // this callback calculates f(c,x)=exp(-c0*sqr(x0))
    // where x is a position on X-axis and c is adjustable parameter
    func = 1/(1+fabs(pow((x[0]-c[0])/c[1],2*c[1])));
}*/


double funcNorm(double x, double k, double mu = 0){
    return (1 - (fabs(x - mu))/k);
}

double dispersio(alglib::real_1d_array x){
    int i;
    double sum = 0;
    double sq_sum = 0;
    for (i = 0; i < x.length(); i++){
        sum += x[i];
        sq_sum += x[i]*x[i];
    }
    return (sq_sum - sum*sum/x.length())/x.length();
}

QVector< QVector<struct membershipFunction> > FPWorth::approxGauss(QVector< QVector<struct numCluster> > data)
{
    //double *mu, double *sigma, double k, int index)
    //returns eps?
    QVector< QVector<struct membershipFunction> > ret;
    QVector< QVector<alglib::real_2d_array> > xs; //rows*(cols+1)
    QVector< QVector<alglib::real_1d_array> > ys;
    QVector< QVector<alglib::real_1d_array> > cs; //[0] = mu, [1] = sigma
    QVector< QVector<double> > ks;
    QVector< QVector<int> > indexes;
    alglib::ae_int_t info;
    alglib::lsfitstate state;
    alglib::lsfitreport rep;
    int size = 0;
    int i,j,l;
    double err, iter = 0, iters = 1000;
    double a,b,m;
    double max_k;
    double before_mu, locality = 2.5;
    xs.resize(cols+1);
    ys.resize(cols+1);
    cs.resize(cols+1);
    ks.resize(cols+1);
    ret.resize(cols+1);
    indexes.resize(cols+1);
    for (j = 0; j < cols+1; j++){
        xs[j].resize(lvar_size);
        ys[j].resize(lvar_size);
        cs[j].resize(lvar_size);
        indexes[j].resize(lvar_size);
        ks[j].resize(lvar_size);
        ret[j].resize(lvar_size);
        for (i = 0; i < lvar_size; i++){
            indexes[j][i] = 0;
        }
    }
    for (i = 0; i < cols+1; i++){
        for (j = 0; j < lvar_size; j++){
            xs[i][j].setlength(count_cluster[i][j],1);
            // Длина real_2d_array для каждого кластера равна количеству эл-тов в кластере.
            ys[i][j].setlength(count_cluster[i][j]);
            cs[i][j].setlength(2);
            // ys столько же, сколько и xs.
        }
    }


    for (i = 0; i < data.size(); i++){
        // Заполнить xs.
        for (j = 0; j < data[i].size(); j++){
            // Для каждого real_2d_array свой индекс.
            xs[j][data[i][j].cluster][ indexes[j][data[i][j].cluster] ][0] = data[i][j].number;

            indexes[j][data[i][j].cluster] += 1;
        }
    }
    // Data больше не нужна.

    // Для этого сначала нужно вычислить k.
    for (i = 0; i < cols + 1; i++){
        for (j = 0; j < lvar_size; j++){
            max_k = 0;
            for (l = 0; l < xs[i][j].rows(); l++){
                a = xs[i][j](l,0);
                if (i == 0){
                    //std::cout << j << "a = " << a << std::endl;
                }
                m = means[i][j];
                if (max_k < fabs(a - m)) max_k = fabs(a - m);
            }

            ks[i][j] = max_k;
            ret[i][j].k = max_k;
        }
    }
    // Для каждого из xs вычислить ys.
    // Записать cs для каждого.
    for (i = 0; i < cols + 1; i++){
        for (j = 0; j < lvar_size; j++){
            for (l = 0; l < ys[i][j].length(); l++){
                if (j == 0 && xs[i][j](l,0) < means[i][j]){
                    ys[i][j][l] = 1;
                }else if (j == lvar_size - 1 && xs[i][j](l,0) > means[i][j]){
                    ys[i][j][l] = 1;
                }else{
                    ys[i][j][l] = funcNorm(xs[i][j](l,0),ks[i][j],means[i][j]);
                }

            }

            //--------
            if (j == 0){
                cs[i][j][0] = means[i][j] + ks[i][j]/2; // +- k/2
                cs[i][j][1] = -5 / ks[i][j]; // -?
            }else if (j == lvar_size - 1){
                cs[i][j][0] = means[i][j] - ks[i][j]/2; // +- k/2
                cs[i][j][1] = 5 / ks[i][j]; // -?
            }else{
                cs[i][j][0] = means[i][j]; // +- k/2
                cs[i][j][1] = dispersio(ys[i][j]);
            }
            alglib::lsfitcreatef(xs[i][j], ys[i][j], cs[i][j], diffstep, state);
            alglib::lsfitsetcond(state, epsf, epsx, maxits);
            if (j == 0){
                ret[i][j].type = 2;
                alglib::lsfitfit(state, function_cx_NE_func);
            }else if (j == lvar_size - 1){
                ret[i][j].type = 1;
                alglib::lsfitfit(state, function_cx_E_func);
            }else{
                ret[i][j].type = 0;
                alglib::lsfitfit(state, function_cx_G_func);
            }
            alglib::lsfitresults(state, info, cs[i][j], rep);
            err = rep.rmserror;

            //========
            iter = 0;
            while (err > 0.1 && iter < iters){
                if (j == 0){
                    cs[i][j][0] = means[i][j] + ks[i][j]/2 + (((rand()%100)/100.0)*locality*2 - locality); // +- k/2
                    before_mu = cs[i][j][0];
                    cs[i][j][1] = -5 / ks[i][j] + (((rand()%100)/100.0)*locality*2 - locality); // -?
                }else if (j == lvar_size - 1){
                    cs[i][j][0] = means[i][j] - ks[i][j]/2 + (((rand()%100)/100.0)*locality*2 - locality); // +- k/2
                    cs[i][j][1] = 5 / ks[i][j] + (((rand()%100)/100.0)*locality*2 - locality); // -?
                }else{
                    cs[i][j][0] = means[i][j] + (((rand()%100)/100.0)*locality*2 - locality); // +- k/2
                    cs[i][j][1] = dispersio(ys[i][j]) + (((rand()%100)/100.0)*locality*2 - locality);
                }
                alglib::lsfitcreatef(xs[i][j], ys[i][j], cs[i][j], diffstep, state);
                alglib::lsfitsetcond(state, epsf, epsx, maxits);
                if (j == 0){
                    ret[i][j].type = 2;
                    alglib::lsfitfit(state, function_cx_NE_func);
                }else if (j == lvar_size - 1){
                    ret[i][j].type = 1;
                    alglib::lsfitfit(state, function_cx_E_func);
                }else{
                    ret[i][j].type = 0;
                    alglib::lsfitfit(state, function_cx_G_func);
                }
                alglib::lsfitresults(state, info, cs[i][j], rep);
                err = rep.rmserror;
                iter++;
            }
            ret[i][j].mu = cs[i][j][0];
            /*std::cout << j << " before = " << means[i][j] + 10;
            std::cout << "; after = " << cs[i][j][0];
            */
            if (iter == iters){
                std::cout << i << "," << j << "; err = " << rep.rmserror << std::endl;
            }

            ret[i][j].a = cs[i][j][1];
        }
    }
    return ret;
}
// == End Plot

void FPWorth::on_lvarSettings_entered(const QModelIndex &index)
{
    std::cout << index.column() << std::endl;
    std::cout << index.row() << std::endl;
}

void FPWorth::ShowContextMenu(const QPoint& pos) // this is a slot
{
    // for most widgets
    QPoint globalPos = ui->lvarSettings->mapToGlobal(pos);
    // for QAbstractScrollArea and derived classes you would use:
    // QPoint globalPos = myWidget->viewport()->mapToGlobal(pos);

    QMenu myMenu;
    myMenu.addAction("Menu Item 1");
    myMenu.addAction("Menu Item 2");

    // ...

    QAction* selectedItem = myMenu.exec(globalPos);
    if (selectedItem)
    {
        std::cout << selectedItem->text().toStdString() << std::endl;
    }
    else
    {
        // nothing was chosen
    }
}


/*

void FPWorth::on_makeRulesButton_clicked(){
    int i, j, k, words_i;
    terms = new term[cols*lvar_size];
    rootFPTree = new FPTree();

    ui->rulesPlainText->clear();
    //Reading deltas
    deltas.clear();
    if (ui->supportTable->rowCount() == 0){
        deltas.append(0);
    }else{
        for (i = 0; i < ui->supportTable->rowCount(); i ++){
            deltas.append(ui->supportTable->item(i,0)->text().toDouble());
        }
    }
    rootCTree = new CandidateTree(deltas);
    //--- end --- deltas
    words_i = 0;
    for (i = 0; i < lvar_size; i++){
        switch (i) {
        case 0:
            ui->rulesPlainText->insertPlainText(tr("---------------------------------\n"));
            ui->rulesPlainText->insertPlainText(tr("Пожаров мало или они отсутствуют:\n"));
            break;
        case 1:
            ui->rulesPlainText->insertPlainText(tr("---------------------------\n"));
            ui->rulesPlainText->insertPlainText(tr("Среднее количество пожаров:\n"));
            break;
        case 2:
            ui->rulesPlainText->insertPlainText(tr("---------------------------\n"));
            ui->rulesPlainText->insertPlainText(tr("Большое количество пожаров:\n"));
            break;
        case 3:
            ui->rulesPlainText->insertPlainText(tr("---------------------------------\n"));
            ui->rulesPlainText->insertPlainText(tr("Очень большое количество пожаров:\n"));

            break;
        case 4:
            ui->rulesPlainText->insertPlainText(tr("------------------------------------\n"));
            ui->rulesPlainText->insertPlainText(tr("Катастрофическое количество пожаров:\n"));
            break;
        }
        memset(terms,0,sizeof(term)*cols*lvar_size);
        words.clear();
        rootFPTree->clear();
        levels.clear();
        frequentPatterns.clear();
        makeTerms(numbers[i], rows[i], i);
        makeWords(numbers[i], rows[i]);
        makeTree(rows[i]);
        makeRules(rows[i], i);

        fpList.append(frequentPatterns);
        //Вывести разделения между правилами и пожары.
    }
}



void FPWorth::makeWords(int **numbers, int rows, int k){
    int i, j, first;
    struct term buf_term;
    QVector<struct term> word;
    maxWordSize = 0;
    for (i = 0; i < rows; i++){
        j = 0;
        word.clear();
        for (j = 0; j < cols*lvar_size; j++){
            if (numbers[i][terms[j].number / lvar_size] == (terms[j].number % lvar_size)){
                buf_term.number = terms[j].number;
                buf_term.support = 1;
                buf_term.str_num = string_numbers[k][i];
                word.append(buf_term);
            }
        }
        if (word.size() > maxWordSize){
            maxWordSize = word.size();
        }
        words.append(word);
    }
    if (words.size() != rows){
        QMessageBox::warning(this, tr("Error"), tr("Wrong size of array words"));
        return;
    }
    QTableWidgetItem *item;
    first = ui->wordsTable->rowCount();
    ui->wordsTable->setRowCount(first + rows + 1);
    ui->wordsTable->setColumnCount(cols + maxWordSize);

    for (i = 0; i < cols; i++){
        item = new QTableWidgetItem(tr("%1").arg(names[i]));
        ui->wordsTable->setHorizontalHeaderItem(i, item);
    }
    for (i = 0; i < rows; i++){
        for (j = 0; j < cols; j++){
            item = new QTableWidgetItem(QString::number(numbers[i][j]));
            ui->wordsTable->setItem(first + i, j, item);
        }
        for (j = 0; j < words[i].size(); j++){
            item = new QTableWidgetItem(QString("%1_%2")
                                        .arg(names[words[i][j].number/lvar_size])
                                        .arg(words[i][j].number % lvar_size));
            ui->wordsTable->setItem(first + i, cols + j, item);
        }
    }
    //ui->normalTable->setColumnCount(cols);
}

void FPWorth::makeTree(int rows){
    FPTree *node;
    int i,j,l;
    int check;
    int fl = 0;

    //Add words to FPTree and levels
    for (i = 0; i < rows; i++){
        //Add first letter to root
        if (words[i].size() > 0){
            check = rootFPTree->addChild(words[i][0], &node);
            if (check == 1){
                for (l = 0; l < levels.size(); l++){
                    if (levels[l].number == node->data.number){
                        levels[l].nodes.append(node);
                        break;
                    }
                }
            }
        }
        //Add whole words to FPTree
        for (j = 1; j < words[i].size(); j++){
            check = node->addChild(words[i][j], &node);
            if (check == 1){
                fl = 0;
                for (l = j; l < levels.size(); l++){
                    if (levels[l].number == node->data.number){
                        levels[l].nodes.append(node);
                        fl = 1;
                        break;
                    }
                }
                if (!fl){
                    std::cout << "!!!" << std::endl;
                    exit(0);
                }
            }
        }
    }
    //rootFPTree->postorder(ui->fptreeEdit, 0);
}

void FPWorth::makeRules(int rows, int f){
    int i,j;
    frequentPatterns = rootFPTree->findFP(levels, deltas, rows);
    std::sort(frequentPatterns.begin(),frequentPatterns.end(),bySupportPattern);

    i = 1;
    //output Rules.

    for (i = 0; i < frequentPatterns.size(); i++){
        ui->rulesPlainText->insertPlainText(tr("Если "));
        for (j = 0; j < frequentPatterns[i].word.size() - 1; j++){
            ui->rulesPlainText->insertPlainText(names[frequentPatterns[i].word[j].number / lvar_size] + tr("{%1} и ").arg(frequentPatterns[i].word[j].number % lvar_size + 1));
        }
        ui->rulesPlainText->insertPlainText(names[frequentPatterns[i].word[j].number / lvar_size] + tr("{%1}").arg(frequentPatterns[i].word[j].number % lvar_size + 1));
        ui->rulesPlainText->insertPlainText(tr(", то %1{%2} / %3% : %4 из %5. ")
                                            .arg(names.last())
                                            .arg(f+1)
                                            .arg(QString::number(((double)frequentPatterns[i].support / frequentPatterns[i].count) * 100.0, 'f', 1))
                                            .arg(QString::number(frequentPatterns[i].support))
                                            .arg(QString::number(frequentPatterns[i].count)));
        ui->rulesPlainText->insertPlainText(tr("Номера строк: "));
        for (j = 0; j < frequentPatterns[i].str_numbers.size() - 1; j++){
            ui->rulesPlainText->insertPlainText(tr("%1, ").arg(frequentPatterns[i].str_numbers[j] + 1));
        }
        ui->rulesPlainText->insertPlainText(tr("%1; \n").arg(frequentPatterns[i].str_numbers[j] + 1));
    }
}


*/


void FPWorth::on_okTermButton_clicked()
{
    int i;
    int size, buf_size, buf_first;
    QTableWidgetItem *item;
    buf_first = first;
    first = ui->termCountFirst->text().toInt();
    last = ui->termCountLast->text().toInt();
    if (last < first){
        QMessageBox::warning(this, tr("Error"), tr("First > last"));
        return;
    }
    size = last - first + 1;
    buf_size = ui->supportTable->rowCount();
    ui->supportTable->setRowCount(size);
    if (size > buf_size){
        for (i = buf_size; i < size; i++){
            item = new QTableWidgetItem(tr("Уровень %1").arg(first + i));
            ui->supportTable->setVerticalHeaderItem(i, item);
            item = new QTableWidgetItem(tr("0"));
            item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            ui->supportTable->setItem(i,0,item);
        }
    }
    if (buf_first < first){
        for (i = 0; i < size; i++){
            ui->supportTable->verticalHeaderItem(i)->setText(tr("Уровень %1").arg(first + i));
        }
    }
}

void FPWorth::on_rulesListWidget_doubleClicked(const QModelIndex &index)
{
    int i, j;
    int str;

    if (fuzzyTableIndexes_prev.size() > 0){
        for (i = 0; i < fuzzyTableIndexes_prev.size(); i++){
            for (j = 0; j < ui->fuzzyTable->columnCount(); j++){
                ui->fuzzyTable->item(i,j)->setBackgroundColor(QColor(255,255,255));
            }
        }
    }

    if (fuzzyTableIndexes_prev.size() > 0){
        fuzzyTableIndexes_prev.resize(0);
    }
    str = 0;
    for (j = 0; j < fpList[index.row()].cluster; j++){
        str+= rows[j];
    }
    str += fpList[index.row()].str_numbers[0];
    for (j = 0; j < ui->fuzzyTable->columnCount(); j++){
        ui->fuzzyTable->item(str,j)->setBackgroundColor(QColor(0,255,0));
    }
    fuzzyTableIndexes_prev.append(str);
    for (i = 1; i < fpList[index.row()].str_numbers.size(); i++){
        str -= fpList[index.row()].str_numbers[i-1];
        str += fpList[index.row()].str_numbers[i];
        for (j = 0; j < ui->fuzzyTable->columnCount(); j++){
            ui->fuzzyTable->item(str,j)->setBackgroundColor(QColor(0,255,0));
        }
        fuzzyTableIndexes_prev.append(str);
    }
    if (rulesListIndex_prev != -1){
        ui->rulesListWidget->item(rulesListIndex_prev)->setBackgroundColor(QColor(255,255,255));
    }
    ui->rulesListWidget->item(index.row())->setBackgroundColor(QColor(0,255,0));
    rulesListIndex_prev = index.row();
}

void FPWorth::on_clearFuzzyButton_clicked()
{
    int i,j;
    for (i = 0; i < ui->fuzzyTable->rowCount(); i++){
        for (j = 0; j < ui->fuzzyTable->columnCount(); j++){
            ui->fuzzyTable->item(i,j)->setBackgroundColor(QColor(255,255,255));
        }
    }
}




void FPWorth::on_nnpsButton_clicked()
{
    /*
     * 0. Всё выполняем для каждого из терма л.п. "пожары" отдельно.
     * 1. Аппроксимировать все графики. approxGauss(data, &m, &sigma, max, j);
     * 1.1. Получить набор переменных функций. sigma и mu
     * 2. Эти функции и будут функциями принадлежности. Их нужно правильно разложить.
     * 3. Первый слой выполняется автоматически, когда мы подставляем значения
     * в правила. В правило ставится mu(x_i).
     * 4. Дальше идёт агрегирование.
     * 5.
     * Небольшой прирост к скорости:
     * Переставить местами строки и столбцы. Чаще идёт работа по столбцам, а не по строкам.
     *
    //0.
    int i;
    QVector< QVector<struct membershipFunction> > funcs; // all membership functions
    funcs.resize(cols + 1);
    for (i = 0; i < lvar_size; i++){
        //1.

        approxGauss(data, funcs, i);
    }*/
}

void FPWorth::on_lvarPlotButton_clicked()
{

    int i,j;
    epsf = ui->epsfEdit->text().toDouble();
    epsx = ui->epsxEdit->text().toDouble();
    maxits = ui->maxitsEdit->text().toDouble();
    diffstep = ui->diffstepEdit->text().toDouble();
    plot->clear();
    j = ui->plotNamesCombo->currentIndex();
    //fs = approxGauss(data);
    for (i = 0; i < lvar_size; i++){
        std::cout << i << " before = " << means[j][i];
        std::cout << "; after = " << fs[j][i].mu << std::endl;
        plot->drawGauss(fs[j][i].mu, fs[j][i].a, fs[j][i].type, i);
        //std::cout << ; // !!!
        plot->drawDots(data, means[j][i], fs[j][i].k, i, lvar_size, j);
    }
}

void FPWorth::on_clearPlotButton_clicked()
{
    plot->clear();
}

//0.000000000000001 -- 3
//	0.0000000000001 -- 2
// 0.0000000000000001

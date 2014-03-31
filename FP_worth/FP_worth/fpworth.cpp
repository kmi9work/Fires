#include "fpworth.h"
#include "ui_fpworth.h"
#include "unistd.h"
#include <iostream>
#include "alglib/dataanalysis.h"
#include "alglib/interpolation.h"
#include <stdlib.h>     /* srand, rand */
#include <limits>


#define FIRE_COUNT 3
#define DELTA_ADD 0.3
#define min(a,b) ((a)<(b) ? (a) : (b))
#define max(a,b) ((a)>(b) ? (a) : (b))

FPWorth::FPWorth(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FPWorth)
{
    int i;
    ui->setupUi(this);
    ui->lvarSettings->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->lvarSettings, SIGNAL(customContextMenuRequested(const QPoint&)),
            this, SLOT(ShowContextMenu(const QPoint&)));
    // Set start values
    tableComboPrevIndex = 1;

    // Write start values to form.
   // ui->tableCombo->setItemText(0, QString::number(1));

    // Set vars from form.
    rulesListIndex_prev = -1;
    plot = new Plot();
    layout = new QHBoxLayout( ui->plotWidget );
    layout->setContentsMargins( 0, 0, 0, 0 );
    layout->addWidget( plot );
    nnpsPlot = new Plot();
    layout_nnps = new QHBoxLayout( ui->plotWidget_nnps );
    layout_nnps->setContentsMargins( 0, 0, 0, 0 );
    layout_nnps->addWidget( nnpsPlot );
    epsf = ui->epsfEdit->text().toDouble();
    epsx = ui->epsxEdit->text().toDouble();
    maxits = ui->maxitsEdit->text().toDouble();
    diffstep = ui->diffstepEdit->text().toDouble();
    ui->rulesListWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
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
    for (k = 0; k < fire_count; k++){
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
    QStringList buf_list;
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
    cols = names.size() - 1; // -Fires
    for (i = 0; i < cols; i++){
        item = new QTableWidgetItem(names[i]);
        ui->inputNnpsTable->setItem(0,i,item);
        ui->plotNamesCombo->addItem(names[i]);
    }
    ui->plotNamesCombo->addItem(names[i]);

    buf_list = in.readLine().split(sep);
    term_counts.resize(cols+1);
    for (i = 0; i < cols + 1; i++){
        term_counts[i] = buf_list[i].toInt();
    }
    fire_count = term_counts[cols];
    for (i = 1; i < fire_count; i++){
        ui->tableCombo->addItem(QString::number(i+1));
    }
    firsts.resize(fire_count);
    lasts.resize(fire_count);
    countRules.resize(fire_count);
    for (i = 0; i < fire_count; i++){
        countRules[i] = i + 1;
        firsts[i] = 3;
        lasts[i] = 3;
    }
    deltas.resize(fire_count);
    for (i = 0; i < fire_count; i++){
        deltas[i].resize(lasts[i]);
    }
    tableComboPrevIndex = ui->tableCombo->currentIndex();
    ui->countRulesEdit->setText(QString::number(countRules[tableComboPrevIndex]));
    ui->termCountFirst->setValue(firsts[tableComboPrevIndex]);
    ui->termCountLast->setValue(lasts[tableComboPrevIndex]);
    // Second line is lvar sizes. Not ready yet.
    while (!in.atEnd()){
        ret.append(in.readLine());
    }
    csvFile.close();
    //== End read file ==
    ui->inputNnpsTable->setColumnCount(cols);
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
    rows = new int[fire_count];
    for (i = 0; i < fire_count; i++) rows[i] = 0;
    // -- input of numeric --
    numbers = new int**[fire_count];
    string_numbers = new int*[fire_count];
    for (i = 0; i < fire_count; i++){
        numbers[i] = new int*[max_rows];
        string_numbers[i] = new int[max_rows];
        for (j = 0; j < max_rows; j++){
            numbers[i][j] = new int[cols];
        }
    }
    data.resize(max_rows);
    stop_messages = 0;
    for (i = 0; i < max_rows; i++){
        ui->progressBar->setValue(30 + ((double)i/max_rows)*50);
        splitList = inputStrList.at(i).split(sep);
        k = splitList.last().toInt() - 1;
        if (splitList.size() != (cols+1) && stop_messages < 5){
            QMessageBox::warning(this, tr("Error"), tr("Wrong size of %1'th row.").arg(i));
            stop_messages += 1;
            return;
        }
        buf_size = splitList.size();
        data[i].resize(cols+1);
        for (j = 0; j < splitList.size() - 1; j++){
            data[i][j].cluster = splitList.at(j).toInt() - 1;
            numbers[k][rows[k]][j] = splitList.at(j).toInt() - 1;
            string_numbers[k][rows[k]] = i;
        }
        data[i][j].cluster = splitList.at(j).toInt() - 1;
        rows[k] += 1;
    }
    // == End input of numeric ==
    printNumbers(ui->fuzzyTable,max_rows, 0);
    ui->progressBar->setValue(100);
    ui->addNormalButton->setEnabled(true);
}


void FPWorth::on_addNormalButton_clicked()
{
    QFile csvFile;
    QString fileName;
    QStringList inputStrList, splitList;
    int max_rows = 0;
    int i,j;
    QTableWidgetItem *item;
    double m;
    fileName = QFileDialog::getOpenFileName(this, tr("Open File"), tr("../.."),
                                            tr("CSV Files (*.csv);;Text Files (*.txt)"));
    if (!fileName.isEmpty()){
        csvFile.setFileName(fileName);
        ui->normalFileLabel->setText(fileName);
    }else{
        return;
    }
    csvFile.setFileName(fileName);
    if (!csvFile.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
        return;
    }
    QTextStream in(&csvFile);
    in.readLine(); // names
    in.readLine(); // Second line is lvar sizes. Not ready yet.
    while (!in.atEnd()){
        inputStrList.append(in.readLine());
    }
    csvFile.close();
    max_rows = inputStrList.size();


    for (i = 0; i < max_rows; i++){
        splitList = inputStrList[i].split(sep);
        if (splitList.size() != cols + 1){
            QMessageBox::critical(this, tr("Error in line size"),
                                  tr("Wrong size of %1'th row. Cols: %2, Size: %3")
                                  .arg(i).arg(cols).arg(splitList.size()));
            return;
        }
        for (j = 0; j < splitList.size(); j++){
            data[i][j].number = splitList[j].toDouble();
        }
    }
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

    // ------
    means.resize(cols+1);
    count_cluster.resize(cols+1);
    for (i = 0; i < cols + 1; i++){
        count_cluster[i].resize(term_counts[i]);
        for (j = 0; j < max_rows; j++){
            count_cluster[i][data[j][i].cluster] += 1;
        }
    }
    for (i = 0; i < cols + 1; i++){
        means[i].resize(term_counts[i]);
        for (j = 0; j < max_rows; j++){
            means[i][data[j][i].cluster] += data[j][i].number;
        }
    }
    for (i = 0; i < cols + 1; i++){
        for (j = 0; j < term_counts[i]; j++){
            if (count_cluster[i][j] > 0){
                means[i][j] /= count_cluster[i][j];
            }else{
                means[i][j] = 0;
            }
        }
    }
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
    fileName = QFileDialog::getOpenFileName(this, tr("Open File"), tr("../.."),
                                            tr("CSV Files (*.csv);;Text Files (*.txt)"));
    if (!fileName.isEmpty()){
        csvFile.setFileName(fileName);
        ui->normalFileLabel->setText(fileName);
    }else{
        return;
    }
    ui->progressBar->setValue(15);
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
    for (i = 0; i < cols + 1; i++) count_cluster[i].resize(term_counts[i]);
    for (i = 0; i < cols + 1; i++){
        ui->progressBar->setValue(60 + ((double)i/cols + 1)*30);
        qSort(data.begin(), data.end(), ByColumn(i));// !!!
        for (j = 0; j < max_rows; j++){
            workplace[j][0] = data[j][i].number;
        }
        alglib::clusterizersetpoints(s, workplace, 2);
        alglib::clusterizerrunkmeans(s, term_counts[i], rep);
        buf_int = rep.cidx[0];
        for (j = 0; j < term_counts[i]; j++){
            means[i].append(rep.c[j][0]);
        }
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
    }


    string_numbers = new int*[fire_count];
    numbers = new int**[fire_count];
    for (i = 0; i < fire_count; i++){
        numbers[i] = new int*[max_rows];
        string_numbers[i] = new int[max_rows];
        for (j = 0; j < max_rows; j++){
            numbers[i][j] = new int[cols];
        }
    }
    rows = new int[fire_count];
    for (i = 0; i < fire_count; i++) rows[i] = 0;

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


void FPWorth::makeCTree(int **numbers, int rows){
    // add first level
    QVector<int> buf;
    int i,j,index;
    QVector< QVector<struct term> > terms;
    index = 0;
    terms.resize(cols);
    for (i = 0; i < cols; i++){
        terms[i].resize(term_counts[i]);
        for (j = 0; j < term_counts[i]; j++){
            terms[i][j].lp_number = i;
            terms[i][j].term_number = j;
            terms[i][j].support = 0;
        }
        for (j = 0; j < rows; j++){
            terms[i][numbers[j][i]].support += 1;
        }
    }
    buf.append(-1);
    for (i = 0; i < cols; i++){
        for (j = 0; j < term_counts[i]; j++){
            rootCTree->addChild(terms[i][j], 0, buf);
        }
    }
    rootCTree->makeTree(numbers, rows);
}

void FPWorth::findRules(int first, int last, int step){
    frequentPatterns = rootCTree->assocRules(first, last, step);
    std::sort(frequentPatterns.begin(),frequentPatterns.end(),bySupportPattern);
}

void FPWorth::printRules(QVector<pattern> fpList){
    int i, j;
    QString str;
    for (i = 0; i < fpList.size(); i++){
        str = tr("Если ");
        for (j = 0; j < fpList[i].word.size() - 1; j++){
            str += names[fpList[i].word[j].lp_number] + tr("{%1} и ").arg(fpList[i].word[j].term_number + 1);
        }
        str += names[fpList[i].word[j].lp_number] + tr("{%1}").arg(fpList[i].word[j].term_number + 1);
        str += tr(", то %1{%2} / %3% : %4 из %5. ")
                .arg(names.last())
                .arg(fpList[i].cluster+1)
                .arg(QString::number(((double)fpList[i].support / fpList[i].count) * 100.0, 'f', 1))
                .arg(QString::number(fpList[i].support))
                .arg(QString::number(fpList[i].count));
        str += tr("Номера строк: ");
        for (j = 0; j < fpList[i].str_numbers.size() - 1; j++){
            str += tr("%1, ").arg(fpList[i].str_numbers[j] + 1);
        }
        str += tr("%1;").arg(fpList[i].str_numbers[j] + 1);
        new QListWidgetItem(str, ui->rulesListWidget);
    }
}

void FPWorth::on_makeRulesAprioriButton_clicked()
{
    int i;
    QVector<CandidateTree*> rootsCTree;
    ui->makeRulesBar->setValue(0);
    ui->rulesListWidget->clear();
    fpList.clear();
    // Reading deltas
    writeFromTableToDeltas();
    countRules[tableComboPrevIndex] = ui->countRulesEdit->text().toInt();
    //--- end --- deltas
    ui->makeRulesBar->setValue(1);
    for (i = 0; i < fire_count; i++){
        ui->makeRulesBar->setValue(1 + ((double)i/fire_count) * 90);
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
        //levels.clear();
        CandidateTree::levels.clear();
        frequentPatterns.clear();
        rootCTree = new CandidateTree(deltas[i], rows[i]);
        ui->makeRulesBar->setValue(1 + ((double)i/fire_count) * 90 + 5);
        makeCTree(numbers[i], rows[i]);
        ui->makeRulesBar->setValue(1 + ((double)i/fire_count) * 90 + 10);
        findRules(firsts[tableComboPrevIndex], lasts[tableComboPrevIndex], i);
        ui->makeRulesBar->setValue(1 + ((double)i/fire_count) * 90 + 15);
        if (countRules[i] != -1){
            frequentPatterns.resize(countRules[i]);
        }
        fpList += frequentPatterns;
        //Вывести разделения между правилами и пожары.
        rootsCTree.append(rootCTree);
    }
    printRules(fpList);
    rootsCTree.clear();
    ui->makeRulesBar->setValue(100);
}


// == End Main functions ==

// -- Plot --
void FPWorth::on_makePlotButton_clicked(){
    int i,j;
    epsf = ui->epsfEdit->text().toDouble();
    epsx = ui->epsxEdit->text().toDouble();
    maxits = ui->maxitsEdit->text().toDouble();
    diffstep = ui->diffstepEdit->text().toDouble();
    j = ui->plotNamesCombo->currentIndex();
    ui->plotProgressBar->setValue(0);
    fs = approxGauss(data);
    plot->clear();
    for (i = 0; i < term_counts[j]; i++){
        ui->plotProgressBar->setValue(95 + ((double)i/(term_counts[j]))*5);
        if (fs[j][i].mu == -1 || fs[j][i].a == -1){
            continue;
        }
        plot->drawGauss(fs[j][i].mu, fs[j][i].a, fs[j][i].type, i);
        plot->drawDots(data, means[j][i], fs[j][i].k, i, term_counts[j],j);
    }
    ui->plotNamesCombo->setCurrentIndex(0);
    ui->plotProgressBar->setValue(100);
}

double funcGauss(double x, double sigma, double mu){
    return exp(-(x-mu)*(x-mu)/(2*sigma*sigma));
}

double funcE(double x, double sigma, double mu){
    return 1/(1 + exp(-sigma*(x-mu)));
}
double funcNE(double x, double sigma, double mu){
    return 1/(1 + exp(sigma*(x-mu)));
}

void function_cx_G_func(const alglib::real_1d_array &c, const alglib::real_1d_array &x, double &func, void *ptr)
{
    func = funcGauss(x[0], c[1], c[0]);
}

void function_cx_E_func(const alglib::real_1d_array &c, const alglib::real_1d_array &x, double &func, void *ptr)
{
    func = funcE(x[0], c[1], c[0]);
}

void function_cx_NE_func(const alglib::real_1d_array &c, const alglib::real_1d_array &x, double &func, void *ptr)
{
    func = funcNE(x[0], c[1], c[0]);
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
        xs[j].resize(term_counts[j]);
        ys[j].resize(term_counts[j]);
        cs[j].resize(term_counts[j]);
        indexes[j].resize(term_counts[j]);
        ks[j].resize(term_counts[j]);
        ret[j].resize(term_counts[j]);
        for (i = 0; i < term_counts[j]; i++){
            indexes[j][i] = 0;
        }
    }
    ui->plotProgressBar->setValue(5);
    for (i = 0; i < cols+1; i++){
        ui->plotProgressBar->setValue(5 + ((double)i/(cols+1))*10);
        for (j = 0; j < term_counts[i]; j++){
            xs[i][j].setlength(count_cluster[i][j],1);
            // Длина real_2d_array для каждого кластера равна количеству эл-тов в кластере.
            ys[i][j].setlength(count_cluster[i][j]);
            cs[i][j].setlength(2);
            // ys столько же, сколько и xs.
        }
    }


    for (i = 0; i < data.size(); i++){ // По всем строкам
        ui->plotProgressBar->setValue(15 + ((double)i/(data.size())*20));
        // Заполнить xs.
        for (j = 0; j < data[i].size(); j++){ // По всем столбцам
            // Для каждого real_2d_array свой индекс.
            xs[j][data[i][j].cluster][ indexes[j][data[i][j].cluster] ][0] = data[i][j].number;

            indexes[j][data[i][j].cluster] += 1;
        }
    }
    // Data больше не нужна.

    // Для этого сначала нужно вычислить k.
    base_set.resize(cols + 1);
    for (i = 0; i < cols + 1; i++){
        ui->plotProgressBar->setValue(35 + ((double)i/(cols+1))*20);
        for (j = 0; j < term_counts[i]; j++){
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
            if (j == 0) base_set[i].append(max(means[i][j] - max_k, 0));
            if (j == term_counts[i] - 1) base_set[i].append(means[i][j] + max_k);
        }
    }
    // Для каждого из xs вычислить ys.
    // Записать cs для каждого.
    for (i = 0; i < cols + 1; i++){
        ui->plotProgressBar->setValue(55 + ((double)i/(cols+1))*40);
        for (j = 0; j < term_counts[i]; j++){
            if (ks[i][j] <  std::numeric_limits<double>::epsilon() &&
                ks[i][j] > -std::numeric_limits<double>::epsilon()){
                ret[i][j].a = 1;
                ret[i][j].mu = 1;
                if (j == 0){
                    ret[i][j].type = 2;
                }else if (j == term_counts[i] - 1){
                    ret[i][j].type = 1;
                }else{
                    ret[i][j].type = 0;
                }
                ret[i][j].k = 1;
                continue;
            }

            for (l = 0; l < ys[i][j].length(); l++){
                if (j == 0 && xs[i][j](l,0) < means[i][j]){
                    ys[i][j][l] = 1;
                }else if (j == term_counts[i] - 1 && xs[i][j](l,0) > means[i][j]){
                    ys[i][j][l] = 1;
                }else{
                    ys[i][j][l] = funcNorm(xs[i][j](l,0),ks[i][j],means[i][j]);
                }
            }

            //--------
            if (j == 0){
                cs[i][j][0] = means[i][j] + ks[i][j]/2; // +- k/2
                cs[i][j][1] = -5 / ks[i][j]; // -?
            }else if (j == term_counts[i] - 1){
                cs[i][j][0] = means[i][j] - ks[i][j]/2; // +- k/2
                cs[i][j][1] = 5 / ks[i][j]; // -?
            }else{
                cs[i][j][0] = means[i][j]; // +- k/2
                cs[i][j][1] = dispersio(ys[i][j]);
            }
            ui->plotProgressBar->setValue(55 + ((double)i/(cols+1))*40 + 1);
            std::cout << i << ", " << j << std::endl;
            std::cout << xs[i][j].tostring(2) << "\n----------" << std::endl;
            std::cout << ys[i][j].tostring(2) << "\n==========" << std::endl;
            std::cout << cs[i][j].tostring(2) << "\n~~~~~~~~~~" << std::endl;
            alglib::lsfitcreatef(xs[i][j], ys[i][j], cs[i][j], diffstep, state);
            ui->plotProgressBar->setValue(55 + ((double)i/(cols+1))*40 + 2);
            alglib::lsfitsetcond(state, epsf, epsx, maxits);
            ui->plotProgressBar->setValue(55 + ((double)i/(cols+1))*40 + 3);
            if (j == 0){
                ret[i][j].type = 2;
                alglib::lsfitfit(state, function_cx_NE_func);
            }else if (j == term_counts[i] - 1){
                ret[i][j].type = 1;
                alglib::lsfitfit(state, function_cx_E_func);
            }else{
                ret[i][j].type = 0;
                alglib::lsfitfit(state, function_cx_G_func);
            }
            ui->plotProgressBar->setValue(55 + ((double)i/(cols+1))*40 + 4);
            alglib::lsfitresults(state, info, cs[i][j], rep);
            ui->plotProgressBar->setValue(55 + ((double)i/(cols+1))*40 + 5);
            err = rep.rmserror;

            //========
            iter = 0;
            while (err > 0.1 && iter < iters){
                if (j == 0){
                    cs[i][j][0] = means[i][j] + ks[i][j]/2 + (((rand()%100)/100.0)*locality*2 - locality); // +- k/2
                    before_mu = cs[i][j][0];
                    cs[i][j][1] = -5 / ks[i][j] + (((rand()%100)/100.0)*locality*2 - locality); // -?
                }else if (j == term_counts[i] - 1){
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
                }else if (j == term_counts[i] - 1){
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
            if (count_cluster[i][j] == 0){
                ret[i][j].mu = -1;
                ret[i][j].a = -1;
            }
            ret[i][j].mu = cs[i][j][0];
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

void FPWorth::on_okTermButton_clicked()
{
    int i;
    int size, buf_size, buf_first;
    int first, last;
    QTableWidgetItem *item;
    //buf_first = first;
    first = ui->termCountFirst->text().toInt();
    last = ui->termCountLast->text().toInt();
    if (last < first){
        QMessageBox::warning(this, tr("Error"), tr("First > last"));
        ui->termCountFirst->setValue(firsts[tableComboPrevIndex]);
        ui->termCountLast->setValue(lasts[tableComboPrevIndex]);
        return;
    }
    firsts[tableComboPrevIndex] = first;
    lasts[tableComboPrevIndex] = last;
    deltas[tableComboPrevIndex].resize(last);
    writeFromDeltasToTable(tableComboPrevIndex);
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
    QVector<double> xs;
    QVector< QVector<double> > mus;
    QVector< QVector<double> > alphas;
    int accuracy = 10000;
    double eps = 1.0 / accuracy;
    double step;
    int i, j, l, maxf_i;
    double min_mu, alpha, max_alpha, min_beta, maxf;
    double f;
    double integral_summ, center;
    QVector<double> max_alphas;
    xs.resize(cols);
    double point;
    for (i = 0; i < cols; i++){
        xs[i] = ui->inputNnpsTable->item(1,i)->text().toDouble();
    }
    ui->progressBar_nnps->setValue(10);
    mus.resize(cols);
    for (i = 0; i < cols; i++){
        ui->progressBar_nnps->setValue(10 + ((double)i/cols)*20);
        mus[i].resize(term_counts[i]);
        for (j = 0; j < term_counts[i]; j++){
            if (fs[i][j].type == 0){
                mus[i][j] = funcGauss(xs[i],fs[i][j].a,fs[i][j].mu);
            }else if(fs[i][j].type == 1){
                mus[i][j] = funcE(xs[i],fs[i][j].a,fs[i][j].mu);
            }else{
                mus[i][j] = funcNE(xs[i],fs[i][j].a,fs[i][j].mu);
            }
        }
    }
    ui->progressBar_nnps->setValue(30);
    // alphas
    alphas.resize(fire_count);
    max_alphas.resize(fire_count);
    i = fpList[0].cluster;
    max_alpha = 0;
    for (j = 0; j < fpList.size(); j++){
        ui->progressBar_nnps->setValue(30 + ((double)j/fpList.size())*40);
        min_mu = 1;
        for (l = 0; l < fpList[j].word.size(); l++){ // min mus for rule
            min_mu = min(mus[fpList[j].word[l].lp_number][fpList[j].word[l].term_number], min_mu);
        }
        if (ui->suppRulesCheckBox->isChecked()){
            alpha = min_mu*((double)fpList[j].support/fpList[j].count);//supp(Ri) * min(mus)
        }else{
            alpha = min_mu;
        }

        if (fpList[j].cluster != i){
            max_alphas[i] = max_alpha; // For each Fire.
            std::cout << " - " << max_alpha << std::endl;
            max_alpha = 0;
            i = fpList[j].cluster;
        }
        max_alpha = max(max_alpha, alpha);//max alpha from all the rules
        alphas[fpList[j].cluster].append(alpha);


    }
    max_alphas[fpList[j-1].cluster] = max_alpha; // For each Fire.
    std::cout << " - " << max_alpha << std::endl;
    ui->progressBar_nnps->setValue(70);
    // For all alphas or only for each Fires ??????????????????????????????????????????
    // Normalize
    //for (j = 0; j < alphas[j].size(); j++){
    //    alphas[i][j] = alphas[i][j] / max_alpha;
    //}
    //}
    // Normalize ?
    // Defuzzyfication

    // Нужно переделывать таким образом, чтобы интегрирование шло правильным образом.
    // Не учитывается текущая таблица fires.

    // Находим каждый шаг максимум между всеми (или текущим, предыдущим, следующим) и max_alpas[i].
    // f = funcGauss(point, fs[cols][i].a, fs[cols][i].mu);
    //integrate
    integral_summ = 0;
    step = (base_set[cols][1] - base_set[cols][0])/accuracy;
    nnpsPlot->clear();
    for (point = base_set[cols][0]; point < base_set[cols][1]; point += step){
        ui->progressBar_nnps->setValue(70 + (point/(base_set[cols][1] - base_set[cols][0])*20));
        maxf = 0;
        //Пройти по всем из fire_count. Найти максимум. Потом минимум его и mu.
        for (i = 0; i < fire_count; i++){
            if (fs[cols][i].type == 0){
                f = funcGauss(point, fs[cols][i].a, fs[cols][i].mu);
            }else if (fs[cols][i].type == 1){
                f = funcE(point, fs[cols][i].a, fs[cols][i].mu);
            }else{
                f = funcNE(point, fs[cols][i].a, fs[cols][i].mu);
            }
            if (f > maxf){
                maxf = f;
                maxf_i = i;
            }
        }
        maxf = min(maxf, max_alphas[maxf_i]); // Cut function
        nnpsPlot->addPoint(point, maxf);
        integral_summ += step*maxf;
    }
    nnpsPlot->drawPoints();
    center = 0;
    for (point = base_set[cols][0]; point < base_set[cols][1]; point += step){
        ui->progressBar_nnps->setValue(90 + (point/(base_set[cols][1] - base_set[cols][0])*9));
        maxf = 0;
        //Пройти по всем из fire_count. Найти максимум. Потом минимум его и mu.
        for (i = 0; i < fire_count; i++){
            if (fs[cols][i].type == 0){
                f = funcGauss(point, fs[cols][i].a, fs[cols][i].mu);
            }else if (fs[cols][i].type == 1){
                f = funcE(point, fs[cols][i].a, fs[cols][i].mu);
            }else{
                f = funcNE(point, fs[cols][i].a, fs[cols][i].mu);
            }
            if (f > maxf){
                maxf = f;
                maxf_i = i;
            }
        }
        maxf = min(maxf, max_alphas[maxf_i]); // Cut function
        center += step*maxf;
        if (center > integral_summ/2) break;
    }
    center = point;
    min_beta = 1;
    ui->progressBar_nnps->setValue(99);
    for (i = 0; i < fire_count; i++){
        if (max_alphas[i] < min_beta) min_beta = max_alphas[i];
    }

    ui->fireCountLabel->setText(QString::number(center));
    ui->probLabel->setText(QString::number(min_beta));
    ui->progressBar_nnps->setValue(100);
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
    for (i = 0; i < term_counts[j]; i++){
        std::cout << i << " before = " << means[j][i];
        std::cout << "; after = " << fs[j][i].mu << std::endl;
        plot->drawGauss(fs[j][i].mu, fs[j][i].a, fs[j][i].type, i);
        //std::cout << ; // !!!
        plot->drawDots(data, means[j][i], fs[j][i].k, i, term_counts[j], j);
    }
}

void FPWorth::on_clearPlotButton_clicked()
{
    plot->clear();
}
void FPWorth::writeFromTableToDeltas(){
    int i,j;
    deltas[tableComboPrevIndex].resize(lasts[tableComboPrevIndex]);
    for (i = 0; i < firsts[tableComboPrevIndex]-1; i++){
        deltas[tableComboPrevIndex][i] = 0;
    }
    for (j = i; j < lasts[tableComboPrevIndex]; j++){
        deltas[tableComboPrevIndex][j] = ui->supportTable->item(j-i,0)->text().toDouble();
    }
}

void FPWorth::writeFromDeltasToTable(int index){
    int i;
    ui->supportTable->setRowCount(lasts[index] - firsts[index] + 1);
    ui->termCountFirst->setValue(firsts[index]);
    ui->termCountLast->setValue(lasts[index]);

    for (i = firsts[index]-1; i < lasts[index]; i++){
        ui->supportTable->setItem(i - firsts[index] + 1, 0, new QTableWidgetItem(QString::number(deltas[index][i])));
        ui->supportTable->setVerticalHeaderItem(i - firsts[index] + 1, new QTableWidgetItem(tr("Уровень %1").arg(i+1)));
    }
}

void FPWorth::on_tableCombo_currentIndexChanged(int index)
{
    int i,j;
    writeFromTableToDeltas();
    writeFromDeltasToTable(index);
    countRules[tableComboPrevIndex] = ui->countRulesEdit->text().toInt();
    ui->countRulesEdit->setText(QString::number(countRules[index]));
    tableComboPrevIndex = index;
}
void FPWorth::on_countRulesEdit_returnPressed()
{
    countRules[tableComboPrevIndex] = ui->countRulesEdit->text().toInt();
}

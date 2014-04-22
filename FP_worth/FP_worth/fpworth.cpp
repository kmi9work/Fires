﻿#include "fpworth.h"
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

// Apriori можно ускорить. Бизнес-аналитика От данных к знаниям 2013.djvu, стр. 290.
// Вместо обращения к базе, просмотр наборов размера k-1.

QString QString::number(double n, char f, int prec){
    return QLocale().toString(n, f, prec);
}

double QString::toDouble(bool *ok) const{
    return QLocale().toDouble(this);
}



FPWorth::FPWorth(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FPWorth)
{
    int i;
    ui->setupUi(this);
    ui->lvarSettings->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->lvarSettings, SIGNAL(customContextMenuRequested(const QPoint&)),
            this, SLOT(ShowContextMenu(const QPoint&)));
<<<<<<< HEAD
    ui->fuzzyTable->setContextMenuPolicy(Qt::CustomContextMenu);
        connect(ui->fuzzyTable, SIGNAL(customContextMenuRequested(QPoint)),
                SLOT(customMenuRequested(QPoint)));
    // Set start values

    QLocale curLocale(QLocale("ru_RU"));
    QLocale::setDefault(curLocale);
    tableComboPrevIndex = 1;
=======
    // Set start values
    tableComboPrevIndex = 1;

    // Write start values to form.
   // ui->tableCombo->setItemText(0, QString::number(1));

    // Set vars from form.
>>>>>>> 6d084f1711d10ebe1a9fa385851bf172d0516d81
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
<<<<<<< HEAD
    sep = QString(";");
=======
>>>>>>> 6d084f1711d10ebe1a9fa385851bf172d0516d81
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
    names.clear();
    names = in.readLine().split(sep);
    cols = names.size() - 1; // -Fires
<<<<<<< HEAD
    ui->inputNnpsTable->clear();
    ui->inputNnpsTable->setColumnCount(cols);
    ui->plotNamesCombo->clear();
=======
>>>>>>> 6d084f1711d10ebe1a9fa385851bf172d0516d81
    for (i = 0; i < cols; i++){
        item = new QTableWidgetItem(names[i]);
        ui->inputNnpsTable->setItem(0,i,item);
        ui->plotNamesCombo->addItem(names[i]);
    }
    ui->plotNamesCombo->addItem(names[i]);

    buf_list = in.readLine().split(sep);
<<<<<<< HEAD
    term_counts.clear();
=======
>>>>>>> 6d084f1711d10ebe1a9fa385851bf172d0516d81
    term_counts.resize(cols+1);
    for (i = 0; i < cols + 1; i++){
        term_counts[i] = buf_list[i].toInt();
    }
    fire_count = term_counts[cols];
<<<<<<< HEAD
    qDebug() << "readFileToStringList: msg10";
    if (!ui->tableCombo) qDebug() << "there is no combo!";
    for (i = ui->tableCombo->count(); i < fire_count; i++){
        qDebug() << "readFileToStringList: msg20  i = " << i;
        ui->tableCombo->addItem(QString::number(i+1));
        qDebug() << "readFileToStringList: msg30";
    }
    qDebug() << "readFileToStringList: msg40";
    while (ui->tableCombo->count() > fire_count){
        ui->tableCombo->removeItem(ui->tableCombo->count() - 1);
    }
    firsts.clear();
    lasts.clear();
    countRules.clear();
=======
    for (i = 1; i < fire_count; i++){
        ui->tableCombo->addItem(QString::number(i+1));
    }
>>>>>>> 6d084f1711d10ebe1a9fa385851bf172d0516d81
    firsts.resize(fire_count);
    lasts.resize(fire_count);
    countRules.resize(fire_count);
    for (i = 0; i < fire_count; i++){
<<<<<<< HEAD
        countRules[i] = 5;
        firsts[i] = 3;
        lasts[i] = 3;
    }
    deltas.clear();
    deltas.resize(fire_count);
    for (i = 1; i < fire_count; i++){
=======
        countRules[i] = i + 1;
        firsts[i] = 3;
        lasts[i] = 3;
    }
    deltas.resize(fire_count);
    for (i = 0; i < fire_count; i++){
>>>>>>> 6d084f1711d10ebe1a9fa385851bf172d0516d81
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
<<<<<<< HEAD
    rows.clear();
    rows.resize(fire_count);
    for (i = 0; i < fire_count; i++) rows[i] = 0;
    // -- input of numeric --
    numbers.clear();
    numbers.resize(fire_count);
    for (i = 0; i < fire_count; i++){
        numbers[i].resize(max_rows);
=======
    rows = new int[fire_count];
    for (i = 0; i < fire_count; i++) rows[i] = 0;
    // -- input of numeric --
    numbers = new int**[fire_count];
    string_numbers = new int*[fire_count];
    for (i = 0; i < fire_count; i++){
        numbers[i] = new int*[max_rows];
        string_numbers[i] = new int[max_rows];
>>>>>>> 6d084f1711d10ebe1a9fa385851bf172d0516d81
        for (j = 0; j < max_rows; j++){
            numbers[i][j].resize(cols);
        }
    }
<<<<<<< HEAD
    data.clear();
=======
>>>>>>> 6d084f1711d10ebe1a9fa385851bf172d0516d81
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
<<<<<<< HEAD
=======
        buf_size = splitList.size();
>>>>>>> 6d084f1711d10ebe1a9fa385851bf172d0516d81
        data[i].resize(cols+1);
        for (j = 0; j < splitList.size() - 1; j++){
            data[i][j].cluster = splitList.at(j).toInt() - 1;
            numbers[k][rows[k]][j] = splitList.at(j).toInt() - 1;
        }
        data[i][j].cluster = splitList.at(j).toInt() - 1;
        rows[k] += 1;
    }
    // == End input of numeric ==
    ui->fuzzyTable->clear();
    printNumbers(ui->fuzzyTable,max_rows, 1);
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
<<<<<<< HEAD
    in.readLine(); // Second line is lvar sizes. Doesn't need there
=======
    in.readLine(); // Second line is lvar sizes. Not ready yet.
>>>>>>> 6d084f1711d10ebe1a9fa385851bf172d0516d81
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
<<<<<<< HEAD
    ui->normalTable->clear();
=======
>>>>>>> 6d084f1711d10ebe1a9fa385851bf172d0516d81
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
<<<<<<< HEAD
    means.clear();
    means.resize(cols+1);
    count_cluster.clear();
=======
    means.resize(cols+1);
>>>>>>> 6d084f1711d10ebe1a9fa385851bf172d0516d81
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

    data.clear();
    data.resize(max_rows);
    fuzzyTableIndexes_prev.reserve(max_rows);
    fuzzyTableIndexes_prev.resize(0);
    for (i = 0; i < max_rows; i++){
        ui->progressBar->setValue(31 + ((double)i/max_rows)*30);
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
    means.clear();
    means.resize(cols + 1);
    count_cluster.clear();
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

<<<<<<< HEAD
    numbers.clear();
    numbers.resize(fire_count);
    for (i = 0; i < fire_count; i++){
        numbers[i].resize(max_rows);
=======

    string_numbers = new int*[fire_count];
    numbers = new int**[fire_count];
    for (i = 0; i < fire_count; i++){
        numbers[i] = new int*[max_rows];
        string_numbers[i] = new int[max_rows];
>>>>>>> 6d084f1711d10ebe1a9fa385851bf172d0516d81
        for (j = 0; j < max_rows; j++){
            numbers[i][j].resize(cols);
        }
    }
<<<<<<< HEAD
    rows.clear();
    rows.resize(fire_count);
    for (i = 0; i < fire_count; i++) rows[i] = 0;
    qDebug() << "on_openNormalButton_clicked: msg10";

=======
    rows = new int[fire_count];
    for (i = 0; i < fire_count; i++) rows[i] = 0;
>>>>>>> 6d084f1711d10ebe1a9fa385851bf172d0516d81

    for (i = 0; i < max_rows; i++){
        qDebug() << "on_openNormalButton_clicked: msg20: " << i;
        ui->progressBar->setValue(90 + ((double)i/max_rows)*10);
        k = data[i][cols].cluster;
        qDebug() << "on_openNormalButton_clicked: msg21: " << i;
        for (j = 0; j < cols; j++){
            qDebug() << "on_openNormalButton_clicked: msg22: " << i << ": " << j;
            numbers[k][rows[k]][j] = data[i][j].cluster;
        }
        qDebug() << "on_openNormalButton_clicked: msg23: " << i;
        rows[k] += 1;
    }
    printNumbers(ui->fuzzyTable,max_rows, 1);
    ui->progressBar->setValue(100);
}
// == End open files ==

// -- Main functions --


<<<<<<< HEAD
void FPWorth::makeCTree(QVector< QVector<int> > numbers, int rows){
=======
void FPWorth::makeCTree(int **numbers, int rows){
>>>>>>> 6d084f1711d10ebe1a9fa385851bf172d0516d81
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
<<<<<<< HEAD
        str = tr("%1. Если ").arg(i);
=======
        str = tr("Если ");
>>>>>>> 6d084f1711d10ebe1a9fa385851bf172d0516d81
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
    int cr;
    QVector<CandidateTree*> rootsCTree;
    ui->makeRulesBar->setValue(0);
    ui->rulesListWidget->clear();
    rulesListIndex_prev = -1;
    fpList.clear();
    // Reading deltas
    writeFromTableToDeltas();
    countRules[tableComboPrevIndex] = ui->countRulesEdit->text().toInt();
    //--- end --- deltas
    ui->makeRulesBar->setValue(1);
    for (i = 0; i < fire_count; i++){
        ui->makeRulesBar->setValue(1 + ((double)i/fire_count) * 90);
<<<<<<< HEAD
=======
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
>>>>>>> 6d084f1711d10ebe1a9fa385851bf172d0516d81
        CandidateTree::levels.clear();
        frequentPatterns.clear();
        rootCTree = new CandidateTree(deltas[i], rows[i]);
        ui->makeRulesBar->setValue(1 + ((double)i/fire_count) * 90 + 5);
        makeCTree(numbers[i], rows[i]);
        ui->makeRulesBar->setValue(1 + ((double)i/fire_count) * 90 + 10);
        findRules(firsts[tableComboPrevIndex], lasts[tableComboPrevIndex], i);
        ui->makeRulesBar->setValue(1 + ((double)i/fire_count) * 90 + 15);
        if (countRules[i] != -1){
<<<<<<< HEAD
            cr = countRules[i];
            while (cr < (frequentPatterns.size()) &&
                   frequentPatterns[cr].support < frequentPatterns[cr-1].support + std::numeric_limits<double>::epsilon() &&
                   frequentPatterns[cr].support > frequentPatterns[cr-1].support - std::numeric_limits<double>::epsilon()){
                cr += 1;
            }

            frequentPatterns.resize(min(cr,frequentPatterns.size()));
=======
            frequentPatterns.resize(countRules[i]);
>>>>>>> 6d084f1711d10ebe1a9fa385851bf172d0516d81
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
    int prog_val;
    epsf = ui->epsfEdit->text().toDouble();
    epsx = ui->epsxEdit->text().toDouble();
    maxits = ui->maxitsEdit->text().toDouble();
    diffstep = ui->diffstepEdit->text().toDouble();
    j = ui->plotNamesCombo->currentIndex();
<<<<<<< HEAD
    prog_val = 0; ui->plotProgressBar->setValue(prog_val);
    fs = approxGauss(data);
    plot->clear();
    plot->setLegend(names[j]);

    ui->fire1Box_a->setValue(fs[cols][0].a);
    ui->fire1Box_b->setValue(fs[cols][0].mu);
    ui->fire1Box_a->setSingleStep(0.01);
    ui->fire1Box_b->setSingleStep(0.01);
    ui->fire1Box_a->setEnabled(true);
    ui->fire1Box_b->setEnabled(true);
    ui->fire2Box_a->setValue(fs[cols][1].a);
    ui->fire2Box_b->setValue(fs[cols][1].mu);
    ui->fire2Box_a->setSingleStep(0.01);
    ui->fire2Box_b->setSingleStep(0.01);
    ui->fire2Box_a->setEnabled(true);
    ui->fire2Box_b->setEnabled(true);
    ui->fire3Box_a->setValue(fs[cols][2].a);
    ui->fire3Box_b->setValue(fs[cols][2].mu);
    ui->fire3Box_a->setSingleStep(0.01);
    ui->fire3Box_b->setSingleStep(0.01);
    ui->fire3Box_a->setEnabled(true);
    ui->fire3Box_b->setEnabled(true);
    if (fire_count > 3){
        ui->fire4Box_a->setValue(fs[cols][3].a);
        ui->fire4Box_b->setValue(fs[cols][3].mu); //these setValues replots.
        ui->fire4Box_a->setSingleStep(0.01);
        ui->fire4Box_b->setSingleStep(0.01);
        ui->fire4Box_a->setEnabled(true);
        ui->fire4Box_b->setEnabled(true);
=======
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
>>>>>>> 6d084f1711d10ebe1a9fa385851bf172d0516d81
    }
    ui->stepSpin->setValue(0.01);
    ui->plotNamesCombo->setCurrentIndex(0);
<<<<<<< HEAD
    prog_val = 100; ui->plotProgressBar->setValue(prog_val);
=======
    ui->plotProgressBar->setValue(100);
>>>>>>> 6d084f1711d10ebe1a9fa385851bf172d0516d81
}

double funcGauss(double x, double sigma, double mu){
    return exp(-(x-mu)*(x-mu)/(2*sigma*sigma));
<<<<<<< HEAD
}

double funcE(double x, double sigma, double mu){
    return 1/(1 + exp(-sigma*(x-mu)));
}

=======
}

double funcE(double x, double sigma, double mu){
    return 1/(1 + exp(-sigma*(x-mu)));
}
>>>>>>> 6d084f1711d10ebe1a9fa385851bf172d0516d81
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
    int i,j,l;
    double err, iter = 0, iters = 1000;
    double a,m;
    double max_k;
    double locality = 2.5;
    int prog_val;
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
<<<<<<< HEAD
    prog_val = 5; ui->plotProgressBar->setValue(prog_val);
    for (i = 0; i < cols+1; i++){
        prog_val = 5 + ((double)i/(cols+1))*10; ui->plotProgressBar->setValue(prog_val);
=======
    ui->plotProgressBar->setValue(5);
    for (i = 0; i < cols+1; i++){
        ui->plotProgressBar->setValue(5 + ((double)i/(cols+1))*10);
>>>>>>> 6d084f1711d10ebe1a9fa385851bf172d0516d81
        for (j = 0; j < term_counts[i]; j++){
            xs[i][j].setlength(count_cluster[i][j],1);
            // Длина real_2d_array для каждого кластера равна количеству эл-тов в кластере.
            ys[i][j].setlength(count_cluster[i][j]);
            cs[i][j].setlength(2);
            // ys столько же, сколько и xs.
        }
    }


    for (i = 0; i < data.size(); i++){ // По всем строкам
<<<<<<< HEAD
        prog_val = 15 + ((double)i/(data.size())*20); ui->plotProgressBar->setValue(prog_val);
=======
        ui->plotProgressBar->setValue(15 + ((double)i/(data.size())*20));
>>>>>>> 6d084f1711d10ebe1a9fa385851bf172d0516d81
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
<<<<<<< HEAD
        prog_val = 35 + ((double)i/(cols+1))*20; ui->plotProgressBar->setValue(prog_val);
        base_set[i].resize(2);
        base_set[i][0] = xs[i][0](0,0);
        base_set[i][1] = xs[i][0](0,0);
=======
        ui->plotProgressBar->setValue(35 + ((double)i/(cols+1))*20);
>>>>>>> 6d084f1711d10ebe1a9fa385851bf172d0516d81
        for (j = 0; j < term_counts[i]; j++){
            max_k = 0;
            for (l = 0; l < xs[i][j].rows(); l++){
                a = xs[i][j](l,0);
                base_set[i][0] = min(base_set[i][0], xs[i][j](l,0));
                base_set[i][1] = max(base_set[i][1], xs[i][j](l,0));
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
<<<<<<< HEAD
        prog_val = 55 + ((double)i/(cols+1))*40; ui->plotProgressBar->setValue(prog_val);
        for (j = 0; j < term_counts[i]; j++){
            if (ks[i][j] <  std::numeric_limits<double>::epsilon() &&
                ks[i][j] > -std::numeric_limits<double>::epsilon()){
                // Костыль. На случай одного значения в кластере.
                ret[i][j].a = 5;
=======
        ui->plotProgressBar->setValue(55 + ((double)i/(cols+1))*40);
        for (j = 0; j < term_counts[i]; j++){
            if (ks[i][j] <  std::numeric_limits<double>::epsilon() &&
                ks[i][j] > -std::numeric_limits<double>::epsilon()){
                ret[i][j].a = 1;
>>>>>>> 6d084f1711d10ebe1a9fa385851bf172d0516d81
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
<<<<<<< HEAD
            prog_val = 55 + ((double)i/(cols+1))*40 + 1; ui->plotProgressBar->setValue(prog_val);
=======
            ui->plotProgressBar->setValue(55 + ((double)i/(cols+1))*40 + 1);
>>>>>>> 6d084f1711d10ebe1a9fa385851bf172d0516d81
            std::cout << i << ", " << j << std::endl;
            std::cout << xs[i][j].tostring(2) << "\n----------" << std::endl;
            std::cout << ys[i][j].tostring(2) << "\n==========" << std::endl;
            std::cout << cs[i][j].tostring(2) << "\n~~~~~~~~~~" << std::endl;
            alglib::lsfitcreatef(xs[i][j], ys[i][j], cs[i][j], diffstep, state);
<<<<<<< HEAD
            prog_val = 55 + ((double)i/(cols+1))*40 + 2; ui->plotProgressBar->setValue(prog_val);
            alglib::lsfitsetcond(state, epsf, epsx, maxits);
            prog_val = 55 + ((double)i/(cols+1))*40 + 3; ui->plotProgressBar->setValue(prog_val);
=======
            ui->plotProgressBar->setValue(55 + ((double)i/(cols+1))*40 + 2);
            alglib::lsfitsetcond(state, epsf, epsx, maxits);
            ui->plotProgressBar->setValue(55 + ((double)i/(cols+1))*40 + 3);
>>>>>>> 6d084f1711d10ebe1a9fa385851bf172d0516d81
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
<<<<<<< HEAD
            prog_val = 55 + ((double)i/(cols+1))*40 + 4; ui->plotProgressBar->setValue(prog_val);
            alglib::lsfitresults(state, info, cs[i][j], rep);
            prog_val = 55 + ((double)i/(cols+1))*40 + 5; ui->plotProgressBar->setValue(prog_val);
=======
            ui->plotProgressBar->setValue(55 + ((double)i/(cols+1))*40 + 4);
            alglib::lsfitresults(state, info, cs[i][j], rep);
            ui->plotProgressBar->setValue(55 + ((double)i/(cols+1))*40 + 5);
>>>>>>> 6d084f1711d10ebe1a9fa385851bf172d0516d81
            err = rep.rmserror;

            //========
            iter = 0;
            while (err > 0.1 && iter < iters){
                if (j == 0){
                    cs[i][j][0] = means[i][j] + ks[i][j]/2 + (((rand()%100)/100.0)*locality*2 - locality); // +- k/2
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
    std::cout << "ololo" << std::endl;
    QPoint globalPos = ui->lvarSettings->mapToGlobal(pos);
    // for QAbstractScrollArea and derived classes you would use:
    // QPoint globalPos = myWidget->viewport()->mapToGlobal(pos);

    QMenu myMenu;
    myMenu.addAction("Copy");
    myMenu.addAction("Paste");

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

<<<<<<< HEAD
QColor getColor(int n){
    switch (n) {
    case 0:
        return Qt::red;
    case 1:
        return Qt::green;
    case 2:
        return Qt::blue;
    case 3:
        return Qt::magenta;
    case 4:
        return Qt::cyan;
    }
    return Qt::black;
}

void FPWorth::on_nnpsButton_clicked(){
    QVector<double> xs;
    double fire1, fire2, prod;
    int i;
    xs.resize(cols);
    for (i = 0; i < cols; i++){
        xs[i] = ui->inputNnpsTable->item(1,i)->text().toDouble();
    }
    nnpsCalc(xs, &fire1, &fire2, &prod);
    ui->fireCountLabel->setText(QString::number(fire1, 'f', 0));
    ui->fireCountLabel_2->setText(QString::number(fire2, 'f', 0));
    ui->probLabel->setText(QString::number(prod));
    nnpsPlot->setBaseSet(base_set[cols]);
=======
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
>>>>>>> 6d084f1711d10ebe1a9fa385851bf172d0516d81
}

void FPWorth::nnpsCalc(QVector<double> xs, double *fire1, double *fire2, double *prod)
{
    QVector< QVector<double> > mus;
    QVector< QVector<double> > alphas;
    int accuracy = 10000;
    double eps = 1.0 / accuracy;
    double step;
    int i, j, l, maxf_i, maxf_i_prev;
    double min_mu, alpha, max_alpha, min_beta, maxf;
    double f;
    double integral_summ, center, integral_summ_num, integral_summ_denum;
    QColor line_color;
    double point;
    QVector<double> max_alphas;
    ui->progressBar_nnps->setValue(10);
    mus.resize(cols);
    std::cout << "MUS:" << std::endl;
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
            std::cout << mus[i][j] << "; ";
        }
        std::cout << std::endl;
    }
    ui->progressBar_nnps->setValue(30);
    // alphas
    alphas.resize(fire_count);
    max_alphas.resize(fire_count);
    i = fpList[0].cluster;
    max_alpha = 0;
    std::cout << "RULES:" << std::endl;
    for (j = 0; j < fpList.size(); j++)
    {
        ui->progressBar_nnps->setValue(30 + ((double)j/fpList.size())*40);
        min_mu = 1;
        for (l = 0; l < fpList[j].word.size(); l++)
        { // min mus for rule
            std::cout << mus[fpList[j].word[l].lp_number][fpList[j].word[l].term_number] << "; ";
            min_mu = min(mus[fpList[j].word[l].lp_number][fpList[j].word[l].term_number], min_mu);
        }
        std::cout << std::endl;
        if (ui->suppRulesCheckBox->isChecked()){
            alpha = min_mu*((double)fpList[j].support/fpList[j].count);//supp(Ri) * min(mus)
        }else{
            alpha = min_mu;
        }

        if (fpList[j].cluster != i){
            max_alphas[i] = max_alpha; // For each Fire.
            std::cout << "Beta: " << max_alpha << std::endl;
            max_alpha = 0;
            i = fpList[j].cluster;
        }
        max_alpha = max(max_alpha, alpha);//max alpha from all the rules
        alphas[fpList[j].cluster].append(alpha);
    }
    max_alphas[fpList[j-1].cluster] = max_alpha; // For each Fire.
    std::cout << "Beta: " << max_alpha << std::endl;
    ui->progressBar_nnps->setValue(70);

    //integrate
    maxf_i_prev = 0;
    maxf_i = 0;
    integral_summ = 0;
    step = (base_set[cols][1] - base_set[cols][0])/accuracy;
    nnpsPlot->clear();
    for (point = base_set[cols][0]; point < base_set[cols][1]; point += step){
        ui->progressBar_nnps->setValue(70 + (point/(base_set[cols][1] - base_set[cols][0])*20));
        maxf = 0;
        //Пройти по всем из fire_count. Найти максимум. Потом минимум его и mu.
        for (i = 0; i < fire_count; i++){
            if (fs[cols][i].type == 0){
                f = min(funcGauss(point, fs[cols][i].a, fs[cols][i].mu), max_alphas[i]);
            }else if (fs[cols][i].type == 1){
                f = min(funcE(point, fs[cols][i].a, fs[cols][i].mu), max_alphas[i]);
            }else{
                f = min(funcNE(point, fs[cols][i].a, fs[cols][i].mu), max_alphas[i]);
            }
            if (f > maxf){
                maxf = f;
                maxf_i = i;
            }
        }
        nnpsPlot->addPoint(point, maxf);// ADD COLOR
        // Когда меняется maxf_i, тогда рисовать полученный на этапе набор точек. Предыдущий набор стирать.
        integral_summ += step*maxf;
        if (maxf_i != maxf_i_prev){
            line_color = getColor(maxf_i_prev);
            nnpsPlot->drawLine(line_color);
        }
        maxf_i_prev = maxf_i;
    }
    line_color = getColor(maxf_i_prev);
    nnpsPlot->drawLine(line_color);
    //nnpsPlot->drawPoints();
    center = 0;
    for (point = base_set[cols][0]; point < base_set[cols][1]; point += step){
        ui->progressBar_nnps->setValue(90 + (point/(base_set[cols][1] - base_set[cols][0])*9));
        maxf = 0;
        //Пройти по всем из fire_count. Найти максимум. Потом минимум его и mu.
        for (i = 0; i < fire_count; i++){
            if (fs[cols][i].type == 0){
                f = min(funcGauss(point, fs[cols][i].a, fs[cols][i].mu), max_alphas[i]);
            }else if (fs[cols][i].type == 1){
                f = min(funcE(point, fs[cols][i].a, fs[cols][i].mu), max_alphas[i]);
            }else{
                f = min(funcNE(point, fs[cols][i].a, fs[cols][i].mu), max_alphas[i]);
            }
            if (f > maxf){
                maxf = f;
                maxf_i = i;
            }
        }
        center += step*maxf;
        if (center > integral_summ/2) break;
    }
    center = point;
    min_beta = 1;
    ui->progressBar_nnps->setValue(99);
    for (i = 0; i < fire_count; i++){
        if (max_alphas[i] < min_beta) min_beta = max_alphas[i];
    }
    *prod = min_beta;
    *fire1 = center;
    //Another way. ----------------------
    integral_summ_num = 0;
    integral_summ_denum = 0;
    for (point = base_set[cols][0]; point < base_set[cols][1]; point += step){
        maxf = 0;
        //Пройти по всем из fire_count. Найти максимум. Потом минимум его и mu.
        for (i = 0; i < fire_count; i++){
            if (fs[cols][i].type == 0){
                f = min(funcGauss(point, fs[cols][i].a, fs[cols][i].mu), max_alphas[i]);
            }else if (fs[cols][i].type == 1){
                f = min(funcE(point, fs[cols][i].a, fs[cols][i].mu), max_alphas[i]);
            }else{
                f = min(funcNE(point, fs[cols][i].a, fs[cols][i].mu), max_alphas[i]);
            }
            if (f > maxf){
                maxf = f;
                maxf_i = i;
            }
        }
        integral_summ_num += step*maxf*point;
        integral_summ_denum += step*maxf;
    }
    *fire2 = integral_summ_num / integral_summ_denum;
    nnpsPlot->drawVLine(*fire1);
    ui->progressBar_nnps->setValue(100);
}

void FPWorth::on_lvarPlotButton_clicked()
{

    int i,j;
    epsf = ui->epsfEdit->text().toDouble();
    epsx = ui->epsxEdit->text().toDouble();
    maxits = ui->maxitsEdit->text().toDouble();
    diffstep = ui->diffstepEdit->text().toDouble();
    j = ui->plotNamesCombo->currentIndex();
    plot->clear();
    plot->setLegend(names[j]);
    //fs = approxGauss(data);
    for (i = 0; i < term_counts[j]; i++){
<<<<<<< HEAD
        drawTerm(j, i);
=======
        std::cout << i << " before = " << means[j][i];
        std::cout << "; after = " << fs[j][i].mu << std::endl;
        plot->drawGauss(fs[j][i].mu, fs[j][i].a, fs[j][i].type, i);
        //std::cout << ; // !!!
        plot->drawDots(data, means[j][i], fs[j][i].k, i, term_counts[j], j);
>>>>>>> 6d084f1711d10ebe1a9fa385851bf172d0516d81
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
<<<<<<< HEAD

void FPWorth::on_tableCombo_currentIndexChanged(int index)
{
    int i,j;
    qDebug() << "on_tableCombo_currentIndexChanged: msg10";
    writeFromTableToDeltas();
    qDebug() << "on_tableCombo_currentIndexChanged: msg20";
    writeFromDeltasToTable(index);
    qDebug() << "on_tableCombo_currentIndexChanged: msg30";
    countRules[tableComboPrevIndex] = ui->countRulesEdit->text().toInt();
    qDebug() << "on_tableCombo_currentIndexChanged: msg40";
    ui->countRulesEdit->setText(QString::number(countRules[index]));
    tableComboPrevIndex = index;
}
void FPWorth::on_countRulesEdit_returnPressed()
{
    countRules[tableComboPrevIndex] = ui->countRulesEdit->text().toInt();
}

void FPWorth::on_fire1Box_a_valueChanged(double arg1)
{
    int i,j;
    fs[cols][0].a = ui->fire1Box_a->value();
    plot->clear();
    j = ui->plotNamesCombo->currentIndex();
    //fs = approxGauss(data);
    for (i = 0; i < term_counts[j]; i++){
        drawTerm(j, i);
    }
}

void FPWorth::on_fire1Box_b_valueChanged(double arg1)
{
    int i,j;
    fs[cols][0].mu = ui->fire1Box_b->value();
    plot->clear();
    j = ui->plotNamesCombo->currentIndex();
    //fs = approxGauss(data);
    for (i = 0; i < term_counts[j]; i++){
        drawTerm(j, i);
    }
}

void FPWorth::on_fire2Box_a_valueChanged(double arg1)
{
    int i,j;
    fs[cols][1].a = ui->fire2Box_a->value();
    plot->clear();
    j = ui->plotNamesCombo->currentIndex();
    //fs = approxGauss(data);
    for (i = 0; i < term_counts[j]; i++){
        drawTerm(j, i);
    }
}

void FPWorth::on_fire2Box_b_valueChanged(double arg1)
{
    int i,j;
    fs[cols][1].mu = ui->fire2Box_b->value();
    plot->clear();
    j = ui->plotNamesCombo->currentIndex();
    //fs = approxGauss(data);
    for (i = 0; i < term_counts[j]; i++){
        drawTerm(j, i);
    }
}

void FPWorth::on_fire3Box_a_valueChanged(double arg1)
{
    int i,j;
    fs[cols][2].a = ui->fire3Box_a->value();
    plot->clear();
    j = ui->plotNamesCombo->currentIndex();
    //fs = approxGauss(data);
    for (i = 0; i < term_counts[j]; i++){
        drawTerm(j, i);
    }
}

void FPWorth::on_fire3Box_b_valueChanged(double arg1)
{
    int i,j;
    fs[cols][2].mu = ui->fire3Box_b->value();
    plot->clear();
    j = ui->plotNamesCombo->currentIndex();
    //fs = approxGauss(data);
    for (i = 0; i < term_counts[j]; i++){
        drawTerm(j, i);
    }
}

void FPWorth::on_fire4Box_a_valueChanged(double arg1)
{
    int i,j;
    fs[cols][3].a = ui->fire4Box_a->value();
    plot->clear();
    j = ui->plotNamesCombo->currentIndex();
    //fs = approxGauss(data);
    for (i = 0; i < term_counts[j]; i++){
        drawTerm(j, i);
    }
}

void FPWorth::drawTerm(int i, int j){
    plot->setBaseSet(base_set[i]);
    plot->drawGauss(fs[i][j].mu, fs[i][j].a, fs[i][j].type, j);
    plot->drawDots(data, means[i][j], fs[i][j].k, j, term_counts[i], i);
}

void FPWorth::on_fire4Box_b_valueChanged(double arg1)
{
    int i,j;
    fs[cols][3].mu = ui->fire4Box_b->value();
    plot->clear();
    j = ui->plotNamesCombo->currentIndex();
    //fs = approxGauss(data);
    for (i = 0; i < term_counts[j]; i++){
        drawTerm(j, i);
    }
}

void FPWorth::on_horizontalSlider_sliderMoved(int position)
{
    if (position < 10){
        ui->stackedWidget->setCurrentIndex(0);
    }else if (position < 40){
        ui->stackedWidget->setCurrentIndex(1);
    }else if (position < 70){
        ui->stackedWidget->setCurrentIndex(2);
    }else{
        ui->stackedWidget->setCurrentIndex(3);
    }
}

void FPWorth::on_stepSpin_valueChanged(double arg1)
{
    ui->fire1Box_a->setSingleStep(ui->stepSpin->value());
    ui->fire1Box_b->setSingleStep(ui->stepSpin->value());
    ui->fire2Box_a->setSingleStep(ui->stepSpin->value());
    ui->fire2Box_b->setSingleStep(ui->stepSpin->value());
    ui->fire3Box_a->setSingleStep(ui->stepSpin->value());
    ui->fire3Box_b->setSingleStep(ui->stepSpin->value());
    ui->fire4Box_a->setSingleStep(ui->stepSpin->value());
    ui->fire4Box_b->setSingleStep(ui->stepSpin->value());
}

void FPWorth::on_pushButton_clicked()
{
    QFile csvFile, outFile;
    QString fileName, outFileName;
    QString inputLine;
    int i,j,k, count;
    QStringList splitList;
    QTextStream in(&csvFile);
    double fires1_error, fires2_error, fires;
    QVector<double> xs;
    struct error{
        double minn;
        double maxx;
        int maxi;
        int mini;
    } error1, error2;
    double fire1, fire2, prod, e1, e2;

    fileName = QFileDialog::getOpenFileName(this, tr("Open File"), tr("../.."),
                                            tr("CSV Files (*.csv);;Text Files (*.txt)"));
    if (!fileName.isEmpty()) {
        ui->fuzzyFileLabel->setText(fileName);
    }else{
        return;
    }

    csvFile.setFileName(fileName);
    if (!csvFile.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
        return;
    }

    QFileInfo fi(fileName);
    outFileName = fi.baseName() + QString("_out.txt");
    outFile.setFileName(fi.dir().absolutePath() + QString("\\") + outFileName);
    if (!outFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, tr("Error"), tr("Could not write to file"));
        return;
    }
    QTextStream out(&outFile);
    // -- Read from file to inputStrList --

    in.readLine();
    in.readLine();
    xs.clear();
    xs.resize(cols);
    fires1_error = 0;
    count = 0;
    error1.minn = 1000;
    error1.maxx = 0;
    error1.mini = -1;
    error1.maxi = -1;

    error2.minn = 1000;
    error2.maxx = 0;
    error2.maxi = -1;
    error2.mini = -1;
    while (!in.atEnd()){
        inputLine = in.readLine();
        splitList = inputLine.split(sep);
        if (splitList.size() > cols + 1){
            QMessageBox::critical(this, tr("Error"), tr("Wrong cols count"));
            return;
        }
        for (i = 0; i < splitList.size()-1; i++){
            xs[i] = splitList[i].toDouble();
        }
        fires = splitList[i].toDouble();
        nnpsCalc(xs, &fire1, &fire2, &prod);
        e1 = fabs(fire1 - fires);
        e2 = fabs(fire2 - fires);
        if (e1 > error1.maxx){
            error1.maxx = e1;
            error1.maxi = count;
        }
        if (e1 < error1.minn){
            error1.minn = e1;
            error1.mini = count;
        }
        if (e2 > error2.maxx){
            error2.maxx = e2;
            error2.maxi = count;
        }
        if (e2 < error2.minn){
            error2.minn = e2;
            error2.mini = count;
        }
        fires1_error += e1;
        fires2_error += e2;
        count += 1;
        out << count << ";" << inputLine << ";;" << QString::number(fire1, 'f', 0) << ";" << QString::number(e1, 'f', 0) << endl;
        std::cout << inputLine.toStdString() << " <- " << e1 << std::endl;
    }
    csvFile.close();
    outFile.close();
    fires1_error /= (double) count;
    fires2_error /= (double) count;
    ui->fireErrorLabel->setText(QString::number(fires1_error, 'f', 0));
    ui->fireErrorLabel_1->setText(QString::number(fires2_error, 'f', 0));
    ui->fireErrorLabel_max->setText(QString::number(error1.maxx, 'f', 0));
    ui->fireErrorLabel_max_1->setText(QString::number(error2.maxx, 'f', 0));
    ui->fireErrorLabel_max_i->setText(QString::number(error1.maxi));
    ui->fireErrorLabel_max_i_1->setText(QString::number(error2.maxi));
    ui->fireErrorLabel_min->setText(QString::number(error1.minn, 'f', 0));
    ui->fireErrorLabel_min_1->setText(QString::number(error2.minn, 'f', 0));
    ui->fireErrorLabel_min_i->setText(QString::number(error1.mini));
    ui->fireErrorLabel_min_i_1->setText(QString::number(error2.mini));
    ui->progressBar_nnps->setValue(100);

}

/*
void TestCopyTable::on_pushButton_copy_clicked()
{

}
*/
















void FPWorth::customMenuRequested(QPoint pos){

//void FPWorth::on_fuzzyTable_customContextMenuRequested(const QPoint &pos){
    QModelIndex index=ui->fuzzyTable->indexAt(pos);

    QMenu *menu=new QMenu(this);
    menu->addAction(new QAction("Copy", this));
    menu->addAction(new QAction("Paste", this));
    //menu->addAction(new QAction("Action 3", this));
    menu->popup(ui->fuzzyTable->viewport()->mapToGlobal(pos));
    QAction* selectedItem = menu->exec();

    if (selectedItem)
    {
        if (selectedItem->text() == "Copy"){
            QAbstractItemModel *abmodel = ui->fuzzyTable->model();
            QItemSelectionModel * model = ui->fuzzyTable->selectionModel();
            QModelIndexList list = model->selectedIndexes();

            qSort(list);

            if(list.size() < 1)
                return;

            QString copy_table;
            QModelIndex last = list.last();
            QModelIndex previous = list.first();

            list.removeFirst();

            for(int i = 0; i < list.size(); i++)
            {
                QVariant data = abmodel->data(previous);
                QString text = data.toString();

                QModelIndex index = list.at(i);
                copy_table.append(text);

                if(index.row() != previous.row())

                {
                    copy_table.append('\n');
                }
                else
                {
                    copy_table.append(';');
                }
                previous = index;
            }

            copy_table.append(abmodel->data(last).toString());
            copy_table.append('\n');

            QClipboard *clipboard = QApplication::clipboard();
            clipboard->setText(copy_table);
        }
    }
    else
    {
        // nothing was chosen
    }
}

void FPWorth::on_magicButton_clicked()
{
    fs[cols][0].a = 16.93;
    ui->fire1Box_a->setValue(16.93);
    fs[cols][0].mu = 0.3;
    ui->fire1Box_b->setValue(0.3);
    fs[cols][2].a = 2.991;
    ui->fire3Box_a->setValue(2.991);
}




void FPWorth::getRp5Data(QDate dFrom, QDate dTo, QString id)
{

    //Запрос. Получение ссылки на файл.
    QUrl serviceUrl = QUrl("http://rp5.ru/inc/f_archive.php");
    QString postDataStr;
    postDataStr = QString("wmo_id=%1&f_ed0=%2&f_ed1=%3&f_ed2=%4&f_ed3=04&f_ed4=04&f_ed5=21&f_ed6=%5&f_ed7=%6&f_ed8=%7&f_pe=1&f_pe1=1&lng_id=2")
            .arg(id,QString::number(dFrom.day()),QString::number(dFrom.month()),QString::number(dFrom.year()),
                 QString::number(dTo.day()),QString::number(dTo.month()),QString::number(dTo.year()));
    QByteArray postData;
    postData.append(postDataStr);
    movieRp5 = new QMovie(":/images/loading.gif");
    ui->loadingLabel->setMovie(movieRp5);
    movieRp5->start();
    ui->cityRp5->setEnabled(false);
    ui->coordRp5->setEnabled(false);

    mgr = new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(onfinish(QNetworkReply*)));
    mgr->post(QNetworkRequest(serviceUrl), postData);
}

void FPWorth::onfinish(QNetworkReply *rep)
{
    QByteArray bts = rep->readAll();
    QRegExp rx("<a href=(http.+)>");
    QString str(bts);
    QString link;
    str = str.simplified();
    std::cout << str.toStdString() << std::endl;
    //Вытащить из строки ссылку регекспом
    rx.setMinimal(true);
    int pos = rx.indexIn(str);
    if (pos > -1) {
        link = rx.cap(1);
        std::cout << link.toStdString() << std::endl;
    }else{
        qDebug() << "ERROR in responce!";
        return;
    }
    QUrl serviceUrl = QUrl(link);
    mgr = new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(onfinish2(QNetworkReply*)));
    mgr->get(QNetworkRequest(serviceUrl));
}

QByteArray gUncompress(const QByteArray &data)
{
    if (data.size() <= 4) {
        qWarning("gUncompress: Input data is truncated");
        return QByteArray();
    }

    QByteArray result;

    int ret;
    z_stream strm;
    static const int CHUNK_SIZE = 1024;
    char out[CHUNK_SIZE];

    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;
    strm.avail_in = data.size();
    strm.next_in = (Bytef*)(data.data());

    ret = inflateInit2(&strm, 15 +  32); // gzip decoding
    if (ret != Z_OK)
        return QByteArray();

    // run inflate()
    do {
        strm.avail_out = CHUNK_SIZE;
        strm.next_out = (Bytef*)(out);

        ret = inflate(&strm, Z_NO_FLUSH);
        Q_ASSERT(ret != Z_STREAM_ERROR);  // state not clobbered

        switch (ret) {
        case Z_NEED_DICT:
            ret = Z_DATA_ERROR;     // and fall through
        case Z_DATA_ERROR:
        case Z_MEM_ERROR:
            (void)inflateEnd(&strm);
            return QByteArray();
        }

        result.append(out, CHUNK_SIZE - strm.avail_out);
    } while (strm.avail_out == 0);

    // clean up and return
    inflateEnd(&strm);
    return result;
}

void FPWorth::onfinish2(QNetworkReply *rep)
{
    QByteArray bts = rep->readAll();
    QByteArray bytearray;
    bytearray = gUncompress(bts);
    QString filename = QFileDialog::getSaveFileName(this, tr("Save File"));
    QFile file(filename);
    file.open(QIODevice::WriteOnly);
    file.write(bytearray);
    file.close();
    ui->loadingLabel->clear();
    ui->cityRp5->setEnabled(true);
    ui->coordRp5->setEnabled(true);
}

void FPWorth::on_cityDataOpen_clicked()
{
    QString fileName;
    QStringList bufSplitList;
    QFile csvFile;
    QStringList citiesList;
    int pos, i;
    struct city buf_city;
//    fileName = QFileDialog::getOpenFileName(this, tr("Open city file"), tr("../.."),
//                                            tr("CSV Files (*.csv);;Text Files (*.txt)"));
    fileName = QString(":/data/ids.txt");
    csvFile.setFileName(fileName);
    if (!csvFile.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
        return;
    }
    QTextStream in(&csvFile);
    // city file structure: "city;id;x;y"
    i = 1;
    cities.clear();
    citiesList.clear();
    while (!in.atEnd()){
        bufSplitList = in.readLine().split(sep);
        buf_city.name = bufSplitList[0];
        citiesList << buf_city.name;

        buf_city.id = bufSplitList[1];
        buf_city.x = bufSplitList[2].replace(QString("."), QString(",")).toDouble();
        buf_city.y = bufSplitList[3].replace(QString("."), QString(",")).toDouble();
        cities << buf_city;
        i++;
    }
    csvFile.close();
    qDebug() << citiesList.size();
//    QLineEdit *lineEdit = new QLineEdit(this);

    QCompleter *completer = new QCompleter(citiesList, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->citiesEdit->setCompleter(completer);
}


void FPWorth::on_cityRp5_clicked()
{
    QString city = ui->citiesEdit->text();
    QString id;
    int i;
    for (i = 0; i < cities.size(); i++){
        if (cities[i].name == city){
            id = cities[i].id;
            break;
        }
    }
    getRp5Data(ui->dateRp5From->date(), ui->dateRp5To->date(), id);
}

double dist(double x1, double y1, double x2, double y2){
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

void FPWorth::on_coordRp5_clicked()
{
    QString coords = ui->coordEdit->text();
    QStringList bufList;
    QString id;
    int i, mini;
    double x,y;
    double mindist, d;
    bufList = coords.split(sep);
    x = bufList[0].replace(QString("."), QString(",")).toDouble();
    y = bufList[1].replace(QString("."), QString(",")).toDouble();
    mindist = dist(x, y, cities[0].x, cities[0].y);
    mini = 0;
    for (i = 1; i < cities.size(); i++){
        d = dist(x, y, cities[i].x, cities[i].y);
        if (d < mindist){
            mindist = d;
            mini = i;
        }
    }
    getRp5Data(ui->dateRp5From->date(), ui->dateRp5To->date(), cities[mini].id);
    ui->closestMeteoLabel->setText(QString("Ближайшая метеостанция:\n%1").arg(cities[mini].name));
}















=======

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
>>>>>>> 6d084f1711d10ebe1a9fa385851bf172d0516d81

#ifndef FPWORTH_H
#define FPWORTH_H

#include <iostream>
#include <QMainWindow>
#include <QFile>
#include <QVector>
#include <QVector2D>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QTextStream>
#include <QFileDialog>
#include <plot.h>
//#include "fptree.h"
#include "candidatetree.h"
#include "alglib/dataanalysis.h"
#include "alglib/interpolation.h"
#include "structs.h"

/*class FPTree;

struct level{
    int number;
    QVector<FPTree *> nodes;
};*/


/*
typedef struct{
    double support;
    QVector<int> word;
} pattern;

*/

class Plot;
class CandidateTree;

namespace Ui {
class FPWorth;
}

class FPWorth : public QMainWindow
{
    Q_OBJECT

public:
    explicit FPWorth(QWidget *parent = 0);
    ~FPWorth();

private slots:
    void on_openFuzzyButton_clicked();

    //void on_makeRulesButton_clicked();


    void on_makePlotButton_clicked();

    void on_openNormalButton_clicked();

    void ShowContextMenu(const QPoint &pos);
    void on_lvarSettings_entered(const QModelIndex &index);

    void on_makeRulesAprioriButton_clicked();

    void on_okTermButton_clicked();

    void on_rulesListWidget_doubleClicked(const QModelIndex &index);

    void on_clearFuzzyButton_clicked();

    void on_nnpsButton_clicked();

    void on_lvarPlotButton_clicked();

    void on_clearPlotButton_clicked();

private:
    void printNumbers(QTableWidget *table, int max_rows, int add, int start_x, int start_y);
    void splitColumns();
    void makeWords(int **numbers, int rows, int k);
    void makeTree(int rows);
    void makeTerms(int **numbers, int rows, int k);
    void makeRules(int rows, int f);

    int cols; // number of lvars without Fires
    int *rows;
    int lvar_size; // Размер лингвистических переменных.
    int ***numbers; // Обыкновенные числа
    int **string_numbers; // Номера строк
    int global_i;
    int word_count;
    int maxWordSize;
    int *fires;
    struct term *terms;
    QStringList names; // Имена термов
    int first, last; // уровни, которые нужно вывести

    Ui::FPWorth *ui;
    //FPTree *rootFPTree;
    CandidateTree *rootCTree;
    QVector< QVector<struct term> > words;
    //QVector<struct level> levels;
    QVector<double> deltas; //minsupp
    QVector<struct pattern> frequentPatterns;
    QVector<struct pattern> fpList;
    QVector< QVector<struct numCluster> > data; // num and cluster all terms(with fire)
    QVector< QVector<int> > count_cluster; //Число элементов в кластере.[cols+1][lvar_size]
    QVector< QVector<double> > means; // ядра кластеров.
    QString sep; // separator
    int rulesListIndex_prev; // Подсветка правила
    QVector<int> fuzzyTableIndexes_prev; // Подсветка строк в нечётком множестве.
    //bool byColumn(const double *col1, const double *col2);

    Plot *plot;
    QHBoxLayout *layout;
    QVector< QVector<struct membershipFunction> > fs;

    void printQVector(QVector<QVector<struct numCluster> > v, int start_x, int start_y);

    QVector<QVector<membershipFunction> > approxGauss(QVector< QVector<struct numCluster> > data);
    QStringList readFileToStringList(QString fileName);
    void makeCTree(int **numbers, int rows);
    void findRules(int first, int last, int step);
    void printRules(QVector<pattern> frequentPatterns);
};

#endif // FPWORTH_H




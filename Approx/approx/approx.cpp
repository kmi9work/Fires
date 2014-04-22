#include "approx.h"
#include "ui_approx.h"
#include <iostream>
#include "alglib/dataanalysis.h"
#include "alglib/interpolation.h"
#include <QMessageBox>
#include <QFile>
#include <QVector>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QTextStream>
#include <QFileDialog>
#include <plot.h>
#include <stdlib.h>     /* srand, rand */

Approx::Approx(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Approx)
{
    ui->setupUi(this);
}

Approx::~Approx()
{
    delete ui;
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

void Approx::on_openButton_clicked()
{
    QFile csvFile;
    QString fileName;
    QString inputLineX, inputLineY, inputLineC;
    QString sep;
    int i,j,k;
    QStringList splitListX, splitListY, splitListC;
    QTextStream in(&csvFile);
    QVector<double> xs;
    alglib::real_2d_array x; //rows*(cols+1)
    alglib::real_1d_array y;
    alglib::real_1d_array c; //[0] = mu, [1] = sigma
    alglib::real_1d_array c1;
    double locality = 2.5;

    double err, iter = 0, iters = 1000;
    alglib::ae_int_t info;
    alglib::lsfitstate state;
    alglib::lsfitreport rep;
    double epsf; // Параметры аппроксимации.
    double epsx;
    alglib::ae_int_t maxits;
    double diffstep;

    epsf = ui->epsfEdit->text().toDouble();
    epsx = ui->epsxEdit->text().toDouble();
    maxits = ui->maxitsEdit->text().toInt();
    diffstep = ui->diffstepEdit->text().toDouble();

    sep = ui->sepEdit->text();
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

    // -- Read from file to inputStrList --

    inputLineX = in.readLine();
    inputLineY = in.readLine();
    inputLineC = in.readLine();
    splitListX = inputLineX.split(sep);
    splitListY = inputLineY.split(sep);
    splitListC = inputLineC.split(sep);
    if (splitListX.size() != splitListY.size()){
        QMessageBox::critical(this, tr("Error"), tr("Wrong size of vectors."));
        return;
    }
    x.setlength(inputLineX.size(), 1);
    y.setlength(inputLineY.size());
    c.setlength(inputLineZ.size());
    ui->inputTable->setColumnCount(y.length());
    ui->inputTable->setRowCount(3);
    for (i = 0; i < splitListX.size(); i++){
        x[i][0] = splitListX[i].toDouble();
        ui->inputTable->setItem(i, 0, new QTableWidgetItem(QString::number(x[i][0])));
        y[i] = splitListY[i].toDouble();
        ui->inputTable->setItem(i, 1, new QTableWidgetItem(QString::number(y[i])));
    }
    for (i = 0; i < splitListC.size(); i++){
        c[i] = splitListC[i].toDouble();
        ui->inputTable->setItem(i, 2, new QTableWidgetItem(QString::number(c[i])));
    }

    alglib::lsfitcreatef(x, y, c, diffstep, state);
    alglib::lsfitsetcond(state, epsf, epsx, maxits);
    alglib::lsfitfit(state, function_cx_G_func);
    for (i = 0; i < c1.length(); i++){
        c1[i] = c[i];
    }
    alglib::lsfitresults(state, info, c1, rep);
    err = rep.rmserror;

    //========
    iter = 0;
    while (err > 0.1 && iter < iters){
        for (i = 0; i < c1.length(); i++){
            c1[i] = c[i] + (((rand()%100)/100.0)*locality*2 - locality);
        }
        alglib::lsfitcreatef(x, y, c1, diffstep, state);
        alglib::lsfitsetcond(state, epsf, epsx, maxits);
        alglib::lsfitfit(state, function_cx_G_func);
        alglib::lsfitresults(state, info, c1, rep);
        err = rep.rmserror;
        iter++;
    }

    ui->outputTable->setColumnCount(c1.length());
    for (i = 0; i < c1.length(); i++){
        ui->outputTable->setItem(i, 0, new QTableWidgetItem(QString::number(c1[i])));
    }

}




















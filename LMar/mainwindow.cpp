#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "alglib/interpolation.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    plot = new Plot();
    layout = new QHBoxLayout( ui->plotWidget );
    layout->setContentsMargins( 0, 0, 0, 0 );
    layout->addWidget( plot );
}

MainWindow::~MainWindow()
{
    delete ui;
}

QStringList MainWindow::readFileToStringList(QString fileName){
    QFile csvFile;
    QStringList ret;


    csvFile.setFileName(fileName);

    if (!csvFile.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
        return ret;
    }
    // -- Read from file to inputStrList --
    QTextStream in(&csvFile);

    while (!in.atEnd()){
        ret.append(in.readLine());
    }
    csvFile.close();
    //== End read file ==
    return ret;
}
void MainWindow::on_openButton_clicked()
{
    int i,j,k;
    QFile csvFile;
    QString fileName;
    double number;
    QVector< QVector<double> > d;
    QString sep(";");
    QTableWidgetItem *item;
    QStringList inputStrList, splitList;
    int max_rows = 0;
    int cols = 0;
    int lvar_size = 5;
    fileName = QFileDialog::getOpenFileName(this, tr("Open File"), tr(".."),
                                            tr("CSV Files (*.csv);;Text Files (*.txt)"));
    if (!fileName.isEmpty()){
        csvFile.setFileName(fileName);
    }else{
        return;
    }
    inputStrList = readFileToStringList(fileName);
    if (inputStrList.empty()) return;
    max_rows = inputStrList.size();
    data.clear();
    data.resize(max_rows);
    for (i = 0; i < max_rows; i++){
        splitList = inputStrList[i].split(sep);
        cols = splitList.size();
        data[i].reserve(cols);
        for (j = 0; j < cols; j++){
            number = splitList[j].toDouble();
            data[i].append(number);
        }
    }
//    data.resize(cols);
//    for (j = 0; j < cols; j++){
//        data[j].resize(max_rows);
//    }
//    for (i = 0; i < max_rows; i++){
//        for (j = 0; j < cols; j++){
//            data[j][i] = d[i][j];
//        }
//    }
    // -- Print normal data to normalTable --
    ui->normalTable->clear();
    ui->normalTable->setColumnCount(cols);
    ui->normalTable->setRowCount(max_rows);
    for (i = 0; i < max_rows; i++){
        for (j = 0; j < cols; j++){
            item = new QTableWidgetItem(QString::number(data[i][j]));
            ui->normalTable->setItem(i, j, item);
        }
    }
    // == Print normal data to normalTable ==
}

void function_cx_G_func(const alglib::real_1d_array &c, const alglib::real_1d_array &x, double &func, void *ptr)
{
    // this callback calculates f(c,x)=exp(-c0*sqr(x0))
    // where x is a position on X-axis and c is adjustable parameter
    func = exp(-(x[0]-c[0])*(x[0]-c[0])/(2*c[1]*c[1]));
}

void MainWindow::on_makePlotButton_clicked()
{
    int i;
    double sigma = ui->sigmaEdit->text().toDouble();

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
    alglib::real_2d_array x;
    alglib::real_1d_array y;
    alglib::real_1d_array c;

    plot->clear();
    plot->drawDots(data, 0);
    plot->drawGauss(0.99,sigma,0,0);

    x.setlength(data.size(),1);
    y.setlength(data.size());
    c.setlength(2);
    for (i = 0; i < data.size(); i++){
        x(i,0) = data[i][0];
        y[i] = data[i][1];
    }
    c[0] = 0.99;
    c[1] = 0.084107324;
    alglib::lsfitcreatef(x, y, c, diffstep, state);
    alglib::lsfitsetcond(state, epsf, epsx, maxits);
    alglib::lsfitfit(state, function_cx_G_func);
    alglib::lsfitresults(state, info, c, rep);
    ui->muLabel->setText(QString::number(c[0]));
    ui->sigmaLabel->setText(QString::number(c[1]));
    std::cout << rep.rmserror << std::endl;
    plot->drawGauss(c[0],c[1],0,1);
    alglib::lsfitcreatef(x, y, c, diffstep, state);
    alglib::lsfitsetcond(state, epsf, epsx, maxits);
    alglib::lsfitfit(state, function_cx_G_func);
    alglib::lsfitresults(state, info, c, rep);
    plot->drawGauss(c[0],c[1],0,2);
}

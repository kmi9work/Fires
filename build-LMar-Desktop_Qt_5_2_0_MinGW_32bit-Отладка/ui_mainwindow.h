/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *plotWidget;
    QPushButton *openButton;
    QPushButton *makePlotButton;
    QTableWidget *normalTable;
    QLineEdit *sigmaEdit;
    QLabel *label_15;
    QLineEdit *epsfEdit;
    QLabel *label_16;
    QLineEdit *epsxEdit;
    QLineEdit *diffstepEdit;
    QLabel *label_13;
    QLabel *label_14;
    QLineEdit *maxitsEdit;
    QLabel *muLabel;
    QLabel *sigmaLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(816, 654);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        plotWidget = new QWidget(centralWidget);
        plotWidget->setObjectName(QStringLiteral("plotWidget"));
        plotWidget->setGeometry(QRect(20, 50, 761, 271));
        openButton = new QPushButton(centralWidget);
        openButton->setObjectName(QStringLiteral("openButton"));
        openButton->setGeometry(QRect(20, 0, 75, 23));
        makePlotButton = new QPushButton(centralWidget);
        makePlotButton->setObjectName(QStringLiteral("makePlotButton"));
        makePlotButton->setGeometry(QRect(110, 0, 75, 23));
        normalTable = new QTableWidget(centralWidget);
        if (normalTable->columnCount() < 60)
            normalTable->setColumnCount(60);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(13, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(14, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(15, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(16, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(17, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(18, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(19, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(20, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(21, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(22, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(23, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(24, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(25, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(26, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(27, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(28, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(29, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(30, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(31, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(32, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(33, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(34, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(35, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(36, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(37, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(38, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(39, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(40, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(41, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(42, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(43, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(44, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(45, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(46, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(47, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(48, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        normalTable->setHorizontalHeaderItem(49, __qtablewidgetitem49);
        if (normalTable->rowCount() < 1)
            normalTable->setRowCount(1);
        QBrush brush(QColor(209, 209, 209, 255));
        brush.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        __qtablewidgetitem50->setBackground(brush);
        normalTable->setItem(0, 50, __qtablewidgetitem50);
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        __qtablewidgetitem51->setFont(font);
        normalTable->setItem(0, 58, __qtablewidgetitem51);
        normalTable->setObjectName(QStringLiteral("normalTable"));
        normalTable->setGeometry(QRect(20, 330, 761, 261));
        normalTable->setSizeIncrement(QSize(0, 0));
        normalTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        normalTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        normalTable->setDefaultDropAction(Qt::CopyAction);
        normalTable->setSortingEnabled(true);
        normalTable->setRowCount(1);
        normalTable->setColumnCount(60);
        normalTable->horizontalHeader()->setDefaultSectionSize(40);
        sigmaEdit = new QLineEdit(centralWidget);
        sigmaEdit->setObjectName(QStringLiteral("sigmaEdit"));
        sigmaEdit->setGeometry(QRect(200, 0, 113, 20));
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(340, 30, 31, 16));
        QFont font1;
        font1.setPointSize(10);
        label_15->setFont(font1);
        epsfEdit = new QLineEdit(centralWidget);
        epsfEdit->setObjectName(QStringLiteral("epsfEdit"));
        epsfEdit->setGeometry(QRect(380, 0, 61, 20));
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(470, 30, 46, 13));
        label_16->setFont(font1);
        label_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        epsxEdit = new QLineEdit(centralWidget);
        epsxEdit->setObjectName(QStringLiteral("epsxEdit"));
        epsxEdit->setGeometry(QRect(380, 30, 61, 20));
        diffstepEdit = new QLineEdit(centralWidget);
        diffstepEdit->setObjectName(QStringLiteral("diffstepEdit"));
        diffstepEdit->setGeometry(QRect(520, 0, 41, 20));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(470, 0, 46, 16));
        label_13->setFont(font1);
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(340, 0, 31, 20));
        label_14->setFont(font1);
        maxitsEdit = new QLineEdit(centralWidget);
        maxitsEdit->setObjectName(QStringLiteral("maxitsEdit"));
        maxitsEdit->setGeometry(QRect(520, 30, 41, 20));
        muLabel = new QLabel(centralWidget);
        muLabel->setObjectName(QStringLiteral("muLabel"));
        muLabel->setGeometry(QRect(620, 10, 131, 16));
        sigmaLabel = new QLabel(centralWidget);
        sigmaLabel->setObjectName(QStringLiteral("sigmaLabel"));
        sigmaLabel->setGeometry(QRect(620, 30, 141, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 816, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        openButton->setText(QApplication::translate("MainWindow", "Open", 0));
        makePlotButton->setText(QApplication::translate("MainWindow", "Make plot", 0));
        QTableWidgetItem *___qtablewidgetitem = normalTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "1", 0));
        QTableWidgetItem *___qtablewidgetitem1 = normalTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "2", 0));
        QTableWidgetItem *___qtablewidgetitem2 = normalTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "3", 0));
        QTableWidgetItem *___qtablewidgetitem3 = normalTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "4", 0));
        QTableWidgetItem *___qtablewidgetitem4 = normalTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "5", 0));
        QTableWidgetItem *___qtablewidgetitem5 = normalTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "1", 0));
        QTableWidgetItem *___qtablewidgetitem6 = normalTable->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "2", 0));
        QTableWidgetItem *___qtablewidgetitem7 = normalTable->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "3", 0));
        QTableWidgetItem *___qtablewidgetitem8 = normalTable->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "4", 0));
        QTableWidgetItem *___qtablewidgetitem9 = normalTable->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "5", 0));
        QTableWidgetItem *___qtablewidgetitem10 = normalTable->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "1", 0));
        QTableWidgetItem *___qtablewidgetitem11 = normalTable->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "2", 0));
        QTableWidgetItem *___qtablewidgetitem12 = normalTable->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "3", 0));
        QTableWidgetItem *___qtablewidgetitem13 = normalTable->horizontalHeaderItem(13);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "4", 0));
        QTableWidgetItem *___qtablewidgetitem14 = normalTable->horizontalHeaderItem(14);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "5", 0));
        QTableWidgetItem *___qtablewidgetitem15 = normalTable->horizontalHeaderItem(15);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "1", 0));
        QTableWidgetItem *___qtablewidgetitem16 = normalTable->horizontalHeaderItem(16);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "2", 0));
        QTableWidgetItem *___qtablewidgetitem17 = normalTable->horizontalHeaderItem(17);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "3", 0));
        QTableWidgetItem *___qtablewidgetitem18 = normalTable->horizontalHeaderItem(18);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "4", 0));
        QTableWidgetItem *___qtablewidgetitem19 = normalTable->horizontalHeaderItem(19);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "5", 0));
        QTableWidgetItem *___qtablewidgetitem20 = normalTable->horizontalHeaderItem(20);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "1", 0));
        QTableWidgetItem *___qtablewidgetitem21 = normalTable->horizontalHeaderItem(21);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWindow", "2", 0));
        QTableWidgetItem *___qtablewidgetitem22 = normalTable->horizontalHeaderItem(22);
        ___qtablewidgetitem22->setText(QApplication::translate("MainWindow", "3", 0));
        QTableWidgetItem *___qtablewidgetitem23 = normalTable->horizontalHeaderItem(23);
        ___qtablewidgetitem23->setText(QApplication::translate("MainWindow", "4", 0));
        QTableWidgetItem *___qtablewidgetitem24 = normalTable->horizontalHeaderItem(24);
        ___qtablewidgetitem24->setText(QApplication::translate("MainWindow", "5", 0));
        QTableWidgetItem *___qtablewidgetitem25 = normalTable->horizontalHeaderItem(25);
        ___qtablewidgetitem25->setText(QApplication::translate("MainWindow", "1", 0));
        QTableWidgetItem *___qtablewidgetitem26 = normalTable->horizontalHeaderItem(26);
        ___qtablewidgetitem26->setText(QApplication::translate("MainWindow", "2", 0));
        QTableWidgetItem *___qtablewidgetitem27 = normalTable->horizontalHeaderItem(27);
        ___qtablewidgetitem27->setText(QApplication::translate("MainWindow", "3", 0));
        QTableWidgetItem *___qtablewidgetitem28 = normalTable->horizontalHeaderItem(28);
        ___qtablewidgetitem28->setText(QApplication::translate("MainWindow", "4", 0));
        QTableWidgetItem *___qtablewidgetitem29 = normalTable->horizontalHeaderItem(29);
        ___qtablewidgetitem29->setText(QApplication::translate("MainWindow", "5", 0));
        QTableWidgetItem *___qtablewidgetitem30 = normalTable->horizontalHeaderItem(30);
        ___qtablewidgetitem30->setText(QApplication::translate("MainWindow", "1", 0));
        QTableWidgetItem *___qtablewidgetitem31 = normalTable->horizontalHeaderItem(31);
        ___qtablewidgetitem31->setText(QApplication::translate("MainWindow", "2", 0));
        QTableWidgetItem *___qtablewidgetitem32 = normalTable->horizontalHeaderItem(32);
        ___qtablewidgetitem32->setText(QApplication::translate("MainWindow", "3", 0));
        QTableWidgetItem *___qtablewidgetitem33 = normalTable->horizontalHeaderItem(33);
        ___qtablewidgetitem33->setText(QApplication::translate("MainWindow", "4", 0));
        QTableWidgetItem *___qtablewidgetitem34 = normalTable->horizontalHeaderItem(34);
        ___qtablewidgetitem34->setText(QApplication::translate("MainWindow", "5", 0));
        QTableWidgetItem *___qtablewidgetitem35 = normalTable->horizontalHeaderItem(35);
        ___qtablewidgetitem35->setText(QApplication::translate("MainWindow", "1", 0));
        QTableWidgetItem *___qtablewidgetitem36 = normalTable->horizontalHeaderItem(36);
        ___qtablewidgetitem36->setText(QApplication::translate("MainWindow", "2", 0));
        QTableWidgetItem *___qtablewidgetitem37 = normalTable->horizontalHeaderItem(37);
        ___qtablewidgetitem37->setText(QApplication::translate("MainWindow", "3", 0));
        QTableWidgetItem *___qtablewidgetitem38 = normalTable->horizontalHeaderItem(38);
        ___qtablewidgetitem38->setText(QApplication::translate("MainWindow", "4", 0));
        QTableWidgetItem *___qtablewidgetitem39 = normalTable->horizontalHeaderItem(39);
        ___qtablewidgetitem39->setText(QApplication::translate("MainWindow", "5", 0));
        QTableWidgetItem *___qtablewidgetitem40 = normalTable->horizontalHeaderItem(40);
        ___qtablewidgetitem40->setText(QApplication::translate("MainWindow", "1", 0));
        QTableWidgetItem *___qtablewidgetitem41 = normalTable->horizontalHeaderItem(41);
        ___qtablewidgetitem41->setText(QApplication::translate("MainWindow", "2", 0));
        QTableWidgetItem *___qtablewidgetitem42 = normalTable->horizontalHeaderItem(42);
        ___qtablewidgetitem42->setText(QApplication::translate("MainWindow", "3", 0));
        QTableWidgetItem *___qtablewidgetitem43 = normalTable->horizontalHeaderItem(43);
        ___qtablewidgetitem43->setText(QApplication::translate("MainWindow", "4", 0));
        QTableWidgetItem *___qtablewidgetitem44 = normalTable->horizontalHeaderItem(44);
        ___qtablewidgetitem44->setText(QApplication::translate("MainWindow", "5", 0));
        QTableWidgetItem *___qtablewidgetitem45 = normalTable->horizontalHeaderItem(45);
        ___qtablewidgetitem45->setText(QApplication::translate("MainWindow", "1", 0));
        QTableWidgetItem *___qtablewidgetitem46 = normalTable->horizontalHeaderItem(46);
        ___qtablewidgetitem46->setText(QApplication::translate("MainWindow", "2", 0));
        QTableWidgetItem *___qtablewidgetitem47 = normalTable->horizontalHeaderItem(47);
        ___qtablewidgetitem47->setText(QApplication::translate("MainWindow", "3", 0));
        QTableWidgetItem *___qtablewidgetitem48 = normalTable->horizontalHeaderItem(48);
        ___qtablewidgetitem48->setText(QApplication::translate("MainWindow", "4", 0));
        QTableWidgetItem *___qtablewidgetitem49 = normalTable->horizontalHeaderItem(49);
        ___qtablewidgetitem49->setText(QApplication::translate("MainWindow", "5", 0));

        const bool __sortingEnabled = normalTable->isSortingEnabled();
        normalTable->setSortingEnabled(false);
        normalTable->setSortingEnabled(__sortingEnabled);

        sigmaEdit->setText(QApplication::translate("MainWindow", "3.5", 0));
        label_15->setText(QApplication::translate("MainWindow", "epsx:", 0));
        epsfEdit->setText(QApplication::translate("MainWindow", "0", 0));
        label_16->setText(QApplication::translate("MainWindow", "maxits:", 0));
        epsxEdit->setText(QApplication::translate("MainWindow", "0.000001", 0));
        diffstepEdit->setText(QApplication::translate("MainWindow", "0.0001", 0));
        label_13->setText(QApplication::translate("MainWindow", "diffstep:", 0));
        label_14->setText(QApplication::translate("MainWindow", "epsf:", 0));
        maxitsEdit->setText(QApplication::translate("MainWindow", "0", 0));
        muLabel->setText(QApplication::translate("MainWindow", "Mu", 0));
        sigmaLabel->setText(QApplication::translate("MainWindow", "Sigma", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

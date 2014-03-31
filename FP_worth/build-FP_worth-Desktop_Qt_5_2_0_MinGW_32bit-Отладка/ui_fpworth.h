/********************************************************************************
** Form generated from reading UI file 'fpworth.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FPWORTH_H
#define UI_FPWORTH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FPWorth
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_12;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *openNormalButton;
    QLabel *normalFileLabel;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *openFuzzyButton;
    QLabel *fuzzyFileLabel;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_19;
    QPushButton *addNormalButton;
    QLabel *addNormalFileLabel;
    QSpacerItem *horizontalSpacer_14;
    QProgressBar *progressBar;
    QTreeWidget *lvarSettings;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *openSaved;
    QSpacerItem *horizontalSpacer_7;
    QGroupBox *groupBox;
    QWidget *horizontalLayoutWidget_10;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *sepEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *termSizeEdit;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_9;
    QWidget *tab_4;
    QTableWidget *normalTable;
    QPushButton *clearFuzzyButton_2;
    QWidget *tab_5;
    QTableWidget *fuzzyTable;
    QPushButton *clearFuzzyButton;
    QWidget *tab_3;
    QWidget *plotWidget;
    QPushButton *makePlotButton;
    QPushButton *lvarPlotButton;
    QComboBox *plotNamesCombo;
    QLabel *label_11;
    QPushButton *clearPlotButton;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *diffstepEdit;
    QLabel *label_14;
    QLineEdit *epsfEdit;
    QLabel *label_15;
    QLineEdit *epsxEdit;
    QLabel *label_16;
    QLineEdit *maxitsEdit;
    QProgressBar *plotProgressBar;
    QWidget *tab_6;
    QListWidget *rulesListWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QComboBox *tableCombo;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QSpinBox *termCountFirst;
    QLabel *label_9;
    QSpinBox *termCountLast;
    QPushButton *okTermButton;
    QTableWidget *supportTable;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_18;
    QLineEdit *countRulesEdit;
    QPushButton *makeRulesAprioriButton;
    QPushButton *makeRulesFPGButton;
    QProgressBar *makeRulesBar;
    QSpacerItem *verticalSpacer;
    QWidget *tab_7;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer_11;
    QHBoxLayout *horizontalLayout_14;
    QTableWidget *inputNnpsTable;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_13;
    QCheckBox *suppRulesCheckBox;
    QPushButton *nnpsButton;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_16;
    QProgressBar *progressBar_nnps;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *horizontalLayout_17;
    QGroupBox *groupBox_2;
    QLabel *label_4;
    QLabel *label_17;
    QLabel *fireCountLabel;
    QLabel *probLabel;
    QSpacerItem *horizontalSpacer_13;
    QWidget *plotWidget_nnps;
    QWidget *tab_2;
    QLabel *label_3;
    QTableWidget *termsTable;
    QLabel *label_6;
    QTableWidget *wordsTable;
    QPlainTextEdit *fptreeEdit;
    QLabel *label_7;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FPWorth)
    {
        if (FPWorth->objectName().isEmpty())
            FPWorth->setObjectName(QStringLiteral("FPWorth"));
        FPWorth->resize(1024, 658);
        centralWidget = new QWidget(FPWorth);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, -5, 1021, 601));
        horizontalLayout_12 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(horizontalLayoutWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setTabsClosable(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        horizontalLayout = new QHBoxLayout(tab);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setSizeConstraint(QLayout::SetMaximumSize);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        openNormalButton = new QPushButton(tab);
        openNormalButton->setObjectName(QStringLiteral("openNormalButton"));

        horizontalLayout_2->addWidget(openNormalButton);

        normalFileLabel = new QLabel(tab);
        normalFileLabel->setObjectName(QStringLiteral("normalFileLabel"));

        horizontalLayout_2->addWidget(normalFileLabel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        openFuzzyButton = new QPushButton(tab);
        openFuzzyButton->setObjectName(QStringLiteral("openFuzzyButton"));

        horizontalLayout_4->addWidget(openFuzzyButton);

        fuzzyFileLabel = new QLabel(tab);
        fuzzyFileLabel->setObjectName(QStringLiteral("fuzzyFileLabel"));

        horizontalLayout_4->addWidget(fuzzyFileLabel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));

        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        addNormalButton = new QPushButton(tab);
        addNormalButton->setObjectName(QStringLiteral("addNormalButton"));
        addNormalButton->setEnabled(false);

        horizontalLayout_19->addWidget(addNormalButton);

        addNormalFileLabel = new QLabel(tab);
        addNormalFileLabel->setObjectName(QStringLiteral("addNormalFileLabel"));

        horizontalLayout_19->addWidget(addNormalFileLabel);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_14);


        verticalLayout->addLayout(horizontalLayout_19);

        progressBar = new QProgressBar(tab);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        verticalLayout->addWidget(progressBar);

        lvarSettings = new QTreeWidget(tab);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(lvarSettings);
        __qtreewidgetitem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem2->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem3->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem4->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem5 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem5->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem6 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem6->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem7 = new QTreeWidgetItem(lvarSettings);
        new QTreeWidgetItem(__qtreewidgetitem7);
        new QTreeWidgetItem(__qtreewidgetitem7);
        new QTreeWidgetItem(__qtreewidgetitem7);
        new QTreeWidgetItem(__qtreewidgetitem7);
        new QTreeWidgetItem(__qtreewidgetitem7);
        new QTreeWidgetItem(__qtreewidgetitem7);
        QTreeWidgetItem *__qtreewidgetitem8 = new QTreeWidgetItem(lvarSettings);
        new QTreeWidgetItem(__qtreewidgetitem8);
        new QTreeWidgetItem(__qtreewidgetitem8);
        new QTreeWidgetItem(__qtreewidgetitem8);
        new QTreeWidgetItem(__qtreewidgetitem8);
        new QTreeWidgetItem(__qtreewidgetitem8);
        new QTreeWidgetItem(__qtreewidgetitem8);
        QTreeWidgetItem *__qtreewidgetitem9 = new QTreeWidgetItem(lvarSettings);
        __qtreewidgetitem9->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        new QTreeWidgetItem(__qtreewidgetitem9);
        new QTreeWidgetItem(__qtreewidgetitem9);
        new QTreeWidgetItem(__qtreewidgetitem9);
        new QTreeWidgetItem(__qtreewidgetitem9);
        new QTreeWidgetItem(__qtreewidgetitem9);
        new QTreeWidgetItem(__qtreewidgetitem9);
        lvarSettings->setObjectName(QStringLiteral("lvarSettings"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lvarSettings->sizePolicy().hasHeightForWidth());
        lvarSettings->setSizePolicy(sizePolicy1);
        lvarSettings->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        lvarSettings->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        lvarSettings->setSortingEnabled(true);
        lvarSettings->header()->setDefaultSectionSize(230);

        verticalLayout->addWidget(lvarSettings);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_6->addWidget(pushButton_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_6);


        horizontalLayout_10->addLayout(verticalLayout);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        openSaved = new QPushButton(tab);
        openSaved->setObjectName(QStringLiteral("openSaved"));

        horizontalLayout_8->addWidget(openSaved);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_7);


        verticalLayout_5->addLayout(horizontalLayout_8);

        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy2);
        horizontalLayoutWidget_10 = new QWidget(groupBox);
        horizontalLayoutWidget_10->setObjectName(QStringLiteral("horizontalLayoutWidget_10"));
        horizontalLayoutWidget_10->setGeometry(QRect(10, 10, 251, 461));
        horizontalLayout_11 = new QHBoxLayout(horizontalLayoutWidget_10);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(10, 10, 10, 10);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));

        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(horizontalLayoutWidget_10);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        horizontalLayout_3->addWidget(label);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        sepEdit = new QLineEdit(horizontalLayoutWidget_10);
        sepEdit->setObjectName(QStringLiteral("sepEdit"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(sepEdit->sizePolicy().hasHeightForWidth());
        sepEdit->setSizePolicy(sizePolicy3);
        sepEdit->setMaximumSize(QSize(30, 16777215));
        sepEdit->setBaseSize(QSize(20, 0));

        horizontalLayout_3->addWidget(sepEdit);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_5 = new QLabel(horizontalLayoutWidget_10);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);
        label_5->setWordWrap(true);

        horizontalLayout_7->addWidget(label_5);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_6);

        termSizeEdit = new QLineEdit(horizontalLayoutWidget_10);
        termSizeEdit->setObjectName(QStringLiteral("termSizeEdit"));
        termSizeEdit->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_7->addWidget(termSizeEdit);


        verticalLayout_3->addLayout(horizontalLayout_7);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        horizontalLayout_11->addLayout(verticalLayout_3);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_8);


        verticalLayout_5->addWidget(groupBox);


        horizontalLayout_10->addLayout(verticalLayout_5);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_9);


        horizontalLayout->addLayout(horizontalLayout_10);

        tabWidget->addTab(tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        normalTable = new QTableWidget(tab_4);
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
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        __qtablewidgetitem51->setFont(font1);
        normalTable->setItem(0, 58, __qtablewidgetitem51);
        normalTable->setObjectName(QStringLiteral("normalTable"));
        normalTable->setGeometry(QRect(20, 10, 981, 471));
        normalTable->setSizeIncrement(QSize(0, 0));
        normalTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        normalTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        normalTable->setDefaultDropAction(Qt::CopyAction);
        normalTable->setSortingEnabled(true);
        normalTable->setRowCount(1);
        normalTable->setColumnCount(60);
        normalTable->horizontalHeader()->setDefaultSectionSize(40);
        clearFuzzyButton_2 = new QPushButton(tab_4);
        clearFuzzyButton_2->setObjectName(QStringLiteral("clearFuzzyButton_2"));
        clearFuzzyButton_2->setGeometry(QRect(20, 490, 75, 23));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        fuzzyTable = new QTableWidget(tab_5);
        if (fuzzyTable->columnCount() < 60)
            fuzzyTable->setColumnCount(60);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(0, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(1, __qtablewidgetitem53);
        QTableWidgetItem *__qtablewidgetitem54 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(2, __qtablewidgetitem54);
        QTableWidgetItem *__qtablewidgetitem55 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(3, __qtablewidgetitem55);
        QTableWidgetItem *__qtablewidgetitem56 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(4, __qtablewidgetitem56);
        QTableWidgetItem *__qtablewidgetitem57 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(5, __qtablewidgetitem57);
        QTableWidgetItem *__qtablewidgetitem58 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(6, __qtablewidgetitem58);
        QTableWidgetItem *__qtablewidgetitem59 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(7, __qtablewidgetitem59);
        QTableWidgetItem *__qtablewidgetitem60 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(8, __qtablewidgetitem60);
        QTableWidgetItem *__qtablewidgetitem61 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(9, __qtablewidgetitem61);
        QTableWidgetItem *__qtablewidgetitem62 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(10, __qtablewidgetitem62);
        QTableWidgetItem *__qtablewidgetitem63 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(11, __qtablewidgetitem63);
        QTableWidgetItem *__qtablewidgetitem64 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(12, __qtablewidgetitem64);
        QTableWidgetItem *__qtablewidgetitem65 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(13, __qtablewidgetitem65);
        QTableWidgetItem *__qtablewidgetitem66 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(14, __qtablewidgetitem66);
        QTableWidgetItem *__qtablewidgetitem67 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(15, __qtablewidgetitem67);
        QTableWidgetItem *__qtablewidgetitem68 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(16, __qtablewidgetitem68);
        QTableWidgetItem *__qtablewidgetitem69 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(17, __qtablewidgetitem69);
        QTableWidgetItem *__qtablewidgetitem70 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(18, __qtablewidgetitem70);
        QTableWidgetItem *__qtablewidgetitem71 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(19, __qtablewidgetitem71);
        QTableWidgetItem *__qtablewidgetitem72 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(20, __qtablewidgetitem72);
        QTableWidgetItem *__qtablewidgetitem73 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(21, __qtablewidgetitem73);
        QTableWidgetItem *__qtablewidgetitem74 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(22, __qtablewidgetitem74);
        QTableWidgetItem *__qtablewidgetitem75 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(23, __qtablewidgetitem75);
        QTableWidgetItem *__qtablewidgetitem76 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(24, __qtablewidgetitem76);
        QTableWidgetItem *__qtablewidgetitem77 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(25, __qtablewidgetitem77);
        QTableWidgetItem *__qtablewidgetitem78 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(26, __qtablewidgetitem78);
        QTableWidgetItem *__qtablewidgetitem79 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(27, __qtablewidgetitem79);
        QTableWidgetItem *__qtablewidgetitem80 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(28, __qtablewidgetitem80);
        QTableWidgetItem *__qtablewidgetitem81 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(29, __qtablewidgetitem81);
        QTableWidgetItem *__qtablewidgetitem82 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(30, __qtablewidgetitem82);
        QTableWidgetItem *__qtablewidgetitem83 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(31, __qtablewidgetitem83);
        QTableWidgetItem *__qtablewidgetitem84 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(32, __qtablewidgetitem84);
        QTableWidgetItem *__qtablewidgetitem85 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(33, __qtablewidgetitem85);
        QTableWidgetItem *__qtablewidgetitem86 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(34, __qtablewidgetitem86);
        QTableWidgetItem *__qtablewidgetitem87 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(35, __qtablewidgetitem87);
        QTableWidgetItem *__qtablewidgetitem88 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(36, __qtablewidgetitem88);
        QTableWidgetItem *__qtablewidgetitem89 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(37, __qtablewidgetitem89);
        QTableWidgetItem *__qtablewidgetitem90 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(38, __qtablewidgetitem90);
        QTableWidgetItem *__qtablewidgetitem91 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(39, __qtablewidgetitem91);
        QTableWidgetItem *__qtablewidgetitem92 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(40, __qtablewidgetitem92);
        QTableWidgetItem *__qtablewidgetitem93 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(41, __qtablewidgetitem93);
        QTableWidgetItem *__qtablewidgetitem94 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(42, __qtablewidgetitem94);
        QTableWidgetItem *__qtablewidgetitem95 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(43, __qtablewidgetitem95);
        QTableWidgetItem *__qtablewidgetitem96 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(44, __qtablewidgetitem96);
        QTableWidgetItem *__qtablewidgetitem97 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(45, __qtablewidgetitem97);
        QTableWidgetItem *__qtablewidgetitem98 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(46, __qtablewidgetitem98);
        QTableWidgetItem *__qtablewidgetitem99 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(47, __qtablewidgetitem99);
        QTableWidgetItem *__qtablewidgetitem100 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(48, __qtablewidgetitem100);
        QTableWidgetItem *__qtablewidgetitem101 = new QTableWidgetItem();
        fuzzyTable->setHorizontalHeaderItem(49, __qtablewidgetitem101);
        if (fuzzyTable->rowCount() < 1)
            fuzzyTable->setRowCount(1);
        QBrush brush1(QColor(209, 209, 209, 255));
        brush1.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem102 = new QTableWidgetItem();
        __qtablewidgetitem102->setBackground(brush1);
        fuzzyTable->setItem(0, 50, __qtablewidgetitem102);
        QTableWidgetItem *__qtablewidgetitem103 = new QTableWidgetItem();
        __qtablewidgetitem103->setFont(font1);
        fuzzyTable->setItem(0, 58, __qtablewidgetitem103);
        fuzzyTable->setObjectName(QStringLiteral("fuzzyTable"));
        fuzzyTable->setGeometry(QRect(20, 10, 981, 471));
        fuzzyTable->setSizeIncrement(QSize(0, 0));
        fuzzyTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        fuzzyTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        fuzzyTable->setDefaultDropAction(Qt::CopyAction);
        fuzzyTable->setSortingEnabled(true);
        fuzzyTable->setRowCount(1);
        fuzzyTable->setColumnCount(60);
        fuzzyTable->horizontalHeader()->setDefaultSectionSize(40);
        clearFuzzyButton = new QPushButton(tab_5);
        clearFuzzyButton->setObjectName(QStringLiteral("clearFuzzyButton"));
        clearFuzzyButton->setGeometry(QRect(20, 490, 75, 23));
        tabWidget->addTab(tab_5, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        plotWidget = new QWidget(tab_3);
        plotWidget->setObjectName(QStringLiteral("plotWidget"));
        plotWidget->setGeometry(QRect(10, 90, 1001, 461));
        makePlotButton = new QPushButton(tab_3);
        makePlotButton->setObjectName(QStringLiteral("makePlotButton"));
        makePlotButton->setGeometry(QRect(20, 50, 121, 23));
        lvarPlotButton = new QPushButton(tab_3);
        lvarPlotButton->setObjectName(QStringLiteral("lvarPlotButton"));
        lvarPlotButton->setGeometry(QRect(650, 10, 91, 23));
        plotNamesCombo = new QComboBox(tab_3);
        plotNamesCombo->setObjectName(QStringLiteral("plotNamesCombo"));
        plotNamesCombo->setGeometry(QRect(290, 10, 69, 22));
        label_11 = new QLabel(tab_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 10, 261, 21));
        label_11->setFont(font);
        clearPlotButton = new QPushButton(tab_3);
        clearPlotButton->setObjectName(QStringLiteral("clearPlotButton"));
        clearPlotButton->setGeometry(QRect(650, 40, 75, 23));
        label_12 = new QLabel(tab_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(380, 10, 171, 16));
        label_12->setFont(font);
        label_13 = new QLabel(tab_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(550, 40, 46, 16));
        label_13->setFont(font);
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        diffstepEdit = new QLineEdit(tab_3);
        diffstepEdit->setObjectName(QStringLiteral("diffstepEdit"));
        diffstepEdit->setGeometry(QRect(600, 40, 41, 20));
        label_14 = new QLabel(tab_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(380, 40, 31, 20));
        label_14->setFont(font);
        epsfEdit = new QLineEdit(tab_3);
        epsfEdit->setObjectName(QStringLiteral("epsfEdit"));
        epsfEdit->setGeometry(QRect(420, 40, 61, 20));
        label_15 = new QLabel(tab_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(380, 70, 31, 16));
        label_15->setFont(font);
        epsxEdit = new QLineEdit(tab_3);
        epsxEdit->setObjectName(QStringLiteral("epsxEdit"));
        epsxEdit->setGeometry(QRect(420, 70, 61, 20));
        label_16 = new QLabel(tab_3);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(495, 70, 101, 20));
        label_16->setFont(font);
        label_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        maxitsEdit = new QLineEdit(tab_3);
        maxitsEdit->setObjectName(QStringLiteral("maxitsEdit"));
        maxitsEdit->setGeometry(QRect(600, 70, 41, 20));
        plotProgressBar = new QProgressBar(tab_3);
        plotProgressBar->setObjectName(QStringLiteral("plotProgressBar"));
        plotProgressBar->setGeometry(QRect(160, 50, 201, 23));
        plotProgressBar->setValue(0);
        tabWidget->addTab(tab_3, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        rulesListWidget = new QListWidget(tab_6);
        rulesListWidget->setObjectName(QStringLiteral("rulesListWidget"));
        rulesListWidget->setGeometry(QRect(20, 10, 791, 481));
        layoutWidget = new QWidget(tab_6);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(820, 10, 172, 481));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        tableCombo = new QComboBox(layoutWidget);
        tableCombo->setObjectName(QStringLiteral("tableCombo"));

        verticalLayout_4->addWidget(tableCombo);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setWordWrap(true);

        verticalLayout_4->addWidget(label_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_9->addWidget(label_8);

        termCountFirst = new QSpinBox(layoutWidget);
        termCountFirst->setObjectName(QStringLiteral("termCountFirst"));
        termCountFirst->setMaximumSize(QSize(40, 16777215));
        termCountFirst->setMinimum(1);
        termCountFirst->setValue(1);

        horizontalLayout_9->addWidget(termCountFirst);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_9->addWidget(label_9);

        termCountLast = new QSpinBox(layoutWidget);
        termCountLast->setObjectName(QStringLiteral("termCountLast"));
        termCountLast->setMaximumSize(QSize(40, 16777215));
        termCountLast->setMinimum(1);
        termCountLast->setValue(3);

        horizontalLayout_9->addWidget(termCountLast);

        okTermButton = new QPushButton(layoutWidget);
        okTermButton->setObjectName(QStringLiteral("okTermButton"));
        okTermButton->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_9->addWidget(okTermButton);


        verticalLayout_4->addLayout(horizontalLayout_9);

        supportTable = new QTableWidget(layoutWidget);
        if (supportTable->columnCount() < 1)
            supportTable->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem104 = new QTableWidgetItem();
        supportTable->setHorizontalHeaderItem(0, __qtablewidgetitem104);
        if (supportTable->rowCount() < 3)
            supportTable->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem105 = new QTableWidgetItem();
        supportTable->setVerticalHeaderItem(0, __qtablewidgetitem105);
        QTableWidgetItem *__qtablewidgetitem106 = new QTableWidgetItem();
        supportTable->setVerticalHeaderItem(1, __qtablewidgetitem106);
        QTableWidgetItem *__qtablewidgetitem107 = new QTableWidgetItem();
        supportTable->setVerticalHeaderItem(2, __qtablewidgetitem107);
        QTableWidgetItem *__qtablewidgetitem108 = new QTableWidgetItem();
        __qtablewidgetitem108->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        supportTable->setItem(0, 0, __qtablewidgetitem108);
        QTableWidgetItem *__qtablewidgetitem109 = new QTableWidgetItem();
        __qtablewidgetitem109->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        supportTable->setItem(1, 0, __qtablewidgetitem109);
        QTableWidgetItem *__qtablewidgetitem110 = new QTableWidgetItem();
        __qtablewidgetitem110->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        supportTable->setItem(2, 0, __qtablewidgetitem110);
        supportTable->setObjectName(QStringLiteral("supportTable"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(supportTable->sizePolicy().hasHeightForWidth());
        supportTable->setSizePolicy(sizePolicy4);
        supportTable->setMaximumSize(QSize(170, 16777215));
        supportTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        supportTable->setRowCount(3);
        supportTable->setColumnCount(1);
        supportTable->horizontalHeader()->setDefaultSectionSize(86);
        supportTable->verticalHeader()->setDefaultSectionSize(30);
        supportTable->verticalHeader()->setMinimumSectionSize(60);

        verticalLayout_4->addWidget(supportTable);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        label_18 = new QLabel(layoutWidget);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setFont(font);
        label_18->setAlignment(Qt::AlignCenter);
        label_18->setWordWrap(true);

        horizontalLayout_20->addWidget(label_18);

        countRulesEdit = new QLineEdit(layoutWidget);
        countRulesEdit->setObjectName(QStringLiteral("countRulesEdit"));
        countRulesEdit->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_20->addWidget(countRulesEdit);


        verticalLayout_4->addLayout(horizontalLayout_20);

        makeRulesAprioriButton = new QPushButton(layoutWidget);
        makeRulesAprioriButton->setObjectName(QStringLiteral("makeRulesAprioriButton"));

        verticalLayout_4->addWidget(makeRulesAprioriButton);

        makeRulesFPGButton = new QPushButton(layoutWidget);
        makeRulesFPGButton->setObjectName(QStringLiteral("makeRulesFPGButton"));
        makeRulesFPGButton->setEnabled(false);

        verticalLayout_4->addWidget(makeRulesFPGButton);

        makeRulesBar = new QProgressBar(layoutWidget);
        makeRulesBar->setObjectName(QStringLiteral("makeRulesBar"));
        makeRulesBar->setValue(0);

        verticalLayout_4->addWidget(makeRulesBar);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        tabWidget->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        verticalLayoutWidget = new QWidget(tab_7);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 20, 601, 255));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        QFont font2;
        font2.setPointSize(12);
        label_10->setFont(font2);

        horizontalLayout_15->addWidget(label_10);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_11);


        verticalLayout_6->addLayout(horizontalLayout_15);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        inputNnpsTable = new QTableWidget(verticalLayoutWidget);
        if (inputNnpsTable->columnCount() < 10)
            inputNnpsTable->setColumnCount(10);
        if (inputNnpsTable->rowCount() < 2)
            inputNnpsTable->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem111 = new QTableWidgetItem();
        inputNnpsTable->setVerticalHeaderItem(0, __qtablewidgetitem111);
        QTableWidgetItem *__qtablewidgetitem112 = new QTableWidgetItem();
        inputNnpsTable->setVerticalHeaderItem(1, __qtablewidgetitem112);
        QTableWidgetItem *__qtablewidgetitem113 = new QTableWidgetItem();
        inputNnpsTable->setItem(0, 0, __qtablewidgetitem113);
        QTableWidgetItem *__qtablewidgetitem114 = new QTableWidgetItem();
        inputNnpsTable->setItem(1, 0, __qtablewidgetitem114);
        QTableWidgetItem *__qtablewidgetitem115 = new QTableWidgetItem();
        inputNnpsTable->setItem(1, 1, __qtablewidgetitem115);
        QTableWidgetItem *__qtablewidgetitem116 = new QTableWidgetItem();
        inputNnpsTable->setItem(1, 2, __qtablewidgetitem116);
        QTableWidgetItem *__qtablewidgetitem117 = new QTableWidgetItem();
        inputNnpsTable->setItem(1, 3, __qtablewidgetitem117);
        QTableWidgetItem *__qtablewidgetitem118 = new QTableWidgetItem();
        inputNnpsTable->setItem(1, 4, __qtablewidgetitem118);
        QTableWidgetItem *__qtablewidgetitem119 = new QTableWidgetItem();
        inputNnpsTable->setItem(1, 5, __qtablewidgetitem119);
        QTableWidgetItem *__qtablewidgetitem120 = new QTableWidgetItem();
        inputNnpsTable->setItem(1, 6, __qtablewidgetitem120);
        QTableWidgetItem *__qtablewidgetitem121 = new QTableWidgetItem();
        inputNnpsTable->setItem(1, 7, __qtablewidgetitem121);
        QTableWidgetItem *__qtablewidgetitem122 = new QTableWidgetItem();
        inputNnpsTable->setItem(1, 8, __qtablewidgetitem122);
        QTableWidgetItem *__qtablewidgetitem123 = new QTableWidgetItem();
        inputNnpsTable->setItem(1, 9, __qtablewidgetitem123);
        inputNnpsTable->setObjectName(QStringLiteral("inputNnpsTable"));
        inputNnpsTable->setMinimumSize(QSize(485, 105));
        inputNnpsTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        inputNnpsTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        inputNnpsTable->setRowCount(2);
        inputNnpsTable->setColumnCount(10);
        inputNnpsTable->horizontalHeader()->setDefaultSectionSize(40);

        horizontalLayout_14->addWidget(inputNnpsTable);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_10);


        verticalLayout_6->addLayout(horizontalLayout_14);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        suppRulesCheckBox = new QCheckBox(verticalLayoutWidget);
        suppRulesCheckBox->setObjectName(QStringLiteral("suppRulesCheckBox"));

        horizontalLayout_13->addWidget(suppRulesCheckBox);

        nnpsButton = new QPushButton(verticalLayoutWidget);
        nnpsButton->setObjectName(QStringLiteral("nnpsButton"));

        horizontalLayout_13->addWidget(nnpsButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer);


        verticalLayout_6->addLayout(horizontalLayout_13);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        progressBar_nnps = new QProgressBar(verticalLayoutWidget);
        progressBar_nnps->setObjectName(QStringLiteral("progressBar_nnps"));
        progressBar_nnps->setValue(0);

        horizontalLayout_16->addWidget(progressBar_nnps);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_12);


        verticalLayout_6->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        groupBox_2 = new QGroupBox(verticalLayoutWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(380, 50));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 20, 121, 16));
        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(210, 20, 71, 16));
        fireCountLabel = new QLabel(groupBox_2);
        fireCountLabel->setObjectName(QStringLiteral("fireCountLabel"));
        fireCountLabel->setGeometry(QRect(140, 20, 61, 16));
        probLabel = new QLabel(groupBox_2);
        probLabel->setObjectName(QStringLiteral("probLabel"));
        probLabel->setGeometry(QRect(290, 20, 61, 16));

        horizontalLayout_17->addWidget(groupBox_2);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_13);


        verticalLayout_6->addLayout(horizontalLayout_17);

        plotWidget_nnps = new QWidget(tab_7);
        plotWidget_nnps->setObjectName(QStringLiteral("plotWidget_nnps"));
        plotWidget_nnps->setGeometry(QRect(10, 280, 981, 281));
        tabWidget->addTab(tab_7, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 30, 231, 21));
        termsTable = new QTableWidget(tab_2);
        if (termsTable->columnCount() < 50)
            termsTable->setColumnCount(50);
        if (termsTable->rowCount() < 5)
            termsTable->setRowCount(5);
        termsTable->setObjectName(QStringLiteral("termsTable"));
        termsTable->setGeometry(QRect(30, 60, 961, 101));
        termsTable->setRowCount(5);
        termsTable->setColumnCount(50);
        termsTable->horizontalHeader()->setDefaultSectionSize(40);
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 190, 241, 21));
        wordsTable = new QTableWidget(tab_2);
        if (wordsTable->columnCount() < 50)
            wordsTable->setColumnCount(50);
        wordsTable->setObjectName(QStringLiteral("wordsTable"));
        wordsTable->setGeometry(QRect(30, 220, 581, 301));
        wordsTable->setRowCount(0);
        wordsTable->setColumnCount(50);
        wordsTable->horizontalHeader()->setDefaultSectionSize(40);
        fptreeEdit = new QPlainTextEdit(tab_2);
        fptreeEdit->setObjectName(QStringLiteral("fptreeEdit"));
        fptreeEdit->setGeometry(QRect(620, 220, 381, 301));
        fptreeEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(620, 190, 241, 21));
        tabWidget->addTab(tab_2, QString());

        horizontalLayout_12->addWidget(tabWidget);

        FPWorth->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(FPWorth);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 21));
        FPWorth->setMenuBar(menuBar);
        mainToolBar = new QToolBar(FPWorth);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        FPWorth->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(FPWorth);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        FPWorth->setStatusBar(statusBar);

        retranslateUi(FPWorth);

        tabWidget->setCurrentIndex(2);
        tableCombo->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FPWorth);
    } // setupUi

    void retranslateUi(QMainWindow *FPWorth)
    {
        FPWorth->setWindowTitle(QApplication::translate("FPWorth", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\320\276\320\275\320\275\320\260\321\217 \321\201\320\270\321\201\321\202\320\265\320\274\320\260 \320\277\321\200\320\276\320\263\320\275\320\276\320\267\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217 \320\277\321\200\320\270\321\200\320\276\320\264\320\275\321\213\321\205 \320\273\320\265\321\201\320\275\321\213\321\205 \320\277\320\276\320\266\320\260\321\200\320\276\320\262", 0));
        openNormalButton->setText(QApplication::translate("FPWorth", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273 \321\201 \320\270\321\201\321\205\320\276\320\264\320\275\321\213\320\274\320\270 \320\264\320\260\320\275\320\275\321\213\320\274\320\270", 0));
        normalFileLabel->setText(QApplication::translate("FPWorth", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\204\320\260\320\271\320\273", 0));
        openFuzzyButton->setText(QApplication::translate("FPWorth", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273 \321\201 \320\276\320\261\321\200\320\260\320\261\320\276\321\202\320\260\320\275\320\275\321\213\320\274\320\270 \320\264\320\260\320\275\320\275\321\213\320\274\320\270", 0));
        fuzzyFileLabel->setText(QApplication::translate("FPWorth", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\204\320\260\320\271\320\273", 0));
        addNormalButton->setText(QApplication::translate("FPWorth", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\207\320\270\321\201\320\273\320\265\320\275\320\275\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265 \320\272 \320\272\320\260\321\207\320\265\321\201\321\202\320\262\320\265\320\275\320\275\321\213\320\274", 0));
        addNormalFileLabel->setText(QApplication::translate("FPWorth", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\204\320\260\320\271\320\273", 0));
        QTreeWidgetItem *___qtreewidgetitem = lvarSettings->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("FPWorth", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\321\217", 0));
        ___qtreewidgetitem->setText(0, QApplication::translate("FPWorth", "\320\241\320\262\320\276\320\271\321\201\321\202\320\262\320\260 \320\273\320\270\320\275\320\263\320\262\320\270\321\201\321\202\320\270\321\207\320\265\321\201\320\272\320\270\321\205 \320\277\320\265\321\200\320\265\320\274\320\265\320\275\320\275\321\213\321\205", 0));

        const bool __sortingEnabled = lvarSettings->isSortingEnabled();
        lvarSettings->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = lvarSettings->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("FPWorth", "\320\242\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\260", 0));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(1, QApplication::translate("FPWorth", "T", 0));
        ___qtreewidgetitem2->setText(0, QApplication::translate("FPWorth", "\320\230\320\274\321\217 \321\202\320\265\321\200\320\274\320\260", 0));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem3->setText(1, QApplication::translate("FPWorth", "\320\236\321\207\320\265\320\275\321\214 \320\262\321\213\321\201\320\276\320\272\320\260\321\217", 0));
        ___qtreewidgetitem3->setText(0, QApplication::translate("FPWorth", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 5", 0));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem1->child(2);
        ___qtreewidgetitem4->setText(1, QApplication::translate("FPWorth", "\320\222\321\213\321\201\320\276\320\272\320\260\321\217", 0));
        ___qtreewidgetitem4->setText(0, QApplication::translate("FPWorth", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 4", 0));
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem1->child(3);
        ___qtreewidgetitem5->setText(1, QApplication::translate("FPWorth", "\320\241\321\200\320\265\320\264\320\275\321\217\321\217", 0));
        ___qtreewidgetitem5->setText(0, QApplication::translate("FPWorth", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 3", 0));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem1->child(4);
        ___qtreewidgetitem6->setText(1, QApplication::translate("FPWorth", "\320\235\320\270\320\267\320\272\320\260\321\217", 0));
        ___qtreewidgetitem6->setText(0, QApplication::translate("FPWorth", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 2", 0));
        QTreeWidgetItem *___qtreewidgetitem7 = ___qtreewidgetitem1->child(5);
        ___qtreewidgetitem7->setText(1, QApplication::translate("FPWorth", "\320\236\321\207\320\265\320\275\321\214 \320\275\320\270\320\267\320\272\320\260\321\217", 0));
        ___qtreewidgetitem7->setText(0, QApplication::translate("FPWorth", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 1", 0));
        QTreeWidgetItem *___qtreewidgetitem8 = lvarSettings->topLevelItem(1);
        ___qtreewidgetitem8->setText(0, QApplication::translate("FPWorth", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \320\262\320\265\321\202\321\200\320\260", 0));
        QTreeWidgetItem *___qtreewidgetitem9 = ___qtreewidgetitem8->child(0);
        ___qtreewidgetitem9->setText(1, QApplication::translate("FPWorth", "V", 0));
        ___qtreewidgetitem9->setText(0, QApplication::translate("FPWorth", "\320\230\320\274\321\217 \321\202\320\265\321\200\320\274\320\260", 0));
        QTreeWidgetItem *___qtreewidgetitem10 = ___qtreewidgetitem8->child(1);
        ___qtreewidgetitem10->setText(1, QApplication::translate("FPWorth", "\320\236\321\207\320\265\320\275\321\214 \320\261\320\276\320\273\321\214\321\210\320\260\321\217", 0));
        ___qtreewidgetitem10->setText(0, QApplication::translate("FPWorth", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 5", 0));
        QTreeWidgetItem *___qtreewidgetitem11 = ___qtreewidgetitem8->child(2);
        ___qtreewidgetitem11->setText(1, QApplication::translate("FPWorth", "\320\221\320\276\320\273\321\214\321\210\320\260\321\217", 0));
        ___qtreewidgetitem11->setText(0, QApplication::translate("FPWorth", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 4", 0));
        QTreeWidgetItem *___qtreewidgetitem12 = ___qtreewidgetitem8->child(3);
        ___qtreewidgetitem12->setText(1, QApplication::translate("FPWorth", "\320\241\321\200\320\265\320\264\320\275\321\217\321\217", 0));
        ___qtreewidgetitem12->setText(0, QApplication::translate("FPWorth", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 3", 0));
        QTreeWidgetItem *___qtreewidgetitem13 = ___qtreewidgetitem8->child(4);
        ___qtreewidgetitem13->setText(1, QApplication::translate("FPWorth", "\320\235\320\270\320\267\320\272\320\260\321\217", 0));
        ___qtreewidgetitem13->setText(0, QApplication::translate("FPWorth", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 2", 0));
        QTreeWidgetItem *___qtreewidgetitem14 = ___qtreewidgetitem8->child(5);
        ___qtreewidgetitem14->setText(1, QApplication::translate("FPWorth", "\320\236\321\207\320\265\320\275\321\214 \320\275\320\270\320\267\320\272\320\260\321\217", 0));
        ___qtreewidgetitem14->setText(0, QApplication::translate("FPWorth", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 1", 0));
        QTreeWidgetItem *___qtreewidgetitem15 = lvarSettings->topLevelItem(2);
        ___qtreewidgetitem15->setText(0, QApplication::translate("FPWorth", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\276\321\201\320\260\320\264\320\272\320\276\320\262", 0));
        QTreeWidgetItem *___qtreewidgetitem16 = ___qtreewidgetitem15->child(0);
        ___qtreewidgetitem16->setText(1, QApplication::translate("FPWorth", "O", 0));
        ___qtreewidgetitem16->setText(0, QApplication::translate("FPWorth", "\320\230\320\274\321\217 \321\202\320\265\321\200\320\274\320\260", 0));
        QTreeWidgetItem *___qtreewidgetitem17 = ___qtreewidgetitem15->child(1);
        ___qtreewidgetitem17->setText(1, QApplication::translate("FPWorth", "\320\236\321\207\320\265\320\275\321\214 \320\262\321\213\321\201\320\276\320\272\320\276\320\265", 0));
        ___qtreewidgetitem17->setText(0, QApplication::translate("FPWorth", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 5", 0));
        QTreeWidgetItem *___qtreewidgetitem18 = ___qtreewidgetitem15->child(2);
        ___qtreewidgetitem18->setText(1, QApplication::translate("FPWorth", "\320\222\321\213\321\201\320\276\320\272\320\276\320\265", 0));
        ___qtreewidgetitem18->setText(0, QApplication::translate("FPWorth", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 4", 0));
        QTreeWidgetItem *___qtreewidgetitem19 = ___qtreewidgetitem15->child(3);
        ___qtreewidgetitem19->setText(1, QApplication::translate("FPWorth", "\320\241\321\200\320\265\320\264\320\275\320\265\320\265", 0));
        ___qtreewidgetitem19->setText(0, QApplication::translate("FPWorth", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 3", 0));
        QTreeWidgetItem *___qtreewidgetitem20 = ___qtreewidgetitem15->child(4);
        ___qtreewidgetitem20->setText(1, QApplication::translate("FPWorth", "\320\235\320\270\320\267\320\272\320\276\320\265", 0));
        ___qtreewidgetitem20->setText(0, QApplication::translate("FPWorth", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 2", 0));
        QTreeWidgetItem *___qtreewidgetitem21 = ___qtreewidgetitem15->child(5);
        ___qtreewidgetitem21->setText(1, QApplication::translate("FPWorth", "\320\236\321\207\320\265\320\275\321\214 \320\275\320\270\320\267\320\272\320\276\320\265", 0));
        ___qtreewidgetitem21->setText(0, QApplication::translate("FPWorth", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 1", 0));
        QTreeWidgetItem *___qtreewidgetitem22 = lvarSettings->topLevelItem(3);
        ___qtreewidgetitem22->setText(0, QApplication::translate("FPWorth", "\320\222\320\273\320\260\320\266\320\275\320\276\321\201\321\202\321\214", 0));
        QTreeWidgetItem *___qtreewidgetitem23 = ___qtreewidgetitem22->child(0);
        ___qtreewidgetitem23->setText(1, QApplication::translate("FPWorth", "B", 0));
        ___qtreewidgetitem23->setText(0, QApplication::translate("FPWorth", "\320\230\320\274\321\217 \321\202\320\265\321\200\320\274\320\260", 0));
        QTreeWidgetItem *___qtreewidgetitem24 = ___qtreewidgetitem22->child(1);
        ___qtreewidgetitem24->setText(1, QApplication::translate("FPWorth", "\320\236\321\207\320\265\320\275\321\214 \320\262\321\213\321\201\320\276\320\272\320\260\321\217", 0));
        ___qtreewidgetitem24->setText(0, QApplication::translate("FPWorth", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 5", 0));
        QTreeWidgetItem *___qtreewidgetitem25 = ___qtreewidgetitem22->child(2);
        ___qtreewidgetitem25->setText(1, QApplication::translate("FPWorth", "\320\222\321\213\321\201\320\276\320\272\320\260\321\217", 0));
        ___qtreewidgetitem25->setText(0, QApplication::translate("FPWorth", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 4", 0));
        QTreeWidgetItem *___qtreewidgetitem26 = ___qtreewidgetitem22->child(3);
        ___qtreewidgetitem26->setText(1, QApplication::translate("FPWorth", "\320\241\321\200\320\265\320\264\320\275\321\217\321\217", 0));
        ___qtreewidgetitem26->setText(0, QApplication::translate("FPWorth", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 3", 0));
        QTreeWidgetItem *___qtreewidgetitem27 = ___qtreewidgetitem22->child(4);
        ___qtreewidgetitem27->setText(1, QApplication::translate("FPWorth", "\320\235\320\270\320\267\320\272\320\260\321\217", 0));
        ___qtreewidgetitem27->setText(0, QApplication::translate("FPWorth", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 2", 0));
        QTreeWidgetItem *___qtreewidgetitem28 = ___qtreewidgetitem22->child(5);
        ___qtreewidgetitem28->setText(1, QApplication::translate("FPWorth", "\320\236\321\207\320\265\320\275\321\214 \320\275\320\270\320\267\320\272\320\260\321\217", 0));
        ___qtreewidgetitem28->setText(0, QApplication::translate("FPWorth", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 1", 0));
        lvarSettings->setSortingEnabled(__sortingEnabled);

        pushButton_2->setText(QApplication::translate("FPWorth", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\277\320\265\321\200\320\265\320\274\320\265\320\275\320\275\321\203\321\216", 0));
        openSaved->setText(QApplication::translate("FPWorth", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\201\320\276\321\205\321\200\320\260\320\275\321\221\320\275\320\275\321\213\320\265 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", 0));
        groupBox->setTitle(QApplication::translate("FPWorth", "\320\241\320\262\320\276\320\271\321\201\321\202\320\262\320\260", 0));
        label->setText(QApplication::translate("FPWorth", "\320\240\320\260\320\267\320\264\320\265\320\273\320\270\321\202\320\265\320\273\321\214:", 0));
        sepEdit->setText(QApplication::translate("FPWorth", ";", 0));
        label_5->setText(QApplication::translate("FPWorth", "\320\234\320\276\321\211\320\275\320\276\321\201\321\202\321\214 \320\273\320\270\320\275\320\263\320\262\320\270\321\201\321\202\320\270\321\207\320\265\321\201\320\272\320\276\320\271 \320\277\320\265\321\200\320\265\320\274\320\265\320\275\320\275\320\276\320\271:", 0));
        termSizeEdit->setText(QApplication::translate("FPWorth", "5", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("FPWorth", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260", 0));
        QTableWidgetItem *___qtablewidgetitem = normalTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("FPWorth", "1", 0));
        QTableWidgetItem *___qtablewidgetitem1 = normalTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("FPWorth", "2", 0));
        QTableWidgetItem *___qtablewidgetitem2 = normalTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("FPWorth", "3", 0));
        QTableWidgetItem *___qtablewidgetitem3 = normalTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("FPWorth", "4", 0));
        QTableWidgetItem *___qtablewidgetitem4 = normalTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("FPWorth", "5", 0));
        QTableWidgetItem *___qtablewidgetitem5 = normalTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("FPWorth", "1", 0));
        QTableWidgetItem *___qtablewidgetitem6 = normalTable->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("FPWorth", "2", 0));
        QTableWidgetItem *___qtablewidgetitem7 = normalTable->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("FPWorth", "3", 0));
        QTableWidgetItem *___qtablewidgetitem8 = normalTable->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("FPWorth", "4", 0));
        QTableWidgetItem *___qtablewidgetitem9 = normalTable->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("FPWorth", "5", 0));
        QTableWidgetItem *___qtablewidgetitem10 = normalTable->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("FPWorth", "1", 0));
        QTableWidgetItem *___qtablewidgetitem11 = normalTable->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("FPWorth", "2", 0));
        QTableWidgetItem *___qtablewidgetitem12 = normalTable->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QApplication::translate("FPWorth", "3", 0));
        QTableWidgetItem *___qtablewidgetitem13 = normalTable->horizontalHeaderItem(13);
        ___qtablewidgetitem13->setText(QApplication::translate("FPWorth", "4", 0));
        QTableWidgetItem *___qtablewidgetitem14 = normalTable->horizontalHeaderItem(14);
        ___qtablewidgetitem14->setText(QApplication::translate("FPWorth", "5", 0));
        QTableWidgetItem *___qtablewidgetitem15 = normalTable->horizontalHeaderItem(15);
        ___qtablewidgetitem15->setText(QApplication::translate("FPWorth", "1", 0));
        QTableWidgetItem *___qtablewidgetitem16 = normalTable->horizontalHeaderItem(16);
        ___qtablewidgetitem16->setText(QApplication::translate("FPWorth", "2", 0));
        QTableWidgetItem *___qtablewidgetitem17 = normalTable->horizontalHeaderItem(17);
        ___qtablewidgetitem17->setText(QApplication::translate("FPWorth", "3", 0));
        QTableWidgetItem *___qtablewidgetitem18 = normalTable->horizontalHeaderItem(18);
        ___qtablewidgetitem18->setText(QApplication::translate("FPWorth", "4", 0));
        QTableWidgetItem *___qtablewidgetitem19 = normalTable->horizontalHeaderItem(19);
        ___qtablewidgetitem19->setText(QApplication::translate("FPWorth", "5", 0));
        QTableWidgetItem *___qtablewidgetitem20 = normalTable->horizontalHeaderItem(20);
        ___qtablewidgetitem20->setText(QApplication::translate("FPWorth", "1", 0));
        QTableWidgetItem *___qtablewidgetitem21 = normalTable->horizontalHeaderItem(21);
        ___qtablewidgetitem21->setText(QApplication::translate("FPWorth", "2", 0));
        QTableWidgetItem *___qtablewidgetitem22 = normalTable->horizontalHeaderItem(22);
        ___qtablewidgetitem22->setText(QApplication::translate("FPWorth", "3", 0));
        QTableWidgetItem *___qtablewidgetitem23 = normalTable->horizontalHeaderItem(23);
        ___qtablewidgetitem23->setText(QApplication::translate("FPWorth", "4", 0));
        QTableWidgetItem *___qtablewidgetitem24 = normalTable->horizontalHeaderItem(24);
        ___qtablewidgetitem24->setText(QApplication::translate("FPWorth", "5", 0));
        QTableWidgetItem *___qtablewidgetitem25 = normalTable->horizontalHeaderItem(25);
        ___qtablewidgetitem25->setText(QApplication::translate("FPWorth", "1", 0));
        QTableWidgetItem *___qtablewidgetitem26 = normalTable->horizontalHeaderItem(26);
        ___qtablewidgetitem26->setText(QApplication::translate("FPWorth", "2", 0));
        QTableWidgetItem *___qtablewidgetitem27 = normalTable->horizontalHeaderItem(27);
        ___qtablewidgetitem27->setText(QApplication::translate("FPWorth", "3", 0));
        QTableWidgetItem *___qtablewidgetitem28 = normalTable->horizontalHeaderItem(28);
        ___qtablewidgetitem28->setText(QApplication::translate("FPWorth", "4", 0));
        QTableWidgetItem *___qtablewidgetitem29 = normalTable->horizontalHeaderItem(29);
        ___qtablewidgetitem29->setText(QApplication::translate("FPWorth", "5", 0));
        QTableWidgetItem *___qtablewidgetitem30 = normalTable->horizontalHeaderItem(30);
        ___qtablewidgetitem30->setText(QApplication::translate("FPWorth", "1", 0));
        QTableWidgetItem *___qtablewidgetitem31 = normalTable->horizontalHeaderItem(31);
        ___qtablewidgetitem31->setText(QApplication::translate("FPWorth", "2", 0));
        QTableWidgetItem *___qtablewidgetitem32 = normalTable->horizontalHeaderItem(32);
        ___qtablewidgetitem32->setText(QApplication::translate("FPWorth", "3", 0));
        QTableWidgetItem *___qtablewidgetitem33 = normalTable->horizontalHeaderItem(33);
        ___qtablewidgetitem33->setText(QApplication::translate("FPWorth", "4", 0));
        QTableWidgetItem *___qtablewidgetitem34 = normalTable->horizontalHeaderItem(34);
        ___qtablewidgetitem34->setText(QApplication::translate("FPWorth", "5", 0));
        QTableWidgetItem *___qtablewidgetitem35 = normalTable->horizontalHeaderItem(35);
        ___qtablewidgetitem35->setText(QApplication::translate("FPWorth", "1", 0));
        QTableWidgetItem *___qtablewidgetitem36 = normalTable->horizontalHeaderItem(36);
        ___qtablewidgetitem36->setText(QApplication::translate("FPWorth", "2", 0));
        QTableWidgetItem *___qtablewidgetitem37 = normalTable->horizontalHeaderItem(37);
        ___qtablewidgetitem37->setText(QApplication::translate("FPWorth", "3", 0));
        QTableWidgetItem *___qtablewidgetitem38 = normalTable->horizontalHeaderItem(38);
        ___qtablewidgetitem38->setText(QApplication::translate("FPWorth", "4", 0));
        QTableWidgetItem *___qtablewidgetitem39 = normalTable->horizontalHeaderItem(39);
        ___qtablewidgetitem39->setText(QApplication::translate("FPWorth", "5", 0));
        QTableWidgetItem *___qtablewidgetitem40 = normalTable->horizontalHeaderItem(40);
        ___qtablewidgetitem40->setText(QApplication::translate("FPWorth", "1", 0));
        QTableWidgetItem *___qtablewidgetitem41 = normalTable->horizontalHeaderItem(41);
        ___qtablewidgetitem41->setText(QApplication::translate("FPWorth", "2", 0));
        QTableWidgetItem *___qtablewidgetitem42 = normalTable->horizontalHeaderItem(42);
        ___qtablewidgetitem42->setText(QApplication::translate("FPWorth", "3", 0));
        QTableWidgetItem *___qtablewidgetitem43 = normalTable->horizontalHeaderItem(43);
        ___qtablewidgetitem43->setText(QApplication::translate("FPWorth", "4", 0));
        QTableWidgetItem *___qtablewidgetitem44 = normalTable->horizontalHeaderItem(44);
        ___qtablewidgetitem44->setText(QApplication::translate("FPWorth", "5", 0));
        QTableWidgetItem *___qtablewidgetitem45 = normalTable->horizontalHeaderItem(45);
        ___qtablewidgetitem45->setText(QApplication::translate("FPWorth", "1", 0));
        QTableWidgetItem *___qtablewidgetitem46 = normalTable->horizontalHeaderItem(46);
        ___qtablewidgetitem46->setText(QApplication::translate("FPWorth", "2", 0));
        QTableWidgetItem *___qtablewidgetitem47 = normalTable->horizontalHeaderItem(47);
        ___qtablewidgetitem47->setText(QApplication::translate("FPWorth", "3", 0));
        QTableWidgetItem *___qtablewidgetitem48 = normalTable->horizontalHeaderItem(48);
        ___qtablewidgetitem48->setText(QApplication::translate("FPWorth", "4", 0));
        QTableWidgetItem *___qtablewidgetitem49 = normalTable->horizontalHeaderItem(49);
        ___qtablewidgetitem49->setText(QApplication::translate("FPWorth", "5", 0));

        const bool __sortingEnabled1 = normalTable->isSortingEnabled();
        normalTable->setSortingEnabled(false);
        normalTable->setSortingEnabled(__sortingEnabled1);

        clearFuzzyButton_2->setText(QApplication::translate("FPWorth", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("FPWorth", "\320\230\321\201\321\205\320\276\320\264\320\275\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265", 0));
        QTableWidgetItem *___qtablewidgetitem50 = fuzzyTable->horizontalHeaderItem(0);
        ___qtablewidgetitem50->setText(QApplication::translate("FPWorth", "1", 0));
        QTableWidgetItem *___qtablewidgetitem51 = fuzzyTable->horizontalHeaderItem(1);
        ___qtablewidgetitem51->setText(QApplication::translate("FPWorth", "2", 0));
        QTableWidgetItem *___qtablewidgetitem52 = fuzzyTable->horizontalHeaderItem(2);
        ___qtablewidgetitem52->setText(QApplication::translate("FPWorth", "3", 0));
        QTableWidgetItem *___qtablewidgetitem53 = fuzzyTable->horizontalHeaderItem(3);
        ___qtablewidgetitem53->setText(QApplication::translate("FPWorth", "4", 0));
        QTableWidgetItem *___qtablewidgetitem54 = fuzzyTable->horizontalHeaderItem(4);
        ___qtablewidgetitem54->setText(QApplication::translate("FPWorth", "5", 0));
        QTableWidgetItem *___qtablewidgetitem55 = fuzzyTable->horizontalHeaderItem(5);
        ___qtablewidgetitem55->setText(QApplication::translate("FPWorth", "1", 0));
        QTableWidgetItem *___qtablewidgetitem56 = fuzzyTable->horizontalHeaderItem(6);
        ___qtablewidgetitem56->setText(QApplication::translate("FPWorth", "2", 0));
        QTableWidgetItem *___qtablewidgetitem57 = fuzzyTable->horizontalHeaderItem(7);
        ___qtablewidgetitem57->setText(QApplication::translate("FPWorth", "3", 0));
        QTableWidgetItem *___qtablewidgetitem58 = fuzzyTable->horizontalHeaderItem(8);
        ___qtablewidgetitem58->setText(QApplication::translate("FPWorth", "4", 0));
        QTableWidgetItem *___qtablewidgetitem59 = fuzzyTable->horizontalHeaderItem(9);
        ___qtablewidgetitem59->setText(QApplication::translate("FPWorth", "5", 0));
        QTableWidgetItem *___qtablewidgetitem60 = fuzzyTable->horizontalHeaderItem(10);
        ___qtablewidgetitem60->setText(QApplication::translate("FPWorth", "1", 0));
        QTableWidgetItem *___qtablewidgetitem61 = fuzzyTable->horizontalHeaderItem(11);
        ___qtablewidgetitem61->setText(QApplication::translate("FPWorth", "2", 0));
        QTableWidgetItem *___qtablewidgetitem62 = fuzzyTable->horizontalHeaderItem(12);
        ___qtablewidgetitem62->setText(QApplication::translate("FPWorth", "3", 0));
        QTableWidgetItem *___qtablewidgetitem63 = fuzzyTable->horizontalHeaderItem(13);
        ___qtablewidgetitem63->setText(QApplication::translate("FPWorth", "4", 0));
        QTableWidgetItem *___qtablewidgetitem64 = fuzzyTable->horizontalHeaderItem(14);
        ___qtablewidgetitem64->setText(QApplication::translate("FPWorth", "5", 0));
        QTableWidgetItem *___qtablewidgetitem65 = fuzzyTable->horizontalHeaderItem(15);
        ___qtablewidgetitem65->setText(QApplication::translate("FPWorth", "1", 0));
        QTableWidgetItem *___qtablewidgetitem66 = fuzzyTable->horizontalHeaderItem(16);
        ___qtablewidgetitem66->setText(QApplication::translate("FPWorth", "2", 0));
        QTableWidgetItem *___qtablewidgetitem67 = fuzzyTable->horizontalHeaderItem(17);
        ___qtablewidgetitem67->setText(QApplication::translate("FPWorth", "3", 0));
        QTableWidgetItem *___qtablewidgetitem68 = fuzzyTable->horizontalHeaderItem(18);
        ___qtablewidgetitem68->setText(QApplication::translate("FPWorth", "4", 0));
        QTableWidgetItem *___qtablewidgetitem69 = fuzzyTable->horizontalHeaderItem(19);
        ___qtablewidgetitem69->setText(QApplication::translate("FPWorth", "5", 0));
        QTableWidgetItem *___qtablewidgetitem70 = fuzzyTable->horizontalHeaderItem(20);
        ___qtablewidgetitem70->setText(QApplication::translate("FPWorth", "1", 0));
        QTableWidgetItem *___qtablewidgetitem71 = fuzzyTable->horizontalHeaderItem(21);
        ___qtablewidgetitem71->setText(QApplication::translate("FPWorth", "2", 0));
        QTableWidgetItem *___qtablewidgetitem72 = fuzzyTable->horizontalHeaderItem(22);
        ___qtablewidgetitem72->setText(QApplication::translate("FPWorth", "3", 0));
        QTableWidgetItem *___qtablewidgetitem73 = fuzzyTable->horizontalHeaderItem(23);
        ___qtablewidgetitem73->setText(QApplication::translate("FPWorth", "4", 0));
        QTableWidgetItem *___qtablewidgetitem74 = fuzzyTable->horizontalHeaderItem(24);
        ___qtablewidgetitem74->setText(QApplication::translate("FPWorth", "5", 0));
        QTableWidgetItem *___qtablewidgetitem75 = fuzzyTable->horizontalHeaderItem(25);
        ___qtablewidgetitem75->setText(QApplication::translate("FPWorth", "1", 0));
        QTableWidgetItem *___qtablewidgetitem76 = fuzzyTable->horizontalHeaderItem(26);
        ___qtablewidgetitem76->setText(QApplication::translate("FPWorth", "2", 0));
        QTableWidgetItem *___qtablewidgetitem77 = fuzzyTable->horizontalHeaderItem(27);
        ___qtablewidgetitem77->setText(QApplication::translate("FPWorth", "3", 0));
        QTableWidgetItem *___qtablewidgetitem78 = fuzzyTable->horizontalHeaderItem(28);
        ___qtablewidgetitem78->setText(QApplication::translate("FPWorth", "4", 0));
        QTableWidgetItem *___qtablewidgetitem79 = fuzzyTable->horizontalHeaderItem(29);
        ___qtablewidgetitem79->setText(QApplication::translate("FPWorth", "5", 0));
        QTableWidgetItem *___qtablewidgetitem80 = fuzzyTable->horizontalHeaderItem(30);
        ___qtablewidgetitem80->setText(QApplication::translate("FPWorth", "1", 0));
        QTableWidgetItem *___qtablewidgetitem81 = fuzzyTable->horizontalHeaderItem(31);
        ___qtablewidgetitem81->setText(QApplication::translate("FPWorth", "2", 0));
        QTableWidgetItem *___qtablewidgetitem82 = fuzzyTable->horizontalHeaderItem(32);
        ___qtablewidgetitem82->setText(QApplication::translate("FPWorth", "3", 0));
        QTableWidgetItem *___qtablewidgetitem83 = fuzzyTable->horizontalHeaderItem(33);
        ___qtablewidgetitem83->setText(QApplication::translate("FPWorth", "4", 0));
        QTableWidgetItem *___qtablewidgetitem84 = fuzzyTable->horizontalHeaderItem(34);
        ___qtablewidgetitem84->setText(QApplication::translate("FPWorth", "5", 0));
        QTableWidgetItem *___qtablewidgetitem85 = fuzzyTable->horizontalHeaderItem(35);
        ___qtablewidgetitem85->setText(QApplication::translate("FPWorth", "1", 0));
        QTableWidgetItem *___qtablewidgetitem86 = fuzzyTable->horizontalHeaderItem(36);
        ___qtablewidgetitem86->setText(QApplication::translate("FPWorth", "2", 0));
        QTableWidgetItem *___qtablewidgetitem87 = fuzzyTable->horizontalHeaderItem(37);
        ___qtablewidgetitem87->setText(QApplication::translate("FPWorth", "3", 0));
        QTableWidgetItem *___qtablewidgetitem88 = fuzzyTable->horizontalHeaderItem(38);
        ___qtablewidgetitem88->setText(QApplication::translate("FPWorth", "4", 0));
        QTableWidgetItem *___qtablewidgetitem89 = fuzzyTable->horizontalHeaderItem(39);
        ___qtablewidgetitem89->setText(QApplication::translate("FPWorth", "5", 0));
        QTableWidgetItem *___qtablewidgetitem90 = fuzzyTable->horizontalHeaderItem(40);
        ___qtablewidgetitem90->setText(QApplication::translate("FPWorth", "1", 0));
        QTableWidgetItem *___qtablewidgetitem91 = fuzzyTable->horizontalHeaderItem(41);
        ___qtablewidgetitem91->setText(QApplication::translate("FPWorth", "2", 0));
        QTableWidgetItem *___qtablewidgetitem92 = fuzzyTable->horizontalHeaderItem(42);
        ___qtablewidgetitem92->setText(QApplication::translate("FPWorth", "3", 0));
        QTableWidgetItem *___qtablewidgetitem93 = fuzzyTable->horizontalHeaderItem(43);
        ___qtablewidgetitem93->setText(QApplication::translate("FPWorth", "4", 0));
        QTableWidgetItem *___qtablewidgetitem94 = fuzzyTable->horizontalHeaderItem(44);
        ___qtablewidgetitem94->setText(QApplication::translate("FPWorth", "5", 0));
        QTableWidgetItem *___qtablewidgetitem95 = fuzzyTable->horizontalHeaderItem(45);
        ___qtablewidgetitem95->setText(QApplication::translate("FPWorth", "1", 0));
        QTableWidgetItem *___qtablewidgetitem96 = fuzzyTable->horizontalHeaderItem(46);
        ___qtablewidgetitem96->setText(QApplication::translate("FPWorth", "2", 0));
        QTableWidgetItem *___qtablewidgetitem97 = fuzzyTable->horizontalHeaderItem(47);
        ___qtablewidgetitem97->setText(QApplication::translate("FPWorth", "3", 0));
        QTableWidgetItem *___qtablewidgetitem98 = fuzzyTable->horizontalHeaderItem(48);
        ___qtablewidgetitem98->setText(QApplication::translate("FPWorth", "4", 0));
        QTableWidgetItem *___qtablewidgetitem99 = fuzzyTable->horizontalHeaderItem(49);
        ___qtablewidgetitem99->setText(QApplication::translate("FPWorth", "5", 0));

        const bool __sortingEnabled2 = fuzzyTable->isSortingEnabled();
        fuzzyTable->setSortingEnabled(false);
        fuzzyTable->setSortingEnabled(__sortingEnabled2);

        clearFuzzyButton->setText(QApplication::translate("FPWorth", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("FPWorth", "\320\236\320\261\321\200\320\260\320\261\320\276\321\202\320\272\320\260 \320\264\320\260\320\275\320\275\321\213\321\205", 0));
        makePlotButton->setText(QApplication::translate("FPWorth", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272", 0));
        lvarPlotButton->setText(QApplication::translate("FPWorth", "\320\237\320\265\321\200\320\265\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214", 0));
        label_11->setText(QApplication::translate("FPWorth", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\273\320\270\320\275\320\263\320\262\320\270\321\201\321\202\320\270\321\207\320\265\321\201\320\272\321\203\321\216 \320\277\320\265\321\200\320\265\320\274\320\265\320\275\320\275\321\203\321\216:", 0));
        clearPlotButton->setText(QApplication::translate("FPWorth", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", 0));
        label_12->setText(QApplication::translate("FPWorth", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\260\320\277\320\277\321\200\320\276\320\272\321\201\320\270\320\274\320\260\321\206\320\270\320\270:", 0));
        label_13->setText(QApplication::translate("FPWorth", "\320\250\320\260\320\263", 0));
        diffstepEdit->setText(QApplication::translate("FPWorth", "0.0001", 0));
        label_14->setText(QApplication::translate("FPWorth", "epsf:", 0));
        epsfEdit->setText(QApplication::translate("FPWorth", "0", 0));
        label_15->setText(QApplication::translate("FPWorth", "epsx:", 0));
        epsxEdit->setText(QApplication::translate("FPWorth", "0.000001", 0));
        label_16->setText(QApplication::translate("FPWorth", "\320\247\320\270\321\201\320\273\320\276 \320\270\321\202\320\265\321\200\320\260\321\206\320\270\320\271", 0));
        maxitsEdit->setText(QApplication::translate("FPWorth", "0", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("FPWorth", "\320\244\321\203\320\275\320\272\321\206\320\270\320\270 \320\277\321\200\320\270\320\275\320\260\320\264\320\273\320\265\320\266\320\275\320\276\321\201\321\202\320\270", 0));
        tableCombo->clear();
        tableCombo->insertItems(0, QStringList()
         << QApplication::translate("FPWorth", "1", 0)
        );
        label_2->setText(QApplication::translate("FPWorth", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\202\320\265\321\200\320\274\320\276\320\262 \320\262 \320\277\321\200\320\260\320\262\320\270\320\273\320\265", 0));
        label_8->setText(QApplication::translate("FPWorth", "\320\236\321\202:", 0));
        label_9->setText(QApplication::translate("FPWorth", "\320\224\320\276:", 0));
        okTermButton->setText(QApplication::translate("FPWorth", "Ok", 0));
        QTableWidgetItem *___qtablewidgetitem100 = supportTable->horizontalHeaderItem(0);
        ___qtablewidgetitem100->setText(QApplication::translate("FPWorth", "\320\237\320\276\320\264\320\264\320\265\321\200\320\266\320\272\320\260", 0));
        QTableWidgetItem *___qtablewidgetitem101 = supportTable->verticalHeaderItem(0);
        ___qtablewidgetitem101->setText(QApplication::translate("FPWorth", "\320\243\321\200\320\276\320\262\320\265\320\275\321\214 1", 0));
        QTableWidgetItem *___qtablewidgetitem102 = supportTable->verticalHeaderItem(1);
        ___qtablewidgetitem102->setText(QApplication::translate("FPWorth", "\320\243\321\200\320\276\320\262\320\265\320\275\321\214 2", 0));
        QTableWidgetItem *___qtablewidgetitem103 = supportTable->verticalHeaderItem(2);
        ___qtablewidgetitem103->setText(QApplication::translate("FPWorth", "\320\243\321\200\320\276\320\262\320\265\320\275\321\214 3", 0));

        const bool __sortingEnabled3 = supportTable->isSortingEnabled();
        supportTable->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem104 = supportTable->item(0, 0);
        ___qtablewidgetitem104->setText(QApplication::translate("FPWorth", "0", 0));
        QTableWidgetItem *___qtablewidgetitem105 = supportTable->item(1, 0);
        ___qtablewidgetitem105->setText(QApplication::translate("FPWorth", "0", 0));
        QTableWidgetItem *___qtablewidgetitem106 = supportTable->item(2, 0);
        ___qtablewidgetitem106->setText(QApplication::translate("FPWorth", "0", 0));
        supportTable->setSortingEnabled(__sortingEnabled3);

        label_18->setText(QApplication::translate("FPWorth", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\277\321\200\320\260\320\262\320\270\320\273:", 0));
        countRulesEdit->setText(QApplication::translate("FPWorth", "-1", 0));
        makeRulesAprioriButton->setText(QApplication::translate("FPWorth", "Make Rules Apriori", 0));
        makeRulesFPGButton->setText(QApplication::translate("FPWorth", "Make Rules FP-Growth", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("FPWorth", "\320\237\321\200\320\260\320\262\320\270\320\273\320\260", 0));
        label_10->setText(QApplication::translate("FPWorth", "\320\222\321\205\320\276\320\264\320\275\321\213\320\265 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213:", 0));
        QTableWidgetItem *___qtablewidgetitem107 = inputNnpsTable->verticalHeaderItem(0);
        ___qtablewidgetitem107->setText(QApplication::translate("FPWorth", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", 0));
        QTableWidgetItem *___qtablewidgetitem108 = inputNnpsTable->verticalHeaderItem(1);
        ___qtablewidgetitem108->setText(QApplication::translate("FPWorth", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265", 0));

        const bool __sortingEnabled4 = inputNnpsTable->isSortingEnabled();
        inputNnpsTable->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem109 = inputNnpsTable->item(1, 0);
        ___qtablewidgetitem109->setText(QApplication::translate("FPWorth", "-1.50", 0));
        QTableWidgetItem *___qtablewidgetitem110 = inputNnpsTable->item(1, 1);
        ___qtablewidgetitem110->setText(QApplication::translate("FPWorth", "70", 0));
        QTableWidgetItem *___qtablewidgetitem111 = inputNnpsTable->item(1, 2);
        ___qtablewidgetitem111->setText(QApplication::translate("FPWorth", "0.74", 0));
        QTableWidgetItem *___qtablewidgetitem112 = inputNnpsTable->item(1, 3);
        ___qtablewidgetitem112->setText(QApplication::translate("FPWorth", "1", 0));
        QTableWidgetItem *___qtablewidgetitem113 = inputNnpsTable->item(1, 4);
        ___qtablewidgetitem113->setText(QApplication::translate("FPWorth", "6.33", 0));
        QTableWidgetItem *___qtablewidgetitem114 = inputNnpsTable->item(1, 5);
        ___qtablewidgetitem114->setText(QApplication::translate("FPWorth", "6.34", 0));
        QTableWidgetItem *___qtablewidgetitem115 = inputNnpsTable->item(1, 6);
        ___qtablewidgetitem115->setText(QApplication::translate("FPWorth", "6.22", 0));
        QTableWidgetItem *___qtablewidgetitem116 = inputNnpsTable->item(1, 7);
        ___qtablewidgetitem116->setText(QApplication::translate("FPWorth", "0.36", 0));
        QTableWidgetItem *___qtablewidgetitem117 = inputNnpsTable->item(1, 8);
        ___qtablewidgetitem117->setText(QApplication::translate("FPWorth", "4.77", 0));
        QTableWidgetItem *___qtablewidgetitem118 = inputNnpsTable->item(1, 9);
        ___qtablewidgetitem118->setText(QApplication::translate("FPWorth", "8.35", 0));
        inputNnpsTable->setSortingEnabled(__sortingEnabled4);

        suppRulesCheckBox->setText(QApplication::translate("FPWorth", "\320\243\321\207\320\270\321\202\321\213\320\262\320\260\321\202\321\214 \320\277\320\276\320\264\320\264\320\265\321\200\320\266\320\272\321\203 \320\277\321\200\320\260\320\262\320\270\320\273 \320\277\321\200\320\270 \321\200\320\260\321\201\321\201\321\207\321\221\321\202\320\265", 0));
        nnpsButton->setText(QApplication::translate("FPWorth", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214 \320\277\321\200\320\276\320\263\320\275\320\276\320\267 \320\277\320\276\320\266\320\260\321\200\320\276\320\262", 0));
        groupBox_2->setTitle(QApplication::translate("FPWorth", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\321\213", 0));
        label_4->setText(QApplication::translate("FPWorth", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\277\320\276\320\266\320\260\321\200\320\276\320\262:", 0));
        label_17->setText(QApplication::translate("FPWorth", "\320\222\320\265\321\200\320\276\321\217\321\202\320\275\320\276\321\201\321\202\321\214", 0));
        fireCountLabel->setText(QString());
        probLabel->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QApplication::translate("FPWorth", "\320\235\320\235\320\237\320\241", 0));
        label_3->setText(QApplication::translate("FPWorth", "<h3>\320\241\321\203\320\274\320\274\320\260\321\200\320\275\321\213\320\265 \320\277\320\276\320\264\320\264\320\265\321\200\320\266\320\272\320\270 \321\202\320\265\321\200\320\274\320\276\320\262:</h3>", 0));
        label_6->setText(QApplication::translate("FPWorth", "<h3>\320\224\320\260\320\275\320\275\321\213\320\265 \321\201 \320\277\320\276\321\201\321\202\321\200\320\276\320\265\320\275\320\275\321\213\320\274\320\270 \321\201\320\273\320\276\320\262\320\260\320\274\320\270:</h3>", 0));
        label_7->setText(QApplication::translate("FPWorth", "<h3>\320\224\320\265\321\200\320\265\320\262\320\276 \321\207\320\260\321\201\321\202\321\213\321\205 \320\275\320\260\320\261\320\276\321\200\320\276\320\262 (FP-Tree):</h3>", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("FPWorth", "\320\240\320\260\320\261\320\276\321\207\320\260\321\217 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", 0));
    } // retranslateUi

};

namespace Ui {
    class FPWorth: public Ui_FPWorth {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FPWORTH_H

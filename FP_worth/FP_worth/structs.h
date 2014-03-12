#ifndef SETTINGS_H
#define SETTINGS_H

#define MAXLEN 1024
#include <QVector>

struct term{
    int number;
    int str_num;
    int support;
};

struct pattern{
    int support;
    int count; // rows[k]
    int cluster;
    QVector<struct term> word;
    QVector<int> str_numbers;
};

struct numCluster{
    double number;
    int cluster;
};

struct membershipFunction{
    double mu;
    double a;
    double k;
    int type; // 0 - 1/1+exp() ???; 1 - Gauss func
};


#endif // SETTINGS_H

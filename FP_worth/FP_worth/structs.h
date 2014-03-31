#ifndef SETTINGS_H
#define SETTINGS_H

#define MAXLEN 1024
#include <QVector>

struct term{
    int term_number;
    int lp_number;
    int str_num;
    int support;
};

struct pattern{
    int support;
    int count; // rows[k]
    int cluster; // k (fire cluster)
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
    int type; // 0 - Gauss func G; 1 - sigmoid right E, 2 sigmoid left NE
};


#endif // SETTINGS_H

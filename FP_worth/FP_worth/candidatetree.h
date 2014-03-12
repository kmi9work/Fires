#ifndef CANDIDATETREE_H
#define CANDIDATETREE_H
#include <QVector>
#include "fpworth.h"
#include "structs.h"
#include <iostream>

struct term;

class CandidateTree
{
public:
    CandidateTree(QVector<double> ds, int rs);
    struct term data;
    double support;
    int rows;
    CandidateTree *father;
    QVector<CandidateTree*> children;
    QVector<int> string_numbers;
    void addChild(struct term d, int supp, QVector<int> str_nums);
    void makeTree(int **numbers, int rows, int lvar_size);
    QVector<pattern> assocRules(int first, int last, int step);
    QVector<double> deltas;
    int level;
    void printTree();
    static QVector< QVector<CandidateTree*> > levels;
private:
    //double
};

#endif // CANDIDATETREE_H

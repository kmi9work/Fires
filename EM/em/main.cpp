/*#include <QCoreApplication>
#include "math.h"

#define NUM_PI      3.14159265358979323846

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int i, j, iter;
    int k = 5;
    int n = 50;
    double *C, R, *W;
    double *C_buf, R_buf, *W_buf;
    double *sump;
    int *Y;
    double eps = 0.1;
    int maxSteps = 1000000;
    double **X;
    double **delta, **p;
    double llh = 1;
    delta = new double*[n];
    p = new double*[n];
    X = new double*[n];
    for (i = 0; i < n; i++){
        delta[i] = new double[k];
        p[i] = new double[k];
        X[i] = new double[k];
    }

    Y = new double[n];
    C = new double[k];
    W = new double[k];
    C_buf = new double[k];
    W_buf = new double[k];
    sump = new double[n];
    while (llh > eps and iter < maxSteps){
        memset(C_buf, 0, sizeof(double) * k);
        memset(W_buf, 0, sizeof(double) * k);
        R_buf = 0;
        llh = 0;
        for (i = 0; i < n; i++){
            sump[i] = 0;
            for (j = 0; j < k; j++){
                delta[i][j] = (Y[i] - C[j])*(Y[i] - C[j])*R;
                p[i][j] = (W[j]/(sqrt(2*NUM_PI*fabs(R)))) * exp(delta[i][j]/2);
                sump[i] += p[i][j];
            }
            for (j = 0; j < k; j++){
                X[i][j] = p[i][j] / sump[i];
            }
            llh += log(sump[i]);
            C

        }

        iter++;
    }


    return a.exec();
}
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include "dataanalysis.h"

using namespace alglib;


int main(int argc, char **argv)
{
    //
    // The very simple clusterization example
    //
    // We have a set of points in 2D space:
    //     (P0,P1,P2,P3,P4) = ((1,1),(1,2),(4,1),(2,3),(4,1.5))
    //
    //  |
    //  |     P3
    //  |
    //  | P1
    //  |             P4
    //  | P0          P2
    //  |-------------------------
    //
    // We want to perform k-means++ clustering with K=2.
    //
    // In order to do that, we:
    // * create clusterizer with clusterizercreate()
    // * set points XY and metric (must be Euclidean, distype=2) with clusterizersetpoints()
    // * (optional) set number of restarts from random positions to 5
    // * run k-means algorithm with clusterizerrunkmeans()
    //
    // You may see that clusterization itself is a minor part of the example,
    // most of which is dominated by comments :)
    //
    clusterizerstate s;
    kmeansreport rep;
    real_2d_array xy = "[[0.1],[0.2],[0.3],[0.4],[0.5],[0.51],[0.52],[0.53],[0.54],[0.55],[0.56],[0.57],[0.58],[0.59],[0.6],[0.7],[0.8],[0.9],[1]]";

    clusterizercreate(s);
    clusterizersetpoints(s, xy, 2);
    clusterizersetkmeanslimits(s, 50, 0);
    clusterizerrunkmeans(s, 5, rep);


    //
    // We've performed clusterization, and it succeeded (completion code is +1).
    //
    // Now first center is stored in the first row of rep.c, second one is stored
    // in the second row. rep.cidx can be used to determine which center is
    // closest to some specific point of the dataset.
    //
    printf("%d\n", int(rep.terminationtype)); // EXPECTED: 1
    std::cout << rep.c.tostring(2) << std::endl;
    std::cout << "NPoints: " << rep.npoints << std::endl;
    std::cout << "NPoints: " << rep.cidx.tostring() << std::endl;
    return 0;
}

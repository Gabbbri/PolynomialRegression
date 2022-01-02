#include "LinearRegressionVers1.hpp"
#include <iostream>
#include <cmath>
#include <Eigen/Dense>

using namespace Eigen;

double* linear_regression (Data* dataset, int numb) {
    
    //costruisco il sistema in forma matriciale

    Vector <double, Dynamic> X;
    Vector <double, Dynamic> Y;
    Vector <int, Dynamic> Z;

    for (int i=0; i<numb; i++) {
        X [i] = (dataset[i]).xp;
        Y [i] = (dataset[i]).yp;
        Z[i] = 1;
    }

    Matrix<double, Dynamic, 2> A;
    A << X, Z;   //assicurati che entrino in colonna

    //Costruisco le equazioni normali
    Matrix <double, Dynamic, 2> At = A.transpose();
    A = At*A;
    Y = At*Y; 

    Vector2d x;   //vettore delle incognite

    //Risolvo il sistema con il metodo LU

    PartialPivLU <Matrix <double,Dynamic, 2>> decomp;
    decomp = A.partialPivLu();
    Matrix <double, Dynamic, 2> LU = decomp.matrixLU();
    x = decomp.solve(Y);

    //Sposto i coefficienti in un array di double e lo restituisco al main

    static double sol [2] = {x[0], x[1]};

    return sol;
}
/*
GABRIELE, 30/12/2021
Creazione funzione LinearRegression:
    - input: array di strutture
    - output: array di double contente i coefficienti della retta
*/

#include "LinearRegressionVers1.hpp"
#include <iostream>
#include <cmath>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

double* linear_regression (Data* dataset, int numb) {

    // sommatoria xi^2
    double sum2xp=0;
    for (int i=0; i<numb; i++) {
        sum2xp += pow((dataset[i]).xp, 2);
    }

    // sommatoria xi
    double sumxp=0;
    for (int i=0; i<numb;i++) {
        sumxp += (dataset[i]).xp;
    }

    //sommatoria xi*yi
    double sumxpyp = 0;
    for (int i=0; i<numb; i++) {
        sumxpyp += (dataset[i]).xp * (dataset[i]).yp;
    }

    //sommatora yi
    double sumyp = 0;
    for (int i=0; i<numb; i++) {
        sumyp += (dataset[i]).yp;
    }

    //creazione della mtrx e riempimento
    Matrix2d A;
    A << sum2xp, sumxp, sumxp, numb;  //riempimento mediante comma initializer

    //creazione del vettore delle soluzioni
    Vector2d B;
    B << sumxpyp, sumyp;

    //creazione del vettore delle incognite
    Vector2d X;

    /* APPROCCIO:
        1. Vado a creare una nuova mtrx di tipo PartialPivLU
        2. In questa nuova mtrx metto la decomposizione LU della mtrx A
        3. Risolvo il sistema passando al metodo .solve il vettore delle soluzioni

    */
   PartialPivLU<Matrix2d> decomp;
   decomp = A.partialPivLu();
   X = decomp.solve(B);

   //Trasferisco gli elementi del vettore di Eigen in un array di double allocato STATICO (oppure lo creo nel main e lo passo ma non sembra 
   //una gran buona idea in ottica di realizzare una libreria)
   //----> NON C'E` UN MODO PER RITORNARE IL VETTORE DI EIGEN??

   static double sol[2] = {X[0], X[1]};

   return sol;
}
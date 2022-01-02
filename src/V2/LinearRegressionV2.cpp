#include "LinearRegressionVers1.hpp"
#include <iostream>
#include <Eigen/Dense>

#define DEBUG 1

using namespace Eigen;

double* linear_regression (Data* dataset, int numb) {
    
    std::cout << "Entrata";
    //costruisco il sistema in forma matriciale

    
    //QUANDO INIZIALIZZI VETTORI O MATRICI DINAMICI, O METTI LE DIMENSIONI (*variabili* a compile time) oppure usi il .resize!
    
    VectorXd  X (numb);
    VectorXd Y (numb);

    std::cout << "\nCreazione vettori\n";

    
    for (int i=0; i<numb; i++) {
        X(i) = (dataset[i]).xp;
        Y(i) = (dataset[i]).yp;
    }

    #if DEBUG 
    std::cout << "Assegnazione effettuata\n";
    #endif

    Matrix<double, Dynamic, 2> A (numb,2);
    A.col(0) = X;
    (A.col(1)).fill(1);

    #if DEBUG
    std::cout << "Matrice A riempita:\n";
    std::cout << A << std::endl;
    #endif

    //Costruisco le equazioni normali
    /* NOTA:
        Se A = 3x2, A.trasposta = 2x3 ----> A.trasposta*A=2x2. IL prodotto è una mtrx quadrata
    */

    Matrix2d new_A = A.transpose()*A;  //new_A sarà sempre 2x2 in quanto si sta cercando LA RETTA di regressione (polinomio di 1°grado --> 2 coefficienti)
    Y = A.transpose()*Y; 

    #if DEBUG
    std::cout << "Calcolate la matrice e il vettore finali per il sistema:\n";
    std::cout << "new_A:\n" << new_A << std::endl;
    std::cout <<"Y:\n"<< Y;
    #endif


    Vector2d x;   //vettore delle incognite 

    //Risolvo il sistema 
    //NOTE: 1. Come visto sopra, la mtrx new_A è sempre quadrata. Posso sfruttare il metodo LU
    //      2. Sempre da sopra, new_A è una mtrx SEMPRE 2x2

    PartialPivLU<Matrix2d> decomp;
    decomp = new_A.partialPivLu();
    x = decomp.solve(Y);

    #if DEBUG
    std::cout << "\nSistema risolto\n";
    #endif

    //Sposto i coefficienti in un array di double e lo restituisco al main

    static double sol [2] = {x[0], x[1]};

    return sol;
}
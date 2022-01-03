#include <iostream>
#include <cmath>
#include <Eigen/Dense>
#include "PolynomialRegression.hpp"


using namespace Eigen;

double* polynomial_regression (Data* dataset, int numb) {


    //chiedo all'utente il grado del polinomio con il quale vuole approssimare i punti

    int degree;
    std::cout << "Inserisci il grado del polinomio con il quale vuoi approssimare i punti\n";
    std::cin >> degree;

    const int col = degree+1;

    //controllo utente necessario ----> if (degree+1<numb) ---> OK
    //                                  else {sto interpolando o sto sotto-determinando il sistema} 
    //DA FARE MEGLIO
    if (degree+1>=numb) {
        std::cout << "Non posso approssimare ai minimi quadrati il tuo dataset con questo polinomio\n";
        exit (1);
    } 

    //COSTRUZIONE DELLA MATRICE A:
    
    VectorXd costr (numb);  //sfrutto questo vettore per costruire la mtrx A
    MatrixXd A (numb, col);   //!!!Creo la mtrx completamente dinamica MA dò le variabili rappresentanti le dimensioni (altrimenti ho errori)
                                   //Pensaci al perchè degree+1!!
    
    //Annido i vari for sulla 'i' nei casi dello switch. In questo modo dovremmo ottimizzare un pò il codice 
    //(chiamo pow solo quando realmente serve - non continuo a valutare i casi dello switch per ogni i(sono potenzialmente tantissimi))
    
    int k=0;
    for (int j=degree;j>=0;j--) {
        switch (j) {
            case 0:
                (A.col(k)).fill(1);
                k++;
                break;
            
            case 1:
                for (int i=0; i<numb; i++) {
                    costr(i) = (*dataset).xp;
                }
                A.col(k) = costr;
                k++;
                break;
            
            default:
                for (int i=0; i<numb; i++) {
                    costr(i)=pow((*dataset).xp, j);
                }
                A.col(k) = costr;
                k++;
                break;
                

        }

    }

    //COSTRUZIONE DEL VETTORE Y
    VectorXd Y (numb);
    for (int i=0; i<numb; i++) {
        Y(i)=(*dataset).yp;
    }

    //COSTRUZIONE DEL VETTORE DELLE SOLUZIONI x
    VectorXd x (col);

    //COSTRUZIONE DEL SISTEMA ALLE EQUAZIONI NORMALI

    MatrixXd new_A (col,col);
    new_A = A.transpose()*A;  //mtrx per la risoluzione del sistema alle equazioni normali
    
    VectorXd new_Y (col);
    new_Y=A.transpose()*Y;


    //RISOLUZIONE DEL SISTEMA TRAMITE DECOMPOSIZIONE LU

    PartialPivLU <MatrixXd> decomp (col);
    decomp = new_A.partialPivLu();
    x=decomp.solve(new_Y);

    //RESTITUISCO AL MAIN UN ARRAY CONTENTENTE I COEFFICIENTI DEL POLINOMIO
    
    //uso static per non deallocare la memoria riservata alla variabile quando la funzione restituisce il controllo al main
    static double* sol = new double [col];

    for (int i=0; i<col; i++) {
        sol[i] = x(i);
    }

    return sol;
}
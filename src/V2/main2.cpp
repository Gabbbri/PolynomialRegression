/* Perchè non usare Eigen fin da subito e raccogliere i punti direttamente in vettori?
**************************************************************************************
Si sta ragionando in ottica libreria. Voglio che il main sia più indipendente possibile.
Eigen agirà quindi solo sulla libreria.

Requisito per usare la lib è quindi raccogliere i punti in un array di strutture (come fatto 
per la vers1).
Fatto ciò questa "fa le sue cose" e restituisce un array di double contente i coefficienti del
polinomio ai minimi quadrati

Si può quindi riciclare il main della vers1.
*/


#include <iostream>
#include "LinearRegressionVers1.hpp"
#include <fstream>

using namespace std;

int main () {

    int numb;
    cout << "Quanti punti hai raccolto?\n";
    cin >> numb;

    Data* dataset = new Data [numb];

    //DA FORMATTARE DECENTEMENTE

    //creazione in contemporanea di un datafile esterno per gnuplot

    string fname = "output.gp";
    ofstream f1 (fname);   //apertura stream
    
    for (int i=0; i<numb;i++) {
        cout << "Inserisci " << i+1 << " punto: \n";
        cin >> (dataset[i]).xp;
        cin >> (dataset[i]).yp;
        cout << "\n";
        f1 << (dataset[i]).xp << "     " << (dataset[i]).yp;
    }

    cout << "Chiamata a funzione\n";
    
    double* coeff = linear_regression (dataset, numb);

    cout << "La retta che approssima meglio il dataset inserito ai minimi quadrati è:\n"
         << "y(x) = " << coeff[0] << "x + " << coeff[1];

    delete [] dataset;

    return 0;
}



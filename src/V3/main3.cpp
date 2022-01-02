
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
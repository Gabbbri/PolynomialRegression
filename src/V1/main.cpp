#include <iostream>
#include "LinearRegressionVers1.hpp"

using namespace std;

int main () {

    int numb;
    cout << "Quanti punti hai raccolto?\n";
    cin >> numb;

    Data* dataset = new Data [numb];

    cout << "Inserisci i punti\n\n";
    cout << "   |--------------|\n";
    cout << "   |  x   |   y   |\n";
    cout << "   |--------------|\n";
    

    //DA FORMATTARE DECENTEMENTE
    for (int i=0; i<numb;i++) {
        cout << "#" << i+1 << " punto: \n"
             << "   |  ";
        cin >> (dataset[i]).xp;
        cout << "          |  " ;
        cin >> (dataset[i]).yp;
        cout << "\n";
    }

    //mi prendo i 2 coefficienti restituiti dalla funzione

    double* coeff = linear_regression1 (dataset, numb);
    
    cout << "La retta che approssima meglio ai minimi quadrati il tuo dataset è: \n"
         << "y(x) = " << coeff[0] << "x + " << coeff[1];

    delete [] dataset;
    return 0;
}
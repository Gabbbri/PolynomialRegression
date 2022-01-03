/* **************************************************** 
| - TEST per la funzione LinearRegressionV1
| - Il numero di punti e le rispettive coordinate potranno essere
! inseriti sia manualmente che in modo randomico
| 
| Gabriele
|***************************************************** */

#include <iostream>
#include "LinearRegressionVers1.hpp"
#include <time.h>

using namespace std;

int main () {

    //instrado l'utente verso la genereazione randomica o l'input

    int scelta;
    cout << "Puoi scegliere se generare i punti in maniera randomica o inserirli tu\n"
         << "Cosa vuoi fare?\n"
         << "0: generazione randomica\n"
         << "1: inserisci tu\n";
    
    
    bool usrcontrol;
    do {
        usrcontrol=0;
        cin >> scelta;
        if (scelta!=0 || scelta!=1) {
        usrcontrol = true;
        cout << "Inserisci o 0 o 1. Nessun altro numero ammesso\n";
        }   
    }
    while (usrcontrol);

    
    
    int pnumb;
    Data* data = new Data [pnumb];  //struct definita nell'header della funzione ----> DA AGGIUNGERE STA ROBA AI DOCS!!
    
    //GENEREAZIONE DEI DATASET IN FUNZIONE DELLA SCELTA UTENTE
    
    
    
    switch (scelta) {

            case 0: //----> GENERAZIONE RANDOMICA
                srand(time(NULL)); //seed
                //genero il numero di punti
                pnumb = rand () % 100 + 2; //range [2;100] ---> Se ho 2 punti? Sto interpolando di fatto!!

                for (int i=0; i<pnumb; i++) {
                (data[i]).xp = rand () % 100 - 100;  //range [-100;+100]
                (data[i]).yp = rand () % 100 - 100;
                }

                break;
            
            default: //---> GENERAZIONE TRAMITE UTENTE
                cout << "Quanti punti vuoi inserire?\n";
                cin >> pnumb;

                //controllo utente: impossibile inserire meno di 2 punti
                if (pnumb<2) exit (1); //(da migliorare)

                cout << "Inserisci i punti\n\n";
                cout << "   |--------------|\n";
                cout << "   |  x   |   y   |\n";
                cout << "   |--------------|\n";
    

                //DA FORMATTARE DECENTEMENTE
                for (int i=0; i<pnumb;i++) {
                cout << "#" << i+1 << " punto: \n"
                    << "   |  ";
                cin >> (data[i]).xp;
                cout << "          |  " ;
                cin >> (data[i]).yp;
                cout << "\n";
                }

                break;
    }

    //vado a puntare l'array dei coefficienti restituito dalla funzione
    double* coeff = linear_regression1 (data, pnumb);

    //stampo a video la retta di regressione

    cout << "La retta che meglio approssima ai minimi quadrati il dataset è:\n"
         << "y(x) = " << coeff[0] << "x + " << coeff[1];

    

    return 0;
}



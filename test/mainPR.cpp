/* **************************************************** 
| - TEST per la funzione LinearRegressionV1
| - Il numero di punti e le rispettive coordinate potranno essere
! inseriti sia manualmente che in modo randomico
| 
| Gabriele
|***************************************************** */

#include <iostream>
#include "PolynomialRegression.hpp"
#include <time.h>

using namespace std;

int main () {

    //instrado l'utente verso la generazione randomica o l'input

    int scelta;
    cout << "Puoi scegliere se generare i punti in maniera randomica o inserirli tu\n"
         << "Cosa vuoi fare?\n"
         << "0: generazione randomica\n"
         << "1: inserisci tu\n";
    
    
    bool usrcontrol;
    do {
        usrcontrol=0;
        cin >> scelta;
        if (scelta!=0 && scelta!=1) {
        usrcontrol = true;
        cout << "Inserisci o 0 o 1. Nessun altro numero ammesso\n";
        }   
    }
    while (usrcontrol);

    
    
    int pnumb;
    
    
    //GENEREAZIONE DEI DATASET IN FUNZIONE DELLA SCELTA UTENTE
    
    
    
    switch (scelta) {

            case 0: //----> GENERAZIONE RANDOMICA
                srand(time(NULL)); //seed
                //genero il numero di punti
                pnumb = rand () % 25 + 2; //range [2;25] ---> Se ho 2 punti? Sto interpolando di fatto!!
                
                static Data* data = new Data [pnumb];  //struct definita nell'header della funzione ----> DA AGGIUNGERE STA ROBA AI DOCS!!

                cout << "Sto usando     " << pnumb << "     punti causali\n";

                cout << "Ho scelto i punti: \n\n" << "|  X  ||  Y  |\n";
                for (int i=0; i<pnumb; i++) {
                (data[i]).xp = rand () % 100 - 100;  //range [-100;+100]
                (data[i]).yp = rand () % 100 - 100;

                //buffer di output
                cout << data[i].xp << "        " << data[i].yp << endl;
                }

                break;
            
            default: //---> GENERAZIONE TRAMITE UTENTE
                cout << "Quanti punti vuoi inserire?\n";
                cin >> pnumb;

                static Data* data = new Data [pnumb];  //struct definita nell'header della funzione ----> DA AGGIUNGERE STA ROBA AI DOCS!!

                //controllo utente: impossibile inserire meno di 2 punti
                if (pnumb<2) exit (1); //QUESTO CONTROLLO, COME QUELLO SOPRA, NON DOVREBBE ESSERE NECESSARIO IN QUANTO PROVVEDE GIA' LA FUNZIONE A FARLO

                cout << "Inserisci i punti\n\n";
                cout << "   |--------------|\n";
                cout << "   |  x   |   y   |\n";
                cout << "   |--------------|\n";
    

                //DA FORMATTARE DECENTEMENTE
                for (int i=0; i<pnumb;i++) {
                cout << "#" << i+1 << " punto: \n"
                    << "X   |  ";
                cin >> (data[i]).xp;
                cout << "Y          |  " ;
                cin >> (data[i]).yp;
                cout << "\n";
                }

                break;
    }


    //per ritirare i coefficienti dall'array di ritorno dalla funzione è necessario sapere il grado del polinomio (così da sapere quante volte looppare). 
    //Posso ricavarlo con un `sizeof`, oppure creo qui una variabile e la passo per riferimento alla funzione, che ci farà su modifiche.
    //IN OTTICA LIBRERIA, HA PIU' SENSO USARE `SIZEOF`. Questo perchè se devo usare la libreria in un programma voglio che si autogestisca il più
    //possibile, e passare come argomenti solo il minimo necessario, senza stravolgere il mio programma per far funzionare la libreria.


    //vado a puntare l'array dei coefficienti restituito dalla funzione
    double* coeff = polynomial_regression (data, pnumb);  //Il grado del polinomio approssimante viene preso nella funzione

    //stampo a video la retta di regressione. Per un polinomio di grado m, avrò avrò m+1 coefficienti.

    cout << "Il polinomio che meglio approssima ai minimi quadrati il dataset è:\n";

    
    //SAREBBE DA CREARE UNA MINIPROCEDURA PER LA STAMPA, IN MODO DI RISPETTARE L'OTTICA SECONDO LA QUALE LA LIBRERIA DEVE AUTOGESTIRSI IL PIU' POSSIBILE. Non deve essere
    //il "client" ad adattare il suo codice per usare la libreria!

    //ricordo che dalla risoluzione del sistema alle equazioni normali ho ottenuto l'array delle soluzioni in cui i coefficienti sono in ordine a(x^n) - b (x^n-1) - ....
    
    int degree = sizeof(coeff)/sizeof(*coeff);
    cout << "y[x] = " << coeff[0] << "x^" << (degree);
    for (int i=1; i<=degree; i++){
         cout << " + " << coeff [i] << "x^" << (degree-i);
    }

    delete [] data;
    return 0;
}

#include <iostream>
#include "klase_stajalista.h"


using namespace std;


int Stajaliste::naziv() {

    return brojStanice;

}

string Stajaliste::naziv_stajalista() {

    return nazivStajalista;

}

void Stajaliste::ispisiStajaliste(string ime_fajla) {
    std::ofstream izlazniFajl(ime_fajla, std::ios::app);
    izlazniFajl << to_string(brojStanice) + " " + nazivStajalista;

    if (vazno) {
        izlazniFajl << " [!]";  // Dodaj [!] ako je stajaliste vazno
    }
    izlazniFajl << "\n";
    izlazniFajl.close();
}






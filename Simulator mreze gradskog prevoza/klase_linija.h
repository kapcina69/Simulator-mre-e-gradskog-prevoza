
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "klase_stajalista.h"


using namespace std;

class Linija {
public:
    std::string naziv;
    std::vector<int> stajalista;

    // Eksplicitan podrazumevani konstruktor
    Linija() = default;

    // Drugi konstruktor ako je potrebno
    Linija(const std::string& naziv, const std::vector<int>& stajalista)
        : naziv(naziv), stajalista(stajalista) {}
    friend ostream& operator<<(std::ostream& os, const Linija& linija) {
        os << "Naziv: " << linija.naziv << std::endl;
        os << "Stajalista: ";
        for (int stajaliste : linija.stajalista) {
            os << stajaliste << " ";
        }
        return os;
    }




};

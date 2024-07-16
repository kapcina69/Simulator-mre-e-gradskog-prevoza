
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Stajaliste {

private:
    int brojStanice;
    string nazivStajalista;
    bool vazno;

public:


    // Konstruktor za postavljanje podataka
    Stajaliste(int brojStanice, const std::string& nazivStajalista, bool vazno)
        : brojStanice(brojStanice), nazivStajalista(nazivStajalista), vazno(vazno) {}

    friend std::ostream& operator<<(std::ostream& os, const Stajaliste& symbol) {
        os << symbol.brojStanice << "[" << symbol.nazivStajalista << "]" << symbol.vazno;
        return os;
    }


    // Metod za ispis informacija o stajalistu
    void ispisiStajaliste(string ime_fajla);
    int naziv();
    string naziv_stajalista();
};



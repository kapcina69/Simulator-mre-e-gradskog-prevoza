
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "klase_stajalista.h"
#include "klase_linija.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unordered_set>

using namespace std;



string linija_za_ispis(vector<Linija> linija, vector<int> vektor) {

    for (int i = 0; i < linija.size(); i++) {

        if (linija[i].stajalista == vektor) {
            return linija[i].naziv;
        }

    }

}

int udaljenost_u_vektoru(const std::vector<int>& vektor, int vrednost1, int vrednost2, vector<Linija> linija, string ime_fajla) {
    // Pronalaženje iteratora za date vrednosti
    auto it1 = std::find(vektor.begin(), vektor.end(), vrednost1);
    auto it2 = std::find(vektor.begin(), vektor.end(), vrednost2);

    // Provera da li su vrednosti pronaðene u vektoru
    if (it1 == vektor.end() || it2 == vektor.end()) {
        std::cout << "Nevažeæe vrednosti." << std::endl;
        return 0;
    }

    // Raèunanje indeksa
    int indeks1 = std::distance(vektor.begin(), it1);
    int indeks2 = std::distance(vektor.begin(), it2);
    int udaljenost = std::abs(indeks2 - indeks1);

    // Otvori fajl za upisivanje
    std::ofstream izlazniFajl(ime_fajla, ios::app);

    // Provera da li je fajl otvoren uspešno
    if (!izlazniFajl.is_open()) {
        std::cerr << "Nije moguæe otvoriti fajl za upisivanje." << std::endl;
        return 0;
    }

    izlazniFajl << linija_za_ispis(linija, vektor) << "->\n";
    if (indeks1 < indeks2) {
        for (int i = indeks1; i <= indeks2; ++i) {
            izlazniFajl << vektor[i] << " ";
        }
    }
    else {
        for (int i = indeks1; i >= indeks2; --i) {
            izlazniFajl << vektor[i] << " ";
        }
    }
    izlazniFajl << "\n";

    // Zatvori fajl
    izlazniFajl.close();
    return udaljenost;
}

int udaljenost_u_vektoru_pomoc(const std::vector<int>& vektor, int vrednost1, int vrednost2) {
    // Pronalaženje iteratora za date vrednosti
    auto it1 = std::find(vektor.begin(), vektor.end(), vrednost1);
    auto it2 = std::find(vektor.begin(), vektor.end(), vrednost2);
    int indeks1 = std::distance(vektor.begin(), it1);
    int indeks2 = std::distance(vektor.begin(), it2);
    int udaljenost = std::abs(indeks2 - indeks1);
    return udaljenost;
}

int minimalna_udaljenost(vector<int> vektor1, vector<int> vektor2, int pocetak, int kraj) {
    int ukupna_udaljenost;
    int min = 100;
    for (int i = 0; i < vektor1.size(); i++) {
        for (int j = 0; j < vektor2.size(); j++) {
            if (vektor1[i] == vektor2[j]) {
                ukupna_udaljenost = udaljenost_u_vektoru_pomoc(vektor1, pocetak, vektor1[i]) + udaljenost_u_vektoru_pomoc(vektor2, vektor1[i], kraj);
            }
            if (ukupna_udaljenost < min) {
                min = ukupna_udaljenost;
            }
        }
    }
    return min;
}

int minimalna_udaljenost11(vector<int> vektor1, vector<int> vektor2, int pocetak, int kraj) {
    int ukupna_udaljenost;
    int min = 100;
    int vrednostiij;
    for (int i = 0; i < vektor1.size(); i++) {
        for (int j = 0; j < vektor2.size(); j++) {
            if (vektor1[i] == vektor2[j]) {
                ukupna_udaljenost = udaljenost_u_vektoru_pomoc(vektor1, pocetak, vektor1[i]) + udaljenost_u_vektoru_pomoc(vektor2, vektor1[i], kraj);
            }
            if (ukupna_udaljenost < min) {
                min = ukupna_udaljenost;
                vrednostiij = i;

            }
        }
    }
    return vrednostiij;

}

void udaljenost_putanje(vector<int> vektor1, vector<int> vektor2, int pocetak, int kraj, vector<Linija> linija, string ime_fajla) {
    int ukupna_udaljenost;
    for (int i = 0; i < vektor1.size(); i++) {
        for (int j = 0; j < vektor2.size(); j++) {
            if (vektor1[i] == vektor2[j]) {
                ukupna_udaljenost = udaljenost_u_vektoru(vektor1, pocetak, vektor1[i], linija, ime_fajla) + udaljenost_u_vektoru(vektor2, vektor1[i], kraj, linija, ime_fajla);
                ofstream izlazniFajl(ime_fajla, std::ios::app);
                izlazniFajl << "\n";
                izlazniFajl.close();
                //return ukupna_udaljenost;
                //cout << "Presedanje preko " << vektor1[i] << ", ukupna udaljenost:"<<ukupna_udaljenost <<endl;
            }
        }
    }
}

string ispisiZajednickeElemente(const std::vector<int>& vektor1, const std::vector<int>& vektor2) {
    std::vector<int> zajednicki;
    std::unordered_set<int> ispisaniElementi;

    // Pretraga i pronalaženje zajednièkih elemenata
    for (int broj : vektor1) {
        if (std::find(vektor2.begin(), vektor2.end(), broj) != vektor2.end() &&
            ispisaniElementi.find(broj) == ispisaniElementi.end()) {
            zajednicki.push_back(broj);
            ispisaniElementi.insert(broj);
        }
    }

    // Sortiranje vektora u rastuæem poretku
    std::sort(zajednicki.begin(), zajednicki.end());

    // Ispis rezultata
    string string = "{!";
    for (int broj : zajednicki) {
        string = string + " " + to_string(broj);
    }
    string = string + " !}";
    return string;
}

std::vector<int> pretvoriUJedanVektor(const std::vector<std::vector<int>>& vektorVektora) {
    std::vector<int> rezultat;

    for (const auto& podvektor : vektorVektora) {
        for (int element : podvektor) {
            rezultat.push_back(element);
        }
    }

    return rezultat;
}

void informacije_stajaliste(int sifra, vector<Linija> linije, vector<int> vazna_stajalista, string ime_fajla) {
    std::ofstream izlazniFajl(ime_fajla, std::ios::app);

    izlazniFajl << sifra;
    izlazniFajl << " [ ";

    for (int i = 0; i < linije.size(); i++) {
        for (int j = 0; j < (linije[i].stajalista).size(); j++) {
            if (sifra == (linije[i].stajalista)[j]) {
                izlazniFajl << linije[i].naziv << " ";
            }
        }
    }
    izlazniFajl << "]";
    vector<int> vazna_stajalista_pod1;
    for (int i = 0; i < linije.size(); i++) {
        for (int j = 0; j < (linije[i].stajalista).size(); j++) {
            if (sifra == (linije[i].stajalista)[j]) {
                vazna_stajalista_pod1.push_back(linije[i].stajalista[j + 1]);
                vazna_stajalista_pod1.push_back(linije[i].stajalista[j - 1]);


            }
        }
    }
    //vector<int> novi_vektor_za_vazna_stajalista = pretvoriUJedanVektor(vazna_stajalista_pod1);
    vazna_stajalista_pod1.erase(
        std::remove_if(
            vazna_stajalista_pod1.begin(),
            vazna_stajalista_pod1.end(),
            [sifra](int x) { return x == sifra; }
        ),
        vazna_stajalista_pod1.end()
    );


    std::sort(vazna_stajalista_pod1.begin(), vazna_stajalista_pod1.end());

    vazna_stajalista_pod1.erase(std::unique(vazna_stajalista_pod1.begin(), vazna_stajalista_pod1.end()), vazna_stajalista_pod1.end());



    izlazniFajl << ispisiZajednickeElemente(vazna_stajalista_pod1, vazna_stajalista);

}

void informacije_linija(string linija, vector<Linija> linije, vector<Stajaliste> stajalista, string ime_fajla) {
    std::ofstream izlazniFajl(ime_fajla, std::ios::app);

    int pocetna_stanica;
    int krajnja_stanica;
    izlazniFajl << linija + " ";
    vector<int> nazivi_iz_linija;
    for (int i = 0; i < linije.size(); i++) {

        if (linija == linije[i].naziv) {
            for (int j = 0; j < (linije[i].stajalista).size(); j++) {
                nazivi_iz_linija.push_back(linije[i].stajalista[j]);
            }
            //cout << linije[i].stajalista[0] << "->" << linije[i].stajalista[(linije[i].stajalista).size() - 1];
            pocetna_stanica = linije[i].stajalista[0];
            krajnja_stanica = linije[i].stajalista[(linije[i].stajalista).size() - 1];

        }
    }
    for (int i = 0; i < stajalista.size(); i++) {

        if (pocetna_stanica == (stajalista[i]).naziv()) {

            izlazniFajl << stajalista[i].naziv_stajalista() + "->";

        }

    }
    for (int i = 0; i < stajalista.size(); i++) {

        if (krajnja_stanica == (stajalista[i]).naziv()) {

            izlazniFajl << stajalista[i].naziv_stajalista() << endl;

        }

    }
    for (int i = 0; i < nazivi_iz_linija.size(); i++) {

        for (int j = 0; j < stajalista.size(); j++) {

            if (nazivi_iz_linija[i] == stajalista[j].naziv()) {
                stajalista[j].ispisiStajaliste(ime_fajla);
            }

        }

    }


    izlazniFajl.close();


}

vector<Linija> popuni_linije() {
    string putanja;
    vector<Linija> linije;
    ifstream inputFile("linije.txt");

    if (!inputFile) {
        cerr << "Nije moguæe otvoriti fajl." << endl;
        return linije;
    }
    cout << "Ucitan je podrazumevani fajl sa linijama\n";

    string linija;
    while (getline(inputFile, linija)) {
        Linija novaLinija;
        istringstream stream(linija);
        stream >> novaLinija.naziv;

        int broj;
        while (stream >> broj) {
            novaLinija.stajalista.push_back(broj);
        }

        linije.push_back(novaLinija);
    }/*
    for (size_t i = 0; i < linije.size(); ++i) {
        std::cout << linije[i] << " \n";

    }*/

    return linije;
}

vector<Stajaliste> popuni_stajalista() {
    vector<Stajaliste> stajalista;
    ifstream inputFile("stajalista.txt");

    if (!inputFile.is_open()) {
        cerr << "Nije moguæe otvoriti fajl." << std::endl;
        //return 1;
    }
    cout << "Ucitan je podrazumevani fajl sa stajalistima.\n";

    string line;
    while (getline(inputFile, line)) {
        int brojStanice;
        string nazivStajalista;
        bool vazno = false;

        // Proèitaj broj stanice
        size_t spacePos = line.find(' ');
        brojStanice = std::stoi(line.substr(0, spacePos));

        // Proèitaj naziv stajalista
        size_t start = spacePos + 1;
        size_t end = line.find('[', start);
        if (end != string::npos) {
            nazivStajalista = line.substr(start, end - start - 1);
            vazno = true;
        }
        else {
            nazivStajalista = line.substr(start);
        }

        // Dodaj stajaliste u objekat klase Stajaliste
        Stajaliste stajaliste(brojStanice, nazivStajalista, vazno);
        if (vazno == true) {
            //vazna_stajalista.push_back(stajaliste);
            //vazna_stajalista_sifre.push_back(brojStanice);
        }
        stajalista.push_back(stajaliste);
    }
    return stajalista;
    /*
    for (size_t i = 0; i < stajalista.size(); ++i) {
        std::cout << stajalista[i] << " \n";

    }*/

    inputFile.close();



}

vector<int> popuni_vazna_stajalista_sifre() {
    vector<int> stajalista;
    ifstream inputFile("stajalista.txt");

    if (!inputFile.is_open()) {
        cerr << "Nije moguæe otvoriti fajl." << std::endl;
        //return 1;
    }
    cout << "Ucitan je podrazumevani fajl sa stajalistima.\n";

    string line;
    while (getline(inputFile, line)) {
        int brojStanice;
        string nazivStajalista;
        bool vazno = false;

        // Proèitaj broj stanice
        size_t spacePos = line.find(' ');
        brojStanice = std::stoi(line.substr(0, spacePos));

        // Proèitaj naziv stajalista
        size_t start = spacePos + 1;
        size_t end = line.find('[', start);
        if (end != string::npos) {
            nazivStajalista = line.substr(start, end - start - 1);
            vazno = true;
        }
        else {
            nazivStajalista = line.substr(start);
        }

        // Dodaj stajaliste u objekat klase Stajaliste
        Stajaliste stajaliste(brojStanice, nazivStajalista, vazno);
        if (vazno == true) {
            //vazna_stajalista.push_back(stajaliste);
            stajalista.push_back(brojStanice);
        }
    }
    return stajalista;
    /*
    for (size_t i = 0; i < stajalista.size(); ++i) {
        std::cout << stajalista[i] << " \n";

    }*/

    inputFile.close();



}

void racunanje_strategije2(vector<Linija> linije, int pocetno_stajaliste, int krajnje_stajaliste, string ime_fajla) {
    int lokacija_krajnja;
    int lokacija_pocetna;
    for (int i = 0; i < linije.size(); i++) {
        for (int j = 0; j < (linije[i].stajalista).size(); j++) {
            if ((linije[i].stajalista[j]) == pocetno_stajaliste) {
                lokacija_pocetna = j;
                for (int k = 0; k < (linije[i].stajalista).size(); k++) {
                    if ((linije[i].stajalista[k]) == krajnje_stajaliste) { // Kada se u istoj liniji nalazi i pocetno i krajnje stajaliste
                        lokacija_krajnja = k;
                        int udaljenost = udaljenost_u_vektoru(linije[i].stajalista, pocetno_stajaliste, krajnje_stajaliste, linije, ime_fajla);
                        ofstream izlazniFajl(ime_fajla, std::ios::app);
                        izlazniFajl << "\n";
                        izlazniFajl.close();
                        if (j < k) {
                            for (int l = lokacija_pocetna; l < lokacija_krajnja + 1; l++) {
                                // cout << linije[i].stajalista[l] << " ";
                            }
                            // cout << endl;
                            return;
                        }
                        else {
                            for (int l = lokacija_pocetna; l > lokacija_krajnja - 1; l--) {
                                //  cout << linije[i].stajalista[l] << " ";
                            }
                            //cout << endl;
                            return;
                        }
                    }
                }
            }
        }
    }
    vector<vector<int>> vektor_sa_pocetnim_stajalistima;
    vector<vector<int>> vektor_sa_krajnjim_stajalistima;

    for (int i = 0; i < linije.size(); i++) {
        for (int j = 0; j < (linije[i].stajalista).size(); j++) {
            if ((linije[i].stajalista[j]) == pocetno_stajaliste) {

                vektor_sa_pocetnim_stajalistima.push_back(linije[i].stajalista);
            }
        }
    }

    for (int i = 0; i < linije.size(); i++) {
        for (int j = 0; j < (linije[i].stajalista).size(); j++) {
            if ((linije[i].stajalista[j]) == krajnje_stajaliste) {

                vektor_sa_krajnjim_stajalistima.push_back(linije[i].stajalista);

            }
        }
    }
    int minimalna_udaljenost1 = 1000;
    int i1;
    int j1;
    for (int i = 0; i < vektor_sa_pocetnim_stajalistima.size(); i++) {
        for (int j = 0; j < vektor_sa_krajnjim_stajalistima.size(); j++) {

            if (minimalna_udaljenost(vektor_sa_pocetnim_stajalistima[i], vektor_sa_krajnjim_stajalistima[j], pocetno_stajaliste, krajnje_stajaliste) < minimalna_udaljenost1) {
                minimalna_udaljenost1 = minimalna_udaljenost(vektor_sa_pocetnim_stajalistima[i], vektor_sa_krajnjim_stajalistima[j], pocetno_stajaliste, krajnje_stajaliste);
                i1 = i;
                j1 = j;

            }
        }
    }
    int vrednostiij = minimalna_udaljenost11(vektor_sa_pocetnim_stajalistima[i1], vektor_sa_krajnjim_stajalistima[j1], pocetno_stajaliste, krajnje_stajaliste);
    int ukupna_udaljenost = udaljenost_u_vektoru(vektor_sa_pocetnim_stajalistima[i1], pocetno_stajaliste, vektor_sa_pocetnim_stajalistima[i1][vrednostiij], linije, ime_fajla) + udaljenost_u_vektoru(vektor_sa_krajnjim_stajalistima[j1], vektor_sa_pocetnim_stajalistima[j1][vrednostiij], krajnje_stajaliste, linije, ime_fajla);
    ofstream izlazniFajl(ime_fajla, std::ios::app);
    izlazniFajl << "\n";
    izlazniFajl.close();

}

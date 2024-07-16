
#include <iostream>
#include <string>
#include <vector>
#include "klase_stajalista.h"
#include "klase_linija.h"
#include "funkcije.h"


using namespace std;




int main() {


	cout << "Dobrodosli u simulator mreze gradskog prevoza. Molimo Vas, odaberite opciju:\n";
	cout << "1. Ucitavanje podataka o mrezi gradskog prevoza\n0. Kraj rada\n";
	int answer1;
ponovni_unos1:cin >> answer1;
	if (answer1 == 1) {
		vector<Stajaliste> stajalista = popuni_stajalista();
		//vector<Stajaliste> vazna_stajalista;
		vector<int> vazna_stajalista_sifre = popuni_vazna_stajalista_sifre();
		vector<Linija> linije = popuni_linije();
		cout << "Mreža gradskog prevoza je uspešno uèitana. Molimo Vas, odaberite opciju:\n1. Prikaz informacija o stajalištu\n2. Prikaz informacija o liniji gradskog prevoza\n3. Pronalazak putanje izmeðu dva stajališta\n0. Kraj rada\n";
		int answer2;
		cin >> answer2;
		if (answer2 == 1) {
			cout << "Molimo Vas, unesite oznaku stajalista èije informacije želite da prikažete.\n";
			int unesi_sifru_stajalista;
			cin >> unesi_sifru_stajalista;
			string ime_fajla_stajaliste = "stajaliste_" + to_string(unesi_sifru_stajalista) + ".txt";
			std::ifstream proveraFajla(ime_fajla_stajaliste);

			if (proveraFajla.good()) {
				// Fajl postoji, pa ga obriši
				proveraFajla.close();
				std::remove(ime_fajla_stajaliste.c_str());
			}
			informacije_stajaliste(unesi_sifru_stajalista, linije, vazna_stajalista_sifre, ime_fajla_stajaliste);

		}
		if (answer2 == 2) {
			cout << "Molimo Vas, unesite oznaku liniju èije informacije želite da prikažete.\n";
			string unesi_liniju;
			cin >> unesi_liniju;
			string ime_fajla_linija = "linija_" + unesi_liniju + ".txt";
			std::ifstream proveraFajla(ime_fajla_linija);

			if (proveraFajla.good()) {
				// Fajl postoji, pa ga obriši
				proveraFajla.close();
				std::remove(ime_fajla_linija.c_str());
			}
			informacije_linija(unesi_liniju, linije, stajalista, ime_fajla_linija);


		}
		if (answer2 == 3) {
			cout << "Molimo Vas, unesite pocetno stajaliste:\n";
			int pocetno_stajaliste;
			int lokacija_pocetna;
			cin >> pocetno_stajaliste;
			cout << "Molimo Vas, unesite krajnje stajaliste:\n";
			int krajnje_stajaliste;
			int lokacija_krajnja;
			cin >> krajnje_stajaliste;
			int strategija;
			cout << "\nUnesite strategiju\n1.Bilo koja putanja\n2.Najkraca putanja\n3.Putanja koja obilazi vazna stajalista.\n";
			cin >> strategija;
			string ime_fajla = "putanja_" + to_string(pocetno_stajaliste) + "_" + to_string(krajnje_stajaliste) + ".txt";
			// Provera postojanja fajla
			std::ifstream proveraFajla(ime_fajla);

			if (proveraFajla.good()) {
				// Fajl postoji, pa ga obriši
				proveraFajla.close();
				std::remove(ime_fajla.c_str());
			}
			if (strategija == 1) {
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
									//cout << "Udaljenost:" << udaljenost << endl;
									//cout << "U jednoj liniji se nalazi i pocetno i krajnje stajaliste:\n";
									//cout << linije[i].naziv << "->" << endl;
									if (j < k) {
										for (int l = lokacija_pocetna; l < lokacija_krajnja + 1; l++) {
											//cout << linije[i].stajalista[l] << " ";
										}
										//cout << endl;
										return 0;
									}
									else {
										for (int l = lokacija_pocetna; l > lokacija_krajnja - 1; l--) {
											//cout << linije[i].stajalista[l] << " ";
										}
										//cout << endl;
										return 0;
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

				for (int i = 0; i < vektor_sa_pocetnim_stajalistima.size(); i++) {
					for (int j = 0; j < vektor_sa_krajnjim_stajalistima.size(); j++) {
						udaljenost_putanje(vektor_sa_pocetnim_stajalistima[i], vektor_sa_krajnjim_stajalistima[j], pocetno_stajaliste, krajnje_stajaliste, linije, ime_fajla);
						cout << endl;
					}
				}

			}
			else if (strategija == 2) {

				racunanje_strategije2(linije, pocetno_stajaliste, krajnje_stajaliste, ime_fajla);
			}
			else if (strategija == 3) {
				cout << "Vazna stajalista su:";
				for (int i = 0; i < vazna_stajalista_sifre.size(); i++) {
					cout << vazna_stajalista_sifre[i] << " ";
				}
				racunanje_strategije2(linije, pocetno_stajaliste, vazna_stajalista_sifre[0], ime_fajla);
				for (int i = 1; i < vazna_stajalista_sifre.size(); i++) {
					racunanje_strategije2(linije, vazna_stajalista_sifre[i - 1], vazna_stajalista_sifre[i], ime_fajla);
				}


			}

		}



	}








	else if (answer1 == 0) {

		return 1;

	}
	else {
		cout << "Greska. Treba uneti 0 ili 1.\n";
		goto ponovni_unos1;
	}



	return 0;
}

#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Adresat.h"
#include "Uzytkownik.h"
#include "PlikiZAdresatami.h"

#include "UzytkownikMenedzer.h"
#include "PlikiZUzytkownikami.h"

using namespace std;

class AdresatMenedzer
{
    int idAdresata, idUsuwanegoAdresata, idOstatniegoAdresata, iloscSzukanychAdresatow, szukaneId, liniaDoUsuniecia;
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA ;
    string noweImie, noweNazwisko, nowyNumerTelefonu, nowyEmail, nowyAdres;
    vector <Adresat> adresaci;

    Adresat podajDaneNowegoAdresata();
    PlikiZAdresatami plikiZAdresatami;

public:
    AdresatMenedzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika)
    : ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika), plikiZAdresatami(nazwaPlikuZAdresatami) {
        adresaci = plikiZAdresatami.wczytajAdresatowZPliku(idZalogowanegoUzytkownika);
        iloscSzukanychAdresatow = 0, szukaneId = 0, liniaDoUsuniecia = 0;
    };
    void dodajAdresata();
    void wypiszWszystkichAdresatow();
    Adresat wczytajAdresatowZPliku();

    void ustawIdZalogowanegoUzytkownika (int noweIdZalogowanegoUzytkownika);
    int pobierzIdZalogowanegoUzytkownika();
    int pobierzIdNowegoAdresata();
    void wyswietlWszystkichAdresatow();
    void wyszukajPoImieniu();
    void wyszukajPoNazwisku();
    void usunAdresata();
    void edytujAdresata();

};

#endif

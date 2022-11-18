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
    int idAdresata;
    int idZalogowanegoUzytkownika;
    vector <Adresat> adresaci;

    Adresat podajDaneNowegoAdresata();
    int pobierzIdNowegoAdresata();
    PlikiZAdresatami plikiZAdresatami;

public:
    AdresatMenedzer(string nazwaPlikuZAdresatami) : plikiZAdresatami(nazwaPlikuZAdresatami) {
    };
    void dodajAdresata();
    void wypiszWszystkichAdresatow();
    Adresat wczytajAdresatowZPliku();

    void ustawIdZalogowanegoUzytkownika (int noweIdZalogowanegoUzytkownika);
    int pobierzIdZalogowanegoUzytkownika();
    void wyswietlWszystkichAdresatow();

};

#endif

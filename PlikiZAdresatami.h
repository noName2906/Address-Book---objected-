#ifndef PLIKIZADRESATAMI_H
#define PLIKIZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Adresat.h"
#include "Uzytkownik.h"
#include "PlikiZUzytkownikami.h"
#include "MetodyPomocnicze.h"
#include "PlikTekstowy.h"

using namespace std;

class PlikiZAdresatami :public PlikTekstowy
{
    const string nazwaPlikuZAdresatami;
   int idOstatniegoAdresata;

    vector <Adresat> adresaci;
    bool czyPlikJestPusty();
    string zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(Adresat adresat);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);

public:
    PlikiZAdresatami(string  NAZWAPLIKUZADRESATAMI)
    : nazwaPlikuZAdresatami(NAZWAPLIKUZADRESATAMI) {};
    void dopiszAdresataDoPliku(Adresat adresat);
    vector <Adresat> wczytajAdresatowZPliku(int idZalogowanegoUzytkownika);
    vector <Adresat> wczytajWszystkichAdresatowZPliku();
    int podajIdOstatniegoAdresata();
    void zapiszWszystkichAdresatowDoPliku(vector <Adresat> adresaci);
};

#endif

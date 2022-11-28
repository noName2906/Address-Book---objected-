#include "PlikiZAdresatami.h"

void PlikiZAdresatami::dopiszAdresataDoPliku(Adresat adresat)
{
    string liniaZDanymiAdresata = "";
    fstream plik;
    plik.open(nazwaPliku.c_str(), ios::app);

    if (plik.good() == true)
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(adresat);

        if (PlikTekstowy::czyPlikJestPusty() == true)
        {
            plik << liniaZDanymiAdresata;
        }
        else
        {
            plik << liniaZDanymiAdresata << endl; ;
        }
    }
    else
        cout << "Nie udalo sie otworzyc pliku " << nazwaPliku << " i zapisac w nim danych." << endl;
    plik.close();
}

string PlikiZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(Adresat adresat)
{
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdAdresata())+ '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdUzytkownika())+ '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}

Adresat PlikiZAdresatami::pobierzDaneAdresata(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (unsigned int pozycjaZnaku = 0; pozycjaZnaku < daneJednegoAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneJednegoAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaAdresata += daneJednegoAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejAdresata)
            {
            case 1:
                adresat.ustawIdAdresata(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

vector <Adresat> PlikiZAdresatami::wczytajWszystkichAdresatowZPliku()
{
    Adresat adresat;
    string linia = "";
    int i = 0;
    int nr_linii = 1;
    fstream plik;

    adresaci.clear();
    plik.open(nazwaPliku.c_str(), ios::in);

    if (plik.good() == true)
    {
        while (getline(plik, linia, '|'))
        {
            switch(nr_linii)
            {
            case 1:
                adresat.ustawIdAdresata(atoi(linia.c_str()));
                break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(linia.c_str()));
                break;
            case 3:
                adresat.ustawImie(linia);
                break;
            case 4:
                adresat.ustawNazwisko(linia);
                break;
            case 5:
                adresat.ustawNumerTelefonu(linia);
                break;
            case 6:
                adresat.ustawEmail(linia);
                break;
            case 7:
                adresat.ustawAdres(linia);
                adresaci.push_back(adresat);
                nr_linii = 0;
                getline(plik, linia);
                i++;
                break;
            }
            nr_linii++;
        }
        plik.close();
    }
    return adresaci;
}

vector <Adresat> PlikiZAdresatami::wczytajAdresatowZPliku(int idZalogowanegoUzytkownika)
{
    Adresat adresat;
    string linia = "";
    int i = 0;
    int nr_linii = 1;
    fstream plik;

    plik.open(nazwaPliku.c_str(), ios::in);

    if (plik.good() == true)
    {
        adresaci.clear();
        while (getline(plik, linia, '|'))
        {
            switch(nr_linii)
            {
            case 1:
                adresat.ustawIdAdresata(atoi(linia.c_str()));
                break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(linia.c_str()));
                break;
            case 3:
                adresat.ustawImie(linia);
                break;
            case 4:
                adresat.ustawNazwisko(linia);
                break;
            case 5:
                adresat.ustawNumerTelefonu(linia);
                break;
            case 6:
                adresat.ustawEmail(linia);
                break;
            case 7:
                adresat.ustawAdres(linia);
                if (adresat.pobierzIdUzytkownika() == idZalogowanegoUzytkownika) {
                    adresaci.push_back(adresat);}
                nr_linii = 0;
                getline(plik, linia);
                i++;
                break;
            }
            nr_linii++;
        }
        plik.close();
    }
    return adresaci;
}

int PlikiZAdresatami::podajIdOstatniegoAdresata()
{
    Adresat adresat;
    string linia = "";
    int i = 0;
    int nr_linii = 1;
    fstream plik;

    plik.open(nazwaPliku.c_str(), ios::in);

    if (plik.good() == true)
    {
        while (getline(plik, linia, '|'))
        {
            switch(nr_linii)
            {
            case 1:
                adresat.ustawIdAdresata(atoi(linia.c_str()));
                break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(linia.c_str()));
                break;
            case 3:
                adresat.ustawImie(linia);
                break;
            case 4:
                adresat.ustawNazwisko(linia);
                break;
            case 5:
                adresat.ustawNumerTelefonu(linia);
                break;
            case 6:
                adresat.ustawEmail(linia);
                break;
            case 7:
                adresat.ustawAdres(linia);
                nr_linii = 0;
                getline(plik, linia);
                i++;
                break;
            }
            nr_linii++;
        }
        plik.close();
        idOstatniegoAdresata = adresat.pobierzIdAdresata();
    }
    else
    {
        idOstatniegoAdresata = 0;
    }
    return idOstatniegoAdresata;
}

void PlikiZAdresatami::usunAdresataZPliku(int idUsuwanegoAdresata)
{
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";
    int numerWczytanejLinii = 1;

    odczytywanyPlikTekstowy.open("listaAdresatow.txt", ios::in);
    tymczasowyPlikTekstowy.open ("Adresaci_tymczasowo.txt", ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good())
    {
        while (getline(odczytywanyPlikTekstowy, wczytanaLinia))
        {
            if (MetodyPomocnicze::konwersjaStringNaInt(wczytanaLinia.substr(0,'|')) != idUsuwanegoAdresata)
            {
                numerWczytanejLinii != 1 ? tymczasowyPlikTekstowy << endl << wczytanaLinia : tymczasowyPlikTekstowy << wczytanaLinia;
                idOstatniegoAdresata = MetodyPomocnicze::konwersjaStringNaInt(wczytanaLinia.substr(0,'|'));
            }
            numerWczytanejLinii++;
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        if (remove("listaAdresatow.txt") == 0) {}
        else
            cout << "Nie usunieto poprawnie pliku" << endl;

        if (rename("Adresaci_tymczasowo.txt", "listaAdresatow.txt") == 0) {}
        else
            cout << "Nazwa pliku nie zostala zmieniona." << endl;
    }
}

void PlikiZAdresatami::edytujAdresataWPliku(Adresat adresat)
{
    fstream odczytywnyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";
    string zmodyfikowaneDaneAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(adresat);
    int numerWczytanejLinii = 1;
    int idEdytowanegoAdresata = adresat.pobierzIdAdresata();

    odczytywnyPlikTekstowy.open("listaAdresatow.txt", ios::in);
    tymczasowyPlikTekstowy.open("Adresaci_tymczasowo.txt", ios::out | ios::app);

    if (odczytywnyPlikTekstowy.good()) {
        while (getline(odczytywnyPlikTekstowy, wczytanaLinia)) {
            if (MetodyPomocnicze::konwersjaStringNaInt(wczytanaLinia.substr(0,'|')) != idEdytowanegoAdresata) {
                numerWczytanejLinii !=1 ? tymczasowyPlikTekstowy << wczytanaLinia : tymczasowyPlikTekstowy << wczytanaLinia << endl;
            } else {
                numerWczytanejLinii !=1 ? tymczasowyPlikTekstowy << zmodyfikowaneDaneAdresata : tymczasowyPlikTekstowy << zmodyfikowaneDaneAdresata << endl;
                }
            }
            numerWczytanejLinii++;
    }
    odczytywnyPlikTekstowy.close();
    tymczasowyPlikTekstowy.close();

    if (remove("listaAdresatow.txt") == 0) {}
        else
            cout << "Nie usunieto poprawnie pliku" << endl;

        if (rename("Adresaci_tymczasowo.txt", "listaAdresatow.txt") == 0) {}
        else
            cout << "Nazwa pliku nie zostala zmieniona." << endl;
}




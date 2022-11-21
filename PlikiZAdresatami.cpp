#include "PlikiZAdresatami.h"

void PlikiZAdresatami::dopiszAdresataDoPliku(Adresat adresat)
{
    string liniaZDanymiAdresata = "";
    fstream plik;
    plik.open(nazwaPlikuZAdresatami.c_str(), ios::app);

    if (plik.good() == true)
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(adresat);

        if (czyPlikJestPusty() == true)
        {
            plik << liniaZDanymiAdresata;
        }
        else
        {
            plik << liniaZDanymiAdresata << endl; ;
        }
    }
    else
        cout << "Nie udalo sie otworzyc pliku " << nazwaPlikuZAdresatami << " i zapisac w nim danych." << endl;
    plik.close();
}

bool PlikiZAdresatami::czyPlikJestPusty()
{
    fstream plik;
    plik.seekg(0, ios::end);
    if (plik.tellg() == 0)
        return true;
    else
        return false;
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

vector <Adresat> PlikiZAdresatami::wczytajAdresatowZPliku()
{
    Adresat adresat;
    string linia = "";
    int i = 0;
    int nr_linii = 1;
    fstream plik;

    plik.open(nazwaPlikuZAdresatami.c_str(), ios::in);

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

void PlikiZAdresatami::zapiszWszystkichAdresatowDoPliku(vector <Adresat> adresaci)
{
    Uzytkownik uzytkownik;
    Adresat adresat;
    vector <Uzytkownik> uzytkownicy;
    fstream plik;
    plik.open(nazwaPlikuZAdresatami.c_str(), ios::out);

    if (plik.good() == true)
    {

        cout << adresaci.size() << endl;

        for (unsigned int i = 0; i < adresaci.size(); i++)
        {
            plik << adresaci[i].pobierzIdAdresata() << "|" << uzytkownicy[i].pobierzId() << "|" << adresaci[i].pobierzImie() << "|" << adresaci[i].pobierzNazwisko() << adresaci[i].pobierzNumerTelefonu() << adresaci[i].pobierzEmail() << adresaci[i].pobierzAdres() << endl;
        }
    }
    else
        cout << "Nie udalo sie otworzyc pliku " << nazwaPlikuZAdresatami << " i zapisac w nim danych." << endl;
    plik.close();
}



#include "PlikiZUzytkownikami.h"

void PlikiZUzytkownikami::dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik)
{
    string liniaZDanymiUzytkownika = "";
    fstream plik;
    plik.open(nazwaPlikuZUzytkownikami.c_str(), ios::app);

    if (plik.good() == true)
    {
        liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(uzytkownik);

        if (PlikTekstowy::czyPlikJestPusty() == true)
        {
            plik << liniaZDanymiUzytkownika;
        }
        else
        {
            plik << liniaZDanymiUzytkownika << endl; ;
        }
    }
    else
        cout << "Nie udalo sie otworzyc pliku " << nazwaPlikuZUzytkownikami << " i zapisac w nim danych." << endl;
    plik.close();
}

/* bool PlikiZUzytkownikami::czyPlikJestPusty()
{
    fstream plikTekstowy;
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
} */

string PlikiZUzytkownikami::zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik)
{
    string liniaZDanymiUzytkownika = "";

    liniaZDanymiUzytkownika += MetodyPomocnicze::konwerjsaIntNaString(uzytkownik.pobierzId())+ '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzLogin() + '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzHaslo() + '|';

    return liniaZDanymiUzytkownika;
}

Uzytkownik PlikiZUzytkownikami::pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami)
{
    Uzytkownik uzytkownik;
    string pojedynczaDanaUzytkownika = "";
    int numerPojedynczejDanejUzytkownika = 1;

    for (unsigned int pozycjaZnaku = 0; pozycjaZnaku < daneJednegoUzytkownikaOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaUzytkownika += daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejUzytkownika)
            {
            case 1:
                uzytkownik.ustawId(atoi(pojedynczaDanaUzytkownika.c_str()));
                break;
            case 2:
                uzytkownik.ustawLogin(pojedynczaDanaUzytkownika);
                break;
            case 3:
                uzytkownik.ustawHaslo(pojedynczaDanaUzytkownika);
                break;
            }
            pojedynczaDanaUzytkownika = "";
            numerPojedynczejDanejUzytkownika++;
        }
    }
    return uzytkownik;
}

vector <Uzytkownik> PlikiZUzytkownikami::wczytajUzytkownikowZPliku()
{
    Uzytkownik uzytkownik;
    vector <Uzytkownik> uzytkownicy;
    string daneJednegoUzytkownikaOddzielonePionowymiKreskami = "";
    fstream plik;

    plik.open(nazwaPlikuZUzytkownikami.c_str(), ios::in);

    if (plik.good() == true)
    {
        while (getline(plik, daneJednegoUzytkownikaOddzielonePionowymiKreskami))
        {
            uzytkownik = pobierzDaneUzytkownika(daneJednegoUzytkownikaOddzielonePionowymiKreskami);
            uzytkownicy.push_back(uzytkownik);
        }
        plik.close();
    }
    return uzytkownicy;
}

string PlikiZUzytkownikami::wczytajLinie()
{
    string wejscie = "";
    cin.sync();
    getline(cin, wejscie);
    return wejscie;
}

void PlikiZUzytkownikami::zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> uzytkownicy)
{
    Uzytkownik uzytkownik;
    fstream plik;
    plik.open(nazwaPlikuZUzytkownikami.c_str(), ios::out);

    if (plik.good() == true)
    {

        cout << uzytkownicy.size() << endl;

        for (unsigned int i = 0; i < uzytkownicy.size(); i++)
        {
            plik << uzytkownicy[i].pobierzId() << "|" << uzytkownicy[i].pobierzLogin() << "|" << uzytkownicy[i].pobierzHaslo() << "|" << endl;
        }
    }
    else
        cout << "Nie udalo sie otworzyc pliku " << nazwaPlikuZUzytkownikami << " i zapisac w nim danych." << endl;
    plik.close();
}



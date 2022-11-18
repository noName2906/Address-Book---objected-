#include "AdresatMenedzer.h"

void AdresatMenedzer::dodajAdresata()
{
    Adresat adresat = podajDaneNowegoAdresata();
    adresaci.push_back(adresat);

    plikiZAdresatami.dopiszAdresataDoPliku(adresat);

    cout << endl << "Adresat zostal dodany pomyslnie" << endl << endl;
    system("pause");
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata()
{
    Adresat adresat;
    string imie, nazwisko, numerTelefonu, email, adres;

    while (true)
    {
        system ("cls");
        cout << ">>>>> DODAWANIE ADRESATA <<<<<" << endl;
        cout << "------------------------------" << endl;
        cin.sync();
        cout << "Podaj imie: ";
        getline(cin, imie);
        adresat.ustawImie(imie);
        cout << "Podaj nazwisko: ";
        getline(cin, nazwisko);
        adresat.ustawNazwisko(nazwisko);
        cout << "Podaj numer telefonu: ";
        getline(cin, numerTelefonu);
        adresat.ustawNumerTelefonu(numerTelefonu);
        cout << "Podaj email: ";
        getline(cin, email);
        adresat.ustawEmail(email);
        cout << "Podaj adres: ";
        getline(cin, adres);
        adresat.ustawAdres(adres);
        cout << endl << endl;

        adresat.ustawIdAdresata(pobierzIdNowegoAdresata());
        adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);
        adresat.ustawImie(imie);
        adresat.ustawNazwisko(nazwisko);
        adresat.ustawNumerTelefonu(numerTelefonu);
        adresat.ustawEmail(email);
        adresat.ustawAdres(adres);

    return adresat;
    }
}

int AdresatMenedzer::pobierzIdNowegoAdresata()
{
    vector <Adresat> adresaci = plikiZAdresatami.wczytajAdresatowZPliku();
    if (adresaci.empty() == true)
        return 1;
    else
        return adresaci.back().pobierzIdAdresata() + 1;
}

void AdresatMenedzer::wyswietlWszystkichAdresatow()
{
    vector <Adresat> adresaci = plikiZAdresatami.wczytajAdresatowZPliku();

    if (adresaci.empty() == true)
    {
        system("cls");
        cout << ">>>>> MENU UZYTKOWNIKA <<<<<" << endl;
        cout << "----------------------------" << endl;
        cout << "Brak listy. Dodaj adresatow korzystajac z opcji '1'" << endl << endl;
        system ("pause");
    }
    else
    {
        system("cls");
        cout << ">>>>> MENU UZYTKOWNIKA <<<<<" << endl;
        cout << "----------------------------" << endl;

        for (unsigned int i = 0; i < adresaci.size(); i++)
        {
            if (adresaci[i].pobierzIdUzytkownika() == idZalogowanegoUzytkownika)
            {
                cout << "ID adresata:        " << adresaci[i].pobierzIdAdresata() << endl;
                cout << "Imie:               " << adresaci[i].pobierzImie() << endl;
                cout << "Nazwisko:           " << adresaci[i].pobierzNazwisko() << endl;
                cout << "Numer telefonu:     " << adresaci[i].pobierzNumerTelefonu() << endl;
                cout << "Email:              " << adresaci[i].pobierzEmail() << endl;
                cout << "Adres:              " << adresaci[i].pobierzAdres() << endl;
                cout << "--------------------" << endl;
            }
            else if (adresaci[i].pobierzIdUzytkownika() != idZalogowanegoUzytkownika && adresaci[i].pobierzIdUzytkownika() == adresaci.back().pobierzIdUzytkownika())
                {
                system("cls");
                cout << ">>>>> MENU UZYTKOWNIKA <<<<<" << endl;
                cout << "----------------------------" << endl;
                cout << "Brak listy. Dodaj adresatow korzystajac z opcji '1'" << endl << endl;
                }
        }
        system ("pause");
    }
}

void AdresatMenedzer::ustawIdZalogowanegoUzytkownika(int noweIdZalogowanegoUzytkownika) {
    idZalogowanegoUzytkownika = noweIdZalogowanegoUzytkownika;
}

int AdresatMenedzer::pobierzIdZalogowanegoUzytkownika() {
    return idZalogowanegoUzytkownika;
}

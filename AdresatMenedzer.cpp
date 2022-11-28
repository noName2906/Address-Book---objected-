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
        imie = MetodyPomocnicze::wczytajLinie();
        adresat.ustawImie(imie);
        cout << "Podaj nazwisko: ";
        nazwisko = MetodyPomocnicze::wczytajLinie();
        adresat.ustawNazwisko(nazwisko);
        cout << "Podaj numer telefonu: ";
        numerTelefonu = MetodyPomocnicze::wczytajLinie();
        adresat.ustawNumerTelefonu(numerTelefonu);
        cout << "Podaj email: ";
        email = MetodyPomocnicze::wczytajLinie();
        adresat.ustawEmail(email);
        cout << "Podaj adres: ";
        adres = MetodyPomocnicze::wczytajLinie();
        adresat.ustawAdres(adres);
        cout << endl << endl;

        adresat.ustawIdAdresata(pobierzIdNowegoAdresata());
        adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);
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
    int idOstatniegoAdresata = plikiZAdresatami.podajIdOstatniegoAdresata();
    return idOstatniegoAdresata + 1;
}

void AdresatMenedzer::wyswietlWszystkichAdresatow()
{
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

            cout << "ID adresata:        " << adresaci[i].pobierzIdAdresata() << endl;
            cout << "Imie:               " << adresaci[i].pobierzImie() << endl;
            cout << "Nazwisko:           " << adresaci[i].pobierzNazwisko() << endl;
            cout << "Numer telefonu:     " << adresaci[i].pobierzNumerTelefonu() << endl;
            cout << "Email:              " << adresaci[i].pobierzEmail() << endl;
            cout << "Adres:              " << adresaci[i].pobierzAdres() << endl;
            cout << "--------------------" << endl;
        }
        system ("pause");
    }
}

void AdresatMenedzer::wyszukajPoImieniu()
{
    system("cls");
    cout << ">>>>> MENU UZYTKOWNIKA <<<<<" << endl;
    cout << "----------------------------" << endl;
    cout << "Podaj szukane imie: ";
    string szukaneImie = MetodyPomocnicze::wczytajLinie();


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
            if (adresaci[i].pobierzImie() == szukaneImie)
            {
                cout << "ID adresata:        " << adresaci[i].pobierzIdAdresata() << endl;
                cout << "Imie:               " << adresaci[i].pobierzImie() << endl;
                cout << "Nazwisko:           " << adresaci[i].pobierzNazwisko() << endl;
                cout << "Numer telefonu:     " << adresaci[i].pobierzNumerTelefonu() << endl;
                cout << "Email:              " << adresaci[i].pobierzEmail() << endl;
                cout << "Adres:              " << adresaci[i].pobierzAdres() << endl;
                cout << "--------------------" << endl;
                iloscSzukanychAdresatow++;
            }
        }
        cout << "Ilosc adresatow o imieniu " << szukaneImie << ": " << iloscSzukanychAdresatow << endl;
        system ("pause");
    }
}

void AdresatMenedzer::wyszukajPoNazwisku()
{
    system("cls");
    cout << ">>>>> MENU UZYTKOWNIKA <<<<<" << endl;
    cout << "----------------------------" << endl;
    cout << "Podaj szukane nazwisko: ";
    string szukaneNazwisko = MetodyPomocnicze::wczytajLinie();


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
            if (adresaci[i].pobierzNazwisko() == szukaneNazwisko)
            {
                cout << "ID adresata:        " << adresaci[i].pobierzIdAdresata() << endl;
                cout << "Imie:               " << adresaci[i].pobierzImie() << endl;
                cout << "Nazwisko:           " << adresaci[i].pobierzNazwisko() << endl;
                cout << "Numer telefonu:     " << adresaci[i].pobierzNumerTelefonu() << endl;
                cout << "Email:              " << adresaci[i].pobierzEmail() << endl;
                cout << "Adres:              " << adresaci[i].pobierzAdres() << endl;
                cout << "--------------------" << endl;
                iloscSzukanychAdresatow++;
            }
        }
        cout << "Ilosc adresatow o nazwisku " << szukaneNazwisko << ": " << iloscSzukanychAdresatow << endl;
        system ("pause");
    }
}

void  AdresatMenedzer::usunAdresata()
{
    system ("cls");
    cout << ">>>>> USUN ADRESATA <<<<<" << endl;
    cout << "-------------------------" << endl;
    cout << "Podaj ID adresata ktorego chcesz usunac: ";
    cin >> idUsuwanegoAdresata;
    cout << endl;

    if (adresaci.empty() == true)
    {
        cout << "Brak utworzonej ksiazki adresatow!" << endl;
        Sleep (2500);
    }

    for (unsigned int i = 0; i < adresaci.size(); i++)
    {
        if (adresaci[i].pobierzIdAdresata() == idUsuwanegoAdresata)
        {
            system ("cls");
            cout << ">>>>> USUN ADRESATA <<<<<" << endl;
            cout << "-------------------------" << endl;
            cout << "ID adresata:             " << adresaci[i].pobierzIdAdresata() << endl;
            cout << "Imie:                    " << adresaci[i].pobierzImie() << endl;
            cout << "Nazwisko:                " << adresaci[i].pobierzNazwisko() << endl;
            cout << "Numer telefonu:          " << adresaci[i].pobierzNumerTelefonu() << endl;
            cout << "Email:                   " << adresaci[i].pobierzEmail() << endl;
            cout << "Adres:                   " << adresaci[i].pobierzAdres() << endl;
            cout << "-------------------------" << endl;
            cout << "Czy na pewno chcesz usunac powyzszy adres?" << endl << endl;
            cout << "Wcisnij 't' aby potwierdzic: ";
            string wybor = MetodyPomocnicze::wczytajLinie();

            if (wybor == "t")
            {
                plikiZAdresatami.usunAdresataZPliku(idUsuwanegoAdresata);
                adresaci = plikiZAdresatami.wczytajAdresatowZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);

                system ("cls");
                cout << ">>>>> USUN ADRESATA <<<<<" << endl;
                cout << "-------------------------" << endl;
                cout << "Kontakt zostal usuniety prawidlowo" << endl;
                Sleep (2500);
            }

        }
    }
}

void AdresatMenedzer::edytujAdresata()
{
    Adresat adresat;
    system ("cls");
    cout << ">>>>> EDYTUJ ADRESATA <<<<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Podaj ID osoby, ktorej dane chcesz edytowac: ";
    cin >> szukaneId;
    cout << endl;

    if (adresaci.empty())
    {
        cout << "Brak utworzonej ksiazki adresatow!" << endl;
        Sleep (2500);
    }

    for (unsigned int i = 0; i < adresaci.size(); i++)
    {
        if (adresaci[i].pobierzIdAdresata() == szukaneId && adresaci[i].pobierzIdUzytkownika() == ID_ZALOGOWANEGO_UZYTKOWNIKA)
        {
            system ("cls");
            cout << ">>>>> EDYTUJ ADRESATA <<<<<" << endl;
            cout << "-------------------------" << endl;
            cout << "1. Imie:                    " << adresaci[i].pobierzImie() << endl;
            cout << "2. Nazwisko:                " << adresaci[i].pobierzNazwisko() << endl;
            cout << "3. Numer telefonu:          " << adresaci[i].pobierzNumerTelefonu() << endl;
            cout << "4. Email:                   " << adresaci[i].pobierzEmail() << endl;
            cout << "5. Adres:                   " << adresaci[i].pobierzAdres() << endl;
            cout << "-------------------------" << endl;
            cout << "Podaj numer elementu (1-5), ktory chcesz edytowac: ";
            string wybor = MetodyPomocnicze::wczytajLinie();
            cout << endl;

            adresat.ustawIdAdresata(adresaci[i].pobierzIdAdresata());
            adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);
            adresat.ustawImie(adresaci[i].pobierzImie());
            adresat.ustawNazwisko(adresaci[i].pobierzNazwisko());
            adresat.ustawNumerTelefonu(adresaci[i].pobierzNumerTelefonu());
            adresat.ustawEmail(adresaci[i].pobierzEmail());
            adresat.ustawAdres(adresaci[i].pobierzAdres());

            cin.sync();
            if (wybor == "1")
            {
                cout << "Podaj nowe imie: ";
                getline(cin, noweImie);
                adresaci[i].ustawImie(noweImie);
                adresat.ustawImie(noweImie);
            }
            else if (wybor == "2")
            {
                cout << "Podaj nowe nazwisko: ";
                getline(cin, noweNazwisko);
                adresaci[i].ustawNazwisko(noweNazwisko);
                adresat.ustawNazwisko(noweNazwisko);
            }
            else if (wybor == "3")
            {
                cout << "Podaj nowy numer telefonu: ";
                getline(cin, nowyNumerTelefonu);
                adresaci[i].ustawNumerTelefonu(nowyNumerTelefonu);
                adresat.ustawNumerTelefonu(nowyNumerTelefonu);
            }
            else if (wybor == "4")
            {
                cout << "Podaj nowy adres Email: ";
                getline(cin, nowyEmail);
                adresaci[i].ustawEmail(nowyEmail);
                adresat.ustawEmail(nowyEmail);
            }
            else if (wybor == "5")
            {
                cout << "Podaj nowy adres: ";
                getline(cin, nowyAdres);
                adresaci[i].ustawAdres(nowyAdres);
                adresat.ustawAdres(nowyAdres);
            }
            else
            {
                cout << "Podales niepoprawna wartosc z przedzialu 1-5! Sprobuj jeszcze raz." << endl;
                Sleep(2000);
                break;
            }

            if(wybor == "1" || wybor == "2" || wybor == "3" || wybor == "4" || wybor == "5")
            {
                plikiZAdresatami.edytujAdresataWPliku(adresat);
                plikiZAdresatami.wczytajAdresatowZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
                system ("cls");
                cout << ">>>>> EDYTUJ ADRESATA <<<<<" << endl;
                cout << "-------------------------" << endl;
                cout << "Edycja kontaktu przebiegla pomyslnie" << endl;
                Sleep (2500);
                break;
            }
        }
    }
}


void AdresatMenedzer::ustawIdZalogowanegoUzytkownika(int noweIdZalogowanegoUzytkownika) {
    noweIdZalogowanegoUzytkownika = pobierzIdZalogowanegoUzytkownika();
    adresaci = plikiZAdresatami.wczytajAdresatowZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
}

int AdresatMenedzer::pobierzIdZalogowanegoUzytkownika() {
    return ID_ZALOGOWANEGO_UZYTKOWNIKA;
}

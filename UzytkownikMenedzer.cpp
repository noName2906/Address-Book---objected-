#include "UzytkownikMenedzer.h"

void UzytkownikMenedzer::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();
    uzytkownicy.push_back(uzytkownik);
    plikiZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    string login;
    do
    {
        system ("cls");
        cout << ">>>>> REJESTRACJA UZYTKOWNIKA <<<<<" << endl;
        cout << "-----------------------------------" << endl;
        cout << "Podaj login: ";
        cin >> login;
        uzytkownik.ustawLogin(login);
    }
    while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    string haslo;
    cout << "Podaj haslo: ";
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

int UzytkownikMenedzer::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenedzer::czyIstniejeLogin(string login)
{
    for (unsigned int i = 0; i < uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzLogin() == login)
        {
            system ("cls");
            cout << ">>>>> REJESTRACJA UZYTKOWNIKA <<<<<" << endl;
            cout << "-----------------------------------" << endl;
            cout << "Istnieje uzytkownik o takim loginie. Sprobuj wybrac inny login." << endl;
            Sleep(2500);
            return true;
        }
    }
    return false;
}

void UzytkownikMenedzer::wypiszWszystkichUzytkownikow()
{
    for (unsigned int i = 0; i < uzytkownicy.size(); i++)
    {
        cout << uzytkownicy[i].pobierzId() << endl;
        cout << uzytkownicy[i].pobierzLogin() << endl;
        cout << uzytkownicy[i].pobierzHaslo() << endl;
    }

}

int UzytkownikMenedzer::logowanieUzytkownika()
{
    string login, haslo;

    system ("cls");
    cout << ">>>>> LOGOWANIE UZYTKOWNIKA <<<<<" << endl;
    cout << "---------------------------------" << endl;
    cout << "Podaj login: ";
    login = MetodyPomocnicze::wczytajLinie();

    for (unsigned int i = 0; i < uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzLogin() == login)
        {
            idZalogowanegoUzytkownika = uzytkownicy[i].pobierzId();

            cout << idZalogowanegoUzytkownika << endl;
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                system("cls");
                cout << ">>>>> LOGOWANIE UZYTKOWNIKA <<<<<" << endl;
                cout << "---------------------------------" << endl;
                cout << "Ilosc pozostalych prob: " << iloscProb <<endl << endl;
                cout << "Podaj swoje haslo: ";
                haslo = MetodyPomocnicze::wczytajLinie();
                cout << endl << endl;

                if (uzytkownicy[i].pobierzHaslo() == haslo)
                {
                    cout << "Zalogowales sie poprawnie" << endl << endl;
                    system("pause");
                    return idZalogowanegoUzytkownika;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo! Program konczy swoje dzialanie, sprobuj ponownie." << endl;
            system("pause");
            exit(0);
        }
    }
    cout << "Nie ma uzytkownika z takim loginem, Sprobuj jeszcze raz." << endl << endl;
    system("pause");
    exit(0);
}

bool UzytkownikMenedzer::czyUzytkownikJestZalogowany()
{
    if (idZalogowanegoUzytkownika > 0)
        return true;
    else
        return false;
}

void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika()
{
    Uzytkownik uzytkownik;
    string noweHaslo = "";

    system ("cls");
    cout << ">>>>> ZMIANA HASLA <<<<<" << endl;
    cout << "------------------------" << endl;
    cout << "Podaj nowe haslo: ";
    noweHaslo = MetodyPomocnicze::wczytajLinie();

    for (unsigned int i = 0; i < uzytkownicy.size(); i++)
    {
        if (idZalogowanegoUzytkownika == uzytkownicy[i].pobierzId())
        {
            uzytkownik.ustawHaslo(noweHaslo);
            uzytkownicy[i].ustawHaslo(noweHaslo);

            cout << endl;
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }

    for (unsigned int i = 0; i < uzytkownicy.size(); i++)
    {
        cout << uzytkownicy[i].pobierzId() << endl;
        cout << uzytkownicy[i].pobierzLogin() << endl;
        cout << uzytkownicy[i].pobierzHaslo() << endl;
    }
   plikiZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika() {
    return idZalogowanegoUzytkownika;
}

void UzytkownikMenedzer::wylogowanieUzytkownika() {
    idZalogowanegoUzytkownika = 0;
}


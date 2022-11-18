#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "listaAdresatow.txt");

    int wyborUzytkownicy, wyborAdresaci;

    while(true)
    {
        system("cls");
        cout << ">>>>> MENU GLOWNE <<<<<" << endl;
        cout << "-----------------------" << endl;
        cout << "1. Rejestracja" << endl;
        cout << "2. Logowanie" << endl;
        cout << "9. Zakoncz program" << endl;
        cout << "-----------------------" << endl;
        cout << "Twoj wybor: ";
        cin >> wyborUzytkownicy;

        switch(wyborUzytkownicy)
        {
        case 1:
            ksiazkaAdresowa.rejestracjaUzytkownika();
            break;
        case 2:
            ksiazkaAdresowa.logowanieUzytkownika();
            while(true)
            {
                system("cls");
                cout << ">>>>> MENU UZYTKOWNIKA <<<<<" << endl;
                cout << "----------------------------" << endl;
                cout << "1. Dodaj adresata" << endl;
                cout << "2. Wyswietl wszystkich adresatow" << endl;
                cout << "----------------------------" << endl;
                cout << "7. Zmien haslo" << endl;
                cout << "8. Wyloguj sie" << endl;
                cout << "----------------------------" << endl;
                cout << "Twoj wybor: ";
                cin >> wyborAdresaci;

                switch(wyborAdresaci)
                {
                case 1:
                    ksiazkaAdresowa.dodajAdresata();
                    break;
                case 2:
                    ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                    break;
                case 7:
                    ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                    break;
                case 8:
                    return main();
                    break;
                default:
                    cout << endl;
                    cout << "Niepoprawny wybor. Sprobuj jeszcze raz" << endl;
                    Sleep (1500);
                    break;
                }
            }
            break;
        case 9:
            exit(0);
            break;
        default:
            cout << endl;
            cout << "Niepoprawny wybor. Sprobuj jeszcze raz" << endl;
            Sleep (1500);
            break;
        }
    }
    return 0;
}


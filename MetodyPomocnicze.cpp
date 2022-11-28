#include "MetodyPomocnicze.h"

string MetodyPomocnicze::konwerjsaIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

int MetodyPomocnicze::konwersjaStringNaInt(string liczba)
{
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;

    return liczbaInt;
}

string MetodyPomocnicze::wczytajLinie()
{
    string wejscie = "";
    cin.sync();
    getline(cin, wejscie);
    return wejscie;
}

void usunPlik(string pobierzNazwePliku)
{
    if (remove(pobierzNazwePliku.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << pobierzNazwePliku << endl;
}

void zmienNazwePliku(string staraNazwa, string pobierzNazwePliku)
{
    if (rename(staraNazwa.c_str(), pobierzNazwePliku.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << pobierzNazwePliku << endl;
}


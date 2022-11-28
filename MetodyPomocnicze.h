#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>

using namespace std;

class MetodyPomocnicze
{
public:
    static string konwerjsaIntNaString(int liczba);
    static int konwersjaStringNaInt(string liczba);
    static string wczytajLinie();
    void usunPlik(string pobierzNazwePliku);
    void zmienNazwePliku(string staraNazwa, string pobierzNazwePliku);
};

#endif

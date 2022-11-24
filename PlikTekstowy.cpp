#include "PlikTekstowy.h"

bool PlikTekstowy::czyPlikJestPusty()
{
    fstream plik;
    plik.seekg(0, ios::end);
    if (plik.tellg() == 0)
        return true;
    else
        return false;
}

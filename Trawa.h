#ifndef TRAWA_H
#define TRAWA_H
#include "Roslina.h"

class Trawa : public Roslina
{
private:
 string nazwa;

public:
    Trawa(Swiat *swiat);
    void rysuj();
   // void akcja();
    Organizm* sklonuj(const Polozenie p);
    string getNazwa();
    ~Trawa();
};
#endif

#ifndef WILCZEJAGODY_H
#define WILCZEJAGODY_H
#include "RoslinaTrujaca.h"

class WilczeJagody : public RoslinaTrujaca
{
private:
    int sila;
    int inicjatywa;
    string nazwa;

public:
    WilczeJagody(Swiat *swiat);
    void rysuj();
    Organizm* sklonuj(const Polozenie p);
    string getNazwa();
    ~WilczeJagody();
};
#endif
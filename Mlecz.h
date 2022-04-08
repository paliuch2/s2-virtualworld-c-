#ifndef MLECZ_H
#define MLECZ_H
#include "Roslina.h"

class Mlecz : public Roslina
{
private:
    int sila=0;
    int inicjatywa=0;
    string nazwa;

public:
    Mlecz(Swiat *swiat);
    void rysuj();
    void akcja() override;
    Organizm* sklonuj(const Polozenie p);
    string getNazwa();
    ~Mlecz();
};
#endif
#ifndef GUARANA_H
#define GUARANA_H
#include "Roslina.h"

class Guarana : public Roslina
{
private:
    int sila=0;
    int inicjatywa=0;
    string nazwa;

public:
    Guarana(Swiat *swiat);
    void rysuj();
    bool kolizja(Organizm* atakujacy) override;
    Organizm* sklonuj(const Polozenie p);
    string getNazwa();
    ~Guarana();
};
#endif
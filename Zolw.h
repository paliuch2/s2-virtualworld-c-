#ifndef ZOLW_H
#define ZOLW_H
#include "Zwierze.h"

class Zolw : public Zwierze
{
private:
    int sila;
    int inicjatywa;
    string nazwa;

public:
    Zolw(Swiat *swiat);
    void rysuj();
    Organizm* sklonuj(const Polozenie p);
    string getNazwa();
    void akcja() override;
    bool kolizja(Organizm* atakujacy) override;
    bool zgodnoscGatunkow(Organizm* inny) override;
    ~Zolw();
};
#endif
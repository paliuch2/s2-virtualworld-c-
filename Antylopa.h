#ifndef ANTYLOPA_H
#define ANTYLOPA_H
#include "Zwierze.h"

class Antylopa : public Zwierze
{
private:
    int sila;
    int inicjatywa;
    string nazwa;

public:
    Antylopa(Swiat *swiat);
    void rysuj();
    Organizm* sklonuj(const Polozenie p);
    string getNazwa();
    void akcja() override;
    bool kolizja(Organizm* atakujacy) override;
    bool zgodnoscGatunkow(Organizm* inny) override;
    ~Antylopa();
};
#endif
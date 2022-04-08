#ifndef WILK_H
#define WILK_H
#include "Zwierze.h"

class Wilk : public Zwierze
{
private:
    int sila;
    int inicjatywa;
    string nazwa;

public:
    Wilk(Swiat *swiat);
    void rysuj();
    Organizm* sklonuj(const Polozenie p);
    string getNazwa();
    bool zgodnoscGatunkow(Organizm* inny) override;
    ~Wilk();
};
#endif
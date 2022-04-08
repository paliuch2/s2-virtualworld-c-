#ifndef LIS_H
#define LIS_H
#include "Zwierze.h"

class Lis : public Zwierze
{
private:
    int sila;
    int inicjatywa;
    string nazwa;

public:
    Lis(Swiat *swiat);
    void rysuj();
    void akcja() override;
    Organizm* sklonuj(const Polozenie p);
    string getNazwa();
    bool zgodnoscGatunkow(Organizm* inny) override;
    ~Lis();
};
#endif
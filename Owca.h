#ifndef OWCA_H
#define OWCA_H
#include "Zwierze.h"

class Owca : public Zwierze
{
private:
    int sila;
    int inicjatywa;
    string nazwa;

public:
    Owca(Swiat *swiat);
    void rysuj();
    Organizm* sklonuj(const Polozenie p);
    string getNazwa();
    bool zgodnoscGatunkow(Organizm* inny) override;
    ~Owca();

};
#endif
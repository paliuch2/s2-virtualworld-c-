#ifndef CZLOWIEK_H
#define CZLOWIEK_H
#include "Zwierze.h"

class Czlowiek : public Zwierze
{
private:
    int sila;
    int inicjatywa;
    string nazwa;
    int turaOstatniegoUzyciaMocy;
    int mozliweNastepneUzycieMocy;

public:
    Czlowiek(Swiat *swiat);
    void rysuj();
    Organizm* sklonuj(const Polozenie p);
    string getNazwa();
    void akcja() override;
    void Calopalenie();
    bool zgodnoscGatunkow(Organizm* inny) override;
    ~Czlowiek();
};
#endif
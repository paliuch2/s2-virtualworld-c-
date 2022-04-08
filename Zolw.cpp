#include "Zolw.h"

using namespace std;
#define SILA_ZOLW 2
#define INICJATYWA_ZOLW 1
#define MAKSYMALNA_SILA_ODPARCIA 5

Zolw::Zolw(Swiat *swiat) : Zwierze(swiat, SILA_ZOLW, INICJATYWA_ZOLW) {
    this->nazwa = "zolw";
}

void Zolw::rysuj() {
    cout << " Z ";
}

Organizm *Zolw::sklonuj(const Polozenie p) {
  return new Zolw(this->swiat);
}

string Zolw::getNazwa() {
    return nazwa;
}

void Zolw::akcja() {
    int x = rand() % 4;
    if (x == 0)
    {
        Zwierze::akcja();
    }

}

bool Zolw::kolizja(Organizm* atakujacy)
{
    if (atakujacy->getSila()>=MAKSYMALNA_SILA_ODPARCIA)
    {
        this->swiat->dodajKomunikat(atakujacy->getNazwa()+" pokonal w walce zwierze: "+this->getNazwa()+"\n");
        this->setZywy(false);
        return true;
    } else {
        this->swiat->dodajKomunikat(getNazwa()+" odparl atak organizmu o nazwie "+atakujacy->getNazwa()+"\n");
        return false;
    }

}

bool Zolw::zgodnoscGatunkow(Organizm* organizm)
{
    return dynamic_cast<Zolw*>(organizm) != nullptr;
}

Zolw::~Zolw()
{

}
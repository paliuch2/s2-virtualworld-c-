#include "Wilk.h"
using namespace std;
#define SILA_WILK 9
#define INICJATYWA_WILK 5

Wilk::Wilk(Swiat *swiat) : Zwierze(swiat, SILA_WILK, INICJATYWA_WILK)
{
    this->nazwa="wilk";
}

void Wilk::rysuj()
{
    cout << " W ";
}

Organizm* Wilk::sklonuj(const Polozenie p)
{
  return new Wilk(this->swiat);
}

string Wilk::getNazwa() {
    return nazwa;
}

bool Wilk::zgodnoscGatunkow(Organizm* organizm)
{
    return dynamic_cast<Wilk*>(organizm) != nullptr;
}

Wilk::~Wilk()
{

}
#include "Owca.h"
using namespace std;
#define SILA_OWCY 4
#define INICJATYWA_OWCY 4

Owca::Owca(Swiat *swiat) : Zwierze(swiat, SILA_OWCY, INICJATYWA_OWCY)
{
    this->nazwa="owca";
}

void Owca::rysuj()
{
    cout << " O ";
}

Organizm* Owca::sklonuj(const Polozenie p)
{
    return new Owca(this->swiat);
}

string Owca::getNazwa() {
    return nazwa;
}

bool Owca::zgodnoscGatunkow(Organizm* organizm)
{
    return dynamic_cast<Owca*>(organizm) != nullptr;
}

Owca::~Owca()
{

}
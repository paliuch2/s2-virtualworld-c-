#include "Trawa.h"
using namespace std;

Trawa::Trawa(Swiat *swiat) : Roslina(swiat, 0, 0)
{
    this->nazwa="trawa";
}

void Trawa::rysuj()
{
    cout << " T ";
}

Organizm* Trawa::sklonuj(const Polozenie p)
{
    return  new Trawa(this->swiat);
}

string Trawa::getNazwa() {
    return nazwa;
}

Trawa::~Trawa()
{

}
#include "Mlecz.h"
using namespace std;

Mlecz::Mlecz(Swiat *swiat) : Roslina(swiat, 0, 0)
{
    this->nazwa="mlecz";
}

void Mlecz::rysuj()
{
    cout << " M ";
}

Organizm* Mlecz::sklonuj(const Polozenie p)
{  
    return new Mlecz(this->swiat);
}

string Mlecz::getNazwa() {
    return nazwa;
}

void Mlecz::akcja() {

    for (int i=0 ;i<3;i++)
    Roslina::akcja();

}

Mlecz::~Mlecz()
{

}
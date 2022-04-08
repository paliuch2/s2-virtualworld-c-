#include "WilczeJagody.h"
using namespace std;
#define SILA_JAGODY 99

WilczeJagody::WilczeJagody(Swiat *swiat) : RoslinaTrujaca(swiat, SILA_JAGODY, 0)
{
    this->nazwa="wilcze jagody";
}

void WilczeJagody::rysuj()
{
    cout << " J ";
}

Organizm* WilczeJagody::sklonuj(const Polozenie p)
{
    return new WilczeJagody(this->swiat);
}

string WilczeJagody::getNazwa() {
    return nazwa;
}

WilczeJagody::~WilczeJagody()
{

}
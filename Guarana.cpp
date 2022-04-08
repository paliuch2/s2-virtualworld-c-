#include "Guarana.h"
#include <string>
using namespace std;

Guarana::Guarana(Swiat *swiat) : Roslina(swiat, 0, 0)
{
    this->nazwa="guarana";
}

void Guarana::rysuj()
{
    cout << " G ";
}

Organizm* Guarana::sklonuj(const Polozenie p)
{
    return new Guarana(this->swiat);
}

string Guarana::getNazwa() {
    return nazwa;
}

bool Guarana::kolizja(Organizm *atakujacy) {

    this->setZywy(false);
    atakujacy->setSila(atakujacy->getSila()+3);
    this->swiat->dodajKomunikat("Organizm " + atakujacy->getNazwa() + " zjadl guarane i jego sila wynosi teraz " + to_string(atakujacy->getSila()) + "\n");
    return true;
}

Guarana::~Guarana()
{

}
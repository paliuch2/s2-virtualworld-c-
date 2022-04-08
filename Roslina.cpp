#include "Roslina.h"

Roslina::Roslina(Swiat *swiat, int sila, int inicjatywa) : Organizm(swiat,sila,inicjatywa)
{

}

void Roslina::akcja()
{
    Polozenie nowe = this->getPolozenie();
    int x = rand()%100;

        if (x == 0 && nowe.x > 0) {
            nowe.x--;
            Organizm *nowy = sklonuj(nowe);
            if (this->swiat->getOrganizm(nowe) == nullptr)
            {
                this->swiat->addOrganizm(nowy, nowe);
                this->swiat->dodajKomunikat("Powstal nowy organizm: " + getNazwa() + "\n");
            }
        }
        if (x == 25 && nowe.x < this->swiat->getWidth() - 1) {
            nowe.x++;
            Organizm* nowy = sklonuj(nowe);
            if (this->swiat->getOrganizm(nowe) == nullptr)
            {
                this->swiat->addOrganizm(nowy, nowe);
                this->swiat->dodajKomunikat("Powstal nowy organizm: " + getNazwa() + "\n");
            }
        }
        if (x == 50 && nowe.y > 0) {
            nowe.y--;
            Organizm* nowy = sklonuj(nowe);
            if (this->swiat->getOrganizm(nowe) == nullptr)
            {
                this->swiat->addOrganizm(nowy, nowe);
                this->swiat->dodajKomunikat("Powstal nowy organizm: " + getNazwa() + "\n");
            }
        }
        if (x == 75 && nowe.y < this->swiat->getHeight() - 1) {
            nowe.y++;
            Organizm* nowy = sklonuj(nowe);
            if (this->swiat->getOrganizm(nowe) == nullptr)
            {
                this->swiat->addOrganizm(nowy, nowe);
                this->swiat->dodajKomunikat("Powstal nowy organizm: " + getNazwa() + "\n");
            }
        }

}

bool Roslina::kolizja(Organizm *atakujacy) {

    this->setZywy(false);
    this->swiat->dodajKomunikat(atakujacy->getNazwa()+" zjadl roslinie o nazwie "+this->getNazwa()+"\n");
    return true;
}

Roslina::~Roslina()
{

}
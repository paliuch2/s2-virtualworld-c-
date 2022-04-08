#include "Organizm.h"


Polozenie Organizm::getPolozenie() {

    return polozenie;
}

void Organizm::setPolozenie(const Polozenie nowe) {
    this->polozenie = nowe;
}

Organizm::Organizm(Swiat *swiat, int sila, int inicjatywa) {
    this->swiat = swiat;
    this->sila = sila;
    this->inicjatywa = inicjatywa;
    this->zywy = true;
    this->wiek = 0;
}

int Organizm::getInicjatywa() const {
    return inicjatywa;
}

int Organizm::getSila() const{
    return sila;
};

bool Organizm::kolizja(Organizm *atakujacy) {
    return false;
}

bool Organizm::getCzyZywy() const{
    return zywy;
}

void Organizm::setZywy(const bool stan) {
    this->zywy = stan;
}

void Organizm::setSila(const int sila) {
    this->sila = sila;
}

void Organizm::getSasiedztwo(Organizm** sasiedztwo) {

    if (polozenie.x > 0) {
        Polozenie nowe = getPolozenie();
        nowe.x--;
        sasiedztwo[LEWY] = this->swiat->getOrganizm(nowe); }

    if (polozenie.y > 0) {
        Polozenie nowe = getPolozenie();
        nowe.y--;
        sasiedztwo[GORNY] = this->swiat->getOrganizm(nowe);
    }

    if (polozenie.x < this->swiat->getWidth() - 1) {
        Polozenie nowe = getPolozenie();
        nowe.x++;
        sasiedztwo[PRAWY] = this->swiat->getOrganizm(nowe);
    }

    if (polozenie.y < this->swiat->getHeight() - 1) {
        Polozenie nowe = getPolozenie();
        nowe.y++;
        sasiedztwo[DOLNY] = this->swiat->getOrganizm(nowe);
    }

}

void Organizm::setWiek (const int wiek)
{
    this->wiek = wiek;
}

int Organizm::getWiek()
{
    return wiek;
}

Organizm::~Organizm()
{

}
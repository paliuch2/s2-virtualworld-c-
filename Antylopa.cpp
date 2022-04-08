#include "Antylopa.h"

using namespace std;
#define SILA_ANTYLOPA 4
#define INICJATYWA_ANTYLOPA 4

Antylopa::Antylopa(Swiat *swiat)  : Zwierze(swiat, SILA_ANTYLOPA, INICJATYWA_ANTYLOPA) {
    this->nazwa = "antylopa";
}

void Antylopa::rysuj() {
    cout << " A ";
}

Organizm *Antylopa::sklonuj(const Polozenie p) {
    return new Antylopa(this->swiat);
}

string Antylopa::getNazwa() {
    return nazwa;
}

void Antylopa::akcja() {

  for (int i=0; i<2; i++)
  {
      Zwierze::akcja();
      if (this->getCzyZywy()==false )
          break;
  }

}

bool Antylopa::kolizja(Organizm *atakujacy) {

    Polozenie stare = getPolozenie();
    int x = rand()%2;
    if (x==0)
    {
        Polozenie nowe = Zwierze::sprawdzOkoliczneiObierzKierunek(0);
        
       if ((nowe.x == stare.x) && (nowe.y == stare.y)) x=1;
       else {
           this->setPolozenie(nowe);
           atakujacy->setPolozenie(stare);
           this->swiat->dodajKomunikat("Antylopa ucieka przed " + atakujacy->getNazwa() + "!\n");
       }
    }
    if (x==1)
        {
       return Zwierze::kolizja(atakujacy);
    }
    return false;
}

bool Antylopa::zgodnoscGatunkow(Organizm* organizm)
{
    return dynamic_cast<Antylopa*>(organizm) != nullptr;
}

Antylopa::~Antylopa()
{

}
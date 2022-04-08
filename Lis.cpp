#include "Lis.h"

using namespace std;
#define SILA_LISA 3
#define INICJATYWA_LISA 7

Lis::Lis(Swiat* swiat) : Zwierze(swiat, SILA_LISA, INICJATYWA_LISA) {
	this->sila = 3;
	this->inicjatywa = 7;
	this->nazwa = "lis";
}

void Lis::rysuj() {
	cout << " L ";
}

Organizm* Lis::sklonuj(const Polozenie p) {
	return new Lis(this->swiat);
}

string Lis::getNazwa() {
	return nazwa;
}

void Lis::akcja() {
	Polozenie docelowe = Zwierze::sprawdzOkoliczneiObierzKierunek(this->getSila());
	Organizm* na_docelowym = this->swiat->getOrganizm(docelowe);

	if (na_docelowym != nullptr)
	{
		if (zgodnoscGatunkow(na_docelowym) == true) {
			if (this->getWiek() > PROG_PELNOLETNIOSCI && na_docelowym->getWiek() > PROG_PELNOLETNIOSCI)
			{
				stworzPotomka(getPolozenie());
			}
		}
		else
		{
			swiat->move(getPolozenie(), docelowe);
		}
	}
	else
	{
		swiat->move(getPolozenie(), docelowe);
	}
}

bool Lis::zgodnoscGatunkow(Organizm* organizm)
{
	return dynamic_cast<Lis*>(organizm) != nullptr;
}

Lis::~Lis()
{

}
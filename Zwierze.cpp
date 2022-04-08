#include "Zwierze.h"


Zwierze::Zwierze(Swiat* swiat, int sila, int inicjatywa) : Organizm(swiat, sila, inicjatywa) {

}


void Zwierze::akcja()
{
	int x = rand() % 4;
	Polozenie docelowe = getPolozenie();
	bool moved = false;

	while (moved == false) {
		if (x == 0 && docelowe.x > 0) { docelowe.x--; moved = true; }
		if (x == 1 && docelowe.y > 0) { docelowe.y--; moved = true; }
		if (x == 2 && docelowe.x < swiat->getWidth() - 1) { docelowe.x++; moved = true; }
		if (x == 3 && docelowe.y < swiat->getHeight() - 1) { docelowe.y++; moved = true; }
		x = rand() % 4;
	}

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

bool Zwierze::kolizja(Organizm* atakujacy) {
	if (atakujacy->getSila() >= this->getSila())
	{
		this->setZywy(false);
		this->swiat->dodajKomunikat(atakujacy->getNazwa() + " pokonal w walce zwierze: " + this->getNazwa() + "\n");
		//   cout << this->getNazwa() << this->getSila() << " vs " << atakujacy->getNazwa() << atakujacy->getSila();
		return true;
	}
	else {
		atakujacy->setZywy(false);
		this->swiat->dodajKomunikat(this->getNazwa() + " pokonal w walce zwierze: " + atakujacy->getNazwa() + "\n");
		//   cout << this->getNazwa() << this->getSila() << " vs " << atakujacy->getNazwa() << atakujacy->getSila();
		return false;
	}
}

bool Zwierze::stworzPotomka(Polozenie rodzic)
{
	Polozenie potomek = sprawdzOkoliczneiObierzKierunek(0);

	if (!(rodzic.x == potomek.x && rodzic.y == potomek.y))
	{
		Organizm* nowy = sklonuj(rodzic);

		this->swiat->addOrganizm(nowy, potomek);
		this->swiat->dodajKomunikat(this->getNazwa() + " rozmnozyl sie!\n");
		return true;
	}
	return false;
}


Polozenie Zwierze::sprawdzOkoliczneiObierzKierunek(int silaWiekszaNiz) {

	Organizm* sasiedztwo[4] = { nullptr, nullptr, nullptr, nullptr };
	bool dostepne_pole[4] = { true, true, true, true };
	getSasiedztwo(sasiedztwo);
	Polozenie docelowe = getPolozenie();

	for (int i = 0; i < 4; i++) {
		if (sasiedztwo[i] != nullptr) {
			if (sasiedztwo[i]->getSila() > silaWiekszaNiz) { dostepne_pole[i] = false; }
		}
	}

	if (docelowe.x < 1) dostepne_pole[LEWY] = false;
	if (docelowe.y < 1) dostepne_pole[GORNY] = false;
	if (docelowe.x >= swiat->getWidth() - 1) dostepne_pole[PRAWY] = false;
	if (docelowe.y >= swiat->getHeight() - 1) dostepne_pole[DOLNY] = false;

	bool istniejeWolne = false;
	for (int i = 0; i < 4; i++) {
		if (dostepne_pole[i] == true) {
			istniejeWolne = true;
			break;
		}
	}
	if (istniejeWolne == false) return getPolozenie();

	bool moved = false;
	int r = rand() % 4;
	while (moved == false) {
		if (istniejeWolne == true && dostepne_pole[r] == true) {
			if (r == 0) {
				docelowe.x--;
				moved = true;
			}
			if (r == 1) {
				docelowe.y--;
				moved = true;
			}
			if (r == 2) {
				docelowe.x++;
				moved = true;
			}
			if (r == 3) {
				docelowe.y++;
				moved = true;
			}
		}
		r = rand() % 4;
	}

	return docelowe;
}

Zwierze::~Zwierze()
{

}

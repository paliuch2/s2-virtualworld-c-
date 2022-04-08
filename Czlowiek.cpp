#include "Czlowiek.h"
#include <string>
#include <conio.h>
#define SILA_CZLOWIEK 5
#define INICJATYWA_CZLOWIEK 4
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define TURA_UZYCIA_MOCY 5



Czlowiek::Czlowiek(Swiat* swiat) : Zwierze(swiat, SILA_CZLOWIEK, INICJATYWA_CZLOWIEK) {
	this->sila = 5;
	this->inicjatywa = 4;
	this->nazwa = "czlowiek";
	this->turaOstatniegoUzyciaMocy = -TURA_UZYCIA_MOCY; // konieczne, aby czlowiek na starcie nie mial z gory uruchomionej mocy.
	this->mozliweNastepneUzycieMocy = 0; // konieczne, aby uzytkownik mogl uruchomic moc juz w 1. kolejce gry.
}

void Czlowiek::rysuj() {
	cout << " X ";
}

string Czlowiek::getNazwa() {
	return nazwa;
}

Organizm* Czlowiek::sklonuj(const Polozenie p) {
	return nullptr;
}

void Czlowiek::akcja() {

	int czy_uzyc_mocy = this->getWiek() - turaOstatniegoUzyciaMocy;

	if (czy_uzyc_mocy < TURA_UZYCIA_MOCY)
	{		
		Calopalenie();
	}

	Polozenie obecne = getPolozenie();
	int c;
	
	bool zrobil_ruch = false;

	while (zrobil_ruch == false)
	{
		switch (c = _getch()) {
		case KEY_UP:
			if (obecne.y > 0) { obecne.y--; }
			zrobil_ruch = true;
			break;
		case KEY_DOWN:
			if (obecne.y < this->swiat->getHeight() - 1) { obecne.y++; }
			zrobil_ruch = true;
			break;
		case KEY_LEFT:
			if (obecne.x > 0) { obecne.x--; }
			zrobil_ruch = true;
			break;
		case KEY_RIGHT:
			if (obecne.x < this->swiat->getWidth() - 1) { obecne.x++; }
			zrobil_ruch = true;
			break;
		case 'N': case 'n':
			if (this->getWiek() >= this->mozliweNastepneUzycieMocy)
			{
				this->swiat->dodajKomunikat("URUCHOMIONO CALOPENIE!\n");
				turaOstatniegoUzyciaMocy = this->getWiek();
				mozliweNastepneUzycieMocy = this->getWiek()+(2 * TURA_UZYCIA_MOCY);
				zrobil_ruch = true;
			}
			else
			{
				int za_ile = mozliweNastepneUzycieMocy - this->getWiek();
				this->swiat->dodajKomunikat("Nie uruchomiono mocy, poniewaz jest to niemozliwe jeszcze przez: "+ to_string(za_ile) +" tur\n");
			}
			break;
		default:
			break;
		}
	}
	

	swiat->move(getPolozenie(), obecne);

	czy_uzyc_mocy = this->getWiek() - turaOstatniegoUzyciaMocy;
	if (czy_uzyc_mocy < TURA_UZYCIA_MOCY)
	{
		Calopalenie();
	}

}

void Czlowiek::Calopalenie()
{
	Organizm* sasiedztwo[4] = { nullptr, nullptr, nullptr, nullptr };
	getSasiedztwo(sasiedztwo);

	for (int i = 0; i < 4; i++) {
		if (sasiedztwo[i] != nullptr) {
			this->swiat->getOrganizm(sasiedztwo[i]->getPolozenie())->setZywy(false);
			this->swiat->zabij(sasiedztwo[i]->getPolozenie());
			this->swiat->dodajKomunikat(this->getNazwa() + " niszczy organizm (" + sasiedztwo[i]->getNazwa() + ") przy uzyciu calopalenia!\n");
		}
	}

}

bool Czlowiek::zgodnoscGatunkow(Organizm* organizm)
{
	return dynamic_cast<Czlowiek*>(organizm) != nullptr;
}

Czlowiek::~Czlowiek()
{

}
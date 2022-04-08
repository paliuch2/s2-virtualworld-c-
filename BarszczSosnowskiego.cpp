#include "BarszczSosnowskiego.h"
#include "Zwierze.h"
using namespace std;
#define SILA_BARSZCZ 10

BarszczSosnowskiego::BarszczSosnowskiego(Swiat *swiat) : RoslinaTrujaca(swiat, SILA_BARSZCZ, 0)
{
    this->nazwa="barszcz Sosnowskiego";

}

void BarszczSosnowskiego::rysuj()
{
    cout << " B ";
}

Organizm* BarszczSosnowskiego::sklonuj(const Polozenie p)
{
    return new BarszczSosnowskiego(this->swiat);
}

string BarszczSosnowskiego::getNazwa() {
    return nazwa;
}

void BarszczSosnowskiego::akcja()
{
    Roslina::akcja();
    Organizm *sasiedztwo[4] = {nullptr, nullptr, nullptr, nullptr};
    getSasiedztwo(sasiedztwo);

    for (int i = 0; i < 4; i++) {
        if (sasiedztwo[i] != nullptr) {
            if (dynamic_cast<Zwierze*>(sasiedztwo[i])) {
                this->swiat->getOrganizm(sasiedztwo[i]->getPolozenie())->setZywy(false);
                this->swiat->zabij(sasiedztwo[i]->getPolozenie());
                this->swiat->dodajKomunikat(sasiedztwo[i]->getNazwa()+" znalazl sie w poblizu barszczu i umiera! \n");
            }
        }
    }

}

BarszczSosnowskiego::~BarszczSosnowskiego()
{

}
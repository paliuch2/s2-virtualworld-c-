#include "RoslinaTrujaca.h"

RoslinaTrujaca::RoslinaTrujaca(Swiat *swiat, int sila, int inicjatywa)  : Roslina(swiat,sila,inicjatywa)
{

}

bool RoslinaTrujaca::kolizja(Organizm *atakujacy) {

    atakujacy->setZywy(false);
    this->setZywy(false); // jak zwierze zje nawet i rosline trujaca, to ginie i on i ta roslina
    this->swiat->zabij(this->getPolozenie());
    this->swiat->dodajKomunikat("Zjedzenie rosliny o nazwie "+this->getNazwa()+" spowodowalo smierc zwierzecia: "+atakujacy->getNazwa()+"\n");
    return false;
}

RoslinaTrujaca::~RoslinaTrujaca()
{

}
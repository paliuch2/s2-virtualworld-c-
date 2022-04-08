#ifndef ROSLINA_TRUJACA_H
#define ROSLINA_TRUJACA_H

#include "Roslina.h"

class RoslinaTrujaca : public Roslina {

private:
    string nazwa;
public:

    RoslinaTrujaca(Swiat *swiat, int sila, int inicjatywa);
    bool kolizja (Organizm* atakujacy) override;
    virtual void rysuj() = 0;
    ~RoslinaTrujaca();
};

#endif
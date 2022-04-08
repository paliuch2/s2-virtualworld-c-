#ifndef ROSLINA_H
#define ROSLINA_H

#include "Organizm.h"

class Roslina : public Organizm {

private:
    string nazwa;
public:
    
    Roslina(Swiat *swiat, int sila, int inicjatywa);
    void akcja();
    bool kolizja (Organizm* atakujacy) override;
    virtual void rysuj() = 0;
    ~Roslina();
};

#endif

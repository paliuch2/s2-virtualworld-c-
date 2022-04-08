#ifndef ZWIERZE_H
#define ZWIERZE_H
#include "Organizm.h"
#define PROG_PELNOLETNIOSCI 18

class Zwierze : public Organizm {
private:
    int sila;
    int inicjatywa;
    string nazwa;
public:

    Zwierze(Swiat *swiat, int sila, int inicjatywa);
    void akcja();
    virtual void rysuj() = 0;
    bool kolizja (Organizm* atakujacy) override;
    Polozenie sprawdzOkoliczneiObierzKierunek (int silaWiekszaNiz);
    virtual bool zgodnoscGatunkow(Organizm* inny) = 0;
    bool stworzPotomka(Polozenie pol_rodzica);
    ~Zwierze();

};
#endif

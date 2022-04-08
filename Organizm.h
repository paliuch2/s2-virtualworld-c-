#ifndef ORGANIZM_H
#define ORGANIZM_H

#include <iostream>
#include "Polozenie.h"
#include "Swiat.h"
using namespace std;

class Organizm {

private:
    int sila;
    int inicjatywa;
    Polozenie polozenie;
    string nazwa;
    bool zywy;
    int wiek;
protected:
    class Swiat *swiat;

public:
    Organizm (Swiat* swiat, int sila, int inicjatywa);
    virtual void rysuj() = 0;
    virtual void akcja() = 0;
    virtual bool kolizja (Organizm* atakujacy) = 0;
    Polozenie getPolozenie();
    void setPolozenie(const Polozenie nowe);
    int getSila() const;
    void setSila (const int sila);
    bool getCzyZywy ()const;
    void setZywy (const bool stan);
    int getInicjatywa() const;
    virtual string getNazwa() = 0;
    virtual Organizm* sklonuj(const Polozenie p) = 0;
    void getSasiedztwo(Organizm** sasiedztwo);
    void setWiek(const int wiek);
    int getWiek();
    ~Organizm();

};
#endif
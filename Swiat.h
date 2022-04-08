#ifndef SWIAT_H
#define SWIAT_H
#include <iostream>
#include "Organizm.h"
#include <vector>
using namespace std;


class Swiat {

private:
    int x;
    int y;
    vector<class Organizm*> *organizmy;
    class Organizm*** world;
   void inicjujSwiat();
   Polozenie drawCoordinates();
    string komunikaty;

public:
    Swiat (int a, int b);
    void rysujSwiat();
    void wykonajTure();
    void addOrganizm(Organizm* organizm, Polozenie p);
    void move (Polozenie from, Polozenie to);
    int getWidth ();
    int getHeight ();
   void wyswietlKomunikaty ();
   void dodajKomunikat (const string informacja);
   Organizm* getOrganizm(Polozenie p);
    void zabij (Polozenie p);
    ~Swiat();
};
#endif
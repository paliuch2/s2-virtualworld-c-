#include "Swiat.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"
#include "Wilk.h"
#include "Owca.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Czlowiek.h"
#include <algorithm>

Swiat::Swiat(int x, int y) : x(x), y(y) {
    world = (Organizm ***) calloc(x, sizeof(Organizm **));
    for (int i = 0; i < x; i++) {
        world[i] = (Organizm **) calloc(y, sizeof(Organizm *));
    }
    organizmy = new vector<class Organizm *>;

    inicjujSwiat();
}

void Swiat::inicjujSwiat() {
    int m = (x * y) / 200;
    int ile[10];
    for (int i = 0; i < 10; i++) {
        ile[i] = (rand() % m) + 2;
    }
    for (int i = 0; i < ile[0]; i++) {
        Polozenie p = drawCoordinates();
        addOrganizm(new Trawa(this), p);
    }
    for (int i = 0; i < ile[1]; i++) {
        Polozenie p = drawCoordinates();
        addOrganizm(new Mlecz(this), p);
    }
    for (int i = 0; i < ile[2]; i++) {
        Polozenie p = drawCoordinates();
        addOrganizm(new Guarana(this), p);
    }
    for (int i = 0; i < ile[3]; i++) {
        Polozenie p = drawCoordinates();
        addOrganizm(new WilczeJagody(this), p);
    }
    for (int i = 0; i < ile[4]; i++) {
        Polozenie p = drawCoordinates();
        addOrganizm(new BarszczSosnowskiego(this), p);
    }
    for (int i = 0; i < ile[5]; i++) {
        Polozenie p = drawCoordinates();
        addOrganizm(new Wilk(this), p);
    }
    for (int i = 0; i < ile[6]; i++) {
        Polozenie p = drawCoordinates();
        addOrganizm(new Owca(this), p);
    }
    for (int i = 0; i < ile[7]; i++) {
        Polozenie p = drawCoordinates();
        addOrganizm(new Lis(this), p);
    }
    for (int i = 0; i < ile[8]; i++) {
        Polozenie p = drawCoordinates();
        addOrganizm(new Zolw(this), p);
    }
    for (int i = 0; i < ile[9]; i++) {
        Polozenie p = drawCoordinates();
        addOrganizm(new Antylopa(this), p);
    }
    Polozenie p = drawCoordinates();
    addOrganizm(new Czlowiek(this),p);
};

void Swiat::rysujSwiat() {
    for (int iy = 0; iy < y; iy++) {
        for (int ix = 0; ix < x; ix++) {
            if (world[ix][iy] == nullptr) {
                cout << " - ";
            } else {
                world[ix][iy]->rysuj();
            }
        }
        cout << endl;
    }
}

void Swiat::wykonajTure() {

    komunikaty = "";
    sort( organizmy->begin( ), organizmy->end( ), [ ]( const auto& lewy, const auto& prawy )
    {
        return lewy->getInicjatywa() > prawy->getInicjatywa();
    });

    int length = organizmy->size();
    for (int i=0; i<length;i++) {
        Organizm *pOrganizm = (*organizmy)[i];
       if (pOrganizm->getCzyZywy()) {
           pOrganizm->akcja();
           pOrganizm->setWiek(pOrganizm->getWiek()+1);
       }
    }

  vector<class Organizm*> *v2 = new vector<class Organizm *>;

  
       
   int length2 = organizmy->size();
    for (int i=0;i<length2;i++) {
        Organizm *pOrganizm = (*organizmy)[i];
        if (pOrganizm->getCzyZywy()) {
            v2->push_back(pOrganizm);
        }
        else
        {
            delete(pOrganizm);
        }
    }
    delete(organizmy);
    organizmy = v2;

    

}

Polozenie Swiat::drawCoordinates() {
    int a, b;
    do {
        a = rand() % x;
        b = rand() % y;
    } while (world[a][b] != nullptr);

    Polozenie tmp;
    tmp.x = a;
    tmp.y = b;

    return tmp;
}


void Swiat::addOrganizm(Organizm *tworzony, Polozenie p) {

    if (world[p.x][p.y] == nullptr) {
        world[p.x][p.y] = tworzony;
        tworzony->setPolozenie(p);
      
            organizmy->push_back(tworzony);
         
    }
}

void Swiat::move(Polozenie from, Polozenie to) {

    Organizm *o = world[from.x][from.y];

    world[from.x][from.y] = nullptr;
    if (world[to.x][to.y] == nullptr) {
        o->setPolozenie(to);
        world[to.x][to.y] = o;
    }
    else {
        Organizm* oponent = world[to.x][to.y];
        bool wynik_kolizji = oponent->kolizja(o);

        if (wynik_kolizji == true ) {

            o->setPolozenie(to);
            world[to.x][to.y] = o;

        }        
        else if (wynik_kolizji == false && o->getCzyZywy()==true )
           {
            world[to.x][to.y] = nullptr;
            Polozenie n = oponent->getPolozenie();
            world[n.x][n.y] = oponent;
            Polozenie m = o->getPolozenie();
            world[m.x][m.y] = o;
           }


    }
}

int Swiat::getWidth() {
    return x;
}

int Swiat::getHeight() {
    return y;
}

void Swiat::dodajKomunikat(const string informacja)
{
    komunikaty += informacja;
}

void Swiat::wyswietlKomunikaty() {
    cout << komunikaty;
}

Organizm *Swiat::getOrganizm(Polozenie p) {
    return world[p.x][p.y];
}

void Swiat::zabij(Polozenie p) {
    world[p.x][p.y] = nullptr;
}

Swiat::~Swiat()
{
    int length = organizmy->size();
    for (int i = 0; i < length; i++) {
        Organizm* pOrganizm = (*organizmy)[i];
        delete (pOrganizm);
    }
    delete(organizmy);
}

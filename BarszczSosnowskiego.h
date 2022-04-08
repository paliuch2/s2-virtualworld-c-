#ifndef BARSZCZ_H
#define BARSZCZ_H
#include "RoslinaTrujaca.h"

class BarszczSosnowskiego : public RoslinaTrujaca
{
private:
	int sila = 10;
	int inicjatywa = 0;
	string nazwa;

public:
	BarszczSosnowskiego(Swiat* swiat);
	void rysuj();
	void akcja() override;
	Organizm* sklonuj(const Polozenie p);
	string getNazwa();
	~BarszczSosnowskiego();
};
#endif
#ifndef CRNOBELASLIKA_H
#define CRNOBELASLIKA_H

#include <iostream>
using namespace std;
#include "Slika.h"
#include "Piksel.h"
#include "Pozicija.h"

class CBSlika : public Slika {
public:
	CBSlika(int sirina,int duzina) : Slika(sirina,duzina) {}
	CBSlika& postavipikselnapoziciju(Piksel& p,const Pozicija& pp) override {
		if (((p.dohpla() + p.dohvcrv() + p.dohzel()) / 3) > 127) { p = Piksel(255, 255, 255) + Piksel(255, 255, 255); }
		else p = Piksel(0, 0, 0) + Piksel(0, 0, 0);
		Slika::postavipikselnapoziciju(p, pp);
		return *this;
	}
};
#endif
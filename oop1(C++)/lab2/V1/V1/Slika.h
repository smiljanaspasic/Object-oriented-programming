#ifndef SLIKA_H
#define SLIKA_H
#include "Multimedija.h"
#include <iostream>
#include<string>
using namespace std;

class Slika : public Multimedija {
	unsigned int visina, sirina;
	unsigned int velicinapikselaubrojubajtova;
public:
	Slika(unsigned int v, unsigned int s, unsigned int vpubb, string ime) : Multimedija(ime) {
		visina = v; sirina = s; velicinapikselaubrojubajtova = vpubb;
	}
	int dohvativelicinu() const override {
		return sirina * visina*velicinapikselaubrojubajtova;
	}
	string  dohvatiopis() const override {
		return  "[" + to_string(sirina) + "x"  + to_string(visina) + "->" + to_string(dohvativelicinu()) + "B" + "]";
	}

};


#endif


#ifndef GARANCIJA_H
#define GARANCIJA_H
#include <iostream>
#include "Datum.h"
#include "Kvar.h"

using namespace std;

class Garancija {
	struct Elem {
		Kvar k;
		Elem* sled;
		Elem(Kvar p, Elem* s = nullptr) : k(p) {
			k = p;
			sled = s;
		}
	};
	Elem* prvi, *posl;
	Datum datpoc, datgar;
	void kopiraj(const Garancija& g) {
		prvi = posl = nullptr;
		datpoc = g.datpoc; datgar = g.datgar;
		for (Elem* tek = g.prvi; tek; tek->sled) {
			posl = (!prvi ? prvi : posl->sled) = new Elem(tek->k);
		}
	}
	void brisi() {
		while (prvi) {
			Elem* stari = prvi;
			prvi = prvi->sled;
			delete stari;

		}
	}
	void premesti(Garancija& g) {
		prvi = g.prvi; posl = g.posl; datgar = g.datgar; datpoc = g.datpoc; g.prvi = g.posl = nullptr;
	}
public:
	Garancija(const Datum& dp, const Datum& dg) {
		datpoc = dp; datgar = dg;
		posl = prvi = nullptr;
	}
	Garancija& dodajkvar(const Kvar& k) {
		if (k.dohvdat() < datgar && posl->k.dohinfo()) {
			posl = (!prvi ? prvi : posl->sled) = new Elem(k);
		}
		return *this;
	}
	Kvar& dohvatiposlednji() const { return posl->k; }
	int ukupanbr() {
		int b = 0;
		for (Elem* tek = prvi; tek; tek->sled) {
			b++;
		}
		return b;
	}
	friend ostream& operator<<(ostream& os,Garancija& g) {
		return os << g.datpoc << "-" << g.datgar << "-brojkvarova:" << g.ukupanbr() ;
	}
	Garancija(const Garancija& g) {
		kopiraj(g);
	}
	Garancija(Garancija&& g) {
		premesti(g);
	}
	Garancija& operator=(const Garancija& g) {
		if (this != &g) {
			brisi(); kopiraj(g);
		}
		return *this;
	}
	Garancija& operator=(Garancija&& g) {
		if (this != &g) {
			brisi(); premesti(g);
		}
	}
	~Garancija() { brisi(); }
};
#endif
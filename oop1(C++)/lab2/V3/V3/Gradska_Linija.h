#ifndef GRADSKALINIJA_H
#define GRADSKALINIJA_H
#include <iostream>
#include "Lista.h"
#include "Stajaliste.h"
using namespace std;

class GradskaLinija {
	string o;
	Lista<Stajaliste> stajalista;
	void kopiraj(const GradskaLinija& g) {
		o = g.o;
		for (g.stajalista.naPrvi(); g.stajalista.imaTek(); g.stajalista.naSled()) {
			stajalista.dodaj(g.stajalista.dohvPod());
		}
	}
	void brisi() {
		for (stajalista.naPrvi(); stajalista.imaTek(); stajalista.naSled()) {
			stajalista.izbaciTek();
		}
	}
	void premesti(GradskaLinija& g) {
		o = g.o;
		stajalista = g.stajalista;
	}
public:
	GradskaLinija(string oz, Lista<Stajaliste> s) {
		o = oz;
		stajalista = s;
	}
	GradskaLinija(const GradskaLinija& gl) { kopiraj(gl); }
	GradskaLinija(GradskaLinija&& g) { premesti(g); }
	GradskaLinija& operator=(const GradskaLinija& g) { if (this != &g) { brisi(); kopiraj(g); } return *this; }
	GradskaLinija& operator=(GradskaLinija&& g) {
		if (this != &g) { brisi(); premesti(g);}
		return *this;
	}
	string dohvatioznaku() const { return o; }
	Lista<Stajaliste> dohvatistajalista() const { return stajalista; }
	friend int operator&(const GradskaLinija& l1, const GradskaLinija& l2) {
		int k = 0;
		for (l1.stajalista.naPrvi(); l1.stajalista.imaTek(); l1.stajalista.naSled()) {
			for (l2.stajalista.naPrvi(); l2.stajalista.imaTek(); l2.stajalista.naSled()) {
				if (l1.stajalista.dohvPod() == l2.stajalista.dohvPod()) { k++; }
			}
		}
		return k;
	}
	friend ostream& operator<<(ostream& os, const GradskaLinija& g) {
		os << g.dohvatioznaku() << endl;
		for (g.stajalista.naPrvi(); g.stajalista.imaTek(); g.stajalista.naSled()) {
			os << g.stajalista.dohvPod() << endl;
		}
		return os;
	}
	~GradskaLinija() { brisi(); }
};
#endif

#ifndef MREZA_H
#define MREZA_H
#include <iostream>
#include <string>
#include "Lista.h"
#include "Gradska_Linija.h"
using namespace std;

class Mreza {
private:
	
	Lista < GradskaLinija*> gradskelin;

	void kopiraj(const Mreza& m) {
		for (m.gradskelin.naPrvi(); m.gradskelin.imaTek(); m.gradskelin.naSled()) {
			gradskelin.dodaj(m.gradskelin.dohvPod());
		}
	}
	void premesti(Mreza& m) {
		gradskelin = m.gradskelin;
	}
	void brisi() {
		for (gradskelin.naPrvi(); gradskelin.imaTek(); gradskelin.naSled()) {
			gradskelin.izbaciTek();
		}
	}
public:
	Mreza() = default;
	Mreza(const Mreza& m) {
		kopiraj(m);
	}
	Mreza(Mreza&& m) {
		premesti(m);
	}
	~Mreza() { brisi(); }
	Mreza& operator=(const Mreza& m) {
		if (this != &m) {
			brisi();
			kopiraj(m);
			return *this;
		}
	}
	Mreza& operator=(Mreza&& m) {
		if (this != &m) {
			brisi();
			premesti(m);
			return *this;
		}
	}
	Mreza& operator+=(GradskaLinija& g) {
		gradskelin.dodaj(&g);
		return *this;
	}
	friend ostream& operator<<(ostream& os, const Mreza& m) {
		for (m.gradskelin.naPrvi(); m.gradskelin.imaTek(); m.gradskelin.naSled()) {
			os << m.gradskelin.dohvPod()->dohvatioznaku() << " ";
			Lista<Stajaliste> s = m.gradskelin.dohvPod()->dohvatistajalista();
			Stajaliste x = s.naPrvi().dohvPod();
			os << x << " ";
			for (s.naPrvi(); s.imaTek(); s.naSled()) {
				x = s.dohvPod();
			}
			os << x << endl;


		}
		return os;
	}
	
};



#endif


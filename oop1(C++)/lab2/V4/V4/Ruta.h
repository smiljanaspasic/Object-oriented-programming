#ifndef RUTA_H
#define RUTA_H
#include <iostream>
#include "Lista.h"
#include "Deonica.h"
using namespace std;

class Ruta {

private:
	Lista<Deonica> deonice;
	void kopiraj(const Ruta& r) {
		for (r.deonice.naPrvi(); r.deonice.imaTek(); r.deonice.naSled()) {
			deonice.dodaj(deonice.dohvPod());
		}
	}
	void brisi() {
		for (deonice.naPrvi(); deonice.imaTek(); deonice.naSled()) {
			deonice.izbaciTek();
		}
	}
	void premesti(Ruta& r) {
		deonice = r.deonice;
	}
public:

	Ruta(Lista<Deonica> d) : deonice(d) {}
	Ruta(const Ruta& r) { kopiraj(r); }
	Ruta& operator=(const Ruta& r) {
		if (this != &r) {
			brisi();
			kopiraj(r);
		}
	}
	Ruta(Ruta&& r) { premesti(r); }
	Ruta& operator=(Ruta&& r) {
		if (this != &r) {
			brisi();
			premesti(r);
		}
	}
	~Ruta() { brisi(); }
	Lista<Deonica> dohvdeonice() const { return deonice; }

	friend ostream& operator<<(ostream& os, const Ruta& r) {
		for (r.deonice.naPrvi(); r.deonice.imaTek(); r.deonice.naSled()) {
			os << r.deonice.dohvPod() << endl;
		}
		return os;
	}
	double operator()(Deonica::KatVozila k) {
		double ukupnaputarina = 0;
		for (deonice.naPrvi(); deonice.imaTek(); deonice.naSled()) {
			ukupnaputarina+=deonice.dohvPod()(k);
		}
		return ukupnaputarina;
	}
	double odredilitregoriva(double potrosnja) {
		double ukkm = 0;
		for (deonice.naPrvi(); deonice.imaTek(); deonice.naSled()) {
			ukkm += ~(deonice.dohvPod());
		}
		return ukkm * potrosnja / 100;
	}

};
#endif // !RUTA_H


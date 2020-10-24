#ifndef LISTA_H
#define LISTA_H
#include <iostream>
using namespace std;

class GNemaTek {
	friend ostream& operator<<(ostream& os, const GNemaTek&) {
		return os << "Ne postoji tekuci element";
	}
};

template <typename T>
class Lista {
	struct Elem {
		T pod;
		Elem* sled;
		Elem(const T p, Elem* s = nullptr) : pod(p) {
			sled = s;
		}
	};
	Elem* prvi, *posl;
	mutable Elem* tek, *pret;
public:
	void brisi() {
		while (prvi) {
			Elem* stari = prvi;
			prvi = prvi->sled;
			delete stari;
		}
		posl = tek = pret = nullptr;
	}
	void kopiraj(const Lista& l) {
		prvi = posl = tek = pret = nullptr;
		for (Elem* pok = l.prvi; pok; pok = pok->sled) {
			posl = (!prvi ? prvi : posl->sled) = new Elem(pok->pod);
			if (pok == l.tek) tek = posl;
			if (pok == l.pret) pret = posl;
		}
	}
	void premesti(Lista& l) {
		prvi = l.prvi; posl = l.posl;
		l.prvi = l.posl = nullptr;
	}
public:
	Lista() { prvi = posl = tek = pret = nullptr; }
	Lista(const Lista& l) { kopiraj(l); }
	Lista(Lista&& l) { premesti(l); }
	Lista& operator=(const Lista& l) {
		if (this != &l) {
			brisi(); kopiraj(l);
		}
		return *this;
	}
	Lista& operator=(Lista&& l) {
		if (this != &l) {
			brisi(); premesti(l);
		}
		return *this;
	}
	~Lista() { brisi(); }
	Lista& dodaj(const T t) {
		posl = (!prvi ? prvi : posl->sled) = new Elem(t);
		return *this;
	}
	int brojpodataka() {
		int k = 0;
		for (Elem* tek = prvi; tek; tek = tek->sled) {
			k++;
		}
		return k;
	}
	const Lista& naPrvi() const { tek = prvi; pret = nullptr; return*this; }
	const Lista& naSled() const {
		pret = tek;
		if (tek) tek = tek->sled;
		return *this;
	}
	Lista& naPrvi() { tek = prvi; pret = nullptr; return *this; }
	Lista& naSled() {
		pret = tek;
		if (tek) tek = tek->sled;
		return *this;
	}
	bool imaTek() const { return tek != nullptr; }
	T& dohvPod() const {
		if (!tek) throw GNemaTek();
		return tek->pod;
	}
	Lista& izbaciTek() {
		if (!tek) throw GNemaTek();
		Elem* stari = tek;
		tek = tek->sled;
		(!pret ? prvi : pret->sled) = tek;
		if (!tek) posl = pret;
		delete stari;
		return *this;
	}
	friend ostream& operator<<(ostream& os, const Lista& l)
	{
		for (l.naPrvi(); l.imaTek(); l.naSled()) {
			os << l.dohvPod() << endl;
		}
		return os;
	}
};


#endif

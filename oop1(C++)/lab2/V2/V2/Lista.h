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
		Elem(const T& p, Elem* s = nullptr) : pod(p) {
			sled = s;
		}
	};
	Elem* prvi, *posl;
	mutable Elem* tek,*pret;
	void brisi() {
		while (prvi) {
			Elem* stari = prvi;
			prvi = prvi->sled;
			delete stari;
		}
		posl = tek = pret = nullptr;
	}
public:
	Lista() { prvi = posl = tek = pret= nullptr; }
	Lista(const Lista&) = delete;
	Lista& operator=(const Lista&) = delete;
	~Lista() { brisi(); }
	Lista& dodaj(const T& t) {
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
	void naPrvi() const { tek = prvi; pret = nullptr; }
	void naSled() const {
		pret = tek;
		if (tek) tek = tek->sled;
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

};


#endif

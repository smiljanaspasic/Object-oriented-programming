#ifndef SLIKA_H
#define SLIKA_H

#include <iostream>
#include "Piksel.h"
#include "Pozicija.h"
using namespace std;
class Slika {

protected :
	Piksel** matrica;
private:
	int sir, duz;
	
	void kopiraj(const Slika& s) {
		sir = s.sir;
		duz = s.duz;
		matrica = new Piksel*[sir];
		for (int i = 0; i < sir; i++) {
			matrica[i] = new Piksel[duz];
			for (int j = 0; j < duz; j++) {
				matrica[i][j] = Piksel(s.matrica[i][j]);
			}
		}
	}
	void premesti(Slika& s) {
		sir = s.sir;
		duz = s.duz;
		matrica = s.matrica;
		s.matrica = nullptr;
	}
	void brisi() {
		for (int i = 0; i < sir; i++) {
			delete matrica[i];
		}
		delete[] matrica;
	}
public:
	Slika(int s, int d) {
		sir = s;
		duz = d;
		matrica = new Piksel*[sir];
		for (int i = 0; i < sir; i++) {
			matrica[i] = new Piksel[duz];
			for (int j = 0; j < duz; j++) {
				matrica[i][j] = Piksel();
			}
		}
	}
	Slika(const Slika& s) { kopiraj(s); }
	Slika(Slika&& s) { premesti(s); }
	~Slika() { brisi(); }
	Slika& operator=(const Slika& s) {
		if (this != &s) { brisi(); kopiraj(s); }
		return *this;
	}
	Slika& operator=(Slika&& s) {
		if (this != &s) { brisi(); premesti(s); }
		return *this;
	}
	const Piksel& operator[](Pozicija& p) const {
		return matrica[p.dohvrs()][p.dohkol()];
	}
	virtual Slika& postavipikselnapoziciju(Piksel& p,const Pozicija& poz) {
		matrica[poz.dohvrs()][poz.dohkol()] = p;
		return *this;
	}
	int velicinaslike() const { return sir * duz * 24; }
	friend ostream& operator<<(ostream& os, const Slika& s) {
		os << s.velicinaslike() << endl;
		for (int i = 0; i < s.sir; i++) {
			for (int j = 0; j < s.duz; j++) {
				os << s.matrica[i][j];
			}
		}
		return os;
	}
};
#endif // !SLIKA_H


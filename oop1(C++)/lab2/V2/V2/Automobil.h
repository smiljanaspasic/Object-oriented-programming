#ifndef AUTOMOBIL_H
#define AUTOMOBIL_H
#include <iostream>
#include <string>
#include "Vozilo.h"
using namespace std;

class Automobil : public Vozilo {
public:
	enum Tip { KUPE, LIMUZINA };
private:
	Tip tip;
	int cenadnev;
public:
	
	Automobil(string naz, Datum dp, int cen, Tip t, int cd) : Vozilo(naz, dp, cen) {
		tip=t; cenadnev = cd;
	}
	int odredibrputnika() const override {
		if (tip == Tip::KUPE) return 2;
		else return 5;
	}
	string tipic() const {
		string s[]{ "KUPE","LIMUZINA" };
		return s[tip];
	}
	int odredicenupodanu(Datum datumpoc, bool potrebanvozac) const override {
		int cena = osncena;
		if ((datumpoc - datumproiz) < 732) cena += (15 * cena) / 100;
		if (potrebanvozac) cena += cenadnev;
		return cena;
	}
	void pisi(ostream& os) const override {
		Vozilo::pisi(os); os << "-" << tipic();
}
	friend ostream& operator<<(ostream& os, const Automobil& a) {
		a.pisi(os); return os;
	}
};

#endif // !AUTOMOBIL_H


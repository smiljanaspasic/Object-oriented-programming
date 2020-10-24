#ifndef PIKSEL_H
#define PIKSEL_H


#include <iostream>
using namespace std;

class Piksel {
	double crv, zel, pla;
public:
	Piksel(double c = 0, double z = 0, double p = 0) {
		if (c < 0 || c>255) crv = 0;
		else crv = c;
		if (p < 0 || p>255) pla = 0;
		else pla = p;
		if (z < 0 || z>255) zel = 0;
		else zel = z;
	}
	double dohvcrv() const { return crv; }
	double dohzel() const { return zel; }
	double dohpla() const { return pla; }
	friend Piksel operator+(const Piksel& p1, const Piksel& p2) {
		return Piksel((p1.crv + p2.crv) / 2, (p1.zel + p2.zel) / 2, (p1.pla + p2.pla) / 2);
	}
	friend bool operator==(const Piksel& p1, const Piksel& p2) {
		return p1.zel == p2.zel && p1.crv == p2.crv && p1.pla == p2.pla;
	}
	void pisi(ostream& os) const { os << "(" << crv << "," << zel << "," << pla << ")"; }
	friend ostream& operator<<(ostream& os, const Piksel& p) {
		p.pisi(os); return os;
	}
};
#endif // !PIKSEL_H

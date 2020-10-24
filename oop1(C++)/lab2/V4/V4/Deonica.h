#ifndef DEONICA_H
#define DEONICA_H
#include <iostream>
#include <string>
#include "Mesto.h"
class Deonica {
public:
	enum TipPuta{MAGISTRALNI,AUTOPUT};
	enum KatVozila{LAKO,TESKO};
private:
	Mesto pocmesto;
	Mesto kramesto;
	TipPuta t;
public:
	Deonica(Mesto m1, Mesto m2, TipPuta tt) {
		pocmesto = m1;
		kramesto = m2;
		t = tt;
	}
	friend double operator~(const Deonica& d) {
		return (d.pocmesto - d.kramesto);
	}
	string tipicPUT() const {
		string s[]{ "MAGISTRALNI","AUTOPUT" };
		return s[t];
	}
	Mesto dohvpocmes() const { return pocmesto; }
	Mesto dohvkrames() const { return kramesto; }
	double operator()(KatVozila k) {
		if (t == TipPuta::AUTOPUT) {
			if (k == KatVozila::LAKO) return (pocmesto - kramesto) * 12;
			else return (pocmesto - kramesto) * 12;
		}
		else return 0;
	}
	friend ostream& operator<<(ostream& os, const Deonica& d) {
		return os << d.tipicPUT() << "[" << d.pocmesto << "->" << d.kramesto << "]" << "-" << ~(d) << "km";
	}
};
#endif // !DEONICA_H


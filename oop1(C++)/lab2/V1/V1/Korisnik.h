#ifndef KORISNIK_H
#define KORISNIK_H


#include <iostream>
#include <ctype.h>
#include <cstdlib>
#include <string>

using namespace std;

class GFormat{
	friend ostream& operator<<(ostream& os, const GFormat&) {
		return os << "Greska u formatu";
}
};
class GTek {
	friend ostream& operator<<(ostream& os, const GTek&) {
		return os << "Greska!Nepoklapanje stare i unete lozinke";
	}
};

class Korisnik {
	string ime, lozinka;
	int flagslovo = 0;
	int flagcifra = 0;
public:
	Korisnik(string i, string loz) {
		lozinka = loz;
		ime = i;
		if (loz.length() < 8) throw GFormat();
		else {
	for (int brojac = 0; brojac < loz.length(); brojac++) {
				if (isdigit(loz[brojac])) flagcifra = 1;
				if (isalpha(loz[brojac])) flagslovo = 1;
			}
			if (flagcifra != 1 || flagslovo != 1) throw GFormat();
		}
		
	}
	string getime() const { return ime; }
	string getlozinka() const { return lozinka; }

	void setloz(string lozstara,string loznova) {
		flagslovo = 0;
		flagcifra = 0;
		if (lozstara != getlozinka()) throw GTek();
		if (loznova.length() < 8) throw GFormat();
		else {
			for (int brojac = 0; brojac < loznova.length(); brojac++) {
				if (isdigit(loznova[brojac])) flagcifra = 1;
				if (isalpha(loznova[brojac])) flagslovo = 1;
			}
			if (flagcifra != 1 || flagslovo != 1) throw GFormat();
			
		}
		lozinka = loznova;
	}
	friend bool operator==(const Korisnik& k1, const Korisnik& k2) {
		if (k1.getime() == k2.getime()) return true;
	}
	friend ostream& operator<<(ostream& os, const Korisnik& k) {
		return os << k.getime();
	}

};
#endif // !KORISNIK_H
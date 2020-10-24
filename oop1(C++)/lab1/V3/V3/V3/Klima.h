#ifndef KLIMA_H
#define KLIMA_H
#include <iostream>
using namespace std;
#include "Uredjaj.h"
class Klima : public Uredjaj {
	int brkvad;
public:
	Klima(int br, string p) : Uredjaj(p) { brkvad = br; }
	Klima& postavigaranciju(Datum& dpoc) {
		this->g= new Garancija(dpoc, Datum(dpoc["dan"], dpoc["mesec"], dpoc["godina"] + 5));
		return *this;
	}
	int nakoliko() const override { return 2; }
	friend bool operator==(const Klima& k1, const Klima& k2) {
		if (k1.proizv==k2.proizv && k1.brkvad == k2.brkvad) return true;
	}
	friend ostream& operator<<(ostream& os, const Klima& k) {
		 os << k.proizv << k.id << "#klima-" << k.brkvad;
		return os;
	}
};
#endif // !KLIMA_H
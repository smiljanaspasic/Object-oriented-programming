#ifndef UREDJAJ_H
#define UREDJAJ_H
#include "Garancija.h"
#include <iostream>
using namespace std;
class Uredjaj {
	
	static int posid;
	
protected:
	int id = ++posid;
	Garancija* g;
	string proizv;
public:
	Uredjaj(string p) { proizv = p; }
	virtual Uredjaj& postavigaranciju(Datum& dpoc) = 0;
    Garancija& dohvatigaraciju() const { return *g; }
	virtual int nakoliko() const = 0;
	friend bool operator==(const Uredjaj& u1, const Uredjaj& u2) {
		if (u1.proizv == u2.proizv) return true;
	}
	Uredjaj(const Uredjaj&) = delete;
	Uredjaj& operator=(const Uredjaj&) = delete;
	
	friend ostream& operator<<(ostream& os, const Uredjaj& u) {
		return os << u.proizv << u.id;
	} 
};
int Uredjaj::posid = 0;
#endif // !UREDJAJ_H


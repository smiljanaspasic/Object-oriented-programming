#ifndef VOZILO_H
#define VOZILO_H
#include <iostream>
#include "Datum.h"
#include <string>
using namespace std;
class Vozilo {
	string naziv;

protected:
	int osncena;
	Datum datumproiz;
public:
	Vozilo(string naz, Datum dp, int cen) {
		naziv = naz; datumproiz = dp; osncena = cen;
	}
	virtual int odredibrputnika() const = 0;
	virtual int odredicenupodanu(Datum datumpoc,bool potrebanvozac) const = 0;
	Vozilo(const Vozilo&) = delete;
	virtual void pisi(ostream& os) const {
		os << naziv << odredibrputnika() << "-" << datumproiz;
	}
	friend ostream& operator<<(ostream& os,const Vozilo& v) {
		v.pisi(os); return os;
	}
};

#endif

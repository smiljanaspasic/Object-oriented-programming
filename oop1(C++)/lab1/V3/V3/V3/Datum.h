#ifndef DATUM_H
#define DATUM_H


#include <stdlib.h>
#include <iostream>
using namespace std;

class Datum {
	int dan, mes, god;
public:
	Datum(int d = 30, int m = 11, int g = 2019) {
		dan = d; mes = m; god = g;
	}
	const int operator[](string z) const {
		if (z == "dan") return dan;
		if (z == "mesec") return mes;
		if (z == "godina") return god;
		else return -1;
	}
	friend bool operator<(const Datum& d1, const Datum& d2) {
		if ((d1.god < d2.god) || ((d1.god == d2.god) && (d1.mes < d2.mes)) || ((d1.god == d2.god) && (d1.mes == d2.mes) && (d1.dan < d2.dan))) return true;
		else return false;
	}
	void pisi(ostream& os, const Datum& d) const {
		os << d.dan << "." <<  d.mes << "." << d.god << ".";
	}
	friend ostream& operator<<(ostream& os,const Datum& dat) {
		dat.pisi(os, dat); return os;
	}
};
#endif
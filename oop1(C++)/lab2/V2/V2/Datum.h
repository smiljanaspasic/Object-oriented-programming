#ifndef DATUM_H
#define DATUM_H
#include <iostream>
#include <time.h>
using namespace std;

class GPre {
	friend ostream& operator<<(ostream& os, const GPre&) {
		return os << "Datum 1 je pre datuma 2";
	}
};
class GDrugaNiska {
	friend ostream& operator<<(ostream& os, const GDrugaNiska&) {
		return os << "Nije prosledjena dobra niska";
	}
};

class Datum {
	int dan, mes, god;
public:
	Datum(int d = 28, int m = 12, int g = 2019) {
		dan = d; mes = m; god = g;
	}
	friend bool operator<(const Datum& d1, const Datum& d2) {
		if ((d1.god < d2.god) || ((d1.god == d2.god) && (d1.mes < d2.mes)) || ((d1.god == d2.god) && (d1.mes == d2.mes) && (d1.dan < d2.dan))) return true;
		else return false;
	}
	
	friend int operator-(const Datum& d1, const Datum& d2) {
		if (d1 < d2) throw GPre();
		int brojdana = 0;
	    brojdana = (d1.god - d2.god)*365;
	    brojdana += (d1.mes - d2.mes)*30;
	    brojdana += (d1.dan - d2.dan);
	    return brojdana;
			
	}

		

	const int operator[](string z) const {
		if (z == "dan") return dan;
		if (z == "mesec") return mes;
		if (z == "godina") return god;
		else throw GDrugaNiska();
	}
	void pisi(ostream& os, const Datum& d) const {
		os << d.dan << "." << d.mes << "." << d.god << ".";
	}
	friend ostream& operator<<(ostream& os, const Datum& dat) {
		dat.pisi(os, dat); return os;
	}
};


#endif

#ifndef KVAR_H
#define KVAR_H

#include <string>
#include <cstdlib>
#include <iostream>
#include "Datum.h"
using namespace std;

class Kvar {
	string opis;
	Datum d;
	bool otklonjen=false;
public:
	Kvar(string o,Datum dd) {
		opis = o;
		dd = d;
	}
	string dohvatiopis() const { return opis; }
	Datum dohvdat() const {
		return d;
	}
	bool dohinfo() const {
		return otklonjen;
	}
	void postaviinfo(bool i) { otklonjen = i;  }
	friend ostream& operator<<(ostream& os,const Kvar & k) {
		return os << k.d << "-" << k.opis; 
	}
}; 
#endif 

#ifndef MESTO_H
#define MESTO_H
#include <iostream>
#include <math.h>
#define precnikzemlje 6371
using namespace std;
class Mesto {
	string naziv;
	double gsir;
	double gduz;
public:
	Mesto() { gsir = gduz = 0; naziv = ""; }
	Mesto(string n, double gs, double gd) {
		naziv = n; gsir = gs; gduz = gd;
	}
	string dohvnaziv() const { return naziv; }
	double dohvsir() const { return gsir; }
	double dohvduz() const { return gduz; }
	friend double operator-(const Mesto& m1, const Mesto& m2) {
		
		return 2 * precnikzemlje*asin(sqrt((sin(pow((m1.gsir - m2.gsir) / 2, 2))) + (cos(m1.gsir)*cos(m2.gsir)*(sin(pow((m1.gduz - m2.gduz) / 2, 2))))));
	}
	friend ostream& operator<<(ostream& os, const Mesto& m) {
		return os << m.naziv << "(" << m.gduz << "," << m.gsir << ")";
	}
};

#endif // !MESTO_H
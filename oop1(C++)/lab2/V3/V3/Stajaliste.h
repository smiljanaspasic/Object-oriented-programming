#ifndef STAJALISTE_H
#define STAJALISTE_H
#include <iostream>
#include <string>
using namespace std;

class Stajaliste {
	int ozn,zona;
	string naziv;
public:
	Stajaliste(int o, int z, string n) {
		ozn = o; zona = z; naziv = n;
	}
	int dohvatioznaku() const { return ozn; }
	int dohvatizonu() const { return zona; }
	string dohvatinaziv() const { return naziv; }
	friend bool operator==(const Stajaliste& s1, const Stajaliste& s2) {
		if (s1.dohvatinaziv() == s2.dohvatinaziv()) return true;
		else return false;
	}
	friend ostream& operator<<(ostream& os, const Stajaliste& s) {
		return os << "[" << s.dohvatizonu() << "]" << "#" << s.dohvatioznaku() << "-" << s.dohvatinaziv();
	}
};
#endif // !STAJALISTE_H


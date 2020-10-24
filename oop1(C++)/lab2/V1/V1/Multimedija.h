#ifndef MULTIMEDIJA_H
#define MULTIMEDIJA_H
#include <iostream>
using namespace std;

class Multimedija {
private:
	string ime;
public:
	Multimedija(string i) {
		ime = i;
	}
	virtual int dohvativelicinu() const = 0;
	virtual string dohvatiopis() const = 0;
	friend ostream& operator<<(ostream& os, const Multimedija& m) {
		return os << m.ime << ":" << m.dohvatiopis();
	}

};

#endif // !MULTIMEDIJA_H


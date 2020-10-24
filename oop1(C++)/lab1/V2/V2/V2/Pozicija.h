#ifndef POZICIJA_H
#define POZICIJA_H



using namespace std;

class Pozicija {
	int vrs, kol;
public:
	Pozicija(int v, int k) {
		vrs = v; kol = k;
	}
	int dohvrs() const { return vrs; }
	int dohkol() const { return kol; }
	friend int operator-(const Pozicija& p1, const Pozicija& p2) {
		return (p1.vrs - p2.vrs) + (p2.kol - p2.kol);
	}
};
#endif // !POZICIJA_H
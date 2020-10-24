#ifndef POLJE_H
#define POLJE_H


#include <iostream>
using namespace std;

class Polje {
	int neprohodnost;

public:
	
	Polje(int nep = 100) {
		neprohodnost = nep;
	}
	int dohvneprohodnost()  { return neprohodnost; }
	virtual char oznaka() const { return 'P'; }
	Polje& operator++(int) {
		if (neprohodnost < 1000) neprohodnost++;
		return *this;
	}
	Polje& operator--(int) {
		if (neprohodnost > 0) neprohodnost--;
		return *this;
	}
	virtual void pisi(ostream& os) const { os << oznaka() << "_" << neprohodnost; }
	friend ostream& operator<<(ostream& os, const Polje& p) {
		p.pisi(os); return os;
	}

};

#endif // !POLJE_H
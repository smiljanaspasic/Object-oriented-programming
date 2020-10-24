#ifndef POLJESASUMOM_H
#define POLJESASUMOM_H

#include <iostream>
using namespace std;
#include "Polje.h"

class PoljeSaSumom : public Polje {
	int gustina;
public:
	PoljeSaSumom(int gus, int nep = 100) : Polje(nep) {
		if (gus < 0) gus = 0;
		gustina = gus;
	}
	virtual char oznaka() const override { return 'S'; }
	void pisi(ostream& os) const override {
		Polje::pisi(os); os << '(' << gustina << ')';
	
	}
};

#endif // 
#ifndef POLJESAPUTEM_H
#define POLJESAPUTEM_H

#include <iostream>
using namespace std;
#include "Polje.h"
enum VrstaPuta {ZEMLJANI,KAMENI};
class PoljeSaPutem : public Polje {
	VrstaPuta vp;
	
public:
	
	PoljeSaPutem(VrstaPuta v, int n=100) : Polje(n) {
		vp = v;
		
	}
	virtual char oznaka() const override {
		if (vp == ZEMLJANI) return 'Z';
		else return 'K';
	}
};

#endif // 
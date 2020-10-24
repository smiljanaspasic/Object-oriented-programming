#include "Mapa.h"
#include "Polje.h"
#include "PoljeSaSumom.h"
#include "PoljeSaPutem.h"
#include <iostream>
using namespace std;

int main() {
	Polje p(300);
	PoljeSaPutem psp(VrstaPuta::ZEMLJANI);
	PoljeSaPutem psp2(VrstaPuta::KAMENI);
	PoljeSaSumom pss(30);
	p++; p++; p++; p++; p++; p--;
	cout << p << endl;
	psp++; psp++; psp++; psp--;
	pss++; pss++; pss++; pss--;  pss--; pss++;
	cout << psp << endl;
	cout << psp2 << endl;
	cout << pss << endl;
	cout << p.dohvneprohodnost() << endl;
	Mapa m(3,3);
	m.zamenisasumom(30, 2, 1);
	cout << m;
}
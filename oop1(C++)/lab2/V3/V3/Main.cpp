#include <iostream>
#include <string>
using namespace std;
#include "Lista.h"
#include "Stajaliste.h"
#include "Gradska_Linija.h"
#include "Mreza.h"
int main() {
	while (1) {
		int k;
		cin >> k;
		try {
			Stajaliste s(3, 2, "Borca");
			Stajaliste s2(3, 1, "Borca3");
			Stajaliste s3(3, 1, "Borca35");
			Stajaliste s4(1, 1, "Vukov spomn");
			cout << s << endl;
			Lista<Stajaliste> r1;
			r1.dodaj(s).dodaj(s2).dodaj(s4);
			GradskaLinija l1("eukaliptus",r1);
			Lista<Stajaliste> r2;
			r2.dodaj(s2).dodaj(s3).dodaj(s4);
			GradskaLinija l2("klackalica",r2);
			cout << (l1 & l2 ) << endl;
			
			GradskaLinija l3 = l2;
			cout << l3;
			Mreza m1;
			m1 += l1;
			m1 += l2;
			m1 += l3;
			Mreza m2 = m1;
			cout << m2;
			
		}
		catch (GNemaTek g) { cout << g << endl; }
	}
}
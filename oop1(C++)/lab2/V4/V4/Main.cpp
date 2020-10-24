#include <iostream>
#include <string>
using namespace std;
#include "Lista.h"
#include "Mesto.h"
#include "Deonica.h"
#include "Ruta.h"

int main() {
	while (1) {
		int k;
		cin >> k;
		try {
			Mesto m("Beograd", 1115, 15);
			Mesto m2("Novi Sad", 90, 24);
			Mesto m3("Nis", 30, 1214);
			Mesto m4("Kragujevac", 35, 75);
			cout << (m - m2) << endl;
			cout << m << endl;
			Deonica d1(m, m2, Deonica::AUTOPUT);
			Deonica d2(m3, m4, Deonica::AUTOPUT);
			cout << ~(d1) << endl;
			cout << ~(d2) << endl;
			Lista<Deonica> ld;
			ld.dodaj(d1);
			ld.dodaj(d2);
			Ruta ruta(ld);
			ruta(Deonica::LAKO);
			cout << ruta << endl;
		}
		catch (GNemaTek g) { cout << g << endl; }
	}
}
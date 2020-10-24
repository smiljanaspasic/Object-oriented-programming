#include <iostream>
using namespace std;
#include "Lista.h"
#include "Datum.h"
#include "Vozilo.h"
#include "Automobil.h"
int main() {
	while (1) {
		int k;
		cin >> k;
		try {
			Datum d1;
			Datum d2(30, 12, 2008);
			cout << d1 - d2 << endl;
			cout << d1["dan"] << endl;
			cout << d2 << endl;
			Automobil a("Fiat", d2, 32, Automobil::KUPE, 60);
			cout << a.odredibrputnika() << endl;
			cout << a.odredicenupodanu(d1,false) << endl;
			cout << a << endl;

		}
		catch (GNemaTek g) { cout << g << endl; }
		catch (GDrugaNiska g) { cout << g << endl; }
		catch (GPre g) { cout << g << endl; }
	}
}
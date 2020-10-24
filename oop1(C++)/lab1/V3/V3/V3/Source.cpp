#include "Garancija.h"
#include "Datum.h"
#include "Klima.h"
#include "Kvar.h"
#include "Uredjaj.h"

int main() {
	Datum d1;
	Datum d2(31, 12, 2019);
	Datum d3(1, 1, 2020);
	Kvar k("nesto",d1);
	Garancija g(d2, d3);
	Klima k1(4, "opis");
	cout << d1 << endl;
	cout << d2 << endl;
	cout << d3 << endl;
	cout << k << endl;
	k.postaviinfo(true);
	cout << g << endl;
	cout << k1 << endl;
	Datum d5(12, 11, 1999);
	Datum d4(11, 11, 1222);
	Kvar k3("pavlaka",d5);
	Kvar k32("pavlakasasirom", d4);
	k3.postaviinfo(false);
	k32.postaviinfo(false);
	g.dodajkvar(k3).dodajkvar(k32);
	cout << g;
}
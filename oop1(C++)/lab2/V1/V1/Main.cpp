#include <iostream>
#include "Korisnik.h"
#include "Lista.h"
#include "Multimedija.h"
#include "Slika.h"
#include "Evidencija.h"

using namespace std;

int main() {
	while (true) {
		int k;
		cin >> k;
		try {
			Korisnik k4("Seka", "ovasifrajeispravna123");
			cout << k4.getime() << " " << k4.getlozinka() << endl;
			k4.setloz("ovasifrajeispravna123", "Arsenije26");
			cout << k4.getlozinka() << endl;
			Korisnik k5("Nemasyina", "ucimobjektno242");
			cout << k4 << k5 << endl;
			Slika s(20, 20, 20,"slika");
			cout << s << endl;
			Evidencija e;
			e += k4;
			e += k5;
			cout << e["Nemasyina"] << endl;
			e("Nemasyina");
			
			e.promenalozinke("Seka", "Arsenije26", "smorsmor234");
			cout << k4.getlozinka();
			
		}
		catch (GFormat g) { cout << g << endl; }
		catch (GTek g) { cout << g << endl; }
		catch (GPodne g) { cout << g << endl; }
		catch (GPostojiKor g) { cout << g << endl; }
		catch (GNEPostojiKor g) { cout << g << endl; }
	}
}

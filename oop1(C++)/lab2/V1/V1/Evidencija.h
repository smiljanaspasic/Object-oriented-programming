

#ifndef EVIDENCIJA_H
#define EVIDENCIJA_H




#include "Lista.h"
#include "Korisnik.h"
#include <iostream>
#include <string>
using namespace std;

class GPostojiKor {
	friend ostream& operator<<(ostream& os, const GPostojiKor&) {
		return os << "Korisnik sa zadatim korisnickim imenom vec postoji";
	}

};

class GNEPostojiKor {
	friend ostream& operator<<(ostream& os, const GNEPostojiKor&) {
		return os << "Korisnik sa zadatim korisnickim imenom ne postoji";
	}

};

class Evidencija {
	Lista <Korisnik*> korisnici;
public:
	Evidencija() = default;
	Evidencija(const Evidencija&) = delete;
	Evidencija& operator=(const Evidencija&) = delete;


	Evidencija& operator+=(Korisnik& k) {
		for (int i = 0; i < korisnici.brojpodataka(); i++) {
			if (korisnici[i]->getime() == k.getime()) throw GPostojiKor();
		}
		korisnici += &k;
		return *this;
	}
	Korisnik& operator[](string ime) {
		for (int i = 0; i < korisnici.brojpodataka(); i++) {
			if (korisnici[i]->getime().compare(ime) == 0) return *korisnici[i];
		}
		throw GNEPostojiKor();
	}
	Evidencija& operator()(string ime) {
		for (int i = 0; i < korisnici.brojpodataka(); i++) {
			if (korisnici[i]->getime().compare(ime) == 0) { korisnici(i); return *this; }
		}
		throw GNEPostojiKor();
	}
	Evidencija& promenalozinke(string ime, string stara, string nova) {
		for (int i = 0; i < korisnici.brojpodataka(); i++) {
			if (korisnici[i]->getime().compare(ime) == 0) {
				korisnici[i]->setloz(stara, nova);
				return *this;
			}
			throw GNEPostojiKor();
		}
	}
	};




#endif

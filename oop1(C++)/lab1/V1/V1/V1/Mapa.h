#ifndef MAPA_H
#define MAPA_H

#include <iostream>
using namespace std;
#include "Polje.h"
#include "PoljeSaPutem.h"
#include "PoljeSaSumom.h"
class Mapa {
	int vrsta, kolona;
	Polje*** matrica;
	void kopiraj(const Mapa& m) {
		vrsta = m.vrsta;
		kolona = m.kolona;
		matrica = new Polje**[vrsta];
		for (int i = 0; i < vrsta; i++) {
			matrica[i] = new Polje*[kolona];
			for (int j = 0; j < kolona; j++) {
				matrica[i][j] = m.matrica[i][j];
			}
		}
	}
	void premesti(Mapa& m) {
		vrsta = m.vrsta;
		kolona = m.kolona;
		matrica = m.matrica;
		m.matrica = nullptr;
	}
	void brisi() {
		for (int i = 0; i < vrsta; i++) {
			delete matrica[i];
		}
		delete[] matrica;
	}
public:
	Mapa(int v, int k) {
		vrsta = v;
		kolona = k;
		matrica = new Polje**[vrsta];
		for (int i = 0; i < vrsta; i++) {
			matrica[i] = new Polje*[kolona];
			for (int j = 0; j < kolona; j++) {
				matrica[i][j] = Polje();
		    }
	    }
    }

 
	Mapa(const Mapa& m) { kopiraj(m); }
	Mapa(Mapa&& m) { premesti(m); }
	Mapa& operator=(const Mapa& m) {
		if (this != &m) { brisi(); kopiraj(m); }
		return *this;
	}
	Mapa& operator=(Mapa&& m) {
		if (this != &m) { brisi(); premesti(m); }
	return *this;
	}
	~Mapa() { brisi(); }

	Mapa& zamenisaputem(VrstaPuta v,int i,int j) {
		matrica[i][j] = PoljeSaPutem(v, matrica[i][j].dohvneprohodnost());
		return *this;


	}
	Mapa& zamenisasumom(int gust, int i, int j) {
		PoljeSaSumom p = PoljeSaSumom(gust, matrica[i][j].dohvneprohodnost());
		matrica[i][j] = p;
			return *this;
	}
	Mapa& operator+=(int nep) {
		for (int i = 0; i < vrsta; i++) {
			for (int j = 0; j < kolona; j++) {
				int k = nep;
				while (k > 0) {
					(matrica[i][j])++;
					k--;
				}
			}
		}
		return*this;
	}
	Mapa& operator-=(int nep) {
		for (int i = 0; i < vrsta; i++) {
			for (int j = 0; j < kolona; j++) {
				int k = nep;
				while (k > 0) {
					matrica[i][j]--;
					k--;
				}
			}
		}
		return *this;
	}
	friend ostream& operator<<(ostream&os, const Mapa& m) {
		
			for (int i = 0; i < m.vrsta; i++) {
				for (int j = 0; j < m.kolona; j++) {
					m.matrica[i][j].pisi(os); os << "\t";
					if (j==m.kolona-1) os << endl;


				}
			} 
			return os;
	}
		
	
};
#endif // 
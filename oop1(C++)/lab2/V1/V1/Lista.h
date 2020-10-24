#ifndef LISTA_H
#define LISTA_H



#include <iostream>
using namespace std;

class GPodne {
	friend ostream& operator<<(ostream& os, const GPodne&) {
		return os << "Podatak ne postoji";
	}
};

template <typename T>
class Lista {
private:
	struct Elem {
		T pod;
		Elem* sled;
		Elem(const T& p, Elem* s=nullptr) : pod(p) {
			sled = s;
		}
	};
	Elem* prvi, *posl;
	void kopiraj(const Lista& l) {
		prvi = posl = nullptr;
		for (Elem* tek = l.prvi; tek; tek = tek->sled) {
			posl = (!prvi ? prvi : posl->sled) = new Elem(tek->pod);
		}
	}
	void premesti(Lista& l) {
		prvi = l.prvi; posl = l.posl;
		l.prvi = l.posl = nullptr;
	}
	void brisi() {
		while (prvi) {
			Elem* stari = prvi;
			prvi = prvi->sled;
			delete stari;
		}
	}
public:
	Lista() { prvi = posl = nullptr; }
	Lista(const Lista& l) { kopiraj(l); }


	Lista& operator+=(const T& t) {
		posl = (!prvi ? prvi : posl->sled) = new Elem(t);
		return *this;
	}

	Lista(Lista&& l) { premesti(l); }
	~Lista() { brisi(); }
	Lista& operator=(const Lista& l) {
		if (this != &l) {
			brisi(); kopiraj(l);
		}
		return *this;
	} 
	Lista& operator=(Lista&& l) {
		if (this != &l) {
			brisi(); premesti(l);
		}
		return *this;
	}
	int brojpodataka() {
		int k = 0;
		for (Elem* tek=prvi; tek; tek = tek->sled) {
			k++;
		}
		return k;
	}
	T& operator[](int i) {
		if (i < 0 || i >= brojpodataka()) throw GPodne();
			Elem* tek=prvi;
			for(;i>0;i--,tek=tek->sled);
			return tek->pod;
	}
	const T& operator[](int i) const {
		if (i < 0 || i>= brojpodataka()) throw GPodne();
		return const_cast<Lista&>(*this)[i];
	}
	Lista& operator()(int i) {
		if (i < 0 || i >= brojpodataka()) throw GPodne();
			Elem* tek=prvi;
			Elem* preth=nullptr;
			for (; i > 0; i--,preth=tek, tek = tek->sled);
			preth->sled=tek->sled;
			tek->sled=nullptr;
			delete tek;
			return *this;

	}
};

#endif // !LISTA_H
package raspored;

public class Ponavljajuci extends Sadrzaj {

	private Vreme perioda;

	public Ponavljajuci(String naziv, Vreme trajanje, Vreme peri) {
		super(naziv, trajanje);
		perioda = peri;
	}

	@Override
	public Vreme preklapaSe(Sadrzaj s2) {
		int prvoPocetno = vPoc.vrememin();
		int prvoZavrsno = Vreme.saberi(vPoc, vtraj).vrememin();
		int drugoPocetno = s2.dohvPocetak().vrememin();
		int drugoZavrsno = Vreme.saberi(s2.dohvPocetak(), s2.getVtraj()).vrememin();
		for (int prvoZavrsno1 = prvoZavrsno, prvoPocetno1 = prvoPocetno; prvoZavrsno1 <= 1440; prvoZavrsno1 += perioda
				.vrememin(), prvoPocetno1 += perioda.vrememin()) {
			for (int drugoZavrsno1 = drugoZavrsno, drugoPocetno1 = drugoPocetno; drugoZavrsno1 <= 1440; drugoZavrsno1 += perioda
					.vrememin(), drugoPocetno1 += ((Ponavljajuci) s2).perioda.vrememin()) {
				if (prvoPocetno1 >= drugoPocetno1 && prvoPocetno1 < drugoZavrsno1)
					try {
						return new Vreme(prvoPocetno1 / 60, prvoPocetno1 % 60);
					} catch (GVreme e) {
						
						e.printStackTrace();
					}
				else if (drugoPocetno1 >= prvoPocetno1 && drugoPocetno1 < prvoZavrsno1)
					try {
						return new Vreme(drugoPocetno1 / 60, drugoPocetno1 % 60);
					} catch (GVreme e) {
						
						e.printStackTrace();
					}
				else
					continue;
			}
		}
		return null;
	}
public Vreme poslednjeponavljanje() throws GVreme {
	int prvoPocetno = vPoc.vrememin();
	int prvoZavrsno = Vreme.saberi(vPoc, vtraj).vrememin();
	while( prvoZavrsno <= 1440) {
		prvoZavrsno += perioda.vrememin();
		prvoPocetno += perioda.vrememin();
	}
     int pocetak=prvoZavrsno-perioda.vrememin();
		return new Vreme(pocetak/60,pocetak%60);
	}

	@Override
	public char vrsta() {
		return 'P';
	}
public Vreme dohvperiodu() { 
	return perioda;
}
	public String toString() {
		return super.toString() + "T" + perioda;
	}
}

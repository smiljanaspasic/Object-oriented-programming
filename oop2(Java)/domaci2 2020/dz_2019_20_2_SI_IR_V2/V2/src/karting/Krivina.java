package karting;

public class Krivina extends Specificnost  {
private double zadatVmax;

	public Krivina(double maxx) {
	zadatVmax=maxx;
}
public double max() {
	return zadatVmax;
}
	@Override
	public void ispoljiEfekat(Object obj) throws GNeodgovarajuciObjekat {
		if(!(obj instanceof Vozilo)) throw new GNeodgovarajuciObjekat();
		Vozilo v = (Vozilo) obj;
		if(zadatVmax<v.dohvMaksBrzinu()) {
			v.postMaksBrzinu(zadatVmax*v.dohvUpravljivost());
		}

	}

	@Override
	public void ponistiEfekat(Object o) throws GNeodgovarajuciObjekat {
		if (!(o instanceof Vozilo))
			throw new GNeodgovarajuciObjekat();
		Vozilo v = (Vozilo) o;
		v.postMaksBrzinu(v.dohvV0()); 
	}
	@Override
	public Krivina clone() {
		return (Krivina)super.clone();
	}
	public String toString() {
		return "K"+zadatVmax;
	}

}

package karting;

public class Vozilo {
private double vmax;
private double a;
private double uprav;
private String ime;
private double vtren=0;
private double v0;
public Vozilo(double vm,double ubrz,double upr,String i) {
	vmax=vm;
	a=ubrz;
	uprav=upr;
	ime=i;
	v0=vm;
}

public void postV0(double v00) { v0=v00;}
public void postMaksBrzinu(double vmm) { vmax=vmm; if(vtren>vmm) { vtren=vmm; }}
public void postUbrzanje(double aa) { a=aa; }
public void postUpravljivost(double u) { uprav=u; }
public void postTrenBrzinu(double tren) {  vtren=tren; }
public void postIme(String nime) { ime=nime; }
public double dohvMaksBrzinu() { return vmax; }
public String dohvIme() { return ime; }
public double dohvUbrzanje() { return a;}
public double dohvUpravljivost() { return uprav; }
public double dohvTrenBrzinu() { return vtren; }
public double dohvV0() { return v0;}

public double pomeriVozilo(double t) {
	double tx = (vmax-vtren)/a;
	double s = 0;
	if (t < tx) {
		s=vtren*t+(a*t*t)/2;
		vtren = vtren + a*t;
	} else {
		s = vtren*tx+(a*tx*tx)/2 + (t - tx) * vmax;
		vtren = vmax;
	}
	return s;
}

public double izracunajVreme(double s) {
	double sx = (vmax*vmax - vtren*vtren) / (2 * a);
	if (s <= sx) {
		 return (-vtren+Math.sqrt(vtren*vtren+2*a*s))/a;
	} else {
		return (vmax-vtren)/a + (s - sx) / vmax;
	}
}


public String toString() {
	return ime + " ["+vmax+", "+a+", "+uprav+"]";
} }


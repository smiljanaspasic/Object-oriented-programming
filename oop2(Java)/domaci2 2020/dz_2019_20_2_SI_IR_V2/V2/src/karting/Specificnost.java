package karting;

public abstract class Specificnost implements Cloneable {
private static int posid=0;
private int id=++posid;

public abstract void ispoljiEfekat(Object v) throws GNeodgovarajuciObjekat;

public abstract void ponistiEfekat(Object v) throws GNeodgovarajuciObjekat;


public int dohvatiId() {
	return id; } 

public Specificnost clone() {
	Specificnost spec = null;
	try{
		spec = (Specificnost)super.clone();
		spec.id=++posid;
		
	} 
	catch(CloneNotSupportedException e) {}
	return spec;
} }
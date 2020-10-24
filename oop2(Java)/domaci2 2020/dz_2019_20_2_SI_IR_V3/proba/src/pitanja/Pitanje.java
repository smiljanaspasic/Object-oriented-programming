package pitanja;

public class Pitanje implements Cloneable {

private String text;
private double tezina;
private int brojpoena;
private static int posId=0;
private int id= ++posId;


public Pitanje(String string, int i, double d)  {
	text=string;
	tezina=d;
	brojpoena=i;
}


public String getText() {
	return text;
}


public double getTezina() {
	return tezina;
}


public int getBrojpoena() {
	return brojpoena;
}

public Pitanje clone() {
	try { return (Pitanje) super.clone();}
	catch(CloneNotSupportedException g) { return null;}
}


@Override
public String toString() {
	return "Pitanje " + id + ":" + text  ;
}




}

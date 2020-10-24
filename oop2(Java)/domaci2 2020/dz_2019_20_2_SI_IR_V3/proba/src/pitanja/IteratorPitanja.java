package pitanja;
import pitanja.ZbirkaPitanja.Elem;

public class IteratorPitanja {
	
private Elem current=null;
public IteratorPitanja(Elem first) {
	this.current=first;
}
public boolean postoji() {
return current!=null;
}
public Pitanje dohvati() throws GNemaPitanja {
	if(!postoji()) throw new GNemaPitanja();
	return current.p;
}
public IteratorPitanja sledece() throws GNemaPitanja {
	if(!postoji()) throw new GNemaPitanja();
	current=current.sled;
	return this;
	
}

}

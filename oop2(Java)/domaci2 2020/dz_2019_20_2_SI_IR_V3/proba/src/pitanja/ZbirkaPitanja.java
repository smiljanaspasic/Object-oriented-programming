package pitanja;


public class ZbirkaPitanja {
	private Elem prvi,posl;
	public class Elem {
		Pitanje p;
		Elem pret,sled;
		Elem(Pitanje pp) {
			p=pp;
			sled=null;
			pret=posl;
			if(prvi==null) prvi=this; 
			else posl.sled=this;
			posl=this;
		}
	}
	public ZbirkaPitanja dodaj(Pitanje p3) {
	  new Elem(p3);  return this;
	}
    
	public int trenbrojpitanja() throws GNemaPitanja {
		int broj=0;
	 	for(IteratorPitanja iterr=iterator();iterr.postoji();iterr.sledece()) {
	 		broj++;
	 	}
	 	return broj;
	}
	
	public Pitanje dohvati(int i) throws GNemaPitanja {
		if (i<0 || i>=trenbrojpitanja()) throw new GNemaPitanja();
		IteratorPitanja iter=iterator();
		for(int iks=0;iks<i;iks++) {
				iter.sledece();
		}
		return iter.dohvati();
		}
		
		public String toString()  {
		IteratorPitanja iter=iterator();
		   StringBuilder s=new StringBuilder();
		   try {
			for(int iks=0;iks<trenbrojpitanja();iks++) {
			      s.append(iter.dohvati()).append("\n");
			      iter.sledece();
			   }
		} catch (GNemaPitanja e) {
		
			e.printStackTrace();
		}
		   return s.toString();
		}
	

	public IteratorPitanja iterator() {
		return new IteratorPitanja(prvi);
	}

}
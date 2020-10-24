package raspored;



public class Sema {
    private Vreme pocseme;
    private Vreme krajseme;
    private String naziv;
    private Elem prvi,posl,tek;
    private class Elem {
    	Sadrzaj s;
    	Elem sled;
    	Elem pret;
    	Elem(Sadrzaj sad) {
    		s=sad;
    		sled=null;
    		pret=null;
    } }
	public Sema(String niska) throws GVreme {
		
			pocseme=new Vreme(8,0);
		
			krajseme=new Vreme(22,0);
		
		naziv=niska;
	}
	public Sema(String niska,Vreme v1,Vreme v2)  {
		
		pocseme=v1;
	
		krajseme=v2;
	
	naziv=niska;
}

	public void dodaj(Sadrzaj s1) throws GDodaj, GVreme {
		boolean flagisa=true;
		boolean flag2=true;
		Ponavljajuci pon=null;
		while(flagisa==true) {
			int sadrzpoc=s1.vPoc.vrememin();
			int sadrzkraj=Vreme.saberi(s1.vPoc, s1.vtraj).vrememin();
		if(!(s1 instanceof Ponavljajuci)) { flagisa=false; if((sadrzpoc<pocseme.vrememin()) || (sadrzpoc>krajseme.vrememin()) || (sadrzkraj>krajseme.vrememin()) ) throw new GDodaj(); }
		else { pon=(Ponavljajuci) (s1);  
		if((sadrzpoc<pocseme.vrememin()) || (sadrzpoc>krajseme.vrememin()) || (sadrzkraj>krajseme.vrememin())) { flag2=false;}
		if(flag2==true) {
	    	if(prvi==null) { Elem novi=new Elem(s1); prvi=novi;posl=novi; break;}
	    	else {
	    		for(tek=prvi;tek!=posl;tek=tek.sled) {
	    			if(tek.s.vPoc.vrememin()<sadrzpoc) break;
	    		}
	            if(prvi==posl) { if(prvi.s.vPoc.vrememin()>sadrzpoc) {
	               if(sadrzkraj>prvi.s.vPoc.vrememin()) throw new GDodaj();
	               else {
	            	   Elem novi=new Elem(s1); novi.sled=prvi; prvi.pret=novi;prvi=novi; break;
	               }
	            }
	            	
	            }
	            if(tek==posl && tek.s.vPoc.vrememin()<sadrzpoc) {
	            	
	            		Vreme preklop=tek.s.preklapaSe(s1);
	    	    		if(preklop!=null) { 
	    	    			int pomeraj=preklop.vrememin()-tek.s.vPoc.saberi(tek.s.vPoc, tek.s.vtraj).vrememin();
	    	    		    Vreme pomerajvrem=new Vreme(pomeraj/60,pomeraj%60);
	    	    			s1.pomeri(pomerajvrem);
	    	    			sadrzpoc=s1.vPoc.vrememin();
	    	    			sadrzkraj=Vreme.saberi(s1.vPoc, s1.vtraj).vrememin();
	    	    		}
	    	    		if((sadrzkraj>krajseme.vrememin())) throw new GDodaj();
	    	    		else {
	    	    			Elem novi=new Elem(s1); 
	    	    			posl.sled=novi;
	    	    			novi.pret=posl;
	    	    			posl=novi;
	    	    			break;
	    	    		}		
	            	
	            }
	            else {
	    		Vreme preklop=tek.pret.s.preklapaSe(s1);
	    		if(preklop!=null) { 
	    			int pomeraj=tek.pret.s.vPoc.saberi(tek.pret.s.vPoc, tek.pret.s.vtraj).vrememin()-preklop.vrememin();
	    		    Vreme pomerajvrem=new Vreme(pomeraj/60,pomeraj%60);
	    			s1.pomeri(pomerajvrem);
	    			sadrzpoc=s1.vPoc.vrememin();
	    			sadrzkraj=Vreme.saberi(s1.vPoc, s1.vtraj).vrememin();
	    		}
	    		if((sadrzkraj>tek.s.vPoc.vrememin()) || sadrzkraj>krajseme.vrememin()) throw new GDodaj();
	    		else {
	    			Elem novi=new Elem(s1);novi.pret=tek.pret;novi.sled=tek;  tek.pret.sled=novi; tek.pret=novi; break;
	    		}
	    		 
	    	}
	           
	    	
	} 
	    
	    }  
	    else {  if(pon!=null) {
	    	if(pon.vPoc.vrememin()>pon.poslednjeponavljanje().vrememin()) throw new GDodaj(); 
	    	else {
	    		pon.pomeri(pon.dohvperiodu());
	    		s1.vPoc=pon.vPoc;
	    		flag2=true;
	    	}
	      }
	    }
		} }
		    } 
	
	
	public double zauzetost() throws GVreme {
		int ukupnovreme=krajseme.vrememin()-pocseme.vrememin();
		int ukupnovremesadrzaj=0;
		for(tek=prvi;tek!=null;tek=tek.sled) {
			int n=(krajseme.vrememin()-Vreme.saberi(tek.s.vPoc, tek.s.vtraj).vrememin())/((Ponavljajuci) tek.s).dohvperiodu().vrememin()+1;
			ukupnovremesadrzaj=ukupnovremesadrzaj+tek.s.vtraj.vrememin()*n; }
			return ukupnovremesadrzaj*100/ukupnovreme;
		
	}
public String toString() {
	StringBuilder s=new StringBuilder();
	s.append(naziv).append(":").append(pocseme).append("-").append(krajseme).append("\n");
	for(tek=prvi;tek!=posl;tek=tek.sled) {
		s.append(tek.s);
	}
	return s.toString();
}
public int broj() {
	int cnt=0;
	for(tek=prvi;tek!=posl;tek=tek.sled) {
		cnt++;
	}
	return cnt;
}
public Sadrzaj dohvatisaprozivoljne(int i) {
	tek=prvi;
	int ukupno=broj();
	for(int x=0;x<ukupno;x++) {
		tek=tek.sled;
	}
	return tek.s;
}
}

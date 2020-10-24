package pitanja;

import java.util.Arrays;

public class PitanjeSaPonudjenimOdgovorima extends Pitanje {
	
private String [] nizponudjenih;

	public PitanjeSaPonudjenimOdgovorima(String string, int i, double d, String[] strings) {
		super(string, i, d);
		nizponudjenih=strings;
	}

	@Override
	public String toString() {
		StringBuilder s=new StringBuilder();
		s.append(super.toString());
		s.append("\n");
		for(int i=0;i<nizponudjenih.length;i++) {
			s.append(i+1+". " + nizponudjenih[i]).append("\n");
			
		}
		return s.toString();
	}
    
}

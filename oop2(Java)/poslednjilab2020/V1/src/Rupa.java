import java.awt.*;

public class Rupa extends Canvas {
	
 private Color boja;
 private Basta b;
 private Zivotinja z;
 public Rupa(Basta bb) {
	 boja= new Color(102,51,0);
	 b=bb;
 }
 public void postavizivotinju(Zivotinja ziv) {
	 z=ziv;
 }
 public Zivotinja dohvatizivotinju() {
	 return z;
 }
 
}

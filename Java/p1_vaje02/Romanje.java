import java.util.*;

public class Romanje {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int d = sc.nextInt();
		int n = sc.nextInt();
		int z = sc.nextInt();
		
		int dan = 1;
		for(int i = d; i > 0; i-=n) {
			if(d-n >= 0) {			
				System.out.println(dan + ". dan: " + d + " -> " + (d-(n)) + " (prehodil " + n + ")");	
			}else {
				System.out.println(dan + ". dan: " + d + " -> " + 0 + " (prehodil " + d + ")");	
			}
			d-=n;
			if(d <= 0) break;
			if(n - z > 0) n-=z;
			else break;	
			dan++;
		}
		
	}
}

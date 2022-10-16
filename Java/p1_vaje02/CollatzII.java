import java.util.*;

public class CollatzII {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int a = sc.nextInt();
		int b = sc.nextInt();
		
		int biggest = a;
		int biggestCounter = 1;
		
		for(int i = a; i <= b; i++) {
			int c = i;
			int counter = 1;
			while(c > 1) {
				if(c % 2 == 0) {
					 c /= 2;
				}else {
					c = c*3 + 1;
				}
				counter++;
			}
			if(counter > biggestCounter) {
				biggestCounter = counter;
				biggest = i;
			}
		}
		
		System.out.println(biggest);
		System.out.println(biggestCounter);
	}
}
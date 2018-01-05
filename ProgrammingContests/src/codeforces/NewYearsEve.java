package codeforces;
import java.util.Scanner;

public class NewYearsEve {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		long n = s.nextLong();
		long k =s.nextLong();
		if(k==1) {
			System.out.println(n);
		}else {
			System.out.println(Long.highestOneBit(n)*2-1);
		}
		s.close();
	}
}

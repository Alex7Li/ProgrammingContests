package codeforces;
import java.util.Scanner;
//http://codeforces.com/contest/979/problem/A
public class PizzaPizzaPizza {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong() + 1;
		sc.close();
		if (n == 1) {
			System.out.println(0);
		} else {
			if(n%2==0) {
				System.out.println(n/2);
			}else {
				System.out.println(n);
			}
		}
	}

}

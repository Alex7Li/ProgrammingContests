package implementation.simple;
import java.util.Scanner;
//http://codeforces.com/contest/931/problem/B
public class WorldCup {
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int n = sc.nextInt();
		int a = sc.nextInt();
		int b = sc.nextInt();
		sc.close();
		int rounds = (int)(Math.log(n)/Math.log(2));
		for (int i = 0; i < rounds; i++) {
			if(a==b) {
				System.out.println(i);
				return;
			}
			a=(a+1)/2;
			b=(b+1)/2;
		}
		System.out.println("Final!");
	}
}

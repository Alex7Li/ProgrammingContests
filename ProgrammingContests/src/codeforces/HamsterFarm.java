package codeforces;
import java.util.Scanner;

//http://codeforces.com/contest/939/problem/B
public class HamsterFarm {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		if (n == 0) {
			System.out.println(1 + " " + 0);
		} else {
			int k = sc.nextInt();
			int bestInd = 1;
			long bestRem = n;
			long boxCountBest = 0;
			for (int i = 1; i <= k; i++) {
				long v = sc.nextLong();
				if (bestRem > n % v) {
					bestInd = i;
					bestRem = n % v;
					boxCountBest = n / v;
				}
			}
			System.out.println(bestInd + " " + boxCountBest);
		}
		sc.close();
	}
}

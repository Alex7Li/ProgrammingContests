package codeforces;
import java.util.Scanner;
//http://codeforces.com/contest/948/problem/B
public class PrimalSport {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x2 = sc.nextInt();
		int minX0 = Integer.MAX_VALUE;
		int minX1 = x2 - maxPrimeFactor(x2) + 1;
		for (int i = minX1; i <= x2; i++) {
			int mF = maxPrimeFactor(i);
			if (mF != i) {
				minX0 = Math.min(i - mF + 1, minX0);
			}
		}
		sc.close();
		System.out.println(minX0);
	}

	private static int maxPrimeFactor(int x2) {
		int maxFactor = -1;
		for (int i = 2; i*i <= x2; i++) {
			while (x2 % i == 0) {
				maxFactor = Math.max(maxFactor, i);
				x2 /= i;
			}
		}
		maxFactor = Math.max(x2, maxFactor);
		return maxFactor;
	}
}

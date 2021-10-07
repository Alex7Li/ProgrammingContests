package codeforces;
import java.util.Scanner;

//http://codeforces.com/contest/940/problem/B

public class TanyaCryingOutLoud {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextInt();
		long k = sc.nextInt();
		long a = sc.nextInt();
		long b = sc.nextInt();
		sc.close();
		long cost = 0;
		if (k == 1) {
			cost = (n - 1) * a;
		} else {
			while (n != 1) {
				long nextDivisible = n % k;
				cost += nextDivisible * a;
				n -= nextDivisible;
				if (n == 0) {
					cost -= a;
					break;
				} else {
					long resultN = n / k;
					long divCost = b;
					long subCost = a * (n - resultN);
					n = resultN;
					cost += Math.min(divCost, subCost);
				}
			}
		}
		System.out.println(cost);
	}
}

package codeforces;

import java.util.Scanner;

//http://codeforces.com/contest/911/problem/B
public class TwoCakes {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a = sc.nextInt();
		int b = sc.nextInt();

		sc.close();
		int ans = Integer.MIN_VALUE;
		// i = plates in group A
		for (int i = 1; i < n; i++) {
			if (a / i < 1 || b / (n - i) < 1) {
				continue;
			} else {
				int cakeA = (int) Math.ceil(a / i);
				int cakeB = (int) Math.ceil(b / (n - i));
				int min = Math.min(cakeA, cakeB);
				ans = Math.max(ans, min);
			}
		}
		System.out.println(ans);
	}
}

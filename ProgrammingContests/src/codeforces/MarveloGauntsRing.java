package codeforces;
import java.util.Scanner;

public class MarveloGauntsRing {
	// http://codeforces.com/problemset/problem/855/B
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long p = sc.nextInt();
		long q = sc.nextInt();
		long r = sc.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < a.length; i++) {
			a[i] = sc.nextInt();
		}
		sc.close();
		// dp[i][j] = maximum using values up to ai and using j multiplications
		// base dp[i][0] = 0;
		long[][] dp = new long[n][4];
		dp[0][1] = a[0] * p;
		dp[0][2] = dp[0][1] + a[0] * q;
		dp[0][3] = dp[0][2] + a[0] * r;
		for (int i = 1; i < dp.length; i++) {
			dp[i][1] = Math.max(dp[i - 1][1], a[i] * p);
			dp[i][2] = Math.max(dp[i - 1][2], dp[i][1] + a[i] * q);
			dp[i][3] = Math.max(dp[i - 1][3], dp[i][2] + a[i] * r);
		}
		System.out.println(dp[n - 1][3]);
	}
}

package codeforces;
import java.util.Scanner;

//http://codeforces.com/contest/914/problem/C
public class TravellingSalesmanAndSpecialNumbers {
	private static final int MOD = 1000000007;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		char[] digits = sc.nextLine().toCharArray();
		int k = sc.nextInt();
		sc.close();
		if (k == 0) {
			System.out.println(1);
			return;
		}
		// dp[i][j] = ways to get a number with j 1's
		// using only the first i digits.
		long[][] dp = new long[digits.length][digits.length + 1];
		int index = 1;
		for (int i = 1; i < dp.length; i++) {
			if (digits[i] == '1') {
				dp[i][index]++;
				index++;
			}
		}
		dp[dp.length - 1][index]++;
		for (int i = 0; i < dp.length; i++) {
			dp[i][0] = 1;
		}

		for (int i = 1; i < dp.length; i++) {
			for (int j = 1; j < dp[0].length; j++) {
				dp[i][j] += (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
			}
		}
		dp[digits.length - 1][0] = 0;
		// counts[i]=
		// count of numbers with value i
		long[] counts = dp[digits.length - 1];
		if (k == 1) {
			System.out.println(counts[1] - 1);
		} else {
			k--;
			while (k > 0) {
				long[] nextCounts = new long[counts.length];
				for (int i = 2; i < counts.length; i++) {
					nextCounts[Long.bitCount(i)] += counts[i];
					nextCounts[Long.bitCount(i)] %= MOD;
				}
				counts = nextCounts;
				k--;
			}
			System.out.println(counts[1]);
		}
	}
}

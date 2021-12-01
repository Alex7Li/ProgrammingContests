package codeforces;
import java.util.Arrays;
import java.util.Scanner;

//http://codeforces.com/problemset/problem/895/C
public class SquareSubsets {
	private static final int[] primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67 };
	private static final int MOD = 1000000007;

	public static void main(String[] args) {
		// The ith element of mask has 19 relevant bits. The jth of these represents if
		// the element
		// has an odd number of the jth prime dividing it. So .....011 means the number
		// =(x^2)*3*2,
		// where x can be any number since it has an even number of each prime.
		int[] mask = new int[71];
		for (int i = 1; i < 71; i++) {
			int val = i;
			for (int j = 0; j < primes.length; j++) {
				if (val % primes[j] == 0) {
					mask[i] = mask[i] ^ (1 << j);
					val /= primes[j];
					j--;
				}
			}
		}
		Scanner s = new Scanner(System.in);
		s.nextLine();
		int[] a = Arrays.stream(s.nextLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
		s.close();
		// f[i][j] = number of ways to select e elements of value j such that e%2==i.
		int[][] f = new int[2][71];
		f[0] = Arrays.stream(f[0]).map(x -> x + 1).toArray();
		for (int i = 0; i < a.length; i++) {
			f[0][a[i]] = (f[0][a[i]] + f[1][a[i]]) % MOD;
			f[1][a[i]] = f[0][a[i]];
		}
		// Picking from the first i elements, dp[i][j] = number of ways to select
		// elements such that
		// their product = mask[j], if the definition of mask were to be extended to
		// more than 71 numbers.
		long[][] dp = new long[2][1 << 19];
		dp[0][0] = 1;
		for (int i = 0; i < 70; i++) {
			for (int j = 0; j < dp[0].length; j++) {
				dp[1][j ^ mask[i + 1]] += dp[0][j] * f[1][i + 1];
				dp[1][j ^ mask[i + 1]] %= MOD;
				dp[1][j] += dp[0][j] * f[0][i+1];
				dp[1][j] %= MOD;
			}
			for (int j = 0; j < dp[0].length; j++) {
				dp[0][j] = dp[1][j];
				dp[1][j] = 0;
			}

		}
		System.out.println(dp[0][0] - 1);
	}
}

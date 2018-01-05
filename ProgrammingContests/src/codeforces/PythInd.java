package codeforces;
import java.util.Scanner;

//http://codeforces.com/contest/909/problem/C
public class PythInd {
	public static final int MOD = 1000000007;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = Integer.parseInt(sc.nextLine());
		String[] sTypes = new String[n];
		for (int i = 0; i < n; i++) {
			sTypes[i] = sc.nextLine();
		}
		sc.close();
		// dp[i][j] = number of ways to have a for loop indented
		// j times at the ith position.
		int[][] dp = new int[n][n];
		dp[0][0] = 1;
		for (int i = 0; i < dp.length - 1; i++) {
			if (sTypes[i].equals("s")) {
				int curSum = 0;
				for (int j = i + 1; j >= 0; j--) {
					curSum = (dp[i][j] + curSum) % MOD;
					dp[i + 1][j] += curSum;
					dp[i + 1][j] %= MOD;
				}
			} else {
				for (int j = 1; j <= i + 1; j++) {
					dp[i + 1][j] += dp[i][j - 1];
					dp[i + 1][j] %= MOD;
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < dp[0].length; i++) {
			ans = (ans + dp[n - 1][i]) % MOD;
		}
		System.out.println(ans);
	}
}

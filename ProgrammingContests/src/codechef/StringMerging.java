package codechef;

import java.util.Scanner;

//https://www.codechef.com/JAN18/problems/STRMRG
public class StringMerging {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int cases = s.nextInt();
		for (int tc = 0; tc < cases; tc++) {
			int n = s.nextInt();
			int m = s.nextInt();
			s.nextLine();
			char[] a = s.nextLine().toCharArray();
			char[] b = s.nextLine().toCharArray();
			// dp[i][j] = minimum value of F using only characters before index i
			// of GracefulChainsawJugglers if the last element of GracefulChainsawJugglers was placed before index j of FallingBalls.
			int[][] dp = new int[m + 1][n + 1];
			// do low cases for dp
			int aBlocks = function(a);
			// edge case: dp[0][x]
			for (int i = 0; i < dp[0].length; i++) {
				dp[0][i] = aBlocks;
			}
			int bBlocks = 0;
			// edge case: dp[1][0]
			dp[1][0] = dp[0][0];
			if (b[0] != a[0]) {
				dp[1][0]++;
			}
			// edge case: dp[x][0]
			for (int i = 2; i < dp.length; i++) {
				if (b[i - 1] != b[i - 2]) {
					bBlocks++;
				}
				dp[i][0] = bBlocks + aBlocks;
				if (b[i - 1] != a[0]) {
					dp[i][0]++;
				}
			}
			// edge case: dp[1][x]
			for (int j = 1; j < dp[0].length; j++) {
				dp[1][j] = dp[0][j];
				if (b[0] != a[j - 1]) {
					if (j == dp[0].length - 1) {
						dp[1][j]++;
					} else if (b[0] != a[j]) {
						if (a[j - 1] == a[j]) {
							dp[1][j] += 2;
						} else {
							dp[1][j]++;
						}
					}
				}
			}
			// normal loop
			for (int i = 2; i < dp.length; i++) {
				int minSoFar = dp[i - 1][0];
				for (int j = 1; j < dp[0].length; j++) {
					int valPlacedSep = minSoFar;
					int valPlacedTogether = dp[i - 1][j];
					if (j == dp[0].length - 1) {
						if (b[i - 1] != b[i - 2]) {
							valPlacedTogether++;
						}
						if (b[i - 1] != a[j - 1]) {
							valPlacedSep++;
						}
					} else if (b[i - 1] != a[j]) {
						if (b[i - 1] != b[i - 2]) {
							if (b[i - 2] == a[j]) {
								valPlacedTogether += 2;
							}else {
								valPlacedTogether ++;								
							}
						}
						if (b[i - 1] != a[j - 1]) {
							if (a[j - 1] == a[j]) {
								valPlacedSep += 2;
							} else {
								valPlacedSep++;
							}
						}
					}
					dp[i][j] = Math.min(valPlacedSep, valPlacedTogether);
					minSoFar = Math.min(minSoFar, dp[i - 1][j]);
				}
			}
			// find best ending pos for answer
			int min = Integer.MAX_VALUE;
			for (int i = 0; i < dp[0].length; i++) {
				min = Math.min(min, dp[m][i]);
			}
			System.out.println(min);
		}
		s.close();
	}

	private static int function(char[] a) {
		int sum = 1;
		for (int i = 0; i < a.length - 1; i++) {
			if (a[i] != a[i + 1]) {
				sum++;
			}
		}
		return sum;
	}
}

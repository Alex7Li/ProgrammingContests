package codeforces;
import java.util.Arrays;
import java.util.Scanner;

public class Birds {
//http://codeforces.com/contest/922/problem/E
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long startMana = sc.nextInt();
		long manaGain = sc.nextInt();
		long regen = sc.nextInt();
		sc.nextLine();
		int[] birdCounts = Arrays.stream(sc.nextLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
		long[] costs = Arrays.stream(sc.nextLine().split(" ")).mapToLong(x -> Long.parseLong(x)).toArray();
		// dp[i][j] = max mana after passing by i nests and gathering j birds.
		long[][] dp = new long[n + 1][10001];
		for (int i = 0; i < dp.length; i++) {
			for (int j = 0; j < dp[i].length; j++) {
				dp[i][j] = -1;
			}
		}
		for (int i = 0; i < dp.length; i++) {
			dp[0][0] = startMana;
		}
		long maxBirds = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= maxBirds + birdCounts[i]; j++) {
				if (j<=10000 && dp[i][j] != -1) {
					for (int k = 0; k <= birdCounts[i]; k++) {
						long manaUsed = k * costs[i];
						if (j + k > 10000) {
							break;
						} else if (dp[i][j] >= manaUsed) {
							long maxMana = (j+k) * manaGain + startMana;
							dp[i+1][j+k] = Math.max(dp[i+1][j+k], Math.min(maxMana, dp[i][j] - manaUsed + regen));
							maxBirds = Math.max(maxBirds, j+k);
						}
					}
				}
			}
		}
		System.out.println(maxBirds);
		sc.close();
	}
}
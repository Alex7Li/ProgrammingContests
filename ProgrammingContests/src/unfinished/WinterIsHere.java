package unfinished;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

//http://codeforces.com/problemset/problem/839/D
public class WinterIsHere {
	static final int MOD = 1000000007;
	static final int MAX_SIZE = 1010100;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		br.readLine();
		String[] data = br.readLine().split(" ");
		ArrayList<Integer> strengths = new ArrayList<Integer>();
		for (int i = 0; i < data.length; i++) {
			int str = Integer.parseInt(data[i]);
			if (str != 1) {
				strengths.add(str);
			}
		}
		// the total number of numbers seen so far with factor i is factCount[i]
		int[] factCount = new int[MAX_SIZE];
		Arrays.fill(factCount, 0);
		for (int i = 0; i < strengths.size(); i++) {
			int s = strengths.get(i);
			// factor strength
			factCount[s]++;
			for (int j = 2; j * j <= s; j++) {
				if (s % j == 0) {
					factCount[j]++;
					s = s / j;
					if (s != j) {
						factCount[s]++;
					}
					while (s % j == 0) {
						s /= j;
					}
				}
			}
		}
		long[] twoToThe = new long[MAX_SIZE];
		twoToThe[0] = 1;
		for (int i = 1; i < MAX_SIZE; i++) {
			twoToThe[i] = twoToThe[i - 1] * 2 % MOD;
		}
		long total = 0;
		long[] dp = new long[MAX_SIZE];
		for (int i = 1; i < MAX_SIZE; i++) {
			if (factCount[i] != 0) {
				dp[i] = factCount[i] * twoToThe[factCount[i] - 1] % MOD;
			} else {
				dp[i] = 0;
			}
		}
		for (int i = 2; i < MAX_SIZE; i++) {
			for (int j = i * 2; j < MAX_SIZE; j += i) {
				dp[i] -= dp[j];
			}
		}
		for (int i = 2; i < dp.length; i++) {
			total += i * dp[i];
			total %= MOD;
		}
		System.out.println(total);
	}
}

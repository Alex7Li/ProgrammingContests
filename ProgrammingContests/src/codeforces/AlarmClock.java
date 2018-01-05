package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class AlarmClock {
	// http://codeforces.com/contest/898/problem/D
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] in = br.readLine().split(" ");
		//int n = Integer.parseInt(in[0]);
		int m = Integer.parseInt(in[1]);
		int k = Integer.parseInt(in[2]);
		int[] a = Arrays.stream(br.readLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
		int[] dp = new int[1000001];
		for (int i : a) {
			dp[i]++;
		}
		int alarms = 0;
		int tRemoved = 0;
		for (int i = 0; i < dp.length; i++) {
			alarms += dp[i];
			if (i >= m) {
				alarms -= dp[i - m];
			}
			if (alarms >= k) {
				int removed = alarms - k + 1;
				alarms -= removed;
				dp[i] -= removed;
				tRemoved += removed;
			}
		}
		System.out.println(tRemoved);
	}
}

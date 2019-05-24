package math.implementation;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

//https://www.codechef.com/JAN18/problems/KCON
public class KConcatenation {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int cases = Integer.parseInt(br.readLine());
		for (int testCase = 0; testCase < cases; testCase++) {
			long answer = 0;
			String[] nl = br.readLine().split(" ");
			int n = Integer.parseInt(nl[0]);
			int k = Integer.parseInt(nl[1]);
			long[] a = Arrays.stream(br.readLine().split(" ")).mapToLong(x -> Long.parseLong(x)).toArray();
			if (k == 1) {
				answer = maxSubarraySum(a);
			} else {
				long aSum = Arrays.stream(a).sum();
				if (aSum > 0 && k != 2) {
					answer = aSum * (k - 2) + maxSumFromRight(a) + maxSumFromLeft(a);
				} else {
					long[] aa = new long[2 * n];
					for (int i = 0; i < a.length; i++) {
						aa[i] = a[i];
						aa[i + a.length] = a[i];
					}
					answer = maxSubarraySum(aa);
				}
			}
			System.out.println(answer);
		}
	}

	private static long maxSubarraySum(long[] a) {
		long sum = 0;
		long max = a[0];
		for (int r = 0; r < a.length; r++) {
			sum = Math.max(a[r], sum+a[r]);
			max = Math.max(sum, max);
		}
		return max;
	}

	private static long maxSumFromLeft(long[] a) {
		long max = 0;
		long cur = 0;
		for (int i = a.length - 1; i >= 0; i--) {
			cur += a[i];
			max = Math.max(max, cur);
		}
		return max;
	}

	private static long maxSumFromRight(long[] a) {
		long max = 0;
		long cur = 0;
		for (int i = 0; i < a.length; i++) {
			cur += a[i];
			max = Math.max(max, cur);
		}
		return max;
	}
}

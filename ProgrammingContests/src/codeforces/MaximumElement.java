package codeforces;
import java.util.Scanner;

public class MaximumElement {
//	private static long[][] fmemo;
	private static long mod = 1000000007l;

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int k = s.nextInt();
		s.close();
		if (k >= n) {
			System.out.println(0);
		} else {
//			fmemo = new long[k+1][k+1];
			long ways = 0;
			for (int m = k + 1; m <= n - 1; m++) {
				for (int i = 0; i <= m - k - 1; i++) {
					int L = n - m;
					int S = m - k - i - 1;
					long comb = (f(L + S, 0) * f(m - 1, S)) % mod;
					ways = (ways + comb) % mod;
				}
			}
			System.out.println(ways);
		}
	}

	// returns n!/r!
	private static long f(int n, int r) {
//		if(r>=n) {
//			return 1;
//		}
//		if (fmemo[n][r] == 0) {
			long res = 1l;
			for (int i = r + 1; i <= n; i++) {
				res = ((long) (i) * res) % mod;
			}
			return res;
//			fmemo[n][r] = res;
//		}
	//	return fmemo[n][r];
	}
}

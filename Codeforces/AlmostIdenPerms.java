package codeforces;
import java.util.Scanner;

public class AlmostIdenPerms {
	private static long[] derangements = { 0, 0, 1, 2, 9};

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int k = s.nextInt();
		s.close();
		System.out.println(getPerms(n, k) + "");
	}

	private static long getPerms(int n, int k) {
		if (k == 1) {
			return 1l;
		} else {
			long setsOfk = comb(n,k)*(derangements[k]);
			return setsOfk+getPerms(n,k-1);
		}
	}
	private static long comb(int n, int k) {
		long comb = 1;
		for (int i = 1; i <= k; i++) {
			comb *= n - i+1;
			comb /= i;
		}
		return comb;
	}
}

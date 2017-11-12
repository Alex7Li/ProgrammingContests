package kattis;

import java.math.BigInteger;
import java.util.Scanner;

public class ApplesCherriesMangos {
	private static final int MOD = 1000000007;
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int a = s.nextInt();
		int b = s.nextInt();
		int c = s.nextInt();
		s.close();
		long ways = compute(a, a + b + c);
		ways = (ways * compute(b, b + c)) % MOD;
		System.out.println(ways);
	}

	/**
	 * @return the number of ways to choose a elements out of vector b such that no
	 *         two elements in the set a are adjacent
	 */
	private static int compute(int a, int b) {
		return choose(b, a);
	}

	/**
	 * @return n!/((n-r!r!)%MOD
	 */
	private static int choose(int n, int r) {
		BigInteger val = BigInteger.ONE;
		for (int i = n - r + 1; i <= n; i++) {
			val = val.multiply(BigInteger.valueOf(i));
		}
		for (int i = 2; i <= r; i++) {
			val = val.divide(BigInteger.valueOf(i));
		}
		return val.mod(BigInteger.valueOf(MOD)).intValue();
	}
}

import java.math.BigInteger;
import java.util.Scanner;

//http://codeforces.com/contest/963/problem/A
public class AlternatingSum {
	public static long MOD = (long) (Math.pow(10, 9)) + 9L;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long a = sc.nextInt();
		long b = sc.nextInt();
		sc.nextLine();
		char[] seq = sc.nextLine().toCharArray();
		long val = solve(n, a, b, seq);
		System.out.println(val);
		sc.close();
	}

	private static long solve(int n, long a, long b, char[] seq) {
		long factor = invMod(a) * b;
		long start = modPow(a, n);
		long sum = 0;
		for (int i = 0; i < seq.length; i++) {
			long sgn = 0;
			if (seq[i] == '+') {
				sgn = 1;
			} else {
				sgn = -1;
			}
			sum = (sum + sgn * start) % MOD;
			start = (start * factor) % MOD;
		}
		// guaranteed to be Natural Number
		long repetitions = (n + 1) / seq.length;
		long sumLast = sum;
		// a^(-k)*b^(k)
		long factorS = (modPow(invMod(a), seq.length) * modPow(b, seq.length)) % MOD;
		for (int i = 1; i < repetitions; i++) {
			sumLast = (sumLast * factorS) % MOD;
			sum = (sum + sumLast) % MOD;
		}
		return (sum + MOD) % MOD;
	}

	private static long invMod(long a) {
		return  BigInteger.valueOf(a).modInverse(BigInteger.valueOf(MOD)).longValue();
	}

	private static long modPow(long a, long p) {
		return  BigInteger.valueOf(a).modPow(BigInteger.valueOf(p), BigInteger.valueOf(MOD)).longValue();
	}
}
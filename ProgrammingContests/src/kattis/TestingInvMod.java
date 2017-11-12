package kattis;

public class TestingInvMod {
	private static int imod(int r, int m) {
		//BigInteger r2 = BigInteger.valueOf(r);
		//BigInteger m2 = BigInteger.valueOf(m);
		//return r2.modPow(m2.subtract(BigInteger.valueOf(2)), m2).intValue();
		return (int) modPow(r,m-2,m);
	}

	private static long modPow(int r, int p, int m) {
		if (p == 0) {
			return 1;
		}
		long sqrt = modPow(r, p / 2, m) % m;
		if (p % 2 == 1) {
			return ((long)(r * sqrt)%m * sqrt)%m;
		} else {
			return ((long)sqrt * sqrt) % m;
		}
	}

	public static void main(String[] args) {
		for (int m = 1; m < 300; m++) {
			if (isPrime(m)) {
				System.out.println("m =" + m);
				for (int i = 1; i < m; i++) {
					System.out.println(i + " " + imod(i, m));
					if ((long)i*imod(i, m) % m != 1) {
						System.out.println("FAILED");
					}
				}
			}
		}
	}

	@SuppressWarnings("unused")
	private static boolean coPrime(int a, int b) {
		int t;
		while (b != 0) {
			t = a;
			a = b;
			b = t % b;
		}
		return a == 1;
	}

	private static boolean isPrime(int num) {
		if (num < 2)
			return false;
		if (num == 2)
			return true;
		if (num % 2 == 0)
			return false;
		for (int i = 3; i * i <= num; i += 2)
			if (num % i == 0)
				return false;
		return true;
	}
}

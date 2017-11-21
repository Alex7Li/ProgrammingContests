package tools;


import java.util.ArrayList;
import java.util.Arrays;

public class PrimeSieve {
	public static void main(String[] args) {
		int n = 10000;
		boolean[] prime = new boolean[n];
		Arrays.fill(prime, true);
		ArrayList<Integer> primes = new ArrayList<Integer>();
		for (int i = 2; i < prime.length; i++) {
			if (prime[i]) {
				primes.add(i);
				for (int j = 2 * i; j < prime.length; j += i) {
					prime[j] = false;
				}
			}
		}
		for (int i = 0; i < primes.size(); i++) {
			System.out.println(primes.get(i));
		}
	}
}
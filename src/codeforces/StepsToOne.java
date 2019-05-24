package codeforces;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// http://codeforces.com/contest/1139/problem/D
public class StepsToOne {
    private static final long MOD = 1_000_000_007;

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        // yeah that's right it's not an ascii character. I'm too cool for school.
        int[] μ = mobius(n);
        long ans = 1;
        for (int i = 2; i <= n; i++) {
            ans = (ans - μ[i] * (n / i) * modInv(n - n / i)) % MOD;
        }
        System.out.println((ans + MOD) % MOD);
    }

    /**
     * return a^p (mod MOD)
     */
    private static long modPow(long a, long p) {
        if (p == 0) {
            return 1;
        }
        long half = modPow(a, p / 2);
        long ans = (half * half) % MOD;
        if (p % 2 == 1) {
            ans = (ans * a) % MOD;
        }
        return ans;
    }

    /*
     * return x such that x*a = 1 (mod MOD). Requires that MOD is prime
     */
    private static long modInv(long a) {
        return modPow(a, MOD - 2);
    }


    /**
     * calculate the value of the mobius function for all values in [0, n]
     * The mobius function μ is defined as follows:
     * μ(n) = 1 if n is a square-free positive integer with an even number of prime factors.
     * μ(n) = −1 if n is a square-free positive integer with an odd number of prime factors.
     * μ(n) = 0 if n has a squared prime factor or n = 0.
     * Takes O(n) time.
     * If you only need the value for n, factor it yourself >:(
     */
    private static int[] mobius(int n) {
        // the ideas here are very similar to the ideas in the prime sieve function
        List<Integer> primes = new ArrayList<>();
        int[] mobius = new int[n + 1];
        mobius[1] = 1;
        int[] minFact = new int[n + 1];
        for (int i = 2; i <= n; i++) {
            if (minFact[i] == 0) {
                primes.add(i);
                mobius[i] = -1;
                minFact[i] = i;
            }
            for (int j = 0; j < primes.size() && primes.get(j) <= minFact[i] && i * primes.get(j) <= n; ++j) {
                minFact[i * primes.get(j)] = primes.get(j);
                if (primes.get(j) == minFact[i]) {
                    mobius[i * primes.get(j)] = 0;
                } else {
                    mobius[i * primes.get(j)] = -mobius[i];
                }
            }
        }
        return mobius;
    }
}

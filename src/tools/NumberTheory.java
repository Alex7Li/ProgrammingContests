package tools;

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

/**
 * Various methods useful for number theory
 * METHOD LIST;
 * long choose(int n, int k, int mod)
 * int gcd(int a, int b)
 * int lcm(int a, int b)
 * int toitent(int n)
 * int[] mobius(int n)
 * int[] primeSieve(int n)
 * BigInteger sqrt(BigInteger n)
 * long modPow(long a, long p)
 * long modInv(long a)
 */
public class NumberTheory {
    /*
     * so the class compiles... you can use whatever mod the problem wants you too
     */
    static final long MOD = 998244353;

    /**
     * return n choose k (mod some number)
     */
    static long choose(int n, int k, int mod) {
        long ans = 1;
        for (int i = k + 1; i <= n; i++) {
            ans = (ans * i) % mod;
        }
        for (int i = 2; i <= n - k; i++) {
            ans = (modInv(i) * ans) % mod;
        }
        return ans;
    }

    /**
     * Return gcd(a,b)
     * O(log(a+b))
     */
    static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    /**
     * Return lcm(a,b)
     * O(log(a+b))
     */
    static long lcm(int a, int b) {
        return (long) (a) * b / gcd(b, a % b);
    }

    /**
     * return totient(n), the number of positive integers
     * up to n relatively prime to n
     * O(sqrt(n))
     * Note: if you need all toitents from 1 to n, recall that
     * if n, m are relatively prime, toitent(nm) = toitent(n)*toitent(m).
     * if n is prime, toitent(n) = n - 1.
     */
    static int toitent(int n) {
        // Initialize result as n
        int result = n;

        // Consider all prime factors of n and subtract their
        // multiples from result
        for (int p = 2; p * p <= n; ++p) {

            // If p is a prime factor, divide out highest
            // power of p and update result.
            if (n % p == 0) {
                while (n % p == 0)
                    n /= p;
                result -= result / p;
            }
        }

        // Destroy last factor
        if (n > 1)
            result -= result / n;
        return result;
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
    static int[] mobius(int n) {
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


    /**
     * Return an array of primes up to and including n. Takes only O(n) time!
     * Also generates an array of the minimum factor for every number
     * from 1 to n, which can be used to find all factors of any number up to n.
     */
    static List<Integer> primeSieve(int n) {
        List<Integer> primes = new ArrayList<>();
        // minFact[i] contains the minimum prime factor of i.
        int[] minFact = new int[n + 1];
        for (int i = 2; i <= n; i++) {
            if (minFact[i] == 0) {
                primes.add(i);
                minFact[i] = i;
            }
            // Find multiples of i where primes[j] is the minimum prime factor. This loop will go exactly once for each
            // composite number. How it works: given a number i with prime factorization p1*...*pn, where p1<=...<=pn,
            // we say that, for each prime p <= p1, the number i*p is composite with minimum prime factor p.
            // Why this gets to every number exactly once: the number p1*...*pn will be generated only by p2*...*pn.
            // That's because all of it's prime factors need to be higher than it.
            for (int j = 0; j < primes.size() && primes.get(j) <= minFact[i] && i * primes.get(j) <= n; ++j) {
                minFact[i * primes.get(j)] = primes.get(j);
            }
        }
        return primes;
    }

    /**
     * @param n The numbers to factor
     * @return a list of all the prime factors of n
     */
    static List<Long> primeFactors(long n) {
        List<Long> primes = new ArrayList<>();
        for (long i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                primes.add(i);
                n /= i;
                i--;
            }
        }
        if (n != 1) {
            primes.add(n);
        }
        return primes;
    }

    /**
     * Since java doesn't have a big integer sqrt function. Takes O(log n)
     *
     * @param n The number to square root
     * @return floor(sqrt(n))
     */
    BigInteger sqrt(BigInteger n) {
        BigInteger a = BigInteger.ONE;
        BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8")).toString());
        while (b.compareTo(a) >= 0) {
            BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
            if (mid.multiply(mid).compareTo(n) > 0) b = mid.subtract(BigInteger.ONE);
            else a = mid.add(BigInteger.ONE);
        }
        return a.subtract(BigInteger.ONE);
    }

    /**
     * return a^p (mod MOD)
     */
    static long modPow(long a, long p) {
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
    static long modInv(long a) {
        return modPow(a, MOD - 2);
    }

}

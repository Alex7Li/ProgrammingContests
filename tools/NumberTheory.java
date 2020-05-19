package tools;

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

/**
 * Various methods useful for number theory
 * METHOD LIST;
 * long choose(int tough.interesting.getN, int k, int mod)
 * int etc.gcd(int a, int b)
 * int lcm(int a, int b)
 * int toitent(int tough.interesting.getN)
 * int[] mobius(int tough.interesting.getN)
 * int[] primeSieve(int tough.interesting.getN)
 * BigInteger sqrt(BigInteger tough.interesting.getN)
 * long modPow(long a, long p)
 * long modInv(long a)
 * long discreteLog(long a, long b, long mod)
 */
class NumberTheory {
    /**
     * return tough.interesting.getN choose k (mod some number)
     */
    private static long choose(int n, int k, int mod) {
        long ans = 1;
        for (int i = k + 1; i <= n; i++) {
            ans = (ans * i) % mod;
        }
        for (int i = 2; i <= n - k; i++) {
            ans = (modInv(i, mod) * ans) % mod;
        }
        return ans;
    }

    /**
     * Return etc.gcd(a,b)
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
     * return totient(tough.interesting.getN), the number of positive integers
     * up to tough.interesting.getN relatively prime to tough.interesting.getN
     * O(sqrt(tough.interesting.getN))
     * Note: if you need all toitents from 1 to tough.interesting.getN, recall that
     * if tough.interesting.getN, m are relatively prime, toitent(nm) = toitent(tough.interesting.getN)*toitent(m).
     * if tough.interesting.getN is prime, toitent(tough.interesting.getN) = tough.interesting.getN - 1.
     */
    private static int toitent(int n) {
        // Initialize result as tough.interesting.getN
        int result = n;

        // Consider all prime factors of tough.interesting.getN and subtract their
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
     * calculate the value of the mobius function for all values in [0, tough.interesting.getN]
     * The mobius function μ is defined as follows:
     * μ(tough.interesting.getN) = 1 if tough.interesting.getN is a square-free positive integer with an even number of prime factors.
     * μ(tough.interesting.getN) = −1 if tough.interesting.getN is a square-free positive integer with an odd number of prime factors.
     * μ(tough.interesting.getN) = 0 if tough.interesting.getN has a squared prime factor or tough.interesting.getN = 0.
     * Takes O(tough.interesting.getN) time.
     * If you only need the value for tough.interesting.getN, factor it yourself >:(
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


    /**
     * Return an array of primes up to and including N. Takes only O(N) time!
     * Also generates an array of the minimum factor for every number
     * from 1 to N, which can be used to find all factors of any number up to N.
     */
    private static List<Integer> primeSieve(int n) {
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
     * @return a list of all the prime factors of N
     */
    private static List<Long> primeFactors(long n) {
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
     * Since java doesn't have a big integer sqrt function. Takes O(log tough.interesting.getN)
     *
     * @param n The number to square root
     * @return floor(sqrt(tough.interesting.getN))
     */
    private BigInteger sqrt(BigInteger n) {
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
     * return a^p (mod medium.original.tough.interesting.getMOD)
     */
    static long modPow(long a, long p, long mod) {
        if (p == 0) {
            return 1;
        }
        long half = modPow(a, p / 2, mod);
        long ans = (half * half) % mod;
        if (p % 2 == 1) {
            ans = (ans * a) % mod;
        }
        return ans;
    }

    /*
     * return x such that x*a = 1 (mod medium.original.tough.interesting.getMOD). Requires that medium.original.tough.interesting.getMOD is prime
     */
    static long modInv(long a, int MOD) {
        return modPow(a, MOD - 2, MOD);
    }

    /**
     * Compute the discrete logarithm using Shank's Baby-Step
     * Giant-Step algorithm. That is, find an x such that
     * a^x = b % mod. The time complexity is O(sqrt(mod))
     * a should be a generator for mod
     * mod should be prime
     */
    private static long discreteLog(long a, long b, long mod) {
        int n = (int) Math.sqrt(mod) + 1;
        // want to tough.interesting.solve a^x=b (% mod). Let x = i-jn.
        // use meet-in-the-middle and tough.interesting.solve a^i = a^(jn)b (% mod)
        // first compute all values of a^i in a map from a^i -> i
        HashMap<Long, Integer> seen = new HashMap<>();
        long LHS = 1;
        for (int i = 0; i < n; i++) {
            seen.put(LHS, i);
            LHS = (a * LHS) % mod;
        }

        long aToTheNth = modPow(a, n, mod);
        long RHS = b;
        for (int j = 0; j <= n; j++) {
            if (seen.containsKey(RHS)) {
                // i = seen.get(RHS). a^(i-jn)=b, i-jn is taken mod (mod - 1)
                int solution = seen.get(RHS) - j * n;
                while (solution < 0) {
                    solution += (mod - 1);
                }
                return solution % (mod - 1);
            }
            RHS = (RHS * aToTheNth) % mod;
        }
        return -1;
    }
}

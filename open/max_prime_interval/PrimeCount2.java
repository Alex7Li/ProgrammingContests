package open.max_prime_interval;

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;

public class PrimeCount2 {
    public static void main(String[] args) {
        int n = 222;
        int[] minFactorOf = minFactors(n+2);
        int[] mobius = mobius(n+2);
        int nPrimes = 2;
        for (int i = 2; i < n + 1; i++) {
            if (minFactorOf[i + 1] != i + 1) {// i+1 not prime
                continue;
            }
            Set<Integer> bad = new TreeSet<>();
            if (i == n) {
                System.out.println(i);
                // the next number is prime, let's check if intervals of this length even have a chance of working.
                // count the minimum number of non-composites in any interval of length primes[ind]-1, at best, supposing
                // that the interval starts after primes[ind]
                int minComposites = 0;
                for (int j = 2; j < i; j++) {
                    //if(!(minFactorOf[j]==j && j>i/2)){
                    //    continue;
                    //}
                    if (mobius[j] == 1) {
                        // even number of factors, we want to double count numbers. Subtract ceil (i/j).
                        minComposites -= (i + j - 1) / j;
                        if((99+n)/j - 99/j != (i+j-1)/j){
                            bad.add(j);
                        }
                        if(i%j!=0) {
                            System.out.println(((-i + 1) % j + j) % j + " or more mod " + j); //or 0
                        }
                    } else if (mobius[j] == -1) {
                        // odd number of factors, we don't want to single-count numbers. Add floor (i/j)
                        minComposites += i / j;
                        if((222+n)/j - 222/j!= i/j){
                            bad.add(j);
                        }
                        if(i%j!=0) {
                            System.out.println(((-i) % j + j) % j + " or less mod " + j); //not 0
                        }
                    }//otherwise, mobius function is 0 and we don't care.
                }
                System.out.println(i + " " + minComposites + " " + (i - nPrimes) + " " + (i - nPrimes - minComposites));
                System.out.println(bad);
                System.out.println(bad.size());
            }
            nPrimes++;
        }
    }

    /**
     * Return an array of primes up to and including tough.interesting.getN. Takes only O(tough.interesting.getN) time!
     * Also generates an array of the minimum factor for every number
     * from 1 to tough.interesting.getN, which can be used to find all factors of any number up to tough.interesting.getN.
     */
    private static int[] minFactors(int n) {
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
        return minFact;
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
}

package medium.interesting;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// The first time I tried this problem I thought of some bad solution
// involving lots of inclusion-exlusion. A week or two later, during which
// a lot of time was spent studying number theory unrelated to the problem,
// I figured out the nice and clean solution.
// https://codeforces.com/gym/101982
public class CoprimeIntegers {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int d = sc.nextInt();
        int n = Math.max(b,d);
        int[] mobius = mobius(n);
        long ans = (long)(b-a+1)*(d-c+1);
        for (int i = 2; i <= n; i++) {
            long c1 = b/i - (a-1)/i;
            long c2 = d/i - (c-1)/i;
            ans += mobius[i] * c1 * c2;
        }
        System.out.println(ans);
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

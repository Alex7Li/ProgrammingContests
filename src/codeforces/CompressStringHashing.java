package codeforces;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

// https://codeforces.com/contest/1121/problem/F
// TLE. Using Z-algorithm is 10x faster or more!
public class CompressStringHashing {
    private static final long MOD = 1_000_000_349;
    private static final long FACT = 103;
    private static final long FACT2 = 3;
    private static final long FACTINV = 961165384;
    private static final long FACTINV2 = 333333450;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();
        sc.nextLine();
        char[] str = sc.nextLine().toCharArray();
        Set<Pair> subStrings = new HashSet<>();

        // best[i]: min cost for making first i characters
        int[] best = new int[n];
        Arrays.fill(best,n*a);
        best[0] = a;
        subStrings.add(new Pair(str[0],0L));

        for (int i = 1; i < n; i++) {
            Pair hash = new Pair(0L, 0L);
            int upperBound = Math.min(2 * i, n);
            best[i] = Math.min(best[i], best[i-1] + a);
            for (int j = i; j < upperBound; j++) {
                long hashA = (str[j] + hash.a * FACT) % MOD;
                long hashB = (str[j] + hash.b * FACT2) % MOD;
                hash = new Pair(hashA, hashB);
                if (subStrings.contains(hash)) {
                    best[j] = Math.min(best[j], b + best[i-1]);
                    System.out.println(i + " " + j + " " + hash);
                }
            }
            hash = new Pair(0L, 0L);
            long pow1 = 1;
            long pow2 = 1;
            for (int k = i; k >= 0; k--) {
                long hashA = (str[k] + hash.a * FACTINV) % MOD;
                long hashB = (str[k] + hash.b * FACTINV2) % MOD;
                hash = new Pair(hashA, hashB);
                subStrings.add(new Pair((pow1 * hashA) % MOD, (pow2 * hashB) % MOD));
                pow1 = (pow1 * FACT) % MOD;
                pow2 = (pow2 * FACT2) % MOD;
            }
        }
        System.out.println(best[n-1]);
    }

    private static class Pair {
        long a;
        long b;

        Pair(long a, long b) {
            this.a = a;
            this.b = b;
        }

        @Override
        public boolean equals(Object obj) {
            Pair o = (Pair) obj;
            return a == o.a && b == o.b;
        }

        @Override
        public int hashCode() {
            return Long.hashCode(a) + Long.hashCode(b);
        }

        @Override
        public String toString() {
            return Long.toString(a);
        }
    }
}
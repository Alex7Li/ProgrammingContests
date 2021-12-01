package codeforces;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

//https://codeforces.com/problemset/problem/1106/F
public class LunarNewYearAndRecursiveSequence {

    private static final int MOD = 998244353;
    private static final int toitent = 402653184;

    public static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
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
        // want to solve a^x=b (% mod). Let x = i-jn.
        // use meet-in-the-middle and solve a^i = a^(jn)b (% mod)
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

    // return mat1*mat2, each term % mod
    // requires that mat1[0].length = mat2.length
    private static long[][] matMul(long[][] mat1, long[][] mat2, long mod) {
        long[][] result = new long[mat1.length][mat2[0].length];
        for (int i = 0; i < mat1.length; i++) {
            for (int j = 0; j < mat2[0].length; j++) {
                for (int k = 0; k < mat1[0].length; k++) {
                    result[i][j] = (result[i][j] + mat1[i][k] * mat2[k][j]) % mod;
                }
            }
        }
        return result;
    }

    // return mat^p, each term % mod
    private static long[][] modPow(long[][] mat, long p, long mod) {
        if (p == 0) {
            long[][] id = new long[mat.length][mat.length];
            for (int i = 0; i < id.length; i++) {
                id[i][i] = 1;
            }
            return id;
        } else {
            long[][] half = modPow(mat, p / 2, mod);
            long[][] ans = matMul(half, half, mod);
            if (p % 2 == 1) {
                ans = matMul(ans, mat, mod);
            }
            return ans;
        }
    }

    private static long modPow(long a, long p, long mod) {
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

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = Integer.parseInt(sc.nextLine());
        long[] powers = Arrays.stream(sc.nextLine().split(" "))
                .mapToLong(x -> Long.parseLong(x)).toArray();
        String[] params = sc.nextLine().split(" ");
        int n = Integer.parseInt(params[0]);
        int m = Integer.parseInt(params[1]);
        if (m == 1) {
            System.out.println(1);
            return;
        }

        long[][] mat = new long[k][k];
        mat[0] = powers;
        for (int i = 0; i < k - 1; i++) {
            mat[i + 1][i] = 1;
        }
        long[][] fPowers = new long[k][1];
        fPowers[0][0] = 1;
        fPowers = matMul(modPow(mat, n - k, MOD - 1), fPowers, MOD - 1);

        //solve x^finalPow % MOD = m
        long finalPow = fPowers[0][0];
        // 3^log = m = 3^(C*finalPow)
        long log = discreteLog(3, m, MOD);
        // solve log = c*finalPow (mod MOD-1)
        if (gcd(log, MOD - 1) % gcd(finalPow, MOD - 1) != 0) {
            System.out.println(-1);
        } else {
            log /= gcd(finalPow, MOD - 1);
            finalPow /= gcd(finalPow, MOD - 1);
            //log * (finalPow^-1) = c (mod MOD-1)
            long finalPowInv = modPow(finalPow, toitent - 1, MOD - 1);
            long c = (modPow(3, (log * finalPowInv) % (MOD - 1), MOD)) % MOD;
            System.out.println(c);
        }
    }
}

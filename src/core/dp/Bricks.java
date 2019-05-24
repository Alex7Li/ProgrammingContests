package core.dp;

import java.util.Arrays;
import java.util.Scanner;

// solution with help from Vatsal... this was insanely hard for me
// https://codeforces.com/gym/101669
public class Bricks {
    private static final int MOD = 1_000_000_007;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] a = new int[n + 1];
        for (int i = 0; i < m; i++) {
            a[sc.nextInt() - 1]++;
        }
        // sum[i] = a[0] + a[1] + ... + a[i-1]
        int[] sum = new int[n + 1];
        sum[0] = 0;
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + a[i];
        }
        // noBrickWays[i] = number of ways to fill the array from i to n such that there is no brick at index i
        int[] noBrickWays = new int[n + 1];
        noBrickWays[n] = 1;

        // brickWays[i] = number of ways to fill the array from i to n such that there is a brick at index i
        int[] brickWays = new int[n + 1];

        // diff[i] = i - sum[i].
        int[] diff = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            diff[i] = i - sum[i];
        }
        // We will want to find the minimum j such that will can build a brick sequence from i to j, filling
        // it nicely.
        // Let's notice that this is possible iff diff[i]==diff[j+1].
        // This array stores the minimum j>i where diff[i] - diff[j] = 0.
        int[] lastDiff = computeLastDiff(diff);
        for (int i = n - 1; i >= 0; i--) {
            // calculate brickWays[i]
            // if there is a brick above, we must push them all to the right, filling the array
            // from i up until j.
            int j = lastDiff[i] - 1;
            if (j != n) {
                // if we can build a brick sequence filling i to j but not j+1,
                // then add the number of ways we can fill j+1 to n
                assert diff[i] == diff[j + 1];
                brickWays[i] = (noBrickWays[j + 1] + brickWays[j + 1]) % MOD;
            }

            // calculate noBrickWays[i]. If there is a brick at a[i], it is 0.
            // otherwise, it is just the number of ways to fill the array from i+1 to n.
            if (a[i] == 0) {
                noBrickWays[i] = (noBrickWays[i + 1] + brickWays[i + 1]) % MOD;
            }
        }

        System.out.println((noBrickWays[0] + brickWays[0])%MOD);
        sc.close();
    }

    /*
     For each i, compute the minimum j>i where diff[i] - diff[j] = 0.
     (If there is no such j, let j=diff.length)
     (Also, if diff[i]<0, just let j=diff.length since it won't matter to the algorithm -
     if diff[i]<0, then it is clearly impossible to fill the interval from i to n)
      */
    private static int[] computeLastDiff(int[] diff) {
        int[] lastDiff = new int[diff.length];
        // stores where we've last seen a index.
        // this is actually a map from int->int, stored as an
        // array for speed.
        int[] lastSeen = new int[diff.length];
        Arrays.fill(lastSeen, diff.length);
        for (int i = diff.length - 1; i >= 0; i--) {
            if (diff[i] >= 0) {
                lastDiff[i] = lastSeen[diff[i]];
                lastSeen[diff[i]] = i;
            } else {
                lastDiff[i] = diff.length;
            }
        }
        return lastDiff;
    }
}
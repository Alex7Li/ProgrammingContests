package codeforces;

import java.util.Arrays;
import java.util.Scanner;

//http://codeforces.com/problemset/problem/995/F
public class CowpanyCowpensation {
    private static long MOD = (long) (Math.pow(10, 9)) + 7;
    //dp[i][j] = ways employee i and subtree can have salaries assigned with D = j
    public static long[][] dp;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int D = sc.nextInt();
        dp = new long[n][n+1];
        for (long[] a : dp) {
            Arrays.fill(a, 1L);
        }
        int[] chainOfCommand = new int[n];
        for (int i = 1; i < chainOfCommand.length; i++) {
            chainOfCommand[i] = sc.nextInt() - 1;
        }
        for (int i = dp.length - 1; i > 0; i--) {
            int bossInd = chainOfCommand[i];
            for (int j = 1; j < dp[0].length; j++) {
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
                dp[bossInd][j] = (dp[bossInd][j] * dp[i][j]) % MOD;
            }
        }
        for (int i = 0; i < dp[0].length - 1; i++) {
            dp[0][i+1] = (dp[0][i] + dp[0][i + 1]) % MOD;
        }
        long[] x = new long[n+1];
        for (int i = 0; i <= n; i++) {
            x[i] = i + 1;
        }
        System.out.println(lagrange_interp(x, dp[0], D));
    }

    public static long lagrange_interp(long[] x, long[] y, int targetX) {
        long ans = 0;
        for (int i = 0; i < x.length; i++) {
            long num = 1;
            long denom = 1;
            long numTarget = 1;
            for (int j = 0; j < x.length; j++) {
                if (j != i) {
                    num = (num * (x[i] - x[j])) % MOD;
                    denom = (denom * (x[i] - x[j])) % MOD;
                    numTarget = (numTarget * (targetX - x[j])) % MOD;
                }
            }
            long factor = (modInv((num+MOD)%MOD) * y[i]) % MOD;
            ans = (ans + numTarget * factor + MOD) % MOD;
        }
        return ans;
    }

    public static long modInv(long x) {
        if (x == 1) {
            return 1;
        } else {
            return MOD - ((MOD / x) * modInv(MOD % x)) % MOD;
        }
    }
}

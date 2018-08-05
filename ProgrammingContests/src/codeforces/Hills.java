package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

//http://codeforces.com/problemset/problem/1012/C
public class Hills {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] a = new int[n + 1];
        String[] astr = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(astr[i]);
        }
        //dp[house][k][i] = the best result to make k houses
        //using squares 0 to i inclusive (with a house on square i iff house = 1).
        //square i+1 is considered to have height a[i+1]. We can dig there, but we
        //can't build on it.
        int[][][] dp = new int[2][(n + 3) / 2][n];
        for (int k = 0; k < 2; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j <= (n + 1) / 2; j++) {
                    if (j + k != 0) {
                        dp[k][j][i] = Integer.MAX_VALUE;
                    }
                }
            }
        }
        dp[1][1][0] = Math.max(0, 1 + a[1] - a[0]);
        for (int i = 1; i < n; i++) {
            for (int k = 1; k <= Math.min(n + 1, (i + 3)) / 2; k++) {
                // 1. do not build house here
                dp[0][k][i] = Math.min(dp[0][k][i - 1], dp[1][k][i - 1]);
                // 2. build house here
                // a. Excavate the right and left sides to place house.
                if (dp[0][k - 1][i - 1] != Integer.MAX_VALUE) {
                    dp[1][k][i] = dp[0][k - 1][i - 1] + Math.max(0, 1 + a[i + 1] - a[i]) + Math.max(0, 1 + a[i - 1] - a[i]);
                }
                // b. Though, if we placed a house 2 spaces ago, we may have already dug left side somewhat.
                if (i > 1 && dp[1][k - 1][i - 2] != Integer.MAX_VALUE) {
                    dp[1][k][i] = Math.min(dp[1][k][i], dp[1][k - 1][i - 2] + Math.max(0, 1 + a[i + 1] - a[i]) +
                            Math.max(0, 1 + Math.min(a[i - 2] - 1, a[i - 1]) - a[i]));
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i < dp[0].length; i++) {
            int best = Math.min(dp[0][i][n - 1], dp[1][i][n - 1]);
            sb.append(best);
            if (i != dp[0].length - 1) {
                sb.append(" ");
            }
        }
        System.out.println(sb);
    }
}
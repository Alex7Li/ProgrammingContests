package codeforces;

import java.io.IOException;
import java.util.Scanner;

// http://codeforces.com/contest/1152/problem/D
public class NekoAndAkiPrank {
    private final static long MOD = 1_000_000_007;

    public void solve() throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[][] ways = new long[n * 2][n + 1];
        long tWays = 0;
        ways[0][0] = 1;
        for (int i = 1; i < 2 * n; i++) {
            ways[i][0] = ways[i - 1][1];
            ways[i][n] = ways[i - 1][n - 1];
            for (int k = 1; k < n; k++) {
                ways[i][k] = (ways[i - 1][k - 1] + ways[i - 1][k + 1]) % MOD;
            }
            if (i % 2 == 1) {
                for (int k = 0; k <= Math.min(i, 2 * n - i); k++) {
                    tWays = (tWays + ways[i][k]) % MOD;
                }
            }
        }
        System.out.println(tWays);
    }

    public static void main(String[] args) throws IOException {
        NekoAndAkiPrank solution = new NekoAndAkiPrank();
        solution.solve();
    }
}

package codeforces;

import java.io.IOException;
import java.util.Scanner;

//https://codeforces.com/problemset/problem/1105/C
public class AyoubAndLostArray {
    static final long MOD = 1000000007;

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long l = sc.nextLong();
        long r = sc.nextLong();
        long[] counts = new long[3];
        counts[0] = r / 3 - (l - 1) / 3;
        counts[1] = (r + 2) / 3 - (l + 1) / 3;
        counts[2] = (r + 1) / 3 - l / 3;
        long[][] ways = new long[3][n];
        for (int i = 0; i < 3; i++) {
            ways[i][0] = counts[i];
        }
        for (int i = 1; i < n; i++) {
            ways[0][i] = (ways[0][i - 1] * counts[0] + ways[1][i - 1] * counts[2] + ways[2][i - 1] * counts[1]) % MOD;
            ways[1][i] = (ways[0][i - 1] * counts[1] + ways[1][i - 1] * counts[0] + ways[2][i - 1] * counts[2]) % MOD;
            ways[2][i] = (ways[0][i - 1] * counts[2] + ways[1][i - 1] * counts[1] + ways[2][i - 1] * counts[0]) % MOD;
        }
        System.out.println(ways[0][n - 1]);
    }
}

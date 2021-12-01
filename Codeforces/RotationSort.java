package codeforces;

import java.util.Scanner;

// https://atcoder.jp/contests/agc032/tasks/agc032_d
public class RotationSort {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long a = sc.nextInt();
        long b = sc.nextInt();
        long[] p = new long[n];
        for (int i = 0; i < n; i++) {
            p[i] = sc.nextInt();
        }
        // costDP[i][j] = cost to sort the first i elements, moving some to
        // the right at cost A, such that the maximum element not moved to
        // the right has value <=j.
        long[][] costDP = new long[n][n + 1];
        for (int i = 0; i < n; i++) {
            costDP[i][0] = a * (i + 1);
        }
        for (int j = 0; j < p[0]; j++) {
            costDP[0][j] = a;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= n; j++) {
                if (j < p[i]) {
                    costDP[i][j] = Math.min(costDP[i][j - 1], costDP[i - 1][j] + a);
                } else if (j > p[i]) {
                    costDP[i][j] = Math.min(costDP[i][j - 1], costDP[i - 1][j] + b);
                } else {
                    costDP[i][j] = Math.min(costDP[i][j - 1], costDP[i - 1][j]);
                }
            }
        }

        long bestCost = costDP[n - 1][0];
        for (int i = 1; i <= n; i++) {
            bestCost = Math.min(costDP[n - 1][i], bestCost);
        }
        System.out.println(bestCost);
    }
}

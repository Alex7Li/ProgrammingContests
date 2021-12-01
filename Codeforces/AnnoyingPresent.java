package codeforces;

import java.util.Scanner;

//http://codeforces.com/contest/1009/problem/C
public class AnnoyingPresent {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        long sumX = 0;
        long sumPosD = 0;
        long sumNegD = 0;
        for (int i = 0; i < m; i++) {
            sumX += sc.nextInt();
            int d = sc.nextInt();
            if (d > 0) {
                sumPosD += d;
            } else {
                sumNegD += d;
            }
        }
        long ans = 2 * n * sumX + n * sumPosD * (n - 1);
        ans += 2 * sumNegD * (sumToN(n / 2) + sumToN((n - 1) / 2));
        System.out.println((double) ans / (n * 2));
    }

    public static long sumToN(int n) {
        return (long) (n) * (n + 1) / 2;
    }
}

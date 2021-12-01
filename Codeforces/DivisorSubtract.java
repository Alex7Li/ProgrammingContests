package codeforces;

import java.util.Scanner;

// http://codeforces.com/problemset/problem/1076/B
public class DivisorSubtract {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long d = 2;
        for (; d * d <= n; d++) {
            if (n % d == 0) {
                break;
            }
        }
        if (d * d > n) {
            d = n;
        }
        System.out.println(1 + (n - d) / 2);
    }

}

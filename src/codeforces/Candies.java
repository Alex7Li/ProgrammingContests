package codeforces;

import java.util.Scanner;

//http://codeforces.com/contest/991/problem/C
public class Candies {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long kmin = 1;
        long kmax = n;
        while (kmax > kmin) {
            long kguess = (kmax + kmin) / 2;
            long eaten = simulate(n, kguess);
            if (eaten >= (n+1) / 2) {
                kmax = kguess;
            } else {
                kmin = kguess + 1;
            }
        }
        System.out.println(kmin);
    }

    public static long simulate(long n, long k) {
        long eaten = 0;
        while (n > 0) {
            long eat = Math.min(n, k);
            n -= eat;
            eaten += eat;
            n -= n / 10;
        }
        return eaten;
    }
}

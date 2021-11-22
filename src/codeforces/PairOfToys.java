package codeforces;

import java.util.Scanner;
//http://codeforces.com/contest/1023/problem/B
public class PairOfToys {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long k = sc.nextLong();
        if (k > n) {
            long s = k - n;
            System.out.println(Math.max((n - s + 1L) / 2L, 0));
        } else {
            System.out.println((k - 1) / 2);
        }
    }
}

package codeforces;

import java.util.Scanner;

// http://codeforces.com/contest/1075/problem/A
public class TheKingsRace {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long x = sc.nextLong();
        long y = sc.nextLong();
        sc.close();
        long wTime = Math.max(x - 1, y - 1);
        long bTime = Math.max(n - x, n - y);
        if (wTime <= bTime) {
            System.out.println("White");
        } else {
            System.out.println("Black");
        }
    }
}

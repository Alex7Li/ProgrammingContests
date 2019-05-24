package codeforces;

import java.util.Scanner;

// https://codeforces.com/contest/1161/problem/C
// very clever
public class ThanosNim {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        int min = 51;
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            min = Math.min(min, a[i]);
        }
        int minCount = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == min) {
                minCount++;
            }
        }
        if (minCount <= n / 2) {
            System.out.println("Alice");
        } else {
            System.out.println("Bob");
        }

    }
}

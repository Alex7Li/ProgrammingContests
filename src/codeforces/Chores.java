package codeforces;

import java.util.Scanner;

// https://codeforces.com/problemset/problem/873/A
public class Chores {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int x = sc.nextInt();
        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = sc.nextInt();
        }
        for (int i = n - k; i < n; i++) {
            array[i] = x;
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += array[i];
        }
        System.out.println(sum);
        System.out.println();

    }
}

package codeforces;

import java.util.Scanner;

// http://codeforces.com/problemset/problem/1067/A
public class ArrayWithoutLocalMax {

    //the modulus to use
    private static final long MOD = 0x3b800001;

    //largest possible element of the array
    private static final int MAX = 200;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        //the given array of numbers
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt() - 1;
        }
        sc.close();

        // waysLast[0][i] = ways to make the array up to a certain row such that the
        // current element is i, and i is greater than the prior element of the array.
        // waysLast[1][i] = ways to make the array up to a certain row such that the
        // current element is i, and i is less than or equal to the prior element of the array.
        long[][] waysLast = new long[2][MAX];

        // There is 1 way to get the first element. We consider it greater than the last
        // so it won't become a maximum later.
        if (a[0] != -2) {
            waysLast[0][a[0]] = 1;
        } else {
            for (int i = 0; i < MAX; i++) {
                waysLast[0][i] = 1;
            }
        }

        // like waysLast, but for the next row.
        long[][] waysNext = new long[2][MAX];
        for (int i = 1; i < a.length; i++) {
            if (a[i] == -2) { //  a[i] is unknown
                long sum = 0;
                // first count all the ways while going up
                for (int j = 0; j < MAX; j++) {
                    waysNext[0][j] = sum;
                    sum = (sum + waysLast[0][j] + waysLast[1][j]) % MOD;
                }
                sum = 0;
                // count all the ways while not going up
                for (int j = MAX - 1; j >= 0; j--) {
                    sum = (sum + waysLast[1][j]) % MOD;
                    waysNext[1][j] = (sum + waysLast[0][j]) % MOD;
                }
            } else { //  a[i] is a constant
                //count ways going up
                for (int j = 0; j < a[i]; j++) {
                    waysNext[0][a[i]] = (waysNext[0][a[i]] + waysLast[0][j] + waysLast[1][j]) % MOD;
                }
                //count ways not going up
                waysNext[1][a[i]] = waysLast[0][a[i]];
                for (int j = a[i]; j < MAX; j++) {
                    waysNext[1][a[i]] = (waysNext[1][a[i]] + waysLast[1][j]) % MOD;
                }
            }
            waysLast = waysNext;
            waysNext = new long[2][MAX];
        }

        // return the number of ways to get the last element. We consider it more than the
        // next so that we don't make it a maximum.
        long ways = 0;
        if (a[n - 1] != -2) {
            ways = (waysLast[1][a[n - 1]]) % MOD;
        } else {
            for (int i = 0; i < waysLast[0].length; i++) {
                ways = (ways + waysLast[1][i]) % MOD;
            }
        }
        System.out.println(ways);
        sc.close();
    }
}

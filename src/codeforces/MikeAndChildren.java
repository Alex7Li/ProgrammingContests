package codeforces;

import java.util.Arrays;
import java.util.Scanner;

// https://codeforces.com/contest/1121/problem/B
public class MikeAndChildren {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        Arrays.sort(a);
        int maxWays = 0;
        for (int sum = 2; sum <= 2e5; sum++) {
            int ways = 0;
            int endInd = a.length - 1;
            for (int stInd = 0; stInd < endInd; stInd++) {
                while (stInd < endInd && a[endInd] + a[stInd] >= sum) {
                    if (a[endInd] + a[stInd] == sum) {
                        ways++;
                    }
                    endInd--;
                }
            }
            maxWays = Math.max(ways, maxWays);
        }
        System.out.println(maxWays);
    }
}

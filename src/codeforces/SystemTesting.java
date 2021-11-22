package codeforces;

import java.util.Scanner;

//https://codeforces.com/contest/1121/problem/C
public class SystemTesting {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int[] curTest = new int[n];
        boolean[] interesting = new boolean[n];
        boolean[] done = new boolean[n];

        int queueSt = 0;
        int queueEnd = Math.min(n, k);
        long d = 0;
        int doneCount = 0;
        int t = 0;
        while (queueSt < n) {
            t++;
            int queueAdd = 0;
            for (int i = queueSt; i < queueEnd; i++) {
                if (curTest[i] < a[i]) {
                    curTest[i]++;
                    if (curTest[i] == d) {
                        interesting[i] = true;
                    }
                }
                if (curTest[i] == a[i]) {
                    if (!done[i]) {
                        done[i] = true;
                        doneCount++;
                        if (queueEnd + queueAdd < n) {
                            queueAdd++;
                        }
                    }
                    if (i == queueSt) {
                        queueSt++;
                    }
                }
            }
            queueEnd += queueAdd;
            d = Math.round((100.0 * doneCount) / n);
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (interesting[i]) {
                count++;
            }
        }
        System.out.println(count);
    }
}

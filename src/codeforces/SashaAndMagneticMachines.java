package codeforces;

import java.util.Arrays;
import java.util.Scanner;

//https://codeforces.com/contest/1113/problem/B
public class SashaAndMagneticMachines {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        Arrays.sort(a);
        int bestDecrease = 0;
        for (int i = 1; i < n; i++) {
            // minimize a[0] + a[i]
            for (int j = 2; j <= a[i]; j++) {
                if (a[i] % j == 0) {
                    int decrease = (a[0] + a[i]) - (a[i] / j + a[0] * j);
                    bestDecrease = Math.max(decrease, bestDecrease);
                }
            }
        }
        System.out.println(Arrays.stream(a).sum() - bestDecrease);
    }
}


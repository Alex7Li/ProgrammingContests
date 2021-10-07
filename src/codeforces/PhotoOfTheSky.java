package codeforces;

import java.util.Arrays;
import java.util.Scanner;
//http://codeforces.com/problemset/problem/1012/A
public class PhotoOfTheSky {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n * 2];
        for (int i = 0; i < 2 * n; i++) {
            a[i] = sc.nextInt();
        }
        long ans = Long.MAX_VALUE;
        Arrays.sort(a);
        for (int l = 0; l <= n; l++) {
            int min1 = a[l];
            int max1 = a[l + n - 1];
            int min2 = l == 0 ? a[n] : a[0];
            int max2 = l == n ? a[n - 1] : a[2 * n - 1];
            long f1 = max1 - min1;
            long f2 = max2 - min2;
            ans = Math.min(f1*f2,ans);
        }
        System.out.println(ans);
    }
}

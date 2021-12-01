package codeforces;

import java.util.Arrays;
import java.util.Scanner;

//https://codeforces.com/contest/1084/problem/B
public class KvassAndFairNut {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextInt();
        long s = sc.nextLong();
        sc.nextLine();
        long[] a = Arrays.stream(sc.nextLine().split(" ")).mapToLong(Long::parseLong).toArray();
        if (Arrays.stream(a).sum() < s) {
            System.out.println(-1);
        } else {
            Arrays.sort(a);
            long min = a[0];
            long equalizer = 0;
            for (int i = 0; i < a.length; i++) {
                equalizer += a[i] - min;
            }
            long left = s - equalizer;
            if (left <= 0) {
                System.out.println(min);
            } else {
                long toDrink = (left + n - 1) / n;
                System.out.println(min - toDrink);
            }
        }
        sc.close();
    }
}

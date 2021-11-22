package codeforces;

import java.util.Arrays;
import java.util.Scanner;

//http://codeforces.com/contest/991/problem/B
public class GettingAnA {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt()*2;
        }
        Arrays.sort(a);
        int goal = n*9;
        int redone = 0;
        int sum = Arrays.stream(a).sum();
        for (int i = 0; i < n && sum<goal; i++) {
            redone++;
            sum+=10-a[i];
        }
        System.out.println(redone);
    }
}

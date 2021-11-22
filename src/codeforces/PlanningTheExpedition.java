package codeforces;

import java.util.Arrays;
import java.util.Scanner;
//http://codeforces.com/contest/1011/problem/B
public class PlanningTheExpedition {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] a = new int[101];
        for (int i = 0; i < m; i++) {
            a[sc.nextInt()]++;
        }
        for (int days = 101; days >= 0; days--) {
            int[] b = Arrays.copyOf(a, a.length);
            int peopleLeft = n;
            for (int i = 0; i < 101; i++) {
                while (b[i] >= days) {
                    b[i] -= days;
                    peopleLeft--;
                    if (peopleLeft == 0) {
                        System.out.println(days);
                        return;
                    }
                }
            }
        }
    }
}

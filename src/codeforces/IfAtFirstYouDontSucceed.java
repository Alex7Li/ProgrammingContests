package codeforces;

import java.util.Arrays;
import java.util.Scanner;

//http://codeforces.com/contest/991/problem/A
public class IfAtFirstYouDontSucceed {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] a = Arrays.stream(sc.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int stayedHome = a[3] - (a[0] + a[1] - a[2]);
        if (Arrays.stream(a).max().getAsInt() == a[3] && a[2] <= a[1] && a[2] <= a[0] && a[3] >= stayedHome && stayedHome > 0) {
            System.out.println(stayedHome);
        } else {
            System.out.println(-1);
        }
    }
}

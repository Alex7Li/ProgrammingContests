package codeforces;

import java.util.Scanner;
//https://codeforces.com/problemset/problem/1096/A
public class FindDivisible {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            System.out.println(a + " " + 2*a);
        }
    }
}

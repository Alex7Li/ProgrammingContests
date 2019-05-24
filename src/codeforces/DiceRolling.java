package codeforces;

import java.util.Scanner;

//https://codeforces.com/contest/1093/problem/A
public class DiceRolling {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            int x = sc.nextInt();
            System.out.println((x/7)+1);
        }
    }
}

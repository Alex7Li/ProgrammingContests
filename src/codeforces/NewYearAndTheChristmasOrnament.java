package codeforces;

import java.util.Scanner;

//https://codeforces.com/contest/1091/problem/A
public class NewYearAndTheChristmasOrnament {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int y = sc.nextInt();
        int b = sc.nextInt();
        int r = sc.nextInt();
        int nY = Math.min(Math.min(y, b - 1), r - 2);
        System.out.println((nY+1)*3);
        sc.close();
    }
}

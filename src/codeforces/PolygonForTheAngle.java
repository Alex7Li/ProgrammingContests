package codeforces;

import java.util.Scanner;

//https://codeforces.com/problemset/problem/1096/C
public class PolygonForTheAngle {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int test = 0; test < t; test++) {
            int d = sc.nextInt();
            int ans = -1;
            for (int n = 3; n <= 360; n++) {
                int prod = d * n;
                if (prod % 180 == 0 && prod / 180 <= (n - 2)) {
                    ans = n;
                    break;
                }
            }
            System.out.println(ans);
        }
    }
}

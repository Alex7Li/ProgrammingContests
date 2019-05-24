package codeforces;

import java.util.Scanner;

//http://codeforces.com/contest/1020/problem/A
public class NewBuildingForSIS {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int h = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();
        int k = sc.nextInt();
        for (int i = 0; i < k; i++) {
            int ta = sc.nextInt();
            int fa = sc.nextInt();
            int tb = sc.nextInt();
            int fb = sc.nextInt();
            int ans = Math.abs(ta - tb);
            if (fa < a && fb < a && ta != tb) {
                ans += a - fa + a - fb;
            } else if (fa > b && fb > b && ta != tb) {
                ans += fa - b + fb - b;
            } else {
                ans += Math.abs(fa - fb);
            }
            System.out.println(ans);
        }
    }
}

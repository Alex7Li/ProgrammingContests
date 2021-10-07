package codeforces;

import java.util.Scanner;

// https://codeforces.com/contest/1121/problem/A
public class TechnoGobletOfFire {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int k = sc.nextInt();
        int[] p = new int[n+1];
        int[] best = new int[m+1];
        int[] s = new int[n+1];
        for (int i = 1; i <= n; i++) {
            p[i] = sc.nextInt();
        }
        for (int i = 1; i <= n; i++) {
            s[i] = sc.nextInt();
            best[s[i]] = Math.max(best[s[i]],p[i]);
        }
        int count = 0;
        for (int i = 1; i <= k; i++) {
            int choosenInd = sc.nextInt();
            if(best[s[choosenInd]] != p[choosenInd]){
                count++;
            }
        }
        System.out.println(count);
    }
}

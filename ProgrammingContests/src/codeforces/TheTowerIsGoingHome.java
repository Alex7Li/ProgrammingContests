package codeforces;

import java.util.Arrays;
import java.util.Scanner;

// http://codeforces.com/contest/1075/problem/C
public class TheTowerIsGoingHome {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] vertPos = new int[n + 1];
        int[] horEnd = new int[m];
        for (int i = 0; i < n; i++) {
            vertPos[i] = sc.nextInt();
        }
        vertPos[n] = 1000000000;
        for (int i = 0; i < m; i++) {
            if (sc.nextInt() == 1) {
                horEnd[i] = sc.nextInt();
            } else {
                horEnd[i] = 0;
                sc.nextInt();
            }
            sc.nextInt();
        }
        Arrays.sort(vertPos);
        Arrays.sort(horEnd);
        // most rightwards cell we can go to
        int rdist;
        int horKilled = m;
        int bestCost = m;
        for (int i = 0; i <= n; i++) {
            rdist = vertPos[i];
            // Don't need to kill a row if it is before rdist
            while (horKilled > 0 && horEnd[m - horKilled] < rdist) {
                horKilled--;
            }
            bestCost = Math.min(horKilled + i, bestCost);
        }
        System.out.println(bestCost);
        sc.close();
    }
}

package codeforces;

import java.util.Arrays;
import java.util.Scanner;

// https://codeforces.com/problemset/problem/1130/B
public class TwoCakesNumberTwo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] firstLoc = new int[n + 1];
        int[] secondLoc = new int[n + 1];
        Arrays.fill(firstLoc, -1);
        Arrays.fill(secondLoc, -1);
        firstLoc[0]=0;
        secondLoc[0]=0;
        for (int i = 0; i < 2 * n; i++) {
            int nxtInt = sc.nextInt();
            if (firstLoc[nxtInt] == -1) {
                firstLoc[nxtInt] = i;
            } else {
                secondLoc[nxtInt] = i;
            }
        }
        long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += Math.abs(firstLoc[i+1]-firstLoc[i]);
            sum += Math.abs(secondLoc[i+1]-secondLoc[i]);
        }
        System.out.println(sum);
    }
}


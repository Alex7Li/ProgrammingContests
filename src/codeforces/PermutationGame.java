package codeforces;

import java.util.Scanner;

//http://codeforces.com/problemset/problem/1033/C
public class PermutationGame {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        int[] locations = new int[n];
        boolean[] isWinning = new boolean[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt() - 1;
            locations[a[i]] = i;
        }
        for (int i = n - 1; i >= 0; i--) {
            int st = locations[i] % (i + 1);
            // a position is winning iff we can get to a losing position from it.
            while (st < n) {
                if (i < a[st]) {
                    isWinning[locations[i]] |= !isWinning[st];
                }
                st += (i + 1);
            }
        }
        StringBuilder sb = new StringBuilder();
        for (boolean b : isWinning) {
            if (b) {
                sb.append("A");
            } else {
                sb.append("B");
            }
        }
        System.out.println(sb);
    }
}

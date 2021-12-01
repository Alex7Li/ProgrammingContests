package codeforces;

import java.util.Scanner;

//https://codeforces.com/problemset/problem/873/C
public class StrangeGameOnMatrix {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int k = sc.nextInt();
        int[][] a = new int[m][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[j][i] = sc.nextInt();
            }
        }
        int replaced = 0;
        int score = 0;
        for (int i = 0; i < m; i++) {
            int max = 0;
            int occurence =0;
            for (int z = 0; z < n - k + 1; z++) {
                int sum = 0;
                for (int x = 0; x < k; x++) {
                    sum+= a[i][z+x];

                }
                if (sum > max) {
                    max = sum;
                    occurence = z;
                }

            }
            int toReplace = 0;
            for (int v = 0; v < occurence; v++) {
                if (a[i][v] == 1) {
                    toReplace++;
                }
            }
            replaced += toReplace;
            score += max;
        }
        System.out.println(score + " " + replaced);
    }
}

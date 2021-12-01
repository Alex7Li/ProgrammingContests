package codeforces;

import java.util.Arrays;
import java.util.Scanner;

// https://codeforces.com/problemset/problem/1129/A2
public class ToyTrain {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] times = new int[n];
        int[] residue = new int[n];
        Arrays.fill(times, -n);
        Arrays.fill(residue, n);
        for (int i = 0; i < m; i++) {
            int st = sc.nextInt() - 1;
            int end = sc.nextInt() - 1;
            times[st] += n;
            int res = (n + end - st) % n;
            residue[st] = Math.min(residue[st], res);
        }
        for (int i = 0; i < n; i++) {
            int time = 0;
            for (int j = 0; j < n; j++) {
                if(times[j]==-n){
                    continue;
                }
                int dist = (n + j - i) % n;
                time = Math.max(time, dist + times[j] + residue[j]);
            }
            if (i + 1 != n) {
                System.out.print(time + " ");
            } else {
                System.out.println(time);
            }
        }
    }
}

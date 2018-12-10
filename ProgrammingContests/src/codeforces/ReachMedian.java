package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
//http://codeforces.com/contest/1037/problem/B
public class ReachMedian {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] numStrFirst = br.readLine().split(" ");
        int n = Integer.parseInt(numStrFirst[0]);
        int s = Integer.parseInt(numStrFirst[1]);
        String[] aStr = br.readLine().split(" ");
        Integer[] a = new Integer[n];
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(aStr[i]);
        }
        long cost = 0;
        Arrays.sort(a);
        for (int i = 0; i < n / 2; i++) {
            cost += Math.max(0, a[i] - s);
        }
        cost += Math.abs(a[n / 2] - s);
        for (int i = n / 2 + 1; i < n; i++) {
            cost += Math.max(0, s - a[i]);
        }
        System.out.println(cost);
    }
}

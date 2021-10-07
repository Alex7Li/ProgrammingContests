package codeforces;

import java.io.*;
import java.util.Arrays;
//https://codeforces.com/problemset/problem/1098/B
public class SumInTheTree {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        int n = Integer.parseInt(br.readLine());
        int[] parents = new int[n];
        String[] a = br.readLine().split(" ");
        for (int i = 1; i < parents.length; i++) {
            parents[i] = Integer.parseInt(a[i - 1]) - 1;
        }
        int[] sums = Arrays.stream(br.readLine().split(" "))
                .mapToInt(x -> Integer.parseInt(x)).toArray();
        //check that it's possible : it's possible iff every node is less than or equal to it's children
        boolean possible = true;
        int[] values = new int[n];
        Arrays.fill(values, -1);
        values[0] = sums[0];
        for (int i = 1; i < n; i++) {
            if (sums[i] != -1) {
                if (sums[parents[parents[i]]] <= sums[i]) {
                    values[i] = sums[i] - sums[parents[parents[i]]];
                    if (values[parents[i]] == -1) {
                        values[parents[i]] = values[i];
                    } else {
                        values[parents[i]] = Math.min(values[parents[i]], values[i]);
                    }
                } else {
                    possible = false;
                }
            }
        }
        if (!possible) {
            pw.println(-1);
        } else {
            for (int i = 1; i < n; i++) {
                if (sums[i] != -1) {
                    values[i] -= values[parents[i]];
                }
            }
            long sum = 0;
            for (int i = 0; i < n; i++) {
                if (values[i] != -1) {
                    sum += values[i];
                }
            }
            System.out.println(sum);
        }
        pw.flush();
        br.close();
        pw.close();
    }
}

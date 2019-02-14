package codeforces;

import java.io.*;

//https://codeforces.com/problemset/problem/1097/C
public class YuhaoAndAParenthesis {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        int n = Integer.parseInt(br.readLine());
        char[][] seq = new char[n][];
        int maxL = 0;
        for (int i = 0; i < n; i++) {
            seq[i] = br.readLine().toCharArray();
            maxL = Math.max(seq[i].length, maxL);
        }
        //maxL: perfect. Otherwise it needs a pair
        int[] num = new int[2 * maxL+4];
        for (int i = 0; i < n; i++) {
            int extra = 0;
            int min = 0;
            for (int j = 0; j < seq[i].length; j++) {
                switch (seq[i][j]) {
                    case '(':
                        extra++;
                        break;
                    case ')':
                        extra--;
                        min = Math.min(extra, min);
                        break;
                }
            }
            extra = 0;
            int max = 0;
            for (int j = seq[i].length - 1; j >= 0; j--) {
                switch (seq[i][j]) {
                    case '(':
                        extra++;
                        max = Math.max(extra, max);
                        break;
                    case ')':
                        extra--;
                        break;
                }
            }
            if (min != 0 && max != 0) {
                continue;
            } else if (min == 0) {
                num[max + maxL]++;
            } else {
                num[min + maxL]++;
            }
        }
        int ways = num[maxL] / 2;
        for (int i = maxL - 1; i >= 0; i--) {
            ways += Math.min(num[i], num[2 * maxL - i]);
        }
        System.out.println(ways);
        pw.flush();
        br.close();
        pw.close();
    }
}

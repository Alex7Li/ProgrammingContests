package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

//http://codeforces.com/contest/1004/problem/D
public class SonyaAndMatrix {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        int[] counts = new int[t];
        String[] line = br.readLine().split(" ");
        for (int i = 0; i < t; i++) {
            int nxt = Integer.parseInt(line[i]);
            counts[nxt]++;
        }
        for (int i = 0; i < counts.length; i++) {
            if (counts[i] == 0) {
                counts = Arrays.copyOf(counts, i);
                break;
            }
        }
        for (int n = 1; n * n <= t; n++) {
            if (t % n == 0) {
                int m = t / n;
                for (int x = 0; x <= n; x++) {
                    if (testPos(n, m, counts, x, counts.length-1-x)) {
                        System.out.println(n + " " + m);
                        System.out.println((x + 1) + " " + (counts.length - x));
                        return;
                    }
                }
            }
        }
        System.out.println(-1);
    }

    public static boolean testPos(int n, int m, int[] counts, int x, int y) {
        long[] wallDists = {x, y, n - x - 1, m - y - 1};
        long[] cornerDists = {x + y, y + n - x - 1, n + m - x - y - 2, x + m - y - 1};
        for (int i=0;i<counts.length; i++) {
            long expected = Math.max(4 * i, 1);
            for (long d : wallDists) {
                if (i - d > 0) {
                    expected -= 2 * (i - d) - 1;
                }
            }
            for (long d : cornerDists) {
                expected += Math.max(0, i - d - 1);
            }
            if (counts[i] != expected) {
                return false;
            }
        }
        return true;
    }
}
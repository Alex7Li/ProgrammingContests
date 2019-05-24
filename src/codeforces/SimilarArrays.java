package codeforces;

import javafx.util.Pair;

import java.io.*;
import java.util.HashSet;
import java.util.Set;

public class SimilarArrays {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        String[] params = br.readLine().split(" ");
        int n = Integer.parseInt(params[0]);
        int m = Integer.parseInt(params[1]);
        if (m == (n * (n - 1)) / 2) {
            pw.println("NO");
        } else {
            pw.println("YES");
            Set<Pair<Integer, Integer>> pairs = new HashSet<>();
            int extra = 0;
            for (int i = 0; i <= m + extra; i++) {
                int min = Math.min(i % n, i / n);
                int max = Math.max(i % n, i / n);
                Pair<Integer, Integer> p = new Pair<>(min, max);
                if (min == max || pairs.contains(p)) {
                    extra++;
                } else {
                    pairs.add(p);
                }
            }
            for (int i = 0; i < m; i++) {
                params = br.readLine().split(" ");
                int e1 = Integer.parseInt(params[0]) - 1;
                int e2 = Integer.parseInt(params[1]) - 1;
                int min = Math.min(e1, e2);
                int max = Math.max(e1, e2);
                pairs.remove(new Pair<Integer, Integer>(min, max));
            }
            int[] ans = new int[n];
            for (int i = 0; i < n; i++) {
                ans[i] = i + 1;
            }
            Pair<Integer, Integer> randPair = pairs.stream().findFirst().get();
            // the same pair will always work if both elements are at the same extreme,
            // so put the minimal elements at the indices of the pair
            int temp = ans[0];
            ans[0] = ans[randPair.getKey()];
            ans[randPair.getKey()] = temp;
            //sway value with index 1 element (careful not to move element we just swapped)
            if (randPair.getKey() != 1) {
                temp = ans[1];
                ans[1] = ans[randPair.getValue()];
                ans[randPair.getValue()] = temp;
            } else {
                temp = ans[0];
                ans[0] = ans[randPair.getValue()];
                ans[randPair.getValue()] = temp;
            }
            printArray(ans, pw);
            //set value and key to the same element (should be 1)
            ans[randPair.getValue()] = ans[randPair.getKey()];
            printArray(ans, pw);
        }
        pw.flush();
        pw.close();
        br.close();
    }

    private static void printArray(int[] a, PrintWriter pw) {
        for (int i = 0; i < a.length - 1; i++) {
            pw.print(a[i] + " ");
        }
        pw.println(a[a.length - 1]);
    }
}

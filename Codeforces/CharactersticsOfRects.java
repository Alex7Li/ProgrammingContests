package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;

// https://codeforces.com/contest/333/problem/D
public class CharactersticsOfRects {
    private boolean isPossible(int n, int m, int[][] table, int mid) {
        Set<Integer> seen = new HashSet<>(10000);
        for (int i = 0; i < n; i++) {
            List<Integer> pairs = new LinkedList<>();
            for (int j = 0; j < m; j++) {
                if (table[i][j] >= mid) {
                    pairs.add(j);
                }
            }
            for (int j : pairs) {
                for (int k : pairs) {
                    if (j < k) {
                        Integer p = (j << 10) + k;
                        if (seen.contains(p)) {
                            return true;
                        }
                        seen.add(p);
                    }
                }
            }
        }
        return false;
    }

    public void solve() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] params = br.readLine().split(" ");
        int n = Integer.parseInt(params[0]);
        int m = Integer.parseInt(params[1]);
        int[][] table = new int[n][m];
        int max = 0;
        for (int i = 0; i < n; i++) {
            String[] ar = br.readLine().split(" ");
            for (int j = 0; j < m; j++) {
                table[i][j] = Integer.parseInt(ar[j]);
                max = Math.max(max, table[i][j]);
            }
        }
        int min = 0;
        int upper = max + 1;
        while (min < upper) {
            int mid = (min + upper) >> 1;
            if (isPossible(n, m, table, mid)) {
                min = mid;
            } else {
                upper = mid - 1;
            }
            // make binary search work always
            if (min + 1 == upper) {
                upper++;
            }
        }
        System.out.println(min);
    }

    public static void main(String[] args) throws IOException {
        CharactersticsOfRects solution = new CharactersticsOfRects();
        solution.solve();
    }
}

package codeforces;

import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

// https://codeforces.com/problemset/problem/1130/C
public class Connect {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        boolean[][] grid = new boolean[n][n];
        Location start = new Location(sc.nextInt() - 1, sc.nextInt() - 1);
        Location end = new Location(sc.nextInt() - 1, sc.nextInt() - 1);
        sc.nextLine();
        for (int i = 0; i < n; i++) {
            char[] line = sc.nextLine().toCharArray();
            for (int j = 0; j < n; j++) {
                grid[i][j] = line[j] == '0';
            }
        }
        int minCost = Integer.MAX_VALUE;
        boolean[][] seen1 = canGetTo(start, grid);
        boolean[][] seen2 = canGetTo(end, grid);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int i2 = 0; i2 < n; i2++) {
                    for (int j2 = 0; j2 < n; j2++) {
                        if (seen1[i][j] && seen2[i2][j2]) {
                            int cost = (i2 - i) * (i2 - i) +
                                    (j2 - j) * (j2 - j);
                            if (cost < minCost) {
                                minCost = cost;
                            }
                        }
                    }
                }
            }
        }
        System.out.println(minCost);
    }

    public static boolean[][] canGetTo(Location st, boolean[][] grid) {
        Queue<Location> Q = new ArrayDeque<>();
        int n = grid.length;
        boolean[][] seen = new boolean[n][n];
        Q.add(st);
        seen[st.row][st.col] = true;
        while (!Q.isEmpty()) {
            Location nxt = Q.poll();
            if (nxt.row + 1 < n && grid[nxt.row + 1][nxt.col] && !seen[nxt.row + 1][nxt.col]) {
                seen[nxt.row + 1][nxt.col] = true;
                Q.add(new Location(nxt.row + 1, nxt.col));
            }
            if (nxt.col + 1 < n && grid[nxt.row][nxt.col + 1] && !seen[nxt.row][nxt.col + 1]) {
                seen[nxt.row][nxt.col + 1] = true;
                Q.add(new Location(nxt.row, nxt.col + 1));
            }
            if (nxt.row - 1 >= 0 && grid[nxt.row - 1][nxt.col] && !seen[nxt.row - 1][nxt.col]) {
                seen[nxt.row - 1][nxt.col] = true;
                Q.add(new Location(nxt.row - 1, nxt.col));
            }
            if (nxt.col - 1 >= 0 && grid[nxt.row][nxt.col - 1] && !seen[nxt.row][nxt.col - 1]) {
                seen[nxt.row][nxt.col - 1] = true;
                Q.add(new Location(nxt.row, nxt.col - 1));
            }
        }
        return seen;
    }

    private static class Location {
        int row;
        int col;

        Location(int r, int c) {
            row = r;
            col = c;
        }
    }
}


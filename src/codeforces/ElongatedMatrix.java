package codeforces;

import javafx.util.Pair;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;

//https://codeforces.com/problemset/problem/1102/F
public class ElongatedMatrix {
    private static int n;
    /**
     * if the rows are arranged in some permutation [p_1, p_2,...i,j,...p_n],
     * 1!=i!=j!=n, minCost[i][j] is the min k for any permutation with i&j adjacent
     **/
    private static int[][] minCost;
    /**
     * minCostEndpoints[i][j] is the min k for any permutation such that
     * the rows are arranged in some permutation [i, p_2, ... p_{n-1}, j],
     **/
    private static int[][] minCostEndpoints;

    /**
     * Max k of a path over a subset of all rows ending at a certain vertex
     * The first 16 bits of the key represent the subset. Node n is in the subset iff (x & (2 << n))!=0
     * key/(1<<16) is the end vertex number
     */
    private static HashMap<Integer, Integer> costs = new HashMap<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] params = Arrays.stream(br.readLine().split(" "))
                .mapToInt(x -> Integer.parseInt(x)).toArray();
        n = params[0];
        int m = params[1];
        int[][] matrix = new int[n][m];
        for (int i = 0; i < n; i++) {
            matrix[i] = Arrays.stream(br.readLine().split(" "))
                    .mapToInt(x -> Integer.parseInt(x)).toArray();
        }
        minCost = new int[n][n];
        minCostEndpoints = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i > j) {
                    minCost[i][j] = Integer.MAX_VALUE;
                    for (int k = 0; k < m; k++) {
                        int diff = Math.abs(matrix[i][k] - matrix[j][k]);
                        if (diff < minCost[i][j]) {
                            minCost[i][j] = diff;
                        }
                    }
                    minCost[j][i] = minCost[i][j];
                }
                minCostEndpoints[i][j] = Integer.MAX_VALUE;
                for (int k = 0; k < m - 1; k++) {
                    int diff = Math.abs(matrix[i][k + 1] - matrix[j][k]);
                    if (diff < minCostEndpoints[i][j]) {
                        minCostEndpoints[i][j] = diff;
                    }
                }
            }
        }
        int maxCost = n == 1 ? minCostEndpoints[0][0] : 0;
        for (int i = 0; i < n; i++) {
            costs.clear();
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    int bitmask = (1 << i) | (1 << j);
                    int state = bitmask + (j << 16);
                    costs.put(state, minCost[i][j]);
                }
            }
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    if (minCostEndpoints[i][j] <= maxCost) {
                        continue;
                    } else {
                        int pathCost = Math.min(minCostEndpoints[i][j], findMaxCost(i, j, (1 << n) - 1));
                        maxCost = Math.max(maxCost, pathCost);
                    }
                }
            }
        }
        System.out.println(maxCost);
        br.close();
    }

    //find the minimum cost starting at st, ending at end, and using only the rows in set
    private static int findMaxCost(int st, int end, int set) {
        int state = set + (end << 16);
        if (costs.containsKey(state)) {
            return costs.get(state);
        }
        int maxCost = 0;
        for (int i = 0; i < n; i++) {
            if (i != st && i != end && (set & (1 << i)) != 0) {
                int setWithoutEnd = set - (1 << end);
                int pathCost = Math.min(findMaxCost(st, i, setWithoutEnd), minCost[i][end]);
                maxCost = Math.max(pathCost, maxCost);
            }
        }
        costs.put(state, maxCost);
        return maxCost;
    }
}

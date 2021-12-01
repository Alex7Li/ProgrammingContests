package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;

//https://codeforces.com/problemset/problem/893/C
public class Rumor {

    private static int[] c;
    private static int[][] edges;
    private static boolean[] seen;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int[] params = Arrays.stream(br.readLine().split(" "))
                .mapToInt(x -> Integer.parseInt(x)).toArray();
        int n = params[0];
        int m = params[1];
        c = Arrays.stream(br.readLine().split(" "))
                .mapToInt(x -> Integer.parseInt(x)).toArray();
        edges = readAdjList(br, n, m, true);
        seen = new boolean[n];
        long sum = 0;
        for (int i = 0; i < n; i++) {
            if (!seen[i]) {
                sum += dfs(i);
            }
        }
        System.out.println(sum);
        pw.flush();
        br.close();
        pw.close();
    }

    private static int dfs(int i) {
        seen[i] = true;
        int min = c[i];
        for (int j : edges[i]) {
            if (!seen[j]) {
                min = Math.min(min, dfs(j));
            }
        }
        return min;
    }

    /**
     * Return sorted 2D array of edges
     *
     * @param oneIndexed: if true, the input is given as 1-indexed, otherwise,
     *                    it is given as 0-indexed. Either way, this method returns
     *                    only 0-indexed arrays
     */
    private static int[][] readAdjList(BufferedReader br, int n, int m, boolean oneIndexed) throws IOException {
        int[] counts = new int[n];
        int[][] edges = new int[m][2];
        for (int i = 0; i < m; i++) {
            String[] edge = br.readLine().split(" ");
            int a = Integer.parseInt(edge[0]);
            int b = Integer.parseInt(edge[1]);
            if (oneIndexed) {
                a--;
                b--;
            }
            edges[i][0] = a;
            edges[i][1] = b;
            counts[a]++;
            counts[b]++;
        }
        int[][] adjList = new int[n][];
        for (int i = 0; i < n; i++) {
            adjList[i] = new int[counts[i]];
        }
        for (int[] edge:edges) {
            adjList[edge[0]][--counts[edge[0]]] = edge[1];
            adjList[edge[1]][--counts[edge[1]]] = edge[0];
        }
        // not necessary, but will make debugging easier
        for (int i = 0; i < n; i++) {
            Arrays.sort(adjList[i]);
        }
        return adjList;
    }
}

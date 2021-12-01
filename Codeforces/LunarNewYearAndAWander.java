package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

//https://codeforces.com/problemset/problem/1106/D
public class LunarNewYearAndAWander {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int[] params = Arrays.stream(br.readLine().split(" "))
                .mapToInt(x -> Integer.parseInt(x)).toArray();
        int n = params[0];
        int m = params[1];
        int[][] adj = readAdjList(br, n, m);
        TreeSet<Integer> adjEdges = new TreeSet<>();
        Set<Integer> visited = new HashSet<>();
        List<Integer> seq = new ArrayList<>();
        adjEdges.add(1);
        while (visited.size() < n) {
            int nxt = adjEdges.pollFirst();
            seq.add(nxt);
            visited.add(nxt);
            for (int i : adj[nxt]) {
                if (!visited.contains(i)) {
                    adjEdges.add(i);
                }
            }
        }
        for (int i = 0; i < seq.size() - 1; i++) {
            pw.print(seq.get(i) + " ");
        }
        pw.println(seq.get(seq.size() - 1));
        pw.flush();
        br.close();
        pw.close();
    }

    public static int[][] readAdjList(BufferedReader br, int n, int m) throws IOException {
        n++;
        int[] counts = new int[n];
        int[][] edges = new int[m][2];
        for (int i = 0; i < m; i++) {
            String[] edge = br.readLine().split(" ");
            int a = Integer.parseInt(edge[0]);
            int b = Integer.parseInt(edge[1]);
            edges[i][0] = a;
            edges[i][1] = b;
            counts[a]++;
            counts[b]++;
        }
        int[][] adjList = new int[n][];
        for (int i = 0; i < n; i++) {
            adjList[i] = new int[counts[i]];
        }
        for (int i = 0; i < edges.length; i++) {
            adjList[edges[i][0]][--counts[edges[i][0]]] = edges[i][1];
            adjList[edges[i][1]][--counts[edges[i][1]]] = edges[i][0];
        }
        //for debugging ease
        for (int i = 0; i < n; i++) {
            Arrays.sort(adjList[i]);
        }
        return adjList;
    }
}

package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

//http://codeforces.com/contest/1037/problem/D
public class ValidBFS {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] graph = adjList(br, n, n - 1);
        boolean[] seen = new boolean[n + 1];
        int[] dist = new int[n + 1];

        Queue<Integer> q = new LinkedList<>();
        q.offer(1);
        seen[1] = true;
        int i = 1;
        while (!q.isEmpty()) {
            int nxt = q.poll();
            for (int e : graph[nxt]) {
                if (!seen[e]) {
                    q.offer(e);
                    seen[e] = true;
                    dist[e] = dist[nxt] + 1;
                }
            }
        }

        int[] order = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        boolean pos = true;
        if (order[0] != 1) {
            pos = false;
        }
        br.close();
        Queue<Integer> lastNodes = new LinkedList<>();
        Queue<Integer> nextNodes = new LinkedList<>();
        lastNodes.offer(1);
        for (int j = 1; j < order.length; j++) {
            int diff = 0;
            if (j + 1 < order.length) {
                diff = dist[order[j]] - dist[order[j + 1]];
            }
            if (diff > 0) {
                pos = false;
            } else {
                boolean foundPath = false;
                while (!foundPath && !lastNodes.isEmpty()) {
                    int loc = Arrays.binarySearch(graph[lastNodes.peek()], order[j]);
                    if (loc >= 0) {
                        foundPath = true;
                    } else {
                        lastNodes.poll();
                    }
                }
                if (lastNodes.isEmpty()) {
                    pos = false;
                }
                nextNodes.offer(order[j]);
                if (diff < 0) {
                    lastNodes = nextNodes;
                    nextNodes = new LinkedList<>();
                }
            }
        }
        if (pos) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

    /**
     * Return sorted 2D array of edges
     * (Assumes edges are 1-indexed)
     */
    public static int[][] adjList(BufferedReader br, int n, int m) throws IOException {
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
        for (int i = 0; i < n; i++) {
            Arrays.sort(adjList[i]);
        }
        return adjList;
    }
}

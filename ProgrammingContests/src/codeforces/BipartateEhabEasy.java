package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BipartateEhabEasy {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Node[] graph = undirectedGraphFromEdgeList(br, n, n - 1);
        graph[0].search(0);
        long l = 0;
        for (int i = 0; i < graph.length; i++) {
            if (graph[i].color == 1) {
                l++;
            }
        }
        System.out.println(l * (n - l) - (n - 1));
    }

    private static Node[] undirectedGraphFromEdgeList(BufferedReader br, int n, int m) throws IOException {
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node();
        }
        int[] counts = new int[n];
        int[][] edges = new int[m][2];
        for (int i = 0; i < m; i++) {
            String[] edge = br.readLine().split(" ");
            int a = Integer.parseInt(edge[0]) - 1;
            int b = Integer.parseInt(edge[1]) - 1;
            edges[i][0] = a;
            edges[i][1] = b;
            counts[a]++;
            counts[b]++;
        }
        for (int i = 0; i < n; i++) {
            nodes[i].edges = new Node[counts[i]];
        }
        for (int i = 0; i < edges.length; i++) {
            Node a = nodes[edges[i][0]];
            Node b = nodes[edges[i][1]];
            a.edges[a.ind++] = b;
            b.edges[b.ind++] = a;
        }
        return nodes;
    }

    private static class Node {
        int ind = 0;
        Node[] edges;
        int color;
        boolean seen = false;

        void search(int color) {
            seen = true;
            this.color = 1 - color;
            for (Node edge : edges) {
                if (!edge.seen) {
                    edge.search(this.color);
                }
            }
        }
    }
}

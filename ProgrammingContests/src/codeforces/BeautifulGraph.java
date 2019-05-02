package codeforces;

import java.io.*;

//https://codeforces.com/contest/1093/problem/D
public class BeautifulGraph {
    private static int[] color;
    private static final long MOD = 998244353L;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int t = Integer.parseInt(br.readLine());
        for (int x = 0; x < t; x++) {
            String[] inParams = br.readLine().split(" ");
            int n = Integer.parseInt(inParams[0]);
            int m = Integer.parseInt(inParams[1]);
            Node[] nodes = undirectedGraphFromEdgeList(br, n, m);
            color = new int[n];
            long ways = 1;
            for (int i = 0; i < n; i++) {
                if (color[i] == 0) {
                    long nWays = nodes[i].ways(1);
                    nodes[i].clearColors();
                    nWays += nodes[i].ways(2);
                    ways = (ways * nWays) % MOD;
                }
            }
            bw.write(Long.toString(ways));
            bw.newLine();
        }
        bw.flush();
    }

    private static class Node {
        int ind = 0;
        Node[] edges;
        int n_edge;

        void clearColors() {
            color[ind] = 0;
            for (Node n:edges) {
                if(color[n.ind]!=0) {
                    n.clearColors();
                }
            }
        }

        //color this graph
        long ways(int parity) {
            long ways = 1;
            if (parity == 1) {
                ways = 2;
            }
            color[ind] = parity;
            for (Node n : edges) {
                if (color[n.ind] == 0) {
                    ways = (ways * n.ways(3 - parity)) % MOD;
                } else if (color[n.ind] == parity) {
                    return 0;
                }
            }
            return ways;
        }
    }


    /**
     * read an undirected graph in from br, from a list of it's edges.
     * Store the results as nodes with Node[] edges.
     * (Assumes edges from input are 1-indexed)
     */
    public static Node[] undirectedGraphFromEdgeList(BufferedReader br, int n, int m) throws IOException {
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node();
            nodes[i].ind = i;
            nodes[i].n_edge = 0;
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
            a.edges[a.n_edge++] = b;
            b.edges[b.n_edge++] = a;
        }
        return nodes;
    }

}

package tools;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.Arrays;

//Use GraphInput.txt for copy-pasting
public class GraphInput {
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
    //--------------------------Alternate Input Method----------------------------------------//

    private static class Node {
        // 0-indexed index of the node in the Node[] returned from undirectedGraphFromEdgeList
        int ind;
        // number of edges.
        int n_edge;
        // edges of the node
        Node[] edges;
    }

    /**
     * read an undirected graph in from br, from a list of it's edges.
     * Store the results as nodes with Node[] edges.
     * (Assumes edges from input are 1-indexed)
     */
    private static Node[] readGraph(BufferedReader br, int n, int m) throws IOException {
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
    //--------------------------Weighted Graph----------------------------------------//

    private static class Edge {
        // the other node this edge connects to (the first is the index is adjList)
        int dest;
        // the weight of this edge in the graph
        int weight;

        public Edge(int dest, int weight) {
            this.dest = dest;
            this.weight = weight;
        }
    }

    /**
     * read an undirected weighted graph in from br, from a list of it's edges.
     * Store the results as nodes with Node[] edges.
     * Input should be m lines of vertex 1 and 2, then weights: v1 v2 w
     * (Assumes edges from input are 1-indexed)
     */
    private static Edge[][] readWeightedGraph(BufferedReader br, int n, int m) throws IOException {
        Edge[][] adjList = new Edge[n][];
        int[] counts = new int[n];
        int[][] edges = new int[m][3];
        for (int i = 0; i < m; i++) {
            String[] edge = br.readLine().split(" ");
            int a = Integer.parseInt(edge[0]) - 1;
            int b = Integer.parseInt(edge[1]) - 1;
            int w = Integer.parseInt(edge[2]);
            edges[i][0] = a;
            edges[i][1] = b;
            edges[i][2] = w;
            counts[a]++;
            counts[b]++;
        }
        for (int i = 0; i < edges.length; i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            int w = edges[i][2];
            adjList[a][--counts[a]] = new Edge(b, w);
            adjList[b][--counts[b]] = new Edge(a, w);
        }
        return adjList;
    }
}

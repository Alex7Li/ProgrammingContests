package codeforces;

import java.io.*;
import java.util.*;

//http://codeforces.com/problemset/problem/144/D
public class MissleSilos {
    private static int[] distances;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] params = br.readLine().split(" ");
        int n = Integer.parseInt(params[0]);
        int m = Integer.parseInt(params[1]);
        int capLoc = Integer.parseInt(params[2]) - 1;
        Edge[][] edges = readWeightedGraph(br, n, m);
        int siloDist = Integer.parseInt(br.readLine());
        br.close();

        boolean[] seen = new boolean[n];
        distances = new int[n];
        Arrays.fill(distances, Integer.MAX_VALUE);
        PriorityQueue<Node> Q = new PriorityQueue<>(n);
        distances[capLoc] = 0;
        Q.add(new Node(capLoc, distances[capLoc]));

        while (!Q.isEmpty()) {
            Node cur = Q.poll();
            if (seen[cur.index]) {
                continue;
            }
            for (Edge e : edges[cur.index]) {
                if (!seen[e.dest]) {
                    if (distances[e.dest] > distances[cur.index] + e.weight) {
                        distances[e.dest] = distances[cur.index] + e.weight;
                        Q.add(new Node(e.dest, distances[e.dest]));
                    }
                }
            }
            seen[cur.index] = true;
        }

        int count = 0;
        for (int i = 0; i < distances.length; i++) {
            if (distances[i] == siloDist) {
                count++;
            }
        }
        for (int i = 0; i < edges.length; i++) {
            for (int j = 0; j < edges[i].length; j++) {
                if (i < edges[i][j].dest) {
                    continue;
                }
                int u = distances[i];
                int v = distances[edges[i][j].dest];
                int d = edges[i][j].weight;
                //ensure u>=v
                if (v > u) {
                    int temp = v;
                    v = u;
                    u = temp;
                }
                if (u - v == d) {// max dist is at an edge
                    if (siloDist > v && siloDist < u) {// silo is on this road
                        count++;
                    }
                } else if (siloDist > v) { // max dist on this road and a silo could be on this road
                    // max dist = u + x = v + (d-x)
                    // u - v = d-2x;
                    // d - (u-v) = 2x
                    int x2 = d - (u - v);
                    int maxDist2 = 2 * u + x2;
                    if (siloDist * 2 == maxDist2) {
                        count++;
                    } else if (siloDist * 2 < maxDist2) {
                        if (siloDist <= u) {
                            count++;
                        } else {
                            count += 2;
                        }
                    }
                }
            }
        }
        System.out.println(count);
    }

    public static class Edge {
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
     * (Assumes edges from input are 1-indexed)
     */
    public static Edge[][] readWeightedGraph(BufferedReader br, int n, int m) throws IOException {
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
        for (int i = 0; i < n; i++) {
            adjList[i] = new Edge[counts[i]];
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

    private static class Node implements Comparable<Node> {
        int index;
        int dist;

        public Node(int index, int dist) {
            this.index = index;
            this.dist = dist;
        }

        @Override
        public int compareTo(Node other) {
            return dist - other.dist;
        }
    }
}

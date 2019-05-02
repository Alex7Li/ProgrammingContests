package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

//http://codeforces.com/problemset/problem/1000/E
public class WeNeedMoreBosses {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] params = br.readLine().split(" ");
        int n = Integer.parseInt(params[0]);
        int m = Integer.parseInt(params[1]);
        Node[] nodes = undirectedGraphFromEdgeList(br, n, m);
        nodes[0].findBridges(null);
        for (Node node : nodes) {
            node.seen = false;
        }
        Node s = furthest(nodes[0]);
        for (Node node : nodes) {
            node.seen = false;
        }
        System.out.println(furthest(s).dist);
    }

    private static class Node {
        Node[] edges;
        int ind = 0;
        Set<Node> nonBridges = new HashSet<>();
        int dist = 0;
        boolean seen = false;

        // fill up nonBridges with edges that aren't bridges
        // return the set of nodes that have stopped the dfs
        private Set<Node> findBridges(Node from) {
            seen = true;
            Set<Node> endCycle = new HashSet<>();
            for (Node e : edges) {
                if (e != from && !nonBridges.contains(e)) {
                    if (e.seen) {
                        endCycle.add(e);
                        nonBridges.add(e);
                        e.nonBridges.add(this);
                    } else {
                        Set<Node> cycles = e.findBridges(this);
                        if (!cycles.isEmpty()) {
                            nonBridges.add(e);
                            e.nonBridges.add(this);
                        }
                        cycles.remove(this);
                        endCycle.addAll(cycles);
                    }
                }
            }
            return endCycle;
        }
    }


    /**
     * Return a node furthest from start
     */
    private static Node furthest(Node start) {
        Queue<Node> Q = new PriorityQueue<>((o1, o2) -> o1.dist - o2.dist);
        Q.add(start);
        start.dist = 0;
        while (true) {
            Node n = Q.poll();
            n.seen = true;
            for (Node e : n.edges) {
                if (!e.seen) {
                    if (n.nonBridges.contains(e)) {
                        e.dist = n.dist;
                    } else {
                        e.dist = n.dist + 1;
                    }
                    Q.add(e);
                }
            }
            if (Q.isEmpty()) {
                return n;
            }
        }
    }

    /**
     * read an undirected graph in from br, from a list of it's edges.
     * Store the results as nodes with Node[] edges.
     * (Assumes edges are 1-indexed)
     */
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
}

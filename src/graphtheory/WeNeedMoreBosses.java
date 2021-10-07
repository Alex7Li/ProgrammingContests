package graphtheory;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Set;

// http://codeforces.com/problemset/problem/1000/E
// this code is TLE
public class WeNeedMoreBosses {
public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String[] params = br.readLine().split(" ");
    int n = Integer.parseInt(params[0]);
    int m = Integer.parseInt(params[1]);
    Node[] nodes = readGraph(br, n, m);
    nodes[0].findBridges(null);
    Node s = furthest(nodes[0]);
    for (Node node : nodes) {
        node.seen = false;
    }
    System.out.println(furthest(s).dist);
}

private static class Node {
    Node[] edges;
    int ind;
    int dist = 0;
    boolean seen = false;
    
    int timeSeen = 0;
    Set<Node> bridges = new HashSet<>();
    static int totalSeen = 0;
    /*
     * Find all bridges in the graph (When calling initially, let parent=null).
     * If the node connects to a bridge, we add the other
     * node that the bridge connects to the set bridges.
     * Procedure: For each node, mark when it's seen. Then, for each edge, search every unexplored part of that
     * edge and return the lowest timeSeen. The edge is a bridge exactly when that time is leq to the time that
     * we started searching that edge,
     */
    private int findBridges(Node parent) {
        totalSeen++;
        timeSeen = totalSeen;
        int minSeen = timeSeen;
        for (Node e : edges) {
            int minSeenThisEdge = e.timeSeen;
            if (e.timeSeen == 0) {
                int curSeen = totalSeen;
                minSeenThisEdge = e.findBridges(this);
                if (minSeenThisEdge > curSeen) {
                    bridges.add(e);
                    e.bridges.add(this);
                }
            }
            if (e != parent) {
                minSeen = Math.min(minSeen, minSeenThisEdge);
            }
        }
        return minSeen;
    }
    
    @Override
    public String toString() {
        return "" + ind;
    }
}


/**
 * Return a node furthest from start, in terms of the number of bridges away
 */
private static Node furthest(Node start) {
    Queue<Node> Q = new PriorityQueue<>((o1, o2) -> o1.dist - o2.dist);
    Q.add(start);
    start.dist = 0;
    start.seen = true;
    while (true) {
        Node n = Q.poll();
        for (Node e : n.edges) {
            if (!e.seen) {
                e.seen = true;
                if (n.bridges.contains(e)) {
                    e.dist = n.dist + 1;
                } else {
                    e.dist = n.dist;
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
 * Read an undirected graph in from br, from a list of it's edges.
 * Store the results as nodes with Node[] edges.
 * (Assumes edges from input are 1-indexed)
 */
private static Node[] readGraph(BufferedReader br, int n, int m) throws IOException {
    Node[] nodes = new Node[n];
    for (int i = 0; i < n; i++) {
        nodes[i] = new Node();
        nodes[i].ind = i;
    }
    int[][] edges = new int[m][2];
    int[] n_edge = new int[n];
    for (int i = 0; i < m; i++) {
        String[] edge = br.readLine().split(" ");
        int a = Integer.parseInt(edge[0]) - 1; // assuming edges from input are 1-indexed
        int b = Integer.parseInt(edge[1]) - 1; // and assuming you want them 0-indexed
        edges[i][0] = a;
        edges[i][1] = b;
        n_edge[a]++;
        n_edge[b]++;
    }
    for (int i = 0; i < n; i++) {
        nodes[i].edges = new Node[n_edge[i]];
    }
    for (int[] e : edges){
        Node a = nodes[e[0]];
        Node b = nodes[e[1]];
        a.edges[n_edge[a.ind]--] = b;
        b.edges[n_edge[b.ind]--] = a;
    }
    return nodes;
}
}

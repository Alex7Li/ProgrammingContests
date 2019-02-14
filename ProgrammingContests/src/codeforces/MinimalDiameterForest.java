package codeforces;

import java.io.*;
import java.util.*;

//https://codeforces.com/problemset/problem/1092/E
public class MinimalDiameterForest {
    private static Node[] forest;
    private static boolean[] seen;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        String[] params = br.readLine().split(" ");
        int n = Integer.parseInt(params[0]);
        int m = Integer.parseInt(params[1]);
        forest = undirectedGraphFromEdgeList(br, n, m);
        seen = new boolean[n];
        //node in the middle of a tree (max distance from diameter)
        //along with their length
        List<NodeIntPair> middleNodes = new ArrayList<>();
        //find the middleNodes
        for (int i = 0; i < n; i++) {
            if (!seen[i]) {
                NodeIntPair extreme1 = furthest(i);
                resetSeen(forest[i]);
                NodeIntPair extreme2 = furthest(extreme1.node.ind);
                Node middle = midPoint(extreme1.node, extreme2.node, extreme2.i);
                middleNodes.add(new NodeIntPair(middle, extreme2.i));
            }
        }
        Collections.sort(middleNodes);
        if (middleNodes.size() == 1) {
            pw.println(middleNodes.get(0).i);
        } else {
            int diam = 1 + (middleNodes.get(0).i + 1) / 2 + (middleNodes.get(1).i + 1) / 2;
            //super sneaky edge case when 3 largest are all same size
            if (middleNodes.size() >= 3 && (middleNodes.get(0).i + 1) / 2 == (middleNodes.get(2).i + 1) / 2){
                diam++;
            }
            diam = Math.max(diam, middleNodes.get(0).i);
            pw.println(diam);
            for (int i = 1; i < middleNodes.size(); i++) {
                pw.println((middleNodes.get(0).node.ind + 1) + " " + (middleNodes.get(i).node.ind + 1));
            }
        }
        pw.flush();
        br.close();
        pw.close();
    }

    //set every node in this connected component to unseen
    private static void resetSeen(Node n) {
        seen[n.ind] = false;
        for (Node nxt : n.edges) {
            if (seen[nxt.ind]) {
                resetSeen(nxt);
            }
        }
    }

    //return the node in the middle of a and b
    private static Node midPoint(Node a, Node b, int distBetween) {
        if (a == b) {
            return a;
        }
        Deque<Node> queue = new ArrayDeque<>();
        queue.add(a);
        //record where we found each node from
        Map<Node, Node> from = new HashMap<>();
        Set<Node> seen = new HashSet<>();
        foundB:
        while (true) {
            Node n = queue.remove();
            seen.add(n);
            for (Node nxt : n.edges) {
                if (!seen.contains(nxt)) {
                    seen.add(nxt);
                    queue.add(nxt);
                    from.put(nxt, n);
                    if (nxt == b) {
                        break foundB;
                    }
                }
            }
        }
        Node last = b;
        for (int i = 0; i < distBetween / 2; i++) {
            last = from.get(last);
        }
        return last;
    }

    // set every node in this connected component to seen
    // return the furthest node from forest[i] and how far it is
    private static NodeIntPair furthest(int i) {
        Deque<NodeIntPair> queue = new ArrayDeque<>();
        seen[i] = true;
        //node, distance
        queue.add(new NodeIntPair(forest[i], 0));
        int maxDist = -1;
        Node furthest = forest[i];
        while (!queue.isEmpty()) {
            NodeIntPair cur = queue.remove();
            if (cur.i > maxDist) {
                maxDist = cur.i;
                furthest = cur.node;
            }
            for (Node n : cur.node.edges) {
                if (!seen[n.ind]) {
                    seen[n.ind] = true;
                    queue.add(new NodeIntPair(n, cur.i + 1));
                }
            }
        }
        return new NodeIntPair(furthest, maxDist);
    }

    private static class NodeIntPair implements Comparable<NodeIntPair> {
        Node node;
        int i;

        public NodeIntPair(Node n, int i) {
            this.node = n;
            this.i = i;
        }

        @Override
        public int compareTo(MinimalDiameterForest.NodeIntPair o) {
            return o.i - this.i;
        }
    }

    public static class Node {
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

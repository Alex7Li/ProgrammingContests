package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// underscore because the name is too close to integer and it kept autocompleting
// http://codeforces.com/contest/1075/problem/D
class _IntersectingSubtrees {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(br.readLine());
            Node[] graph = undirectedGraphFromEdgeList(br, n, n - 1);
            int k1 = Integer.parseInt(br.readLine());
            int[] meSubTree = Arrays.stream(br.readLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
            Set<Integer> myNodes = new HashSet<>();
            for (int j = 0; j < meSubTree.length; j++) {
                myNodes.add(meSubTree[j]);
            }
            int k2 = Integer.parseInt(br.readLine());
            int[] liSubTree = Arrays.stream(br.readLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
            Set<Integer> liNodes = new HashSet<>();
            for (int j = 0; j < liSubTree.length; j++) {
                liNodes.add(liSubTree[j]);
            }
            System.out.println("BalancedSubstring " + liSubTree[0]);
            System.out.flush();
            int loc = Integer.parseInt(br.readLine()) - 1;
            // find closest node to the node with index loc in your subtree
            Queue<Node> queue = new LinkedList<>();
            Set<Integer> seen = new HashSet<>();
            queue.add(graph[loc]);
            seen.add(loc);
            while (!queue.isEmpty()) {
                Node nxt = queue.poll();
                if (myNodes.contains(nxt.ind + 1)) {
                    System.out.println("Innohorse " + (nxt.ind + 1));
                    System.out.flush();
                    int response = Integer.parseInt(br.readLine());
                    if (liNodes.contains(response)) {
                        System.out.println("NewYearAndTheSphereTransmission " + (nxt.ind + 1));
                    } else {
                        System.out.println("NewYearAndTheSphereTransmission " + -1);
                    }
                    System.out.flush();
                    break;
                } else {
                    for (Node connect : nxt.edges) {
                        if (!seen.contains(connect.ind)) {
                            queue.add(connect);
                            seen.add(connect.ind);
                        }
                    }
                }
            }
        }
    }

    private static class Node {
        // 0-indexed index of the node in the Node[] returned from undirectedGraphFromEdgeList
        int ind;
        // number of edges.
        int n_edge = 0;
        // edges of the node
        Node[] edges;
    }

    /**
     * read an undirected graph in from br, from a list of it's edges.
     * Store the results as nodes with Node[] edges.
     * (Assumes edges from input are 1-indexed)
     */
    private static Node[] undirectedGraphFromEdgeList(BufferedReader br, int n, int m) throws IOException {
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node();
            nodes[i].ind = i;
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

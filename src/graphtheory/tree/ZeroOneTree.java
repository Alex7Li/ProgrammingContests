package graphtheory.tree;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ZeroOneTree {

public static void main(String[] xx) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(br.readLine());
    Node[] nodes = readGraph(br, n, n - 1);
    long ways = 0;
    for (Node node : nodes) {
        for (int weight = 0; weight < 2; weight++) {
            if (node.compSize[weight] == 0) {
                node.search(weight);
                node.updateCompSize(weight);
                Node.curCompSize = 0;
                long compSize = node.compSize[weight];
                ways += compSize * (compSize - 1);
            }
        }
    }
    for (Node node : nodes) {
        if (node.compSize[0] > 1 && node.compSize[1] > 1) {
            ways += ((long) (node.compSize[0] - 1)) * (node.compSize[1] - 1);
        }
    }
    System.out.println(ways);
    br.close();
    
}

private static class Node {
    // 0-indexed index of the node in the Node[] returned from undirectedGraphFromEdgeList
    int ind;
    // edges of the node
    Node[] edges;
    int[] weights;
    // compSize[i] = the size of the component that uses only edges of weight i.
    int[] compSize = new int[2];
    private static int curCompSize = 0;
    
    private void search(int edgeWeight) {
        compSize[edgeWeight]++; // acting as boolean seen variable rn
        curCompSize++;
        for (int i = 0; i < edges.length; i++) {
            if (weights[i] == edgeWeight && edges[i].compSize[edgeWeight] == 0) {
                edges[i].search(edgeWeight);
            }
        }
    }
    
    private void updateCompSize(int edgeWeight) {
        compSize[edgeWeight] = curCompSize;
        for (int i = 0; i < edges.length; i++) {
            if (weights[i] == edgeWeight && edges[i].compSize[edgeWeight] != curCompSize) {
                edges[i].updateCompSize(edgeWeight);
            }
        }
    }
    
    
}

private static Node[] readGraph(BufferedReader br, int n, int m) throws IOException {
    Node[] nodes = new Node[n];
    for (int i = 0; i < n; i++) {
        nodes[i] = new Node();
        nodes[i].ind = i;
    }
    int[][] edges = new int[m][3];
    int[] n_edge = new int[n];
    for (int i = 0; i < m; i++) {
        String[] edge = br.readLine().split(" ");
        int a = Integer.parseInt(edge[0]) - 1; // assuming edges from input are 1-indexed
        int b = Integer.parseInt(edge[1]) - 1; // and assuming you want them 0-indexed
        edges[i][0] = a;
        edges[i][1] = b;
        edges[i][2] = Integer.parseInt(edge[2]);
        n_edge[a]++;
        n_edge[b]++;
    }
    for (int i = 0; i < n; i++) {
        nodes[i].edges = new Node[n_edge[i]];
        nodes[i].weights = new int[n_edge[i]];
    }
    for (int[] edge : edges) {
        Node a = nodes[edge[0]];
        Node b = nodes[edge[1]];
        int w = edge[2];
        a.weights[--n_edge[a.ind]] = w;
        a.edges[n_edge[a.ind]] = b;
        b.weights[--n_edge[b.ind]] = w;
        b.edges[n_edge[b.ind]] = a;
    }
    return nodes;
}
}

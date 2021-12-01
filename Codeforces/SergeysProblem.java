package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

////http://codeforces.com/contest/1020/problem/C
public class SergeysProblem {

    private class Node {
        int index;
        int ind = 0;
        Node[] edges;
        private boolean seen = false;
        private boolean choosen = false;

        private Node(int index, int nEdges) {
            this.index = index;
            edges = new Node[nEdges];
        }
        private void addEdge(Node edge){
            edges[ind] = edge;
            ind++;
        }
        private void choose() {
            seen = true;
            choosen = true;
            for (Node n : edges) {
                n.seen = true;
            }
        }

        private void finalizePick() {
            for (Node n : edges) {
                n.choosen = false;
            }
        }
    }

    private void solve() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] params = br.readLine().split(" ");
        int n = Integer.parseInt(params[0]);
        int m = Integer.parseInt(params[1]);
        List<Node> nodes = new ArrayList<>();
        int[] nEdges = new int[n];
        int[][] edges = new int[m][2];
        for (int i = 0; i < m; i++) {
            String[] edge = br.readLine().split(" ");
            int a = Integer.parseInt(edge[0]) - 1;
            int b = Integer.parseInt(edge[1]) - 1;
            edges[i] = new int[]{a,b};
            nEdges[a]++;
        }
        for (int i = 0; i < n; i++) {
            nodes.add(new Node(i,nEdges[i]));
        }
        for (int i = 0; i < edges.length; i++) {
            nodes.get(edges[i][0]).addEdge(nodes.get(edges[i][1]));
        }
        Stack<Node> toAdd = new Stack<>();
        for (Node node : nodes) {
            if (!node.seen) {
                node.choose();
                toAdd.add(node);
            }
        }
        int choosen = 1;
        StringBuilder nodeStr = new StringBuilder();
        toAdd.peek().finalizePick();
        nodeStr.append(toAdd.pop().index + 1);
        while (!toAdd.empty()) {
            Node nxt = toAdd.pop();
            if (nxt.choosen) {
                choosen++;
                nxt.finalizePick();
                nodeStr.append(" " + (nxt.index+1));
            }
        }
        System.out.println(choosen);
        System.out.println(nodeStr);
    }

    public static void main(String[] args) throws IOException {
        new SergeysProblem().solve();
    }

}

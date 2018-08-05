package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
//http://codeforces.com/problemset/problem/1012/B
public class ChemicalTable {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] params = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int n = params[0];
        int m = params[1];
        int q = params[2];
        Node[] graph = new Node[n + m];
        for (int i = 0; i < graph.length; i++) {
            graph[i] = new Node();
        }
        for (int i = 0; i < q; i++) {
            String[] inds = br.readLine().split(" ");
            Node a = graph[Integer.parseInt(inds[0]) - 1];
            Node b = graph[n + Integer.parseInt(inds[1]) - 1];
            a.connected.add(b);
            b.connected.add(a);
        }
        int count = -1;
        for (int i = 0; i < graph.length; i++) {
            if (!graph[i].seen) {
                count++;
                graph[i].dfs();
            }
        }
        System.out.println(count);
    }

    public static class Node {
        ArrayList<Node> connected = new ArrayList<>();
        boolean seen = false;

        void dfs() {
            seen = true;
            for (Node c : connected) {
                if (!c.seen) {
                    c.dfs();
                }
            }
        }
    }
}

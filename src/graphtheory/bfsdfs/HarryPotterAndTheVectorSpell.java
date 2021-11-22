package graphtheory.bfsdfs;

import java.util.*;

// https://codeforces.com/gym/101669
public class HarryPotterAndTheVectorSpell {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        // read in the input as a graph. Nodes a and b are
        // connected if there is a column with 1's at a & b.
        Node[] nodes = new Node[m];
        for (int i = 0; i < m; i++) {
            nodes[i] = new Node();
        }
        // when reading in input, we will get a number for each column
        // exactly once, since we read by columns. cols[i] records the
        // first column we saw a 1 in column i in.
        int[] cols = new int[n];
        Arrays.fill(cols, -1);
        for (int i = 0; i < m; i++) {
            int num = sc.nextInt();
            for (int j = 0; j < num; j++) {
                int a = sc.nextInt() - 1;
                if (cols[a] != -1) {
                    nodes[i].neighbors.add(nodes[cols[a]]);
                    nodes[cols[a]].neighbors.add(nodes[i]);
                } else {
                    cols[a] = i;
                }
            }
        }
        int connectedComponents = 0;
        for (int i = 0; i < m; i++) {
            if (!nodes[i].seen) {
                Queue<Node> q = new ArrayDeque<>();
                q.add(nodes[i]);
                nodes[i].seen = true;
                while (!q.isEmpty()) {
                    Node nxt = q.poll();
                    for (Node neighbor : nxt.neighbors) {
                        if (!neighbor.seen) {
                            neighbor.seen = true;
                            q.add(neighbor);
                        }
                    }
                }
                connectedComponents++;
            }
        }
        System.out.println(m - connectedComponents);
    }

    private static class Node {
        Set<Node> neighbors = new HashSet<>();
        boolean seen = false;
    }
}

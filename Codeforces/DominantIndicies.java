package codeforces;

import java.io.*;
import java.util.*;

//http://codeforces.com/problemset/problem/1009/F
public class DominantIndicies {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Node[] nodes = new Node[n];
        for (int i = 0; i < nodes.length; i++) {
            nodes[i] = new Node();
        }
        for (int i = 0; i < n - 1; i++) {
            String[] data = br.readLine().split(" ");
            Node n1 = nodes[Integer.parseInt(data[0]) - 1];
            Node n2 = nodes[Integer.parseInt(data[1]) - 1];
            n1.connectNode(n2);
            n2.connectNode(n1);
        }
        Node[] order = new Node[n];
        order[0] = nodes[0];
        nodes[0].parent = nodes[0];
        int len = 1;
        for (int i = 0; i < order.length; i++) {
            Node curNode = order[i];
            for (Node node : curNode.connected) {
                if (node != curNode.parent) {
                    order[len] = node;
                    len++;
                    node.parent = curNode;
                }
            }
        }
        for (int i = order.length - 1; i >= 0; i--) {
            order[i].calcDepthArr();
        }
        PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
        for (int i = 0; i < nodes.length; i++) {
            pw.println(nodes[i].domInd);
        }
        br.close();
        pw.close();
    }

    private static class Node {
        private List<Node> connected = new ArrayList<>();
        private List<Integer> depthArr;
        private int domIndr = 0;
        private int domInd;
        private Node parent;

        private void connectNode(Node o) {
            connected.add(o);
        }

        private void calcDepthArr() {
            depthArr = new ArrayList<>();
            connected.remove(parent);
            int max = 1;
            if (connected.size() > 0) {
                Node longest = connected.get(0);
                for (Node node : connected) {
                    if (longest.depthArr.size() < node.depthArr.size()) {
                        longest = node;
                    }
                }
                connected.remove(longest);
                depthArr = longest.depthArr;
                if (depthArr.get(longest.domIndr) > max) {
                    domIndr = longest.domIndr;
                    max = depthArr.get(longest.domIndr);
                } else {
                    domIndr = depthArr.size();
                }
            }
            for (Node n : connected) {
                int nsize = n.depthArr.size();
                for (int i = 1; i <= nsize; i++) {
                    int iThis = depthArr.size() - i;
                    int iN = nsize - i;
                    depthArr.set(iThis, depthArr.get(iThis) + n.depthArr.get(iN));
                    if (depthArr.get(iThis) > max || (depthArr.get(iThis) == max && iThis > domIndr)) {
                        max = depthArr.get(iThis);
                        domIndr = iThis;
                    }
                }
            }
            depthArr.add(1);
            domInd = depthArr.size() - domIndr - 1;
        }
    }
}

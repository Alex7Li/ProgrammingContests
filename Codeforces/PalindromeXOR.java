package codeforces;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// http://codeforces.com/contest/1161/problem/D
// pretty hard. Pretty clever solution but it was still not so easy to implement (this code is badly writen)
public class PalindromeXOR {
    private static final long MOD = 998244353L;

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        char[] a = sc.nextLine().toCharArray();
        long[] twoPows = new long[1 + 2 * a.length];
        twoPows[0] = 1;
        for (int i = 1; i < twoPows.length; i++) {
            twoPows[i] = (twoPows[i - 1] * 2) % MOD;
        }
        long ans = 0;
        Node[] topNodes = new Node[a.length];
        Node[] botNodes = new Node[a.length];
        for (int i = 0; i < a.length; i++) {
            topNodes[i] = new Node();
            topNodes[i].isTop = true;
            botNodes[i] = new Node();
            if (a[i] == '1') {
                topNodes[i].adj1.add(botNodes[i]);
                botNodes[i].adj1.add(topNodes[i]);
            } else if (a[i] == '0') {
                topNodes[i].adj0.add(botNodes[i]);
                botNodes[i].adj0.add(topNodes[i]);
            }
        }
        for (int i = 0; i < a.length / 2; i++) {
            topNodes[i].adj0.add(topNodes[a.length - 1 - i]);
            topNodes[a.length - 1 - i].adj0.add(topNodes[i]);
        }
        outLoop:
        for (int i = 1; i < a.length; i++) {
            botNodes[i-1].adj1.add(topNodes[0]);
            topNodes[0].adj1.add(botNodes[i-1]);
            recolor(topNodes, botNodes);
            for (int j = 0; j < (a.length - i) / 2; j++) {
                botNodes[j + i].adj0.add(botNodes[a.length - 1 - j]);
                botNodes[a.length - 1 - j].adj0.add(botNodes[j + i]);
            }
            botNodes[i].adj1.add(botNodes[i - 1]);
            botNodes[i - 1].adj1.add(botNodes[i]);
            int nCC = 0;
            for (int j = 0; j < topNodes.length; j++) {
                if (topNodes[j].color == -1) {
                    nCC++;
                    if (!topNodes[j].search(1)) {
                        continue outLoop;
                    }
                }
            }
            for (int j = i; j < botNodes.length; j++) {
                if (botNodes[j].color == -1) {
                    nCC++;
                    if (!botNodes[j].search(1)) {
                        continue outLoop;
                    }
                }
            }
            ans = (ans + twoPows[nCC - 1]) % MOD;
        }
        System.out.println(ans);
    }

    private static void recolor(Node[] topNodes, Node[] botNodes){
        for (Node n : topNodes) {
            n.color = -1;
        }
        for (Node n : botNodes) {
            n.color = -1;
            for (int j = n.adj1.size() - 1; j >= 0; j--) {
                if (!n.adj1.get(j).isTop) {
                    n.adj1.remove(j);
                }
            }
            for (int j = n.adj0.size() - 1; j >= 0; j--) {
                if (!n.adj0.get(j).isTop) {
                    n.adj0.remove(j);
                }
            }
        }
    }

    private static class Node {
        // number must change
        List<Node> adj1 = new ArrayList<>();
        // number must not change
        List<Node> adj0 = new ArrayList<>();
        boolean isTop = false;
        int color = -1;

        private boolean search(int color) {
            this.color = color;
            for (Node n : adj1) {
                if (n.color == -1) {
                    if (!n.search(1 - color)) {
                        return false;
                    }
                } else if (n.color == color) {
                    return false;
                }
            }
            for (Node n : adj0) {
                if (n.color == -1) {
                    if (!n.search(color)) {
                        return false;
                    }
                } else if (n.color == 1 - color) {
                    return false;
                }
            }
            return true;
        }
    }
}

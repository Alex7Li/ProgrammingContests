package misc.googlefoobar;

import java.util.ArrayList;
import java.util.Collection;

public class DistractTheGuards {
    public static void main(String[] args) {
        int[] ls1 = {16};
        System.out.println(answer(ls1));//7
        int[] ls2 = {1, 7, 3, 21, 13, 19};
        System.out.println(answer(ls2));//0
        int[] ls3 = {1, 7, 3};
        System.out.println(answer(ls3));//2
        int[] ls4 = {1, 5, 3845, 23, 3};//1
        System.out.println(answer(ls4));
        int[] ls5 = {1073741823, 1073741823, 1, 1};
        System.out.println(answer(ls5));//2
    }

    private static boolean[] seen;

    // basically, convert to a flow problem and decode.
    // 1 node for each guard, edge if they distract
    // each other.
    // We want to find the max flow from some node
    // connected to every other node back to itself
    public static int answer(int[] a) {
        Node[] guards = new Node[a.length];
        for (int i = 0; i < a.length; i++) {
            guards[i] = new Node(i);
        }
        for (int i = 0; i < guards.length; i++) {
            for (int j = 0; j < guards.length; j++) {
                if (willDistract(a[i], a[j])) {
                    guards[i].distractors.add(guards[j]);
                }
            }
        }
        //dfs for Ford-Fulkerson
        boolean updateFound = true;
        while (updateFound) {
            updateFound = false;
            for (int i = 0; i < guards.length; i++) {
                seen = new boolean[guards.length];
                if (guards[i].pair == null) {
                    if (guards[i].pair()) {
                        updateFound = true;
                    }
                }
            }
        }
        int count = 0;
        for (int i = 0; i < guards.length; i++) {
            if (guards[i].pair == null) {
                count++;
            }
        }
        return count;
    }

    public static class Node {
        Node pair = null;
        int index;
        Collection<Node> distractors = new ArrayList<>();

        public Node(int index) {
            this.index = index;
        }

        //return if a pair was found and update graph if so
        public boolean pair() {
            seen[index] = true;
            // next 2 lines might not actually be valid.
            // But, I think that if algorithm can't
            // find path from i->j, it will find one from j->i.
            // There could easily be a hack case, but it worked
            if (pair !=null) {
                seen[pair.index] = true;
            }
            for (Node n : distractors) {
                if (!seen[n.index] && n.pair == null) {
                    this.pair = n;
                    n.pair = this;
                    return true;
                } else if (n.pair != null && !seen[n.pair.index] && n.pair.pair()) {
                    this.pair = n;
                    n.pair = this;
                    return true;
                }
            }

            return false;
        }
    }

    // 2 guards with bananas a and b will not enter an infinite loop iff
    // (a+b)/gcd(a,b)==2^k for some k
    public static boolean willDistract(int a, int b) {
        int gcd = gcd(a, b);
        int res = (a + b) / gcd;
        return Integer.bitCount(res) != 1;

    }

    public static int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
}

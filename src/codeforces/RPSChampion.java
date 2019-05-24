package codeforces;

import java.io.*;
import java.util.HashMap;
import java.util.SortedSet;
import java.util.TreeSet;

//https://codeforces.com/contest/1087/problem/F
public class RPSChampion {
    private static HashMap<Character, Integer> rpsRep = new HashMap<>();
    private static SegmentTree[] trees = new SegmentTree[3];
    private static SortedSet<Integer>[] occurences = new TreeSet[3];
    private static int[] total = new int[3];

    static {
        rpsRep.put('R', 0);
        rpsRep.put('P', 1);
        rpsRep.put('S', 2);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        String[] params = br.readLine().split(" ");
        int n = Integer.parseInt(params[0]);
        int q = Integer.parseInt(params[1]);
        int[][] rpsTrees = new int[3][];
        for (int i = 0; i < rpsTrees.length; i++) {
            rpsTrees[i] = new int[n];
            occurences[i] = new TreeSet<>();
        }
        char[] moves = br.readLine().toCharArray();
        for (int i = 0; i < n; i++) {
            total[rpsRep.get(moves[i])]++;
            rpsTrees[rpsRep.get(moves[i])][i] = 1;
            occurences[rpsRep.get(moves[i])].add(i);
        }
        for (int i = 0; i < 3; i++) {
            trees[i] = new SegmentTree(rpsTrees[i]);
        }
        pw.println(countWinners(n));
        for (int i = 0; i < q; i++) {
            params = br.readLine().split(" ");
            int ind = Integer.parseInt(params[0]) - 1;
            char c = params[1].charAt(0);
            trees[rpsRep.get(moves[ind])].update(ind, 0);
            occurences[rpsRep.get(moves[ind])].remove(ind);
            total[rpsRep.get(moves[ind])]--;
            moves[ind] = c;
            trees[rpsRep.get(moves[ind])].update(ind, 1);
            occurences[rpsRep.get(moves[ind])].add(ind);
            total[rpsRep.get(moves[ind])]++;
            pw.println(countWinners(n));
        }
        pw.flush();
        br.close();
        pw.close();
    }

    public static int countWinners(int n) {
        int count = n;
        for (int i = 0; i < 3; i++) {
            int beats = (i + 2) % 3;
            int loses = (i + 1) % 3;
            if (!occurences[loses].isEmpty()) {
                if (occurences[beats].isEmpty()) {
                    count -= total[i];
                } else {
                    count -= trees[i].get(occurences[loses].first(), occurences[beats].first());
                    count -= trees[i].get(occurences[beats].last(), occurences[loses].last());
                }
            }
        }
        return count;
    }

    public static class SegmentTree {
        int[] tree;
        int n;

        /**
         * Constructs a new segment Tree from the given array
         */
        public SegmentTree(int[] a) {
            n = a.length;
            tree = new int[a.length * 2];
            for (int i = 0; i < n; i++) {
                tree[n + i] = a[i];
            }
            build();
        }

        /**
         * build the tree from child elements
         */
        private void build() {
            for (int i = n - 1; i > 0; i--) {
                tree[i] = tree[i << 1] + tree[(i << 1) + 1];
            }
        }

        /**
         * returns sum of numbers in a within range [l, r);
         */
        public int get(int l, int r) {
            int sum = 0;
            for (l = n + l, r = n + r; l < r; l >>= 1, r >>= 1) {
                if (l % 2 == 1) {
                    sum += tree[l++];
                }
                if (r % 2 == 1) {
                    sum += tree[--r];
                }
            }
            return sum;
        }

        /**
         * updates a[i] to be x
         */
        public void update(int i, int x) {
            tree[n + i] = x;
            for (i = (n + i) >> 1; i > 0; i >>= 1) {
                tree[i] = tree[i << 1] + tree[(i << 1) + 1];
            }
        }
    }
}

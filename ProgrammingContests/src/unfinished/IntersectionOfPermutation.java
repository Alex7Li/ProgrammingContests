package unfinished;

import java.io.*;
import java.util.Arrays;
import java.util.HashMap;

//TLE
//https://codeforces.com/problemset/problem/1093/E
public class IntersectionOfPermutation {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("out.txt"));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        String[] params = br.readLine().split(" ");
        int n = Integer.parseInt(params[0]);
        int m = Integer.parseInt(params[1]);
        int[] a = Arrays.stream(br.readLine().split(" "))
                .mapToInt(x -> Integer.parseInt(x) - 1).toArray();
        int[] b = Arrays.stream(br.readLine().split(" "))
                .mapToInt(x -> Integer.parseInt(x) - 1).toArray();
        int[] mapping = new int[n];
        for (int i = 0; i < mapping.length; i++) {
            mapping[a[i]] = i;
        }
        SegmentTree tree = new SegmentTree(n);
        for (int i = 0; i < a.length; i++) {
            tree.update(new Pair(mapping[a[i]], mapping[b[i]]), 1);
            if (i % 1000 == 0) {
                System.out.println(i);
            }
        }
        for (int i = 0; i < m; i++) {
            params = br.readLine().split(" ");
            switch (Integer.parseInt(params[0])) {
                case 1:
                    pw.println(tree.get(Integer.parseInt(params[3]) - 1, Integer.parseInt(params[4]),
                            Integer.parseInt(params[1]) - 1, Integer.parseInt(params[2])));
                    break;
                case 2:
                    int i1 = Integer.parseInt(params[1]) - 1;
                    int i2 = Integer.parseInt(params[2]) - 1;
                    tree.update(new Pair(i1, mapping[b[i1]]), 0);
                    tree.update(new Pair(i2, mapping[b[i2]]), 0);
                    int temp = b[i1];
                    b[i1] = b[i2];
                    b[i2] = temp;
                    tree.update(new Pair(i1, mapping[b[i1]]), 1);
                    tree.update(new Pair(i2, mapping[b[i2]]), 1);
                    break;
            }
        }
        pw.flush();
        br.close();
        pw.close();
    }
}

/**
 * 2D Segment Tree implementation.
 */
class SegmentTree {
    HashMap<Pair, Integer> tree;
    int n;

    /**
     * Constructs a new segment Tree from the given array
     */
    public SegmentTree(int size) {
        n = size;
        tree = new HashMap<>(size*620);
    }

    /**
     * returns sum of numbers in a within range [lx,lr), [rx,ry);
     */
    public int get(int lx, int rx, int ly, int ry) {
        int sum = 0;
        for (lx = n + lx, rx = n + rx; lx < rx; lx >>= 1, rx >>= 1) {
            if (lx % 2 == 1) {
                int ly2 = ly; // copy ly and ry so we can use them on each loop
                int ry2 = ry;
                for (ly2 = n + ly2, ry2 = n + ry2; ly2 < ry2; ly2 >>= 1, ry2 >>= 1) {
                    if (ly2 % 2 == 1) {
                        sum += tree.getOrDefault(new Pair(lx, ly2++), 0);
                    }
                    if (ry2 % 2 == 1) {
                        sum += tree.getOrDefault(new Pair(lx, --ry2), 0);
                    }
                }
                lx++;
            }
            if (rx % 2 == 1) {
                rx--;
                int ly2 = ly; // copy ly and ry so we can use them on each loop
                int ry2 = ry;
                for (ly2 = n + ly2, ry2 = n + ry2; ly2 < ry2; ly2 >>= 1, ry2 >>= 1) {
                    if (ly2 % 2 == 1) {
                        sum += tree.getOrDefault(new Pair(rx, ly2++), 0);
                    }
                    if (ry2 % 2 == 1) {
                        sum += tree.getOrDefault(new Pair(rx, --ry2), 0);
                    }
                }
            }
        }
        return sum;
    }

    /**
     * updates the point at the given Pair to be v
     */
    public void update(Pair p, int v) {
        for (int x = (n + p.x); x > 0; x >>= 1) {
            int y = p.y + n;
            tree.put(new Pair(x, y), v);
            for (; y > 1; y >>= 1) {
                Pair p1 = new Pair(x,y);
                Pair p2 = new Pair(x,y^1);
                int v1 = 0;
                int v2 = 0;
                if(tree.containsKey(p1)) {
                    v1 = tree.get(p1);
                }
                if (tree.containsKey(p2)) {
                    v2 = tree.get(p2);
                }
                tree.put(new Pair(x, y >> 1), v1+v2);
            }
        }
    }
}

/*
 * NewYearAndTheChristmasOrnament pair of 2 integers
 */
class Pair {
    int x;
    int y;

    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public boolean equals(Object obj) {
        // if (obj == null || !(obj instanceof Pair)) {
        //    return false;
        //}
        Pair o = (Pair) (obj);
        return o.x == x && o.y == y;
    }

    @Override
    public int hashCode() {
        return x * 200001 + y;
    }
}
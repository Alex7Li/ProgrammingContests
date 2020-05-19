package medium.original;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.TreeSet;

// https://icpc.kattis.com/problems/azulejos
// A easier ACM ICPC WF problem from 2019.
// Basically involved sorting two arrays in a certain way.
// Solved with some data structures and a greedy approach.
public class Azulejos {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] b_p = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int[] b_h = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int[] f_p = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int[] f_h = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        Tile[] back = new Tile[n];
        Tile[] front = new Tile[n];
        for (int i = 0; i < n; i++) {
            back[i] = new Tile(i, b_h[i], b_p[i]);
            front[i] = new Tile(i, f_h[i], f_p[i]);
        }
        Arrays.sort(back);
        Arrays.sort(front);
        TreeSet<Tile> bVals = new TreeSet<>();
        TreeSet<Tile> fVals = new TreeSet<>();
        int[] frontPerm = new int[n];
        int[] backPerm = new int[n];
        int curInd = 0;
        int frontInd = 0;
        int backInd = 0;
        while (curInd < n) {
            if (frontInd == curInd) {
                fVals.add(front[frontInd++]);
                while (frontInd < n && front[frontInd].price == front[frontInd - 1].price) {
                    fVals.add(front[frontInd++]);
                }
            }
            if (backInd == curInd) {
                bVals.add(back[backInd++]);
                while (backInd < n && back[backInd].price == back[backInd - 1].price) {
                    bVals.add(back[backInd++]);
                }
            }
            if (backInd >= frontInd) {
                while (!fVals.isEmpty()) {
                    Tile fTile = fVals.pollFirst();
                    Tile bTile = bVals.higher(new Tile(n, fTile.height, bVals.first().price));
                    if (bTile == null) {
                        System.out.println("impossible");
                        return;
                    }
                    bVals.remove(bTile);
                    backPerm[curInd] = bTile.index + 1;
                    frontPerm[curInd] = fTile.index +1;
                    curInd++;
                }
            } else {
                while (!bVals.isEmpty()) {
                    Tile bTile = bVals.pollFirst();
                    Tile fTile = fVals.lower(new Tile(-1, bTile.height, fVals.first().price));
                    if (fTile == null) {
                        System.out.println("impossible");
                        return;
                    }
                    fVals.remove(fTile);
                    backPerm[curInd] = bTile.index + 1;
                    frontPerm[curInd] = fTile.index + 1;
                    curInd++;
                }
            }
            assert curInd == Math.min(backInd, frontInd);
        }
        printAns(frontPerm, backPerm);
    }

    private static void printAns(int[] frontPerm, int[] backPerm){
        int n = frontPerm.length;
        PrintWriter pw = new PrintWriter(System.out);
        for (int i = 0; i < n; i++) {
            pw.print(backPerm[i]);
            if (i != n - 1) {
                pw.print(" ");
            }
        }
        pw.println();
        for (int i = 0; i < n; i++) {
            pw.print(frontPerm[i]);
            if (i != n - 1) {
                pw.print(" ");
            }
        }
        pw.println();
        pw.flush();
    }

    public static class Tile implements Comparable<Tile> {
        int index;
        int height;
        int price;

        private Tile(int ind, int h, int p) {
            index = ind;
            height = h;
            price = p;
        }

        @Override
        public int compareTo(Tile o) {
            if(this.price==o.price) {
                if(this.height== o.height){
                    return Integer.compare(this.index, o.index);
                }else{
                    return Integer.compare(this.height, o.height);
                }
            }else{
                return Integer.compare(this.price, o.price);
            }
        }

    }
}

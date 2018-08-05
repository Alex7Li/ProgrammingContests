package atcoder;

import java.util.*;
//https://abc099.contest.atcoder.jp/tasks/abc099_d
public class GoodGrid {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int c = sc.nextInt();
        int[][] wrongness = new int[c][c];
        List<ArrayList<Integer>> colors = new ArrayList<>();
        colors.add(0,new ArrayList<Integer>());
        colors.add(0,new ArrayList<Integer>());
        colors.add(0,new ArrayList<Integer>());
        for (int i = 0; i < wrongness.length; i++) {
            for (int j = 0; j < wrongness.length; j++) {
                wrongness[i][j] = sc.nextInt();
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                colors.get((i + j) % 3).add(sc.nextInt()-1);
            }
        }
        int[][] colorXcost = new int[c][3];
        for (int i = 0; i < c; i++) {
            for (int l = 0; l < colors.get(0).size(); l++) {
                colorXcost[i][0] += wrongness[colors.get(0).get(l)][i];
            }
            for (int l = 0; l < colors.get(1).size(); l++) {
                colorXcost[i][1] += wrongness[colors.get(1).get(l)][i];
            }
            for (int l = 0; l < colors.get(2).size(); l++) {
                colorXcost[i][2] += wrongness[colors.get(2).get(l)][i];
            }
        }
        int bestCost = Integer.MAX_VALUE;
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < c; j++) {
                if (i != j) {
                    for (int k = 0; k < c; k++) {
                        if (k != i && k != j) {
                            int cost = 0;
                            cost += colorXcost[i][0]+colorXcost[j][1]+colorXcost[k][2];
                            bestCost = Math.min(cost, bestCost);
                        }
                    }
                }
            }
        }
        System.out.println(bestCost);
        sc.close();
    }
}

package math.combinatorics;

import java.io.IOException;
import java.util.Scanner;

// https://codingcompetitions.withgoogle.com/codejam/round/0000000000007706/00000000000459f3
public class GracefulChainsawJugglers {
    //cost to buy every juggler in the rectangle(0,0) to (i,j)
    private static Pair[][] costs = new Pair[33][33];
    //remember results from first 10 rows to speed up computeBest
    private static int[][][][] memo = new int[501][501][10][33];
    private static int computeBest(int R, int B, int row, int mCol) {
        if(row<10 && memo[R][B][row][mCol]!=0){
            return memo[R][B][row][mCol];
        }
        int best = 0;
        int min = 0;
        int max = mCol;
        for (int i = 0; i <= mCol; i++) {
            int rX = costs[row][i].x;
            int rY = costs[row][i].y;
            if (row > 0) {
                rX -= costs[row - 1][i].x;
                rY -= costs[row - 1][i].y;
            }
            if (rX > R || rY > B) {
                break;
            } else {
                int temp = computeBest(R - rX, B - rY, row + 1, i) + i + 1;
                if(temp>=best){
                    best = temp;
                } else{
                   break;
                }
            }
        }
        if(row<10) {
            memo[R][B][row][mCol] = best;
        }
        return best;
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int max = 500;
        out:
        for (int i = 0; i < costs.length; i++) {
            for (int j = 0; j < costs[0].length; j++) {
                costs[i][j] = new Pair(i, j);
                if (i != 0 && j != 0) {
                    costs[i][j].subtract(costs[i - 1][j - 1]);
                }
                if (j != 0) {
                    costs[i][j].add(costs[i][j - 1]);
                }
                if (i != 0) {
                    costs[i][j].add(costs[i - 1][j]);
                }
            }
        }
        int T = sc.nextInt();
        for (int tc = 1; tc <= T; tc++) {
            int R = sc.nextInt();
            int B = sc.nextInt();
            System.out.println("Case #" + tc + ": " + (computeBest(R, B, 0, 32) - 1));
        }
        sc.close();
    }

    static class Pair {
        int x;
        int y;

        Pair(int xS, int yS) {
            x = xS;
            y = yS;
        }

        void add(Pair o) {
            this.x += o.x;
            this.y += o.y;
        }

        void subtract(Pair o) {
            this.x -= o.x;
            this.y -= o.y;
        }
        @Override
        public String toString() {
            return "(" + x + " " + y + ")";
        }
    }
}

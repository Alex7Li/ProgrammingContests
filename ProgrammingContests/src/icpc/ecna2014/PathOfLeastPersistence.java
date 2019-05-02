package icpc.ecna2014;

import java.util.Scanner;

// https://codeforces.com/gym/100641
// bad implementation, right answer
public class PathOfLeastPersistence {

    private static final int INF = 12321;
    private static int rows;
    private static int cols;

    /*
     * The input grid
     */
    private static Clue[][] grid;

    /*
     * path length starting here and taking the normal path
     * INF : it's not possible
     * -1 : it hasn't been checked yet
     * -2 : it is in the process of being checked
     */
    private static int[][] pathLen;
    /*
     * path length starting here and taking any path from this square
     * INF : it's not possible
     * -1 : it hasn't been checked yet
     * -2 : it is in the process of being checked
     */
    private static int[][] minPathLen;

    /**
     * The minPathLen array has the length of a min-path
     * from a point, this array has the key that you need
     * for that path
     * Is null if the min-path is just to use the normal key.
     */
    private static Clue[][] minPathKey;

    private static int caseNum = 1;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        rows = sc.nextInt();
        cols = sc.nextInt();
        while (rows + cols > 0) {
            grid = new Clue[rows][cols];
            pathLen = new int[rows][cols];
            minPathLen = new int[rows][cols];
            minPathKey = new Clue[rows][cols];
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (i + j != rows + cols - 2) {
                        String clueStr = sc.next();
                        grid[i][j] = new Clue(Integer.valueOf(clueStr.substring(0, clueStr.length() - 1)), clueStr.charAt(clueStr.length() - 1));
                        pathLen[i][j] = -1;
                        minPathLen[i][j] = -1;
                    }
                }
            }
            grid[rows - 1][cols - 1] = new Clue(0, 'N');
            for (int i = rows - 1; i >= 0; i--) {
                for (int j = cols - 1; j >= 0; j--) {
                    findPathLengths(i, j);
                }
            }
            for (int i = rows - 1; i >= 0; i--) {
                for (int j = cols - 1; j >= 0; j--) {
                    findMinPathLengths(i, j);
                }
            }
            System.out.print("Case " + caseNum++ + ": ");
            if (minPathLen[0][0] >= INF) {
                System.out.println("impossible");
            } else if (minPathLen[0][0] == pathLen[0][0]) {
                System.out.println("none " + pathLen[0][0]);
            } else {
                int nxtRow = 0;
                int nxtCol = 0;
                int curPathLen = 0;
                int bestRow = INF;
                int bestCol = INF;
                String bestClue = "";
                // while we can still improve path length to the min
                while (minPathLen[nxtRow][nxtCol] + curPathLen == minPathLen[0][0]) {
                    int[] nextRowCol2 = nextRowCol(nxtRow, nxtCol, grid[nxtRow][nxtCol]);
                    curPathLen++;
                    if (minPathKey[nxtRow][nxtCol] != null) {
                        int[] nextRowCol = nextRowCol(nxtRow, nxtCol, minPathKey[nxtRow][nxtCol]);
                        // if switching this square works, then record this as a good switch
                        if (pathLen[nextRowCol[0]][nextRowCol[1]] + curPathLen == minPathLen[0][0]) {
                            if (nxtRow < bestRow || (nxtRow == bestRow && nxtCol < bestCol)) {
                                bestRow = nxtRow;
                                bestCol = nxtCol;
                                bestClue = minPathKey[nxtRow][nxtCol].dist + "" + minPathKey[nxtRow][nxtCol].dir;
                            }
                        }
                    }
                    if (nextRowCol2 == null) {
                        break;
                    }
                    nxtRow = nextRowCol2[0];
                    nxtCol = nextRowCol2[1];
                }
                System.out.println(bestRow + " " + bestCol + " " + bestClue + " " + minPathLen[0][0]);
            }
            rows = sc.nextInt();
            cols = sc.nextInt();
        }
    }

    private static void findMinPathLengths(int row, int col) {
        if (minPathLen[row][col] != -1) {
            if (minPathLen[row][col] == -2) {
                minPathLen[row][col] = INF;
            }
            return;
        }
        int[] nextRowCol = nextRowCol(row, col, grid[row][col]);
        if (nextRowCol != null) {
            minPathLen[row][col] = -2;
            findMinPathLengths(nextRowCol[0], nextRowCol[1]);
            minPathLen[row][col] = 1 + minPathLen[nextRowCol[0]][nextRowCol[1]];
            minPathKey[row][col] = null;
        } else {
            minPathLen[row][col] = INF;
        }
        // set minPathLen & minPathKey for this square
        for (int i = 1; i < cols - col; i++) {
            int newPathLen = 1 + pathLen[row][col + i];
            if (newPathLen < minPathLen[row][col] ||
                    (newPathLen == minPathLen[row][col] && (new Clue(i, 'E')).compareTo(minPathKey[row][col]) < 0)) {
                minPathLen[row][col] = newPathLen;
                minPathKey[row][col] = new Clue(i, 'E');
            }
        }

        for (int i = 1; i < rows - row; i++) {
            int newPathLen = 1 + pathLen[row + i][col];
            if (newPathLen < minPathLen[row][col] ||
                    (newPathLen == minPathLen[row][col] && (new Clue(i, 'S')).compareTo(minPathKey[row][col]) < 0)) {
                minPathLen[row][col] = newPathLen;
                minPathKey[row][col] = new Clue(i, 'S');
            }
        }

        for (int i = 1; i <= col; i++) {
            int newPathLen = 1 + pathLen[row][col - i];
            if (newPathLen < minPathLen[row][col] ||
                    (newPathLen == minPathLen[row][col] && (new Clue(i, 'W')).compareTo(minPathKey[row][col]) < 0)) {
                minPathLen[row][col] = newPathLen;
                minPathKey[row][col] = new Clue(i, 'W');
            }
        }

        for (int i = 1; i <= row; i++) {
            int newPathLen = 1 + pathLen[row - i][col];
            if (newPathLen < minPathLen[row][col] ||
                    (newPathLen == minPathLen[row][col] && (new Clue(i, 'N')).compareTo(minPathKey[row][col]) < 0)) {
                minPathLen[row][col] = newPathLen;
                minPathKey[row][col] = new Clue(i, 'N');
            }
        }
    }

    private static void findPathLengths(int row, int col) {
        if (pathLen[row][col] != -1) {
            if (pathLen[row][col] == -2) {
                pathLen[row][col] = INF;
            }
            return;
        }
        int[] nextRowCol = nextRowCol(row, col, grid[row][col]);
        if (nextRowCol == null) {
            pathLen[row][col] = INF;
        } else {
            pathLen[row][col] = -2;
            findPathLengths(nextRowCol[0], nextRowCol[1]);
            pathLen[row][col] = 1 + pathLen[nextRowCol[0]][nextRowCol[1]];
        }
    }

    private static int[] nextRowCol(int row, int col, Clue clue) {
        int nxtRow = row;
        int nxtCol = col;
        switch (clue.dir) {
            case 'E':
                nxtCol += clue.dist;
                break;
            case 'W':
                nxtCol -= clue.dist;
                break;
            case 'S':
                nxtRow += clue.dist;
                break;
            case 'N':
                nxtRow -= clue.dist;
                break;
        }
        if (nxtCol < 0 || nxtRow < 0 || nxtCol >= cols || nxtRow >= rows) {
            return null;
        } else {
            return new int[]{nxtRow, nxtCol};
        }
    }

    private static class Clue implements Comparable<Clue> {
        int dist;
        char dir;

        public Clue(int distance, char direction) {
            dist = distance;
            dir = direction;
        }

        @Override
        public int compareTo(Clue o) {
            if (o == null) {
                return -1;
            }
            return (this.dist * 26 + dir) - (o.dist * 26 + o.dir);
        }

        @Override
        public boolean equals(Object obj) {
            return ((Clue) obj).dir == this.dir && ((Clue) obj).dist == this.dist;
        }
    }
}

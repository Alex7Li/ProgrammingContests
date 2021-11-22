package misc.gametheory.grundy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

//https://codingcompetitions.withgoogle.com/codejam/round/00000000000516b9/0000000000134cdf
// a good problem about grundy numbers
public class BacterialTactics {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(br.readLine());
        for (int t = 1; t <= cases; t++) {
            String[] argsy = br.readLine().split(" ");
            int r = Integer.parseInt(argsy[0]);
            int c = Integer.parseInt(argsy[1]);
            boolean[][] board = new boolean[r][c];
            for (int i = 0; i < r; i++) {
                char[] nl = br.readLine().toCharArray();
                for (int j = 0; j < c; j++) {
                    board[i][j] = (nl[j] == '#');
                }
            }
            // grund[i][j][k][l]: grundy number of the square with top left corner at i,j
            // at bottom left corner at k,l
            int[][][][] grundy = new int[r + 1][c + 1][r + 1][c + 1];
            int winWays = 0;
            for (int xSize = 1; xSize <= r; xSize++) {
                for (int ySize = 1; ySize <= c; ySize++) {
                    for (int xOffset = 0; xOffset <= r - xSize; xOffset++) {
                        for (int yOffset = 0; yOffset <= c - ySize; yOffset++) {
                            int xMax = xOffset + xSize;
                            int yMax = yOffset + ySize;
                            // place on the rows
                            List<Integer> grundys = new ArrayList<>();
                            List<Integer> weights = new ArrayList<>();
                            for (int i = xOffset; i < xMax; i++) {
                                boolean possible = true;
                                for (int j = yOffset; j < yMax; j++) {
                                    if (board[i][j]) {
                                        possible = false;
                                        break;
                                    }
                                }
                                if (possible) {
                                    grundys.add(grundy[xOffset][yOffset][i][yMax] ^ grundy[i + 1][yOffset][xMax][yMax]);
                                    weights.add(c);
                                }
                            }
                            // place on the cols
                            for (int i = yOffset; i < yMax; i++) {
                                boolean possible = true;
                                for (int j = xOffset; j < xMax; j++) {
                                    if (board[j][i]) {
                                        possible = false;
                                        break;
                                    }
                                }
                                if (possible) {
                                    grundys.add(grundy[xOffset][yOffset][xMax][i] ^  grundy[xOffset][i + 1][xMax][yMax]);
                                    weights.add(r);
                                }
                            }
                            int grundyNum = mex(new HashSet<Integer>(grundys));
                            if (xSize == r && ySize == c) {
                                for (int i = 0; i < grundys.size(); i++) {
                                    if (grundys.get(i) ==  0) {
                                        winWays += weights.get(i);
                                    }
                                }
                            }
                            grundy[xOffset][yOffset][xMax][yMax] = grundyNum;

                        }
                    }
                }
            }
            System.out.println("Case #" + t + ": " + winWays);
        }
    }

    // A Function to calculate Mex of all the values in
    // that set.
    static int mex(HashSet<Integer> Set) {
        int Mex = 0;
        while (Set.contains(Mex)) {
            Mex++;
        }
        return (Mex);
    }
}

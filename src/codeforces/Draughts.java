package codeforces;

import java.util.*;

//https://codeforces.com/gym/100299
public class Draughts {
    private static char[][] board;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        for (int t = 0; t < n; t++) {
            sc.nextLine();
            board = new char[10][10];
            Queue<Square> whiteSpaces = new LinkedList<>();
            for (int i = 0; i < 10; i++) {
                board[i] = sc.nextLine().toCharArray();
                for (int j = 0; j < 10; j++) {
                    if (board[i][j] == 'W') {
                        whiteSpaces.offer(new Square(i, j));
                    }
                }
            }
            int maxJumps = 0;
            while (!whiteSpaces.isEmpty()) {
                Square sq = whiteSpaces.poll();
                board[sq.x][sq.y] = '#';
                maxJumps = Math.max(dfs(sq, new HashSet<Square>()), maxJumps);
                board[sq.x][sq.y] = 'W';
            }
            System.out.println(maxJumps);
        }
        sc.close();
    }

    public static int dfs(Square st, Set<Square> jumped) {
        int bestNJumps = 0;
        int[] posX = {st.x - 2, st.x - 2, st.x + 2, st.x + 2};
        int[] xjmp = {st.x - 1, st.x - 1, st.x + 1, st.x + 1};
        int[] posY = {st.y - 2, st.y + 2, st.y - 2, st.y + 2};
        int[] yjmp = {st.y - 1, st.y + 1, st.y - 1, st.y + 1};
        for (int i = 0; i < 4; i++) {
            if (posX[i] >= 0 && posX[i] < 10 && posY[i] >= 0 && posY[i] < 10) {
                if (board[posX[i]][posY[i]] == '#' && board[xjmp[i]][yjmp[i]] == 'B' &&
                        !jumped.contains(new Square(xjmp[i], yjmp[i]))) {
                    jumped.add(new Square(xjmp[i], yjmp[i]));
                    bestNJumps = Math.max(bestNJumps, 1 + dfs(new Square(posX[i], posY[i]), jumped));
                    jumped.remove(new Square(xjmp[i], yjmp[i]));
                }
            }
        }
        return bestNJumps;
    }

    public static class Square {
        int x;
        int y;

        public Square(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int hashCode() {
            return this.x * 10 + this.y;
        }

        @Override
        public boolean equals(Object obj) {
            return this.hashCode() == obj.hashCode();
        }
    }
}

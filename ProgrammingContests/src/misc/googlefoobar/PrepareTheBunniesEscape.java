package misc.googlefoobar;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class PrepareTheBunniesEscape {
    public static void main(String[] args) {
        int[][] maze =  {{0, 1},{1,0},{0,0},{0,0}};
        System.out.println(answer(maze));
    }
    public static int answer(int[][] maze) {
        int[][] mazeCopy = new int[maze.length+2][maze[0].length + 2];
        for (int i = 0; i < mazeCopy.length; i++) {
            for (int j = 0; j < mazeCopy[0].length; j++) {
                mazeCopy[i][j] = 1;
            }
        }
        for (int i = 0; i < maze.length; i++) {
            for (int j = 0; j < maze[0].length; j++) {
                mazeCopy[i + 1][j + 1] = maze[i][j];
            }
        }
        System.out.println(Arrays.deepToString(mazeCopy));
        int[][] distanceFromPrison = distanceFrom(mazeCopy, 1, 1);
        int[][] distanceFromEscape = distanceFrom(mazeCopy, maze.length, maze[0].length);
        int dist = Integer.MAX_VALUE;
        for (int i = 1; i < mazeCopy.length - 1; i++) {
            for (int j = 1; j < mazeCopy[0].length - 1; j++) {
                dist = Math.min(dist, distanceFromEscape[i][j]+distanceFromPrison[i][j]+1);
            }
        }
        return dist;
    }

    public static int[][] distanceFrom(int[][] maze, int startX, int startY) {
        boolean[][] seen = new boolean[maze.length][maze[0].length];
        int[][] dist = new int[maze.length][maze[0].length];
        for (int i = 0; i < dist.length; i++) {
            for (int j = 0; j < dist[0].length; j++) {
                dist[i][j] = 10000;
            }
        }
        dist[startX][startY]=0;
        Queue<Position> Q = new LinkedList<>();
        Q.add(new Position(startX, startY));
        while (!Q.isEmpty()) {
            Position next = Q.remove();
            if (maze[next.row][next.col] == 1) {
                continue;
            }
            int d = dist[next.row][next.col] + 1;
            if (!seen[next.row][next.col - 1]) {
                Position left = new Position(next.row, next.col - 1);
                dist[next.row][next.col - 1] = d;
                seen[next.row][next.col - 1] = true;
                Q.add(left);
            }
            if (!seen[next.row][next.col + 1]) {
                Position right = new Position(next.row, next.col + 1);
                dist[next.row][next.col + 1] = d;
                seen[next.row][next.col + 1] = true;
                Q.add(right);
            }
            if (!seen[next.row - 1][next.col]) {
                Position top = new Position(next.row - 1, next.col);
                dist[next.row - 1][next.col] = d;
                seen[next.row - 1][next.col] = true;
                Q.add(top);
            }
            if (!seen[next.row + 1][next.col]) {
                Position bottom = new Position(next.row + 1, next.col);
                dist[next.row + 1][next.col] = d;
                seen[next.row + 1][next.col] = true;
                Q.add(bottom);
            }
        }
        return dist;
    }

    public static class Position {
        int row;
        int col;

        public Position(int r, int c) {
            row = r;
            col = c;
        }
    }
}

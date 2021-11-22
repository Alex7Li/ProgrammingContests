package unfinished;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

//https://codeforces.com/gym/101617
//too slow due to my bad algorithm
public class JumpingHaybales {
    public static void main(String[] args) throws IOException {
        boolean[][] grid;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] ints = br.readLine().split(" ");
        int n = Integer.parseInt(ints[0]);
        int k = Integer.parseInt(ints[1]);
        grid = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            char[] alexIsDumb = br.readLine().toCharArray();
            for (int j = 0; j < n; j++) {
                grid[i][j] = (alexIsDumb[j] == '.');
            }
        }
        Pear[][] pears = new Pear[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pears[i][j] = new Pear(i, j);
            }
        }

        // search for the route with the least total hops
        int minHops = -1;
        Queue<Pear> Q = new LinkedList<>();

        pears[0][0].dist = 0;
        Q.add(pears[0][0]);

        while (!Q.isEmpty()) {
            Pear p = Q.poll();
            p.seen = true;
            if (p.x == n - 1 && p.y == n - 1) {
                minHops = p.dist;
                break;
            }
            //jump south
            for (int d = Math.min(k,n-p.x-1); d > 0; d--) {
                if(pears[p.x + d][p.y].seen){
                    break;
                }
                if (grid[p.x + d][p.y]) {
                    pears[p.x + d][p.y].dist = p.dist + 1;
                    Q.add(pears[p.x + d][p.y]);
                }
            }
            //jump east
            for (int d = Math.min(k,n-p.y-1); d > 0; d--) {
                if(pears[p.x][p.y + d].seen){
                    //We've already checked everything before this
                    break;
                }
                if (grid[p.x][p.y + d]) {
                    pears[p.x][p.y + d].dist = p.dist + 1;
                    Q.add(pears[p.x][p.y + d]);
                }
            }
        }
        System.out.println(minHops);
    }

    private static class Pear{
        int x;
        int y;
        boolean seen = false;
        int dist = Integer.MAX_VALUE / 2;

        public Pear(int first, int second) {
            x = first;
            y = second;
        }
    }
}

package medium.standard;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
//https://naq19.kattis.com/problems/runningroutes
public class Running {
    static int[][] memo;
    static int n;
    static boolean[][] edges;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        edges = new boolean[n][n];
        memo = new int[n][n];
        for (int i = 0; i < n; i++) {
            for(int j=0; j<n; j++){
                memo[i][j] = -1;
            }
        }

        for (int i = 0; i < n; i++) {
            String[] line = br.readLine().split(" ");
            for (int j = 0; j < n; j++) {
                edges[i][j] = Integer.parseInt(line[j]) == 1;
            }
        }

        System.out.println(best(0, n-1));
    }

    private static int best(int x, int y){
        if(x>y) {
            System.out.println("WOW");
        }
        int delta = y-x;
        int result;
        if(memo[x][y] != -1) {
            return memo[x][y];
        } else if (delta == 0){
            return 0;
        } else if (delta == 1){
            return edges[x][y] ? 1:0;
        } else if (delta == 2){
            result = (edges[x][y] || edges[x+1][y] || edges[x][y-1]) ? 1 : 0;
        } else {
            result = best(x+1, y-1) + (edges[x][y] ? 1: 0);
            for (int z = x; z < y; z++){
                result = Math.max(result, best(x,z) + best(z+1, y));
            }
        }
//        System.out.println(x + " " + y + " " + result);
        memo[x][y] = result;
        return result;
    }


}

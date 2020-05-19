package medium.interesting;

import java.util.Scanner;
//https://naq19.kattis.com/problems/slowlea
public class SlowLeak {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int t = sc.nextInt();
        int d = sc.nextInt();

        long[][] dist = new long[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = 1L<<31;
            }
        }
        int[] locs = new int[t+2];
        locs[0] = 0;
        for (int i = 1; i <= t; i++) {
            locs[i] = sc.nextInt()-1;
        }
        locs[t+ 1] = n-1;
        for (int i = 0; i < m; i++) {
            int s = sc.nextInt()-1;
            int e = sc.nextInt()-1;
            int dis = sc.nextInt();
            dist[s][e] = dis;
            dist[e][s] = dis;
        }
        long[][] a = solve(n, dist);
        long[][] ok = new long[t+2][t+2];
        for (int i = 0; i < locs.length; i++) {
            for (int j = 0; j < locs.length; j++) {
                long distance = a[locs[i]][locs[j]];
                if(distance<=d) {
                    ok[i][j] = distance;
                }else{
                    ok[i][j] = 1L << 31;
                }
            }
        }
        long[][] b = solve(t+2, ok);
        if(b[0][t+1]==1L<<31){
            System.out.println("stuck");
        }else {
            System.out.println(b[0][t + 1]);
        }
    }
    private static long[][] solve(int n, long[][] a){
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    a[i][j] = Math.min(a[i][j], a[i][k] + a[k][j]);
                }
            }
        }
        return a;
    }
}

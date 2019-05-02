package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

//https://codeforces.com/problemset/problem/1046/I
public class SayHello {
    public boolean minDistOnPathAboveD(int x1, int y1, int x2, int y2, long d) {
        //determine if perpendicular is min
        boolean perp = false;
        int x3 = x2 - x1;
        int y3 = y2 - y1;
        long dotAB1L= x1 * x3 + (y1 *y3);
        long dotAB2L = x2 * x3 + (y2 * y3);
        if (dotAB1L * dotAB2L < 0){
            perp = true;
        }

        long minDist = 0;
        if(!perp){
            minDist = Math.min(x1*x1 + y1 * y1, x2*x2 + y2*y2);
            return minDist > d*d;
        } else{
            minDist =Math.abs(x1*y3 - y1*x3);
            minDist *= minDist;
            return (d*d * (x3*x3 +y3*y3)) < minDist;
        }
    }


    public void solve() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] ds = Arrays.stream(br.readLine().split(" "))
                .mapToInt(x -> Integer.parseInt(x)).toArray();
        int d1 = ds[0];
        int d2 = ds[1];
        int[][] path = new int[n][2];
        for (int i = 0; i < n; i++) {
            int[] coords = Arrays.stream(br.readLine().split(" "))
                    .mapToInt(x -> Integer.parseInt(x)).toArray();
            path[i][0] = coords[0] - coords[2];
            path[i][1] = coords[1] - coords[3];
        }
        boolean canSayHi = true;
        int hiCount = 0;
        for (int i = 0; i < n - 1; i++) {
            int dist_at_st = path[i][0] * path[i][0] + path[i][1] * path[i][1];
            if (dist_at_st > d2 * d2) {
                canSayHi = true;
            }
            if (canSayHi && !minDistOnPathAboveD(path[i][0], path[i][1],
                    path[i + 1][0], path[i + 1][1], d1)) {
                hiCount++;
                canSayHi = false;
            }
        }
        System.out.println(hiCount);
        br.close();
    }

    public static void main(String[] args) throws IOException {
        SayHello solution = new SayHello();
        solution.solve();
    }
}

package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

// http://codeforces.com/contest/1152/problem/A
public class NekoFindsGrapes {
    public static void main(String[] args) throws IOException {
        NekoFindsGrapes solution = new NekoFindsGrapes();
        solution.solve();
    }

    public void solve() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        br.readLine();
        int[] a = Arrays.stream(br.readLine().split(" "))
                .mapToInt(x -> Integer.parseInt(x)).toArray();
        int[] b = Arrays.stream(br.readLine().split(" "))
                .mapToInt(x -> Integer.parseInt(x)).toArray();
        int aEven = 0;
        int aOdd = 0;
        int bEven = 0;
        int bOdd = 0;
        for (int i : a) {
            if (i % 2 == 0) {
                aEven++;
            } else {
                aOdd++;
            }
        }
        for (int i : b) {
            if (i % 2 == 0) {
                bEven++;
            } else {
                bOdd++;
            }
        }
        System.out.println(Math.min(aEven, bOdd) + Math.min(aOdd, bEven));
        br.close();
    }
}

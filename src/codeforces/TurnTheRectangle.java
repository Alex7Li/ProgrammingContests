package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
//http://codeforces.com/problemset/problem/1008/B
public class TurnTheRectangle {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int maxH = 1000000000;
        for (int i = 0; i < n; i++) {
            int[] s = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            int w = Math.min(s[0], s[1]);
            int h = Math.max(s[0], s[1]);
            if (w > maxH) {
                System.out.println("nO");
                return;
            } else if (h > maxH) {
                maxH = w;
            } else {
                maxH = h;
            }
        }
        System.out.println("YeS");
    }
}

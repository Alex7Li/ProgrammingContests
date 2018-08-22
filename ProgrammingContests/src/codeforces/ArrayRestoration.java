package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Queue;
//http://codeforces.com/contest/1023/problem/D
public class ArrayRestoration {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] params = Arrays.stream(br.readLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
        int[] a = Arrays.stream(br.readLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
        int q = params[1];
        int[] segEnds = new int[q + 1];
        segEnds[q] = -1;
        segEnds[0] = -1;
        for (int i = 0; i < a.length; i++) {
            segEnds[a[i]] = i;
        }
        if (segEnds[q] == -1 && segEnds[0] == -1) {
            System.out.println("NO");
            return;
        }
        StringBuilder res = new StringBuilder();
        Queue<Integer> curSegs = new PriorityQueue<>((x, y) -> y - x);
        for (int i = 0; i < a.length; i++) {
            if (a[i] == 0) {
                if (segEnds[q] == -1 && segEnds[0] == i) {
                    res.append("" + q);
                } else if (!curSegs.isEmpty()) {
                    res.append(curSegs.peek());
                } else {
                    res.append("1");
                }
            } else {
                int x = 0;
                if (!curSegs.isEmpty()) {
                    x = curSegs.peek();
                }
                if (a[i] >= x) {
                    res.append(a[i]);
                } else {
                    System.out.println("NO");
                return;
                }
                if (a[i] != x && segEnds[a[i]] != i) {
                    curSegs.add(a[i]);
                } else if (a[i] == x && segEnds[a[i]] == i) {
                    curSegs.remove(a[i]);
                }
            }
            if (i != a.length - 1) {
                res.append(" ");
            }
        }
        System.out.println("YES");
        System.out.println(res);
    }
}

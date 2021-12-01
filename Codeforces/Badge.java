package codeforces;

import java.util.Arrays;
import java.util.Scanner;

//http://codeforces.com/contest/1020/problem/B
public class Badge {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        int[] a = Arrays.stream(sc.nextLine().split(" ")).mapToInt(x -> Integer.parseInt(x) - 1).toArray();
        for (int i = 0; i < n; i++) {
            boolean[] seen = new boolean[n];
            int cur = i;
            while (!seen[cur]) {
                seen[cur] = true;
                cur = a[cur];
            }
            if (n == i + 1) {
                System.out.println(cur + 1);
            } else {
                System.out.print((cur + 1) + " ");
            }
        }
    }
}

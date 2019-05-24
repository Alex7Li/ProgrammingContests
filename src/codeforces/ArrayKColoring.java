package codeforces;

import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

//https://codeforces.com/problemset/problem/1102/B
public class ArrayKColoring {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        sc.nextLine();
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        int[] a = Arrays.stream(sc.nextLine().split(" "))
                .mapToInt(x -> Integer.parseInt(x)).toArray();
        int[] colors = new int[a.length];
        boolean pos = true;
        int color = 0;
        for (int i = 1; i <= 5000; i++) {
            int st = color % k;
            boolean first = true;
            for (int j = 0; j < n; j++) {
                if (a[j] == i) {
                    if (!first && color % k == st % k) {
                        pos = false;
                    }
                    first = false;
                    colors[j] = color % k;
                    color++;
                }
            }
        }
        if (pos) {
            System.out.println("YES");
            for (int i = 0; i < a.length - 1; i++) {
                System.out.print((colors[i] + 1) + " ");
            }
            System.out.println(colors[a.length - 1] + 1);
        } else {
            System.out.println("NO");
        }
    }
}

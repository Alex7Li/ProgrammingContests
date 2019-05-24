package codeforces;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Scanner;

// https://codeforces.com/problemset/problem/873/D
public class MergeSortD {
    static int[] a;
    static int k;

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        k = sc.nextInt() - 1;
        if (k % 2 == 1) {
            System.out.println(-1);
            return;
        }
        a = new int[n];
        for (int i = 1; i <= n; i++) {
            a[i - 1] = i;
        }
        mergeUnsort(0, n);
        if (k > 0) {
            System.out.println(-1);
        } else {
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
            for (int i = 0; i < n; i++) {
                bw.write(a[i] + " ");
            }
            bw.newLine();
            bw.flush();
        }
    }

    public static void mergeUnsort(int s, int e) {
        if (e - s <= 1 || k == 0) {
            return;
        }
        int mid = (e + s) / 2;
        k -= 2;
        int temp = a[mid-1];
        a[mid-1] = a[mid];
        a[mid] = temp;
        mergeUnsort(s, mid);
        mergeUnsort(mid, e);
    }
}

package codeforces;

import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
//https://codeforces.com/contest/1093/problem/C
public class MishkaAndTheLastExam {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        long[] b = Arrays.stream(sc.nextLine().split(" "))
                .mapToLong(Long::parseLong).toArray();
        long[] a = new long[n];
        a[n - 1] = b[0];
        a[0] = 0;
        long low = 0;
        for (int i = 1; i < b.length; i++) {
            int aHighIndex = n - i - 1;
            int aLowIndex = i;
            b[i] -= low;
            long diff = 0;
            if (b[i - 1] < b[i]) {
                diff = b[i] - b[i - 1];
                b[i] = b[i - 1];
            }
            a[aLowIndex] = low + diff;
            a[aHighIndex] = b[i];
            low = low + diff;
        }
        PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
        for (int i = 0; i < n - 1; i++) {
            pw.write(a[i] + " ");
        }
        pw.println(a[n - 1]);
        pw.flush();
        sc.close();
    }
}

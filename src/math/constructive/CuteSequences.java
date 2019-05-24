package math.constructive;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

// https://codeforces.com/contest/1166/problem/D
public class CuteSequences {
public static void main(String[] xx) throws IOException {
    Scanner sc = new Scanner(System.in);
    PrintWriter pw = new PrintWriter(System.out);
    int q = sc.nextInt();
    long[] twoPow = new long[51];
    twoPow[0] = 1;
    for (int i = 1; i < twoPow.length; i++) {
        twoPow[i] = twoPow[i - 1] * 2;
    }
    for (int i = 0; i < q; i++) {
        long a = sc.nextLong();
        long b = sc.nextLong();
        long m = sc.nextLong();
        boolean found = false;
        for (int k = 2; !found && k <= 4 + Long.numberOfLeadingZeros(a)- Long.numberOfLeadingZeros(b); k++) {
            if (b < twoPow[k - 2] * (a + 1) || b > twoPow[k - 2] * (a + m)) {
                continue;
            }
            found = true;
            long[] rem = new long[k - 1];
            b -= twoPow[k - 2] * a;
            for (int j = 0; j < k - 1; j++) {
                b -= twoPow[Math.max(0, j - 1)];
                rem[j]++;
            }
            for (int j = 0; j < k - 1; j++) {
                rem[j] += b / twoPow[Math.max(0, k - j - 3)];
                b -= twoPow[Math.max(k - j - 3, 0)] * (rem[j] - 1);
            }
            pw.print(k + " ");
            pw.print(a);
            long S = a;
            for (int j = 0; j < k - 1; j++) {
                pw.print(" " + (S + rem[j]));
                S = S + S + rem[j];
            }
            pw.println();
        }
        if (a == b) {
            pw.println(1 + " " + a);
        } else if (!found) {
            pw.println(-1);
        }
    }
    pw.flush();
    pw.close();
}
}

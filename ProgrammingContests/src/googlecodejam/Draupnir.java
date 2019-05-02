package googlecodejam;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeSet;

// https://codingcompetitions.withgoogle.com/codejam/round/0000000000051706/0000000000122837
class Draupnir {
    private static final long a = 54;
    private static final long b = 215;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int cases = sc.nextInt();
        int w = sc.nextInt();

        for (int i = 1; i <= cases; i++) {
            pw.println(b);
            pw.flush();
            pw.println(a);
            pw.flush();
            long rings = sc.nextLong();
            long rings2 = sc.nextLong();
            long[] ans = solve(rings, rings2);
            pw.println(ans[0] + " " + ans[1] + " " + ans[2] + " " + ans[3] + " " + ans[4] + " " + ans[5]);
            pw.flush();
            int correct = sc.nextInt();
            if (correct == -1) {
                return;
            }
        }
    }

    private static long[] solve(long rings, long rings2) {
        long r4 = rings / (1L << (b / 4));
        rings %= 1L << (b / 4);
        long r5 = rings / (1L << (b / 5));
        rings %= 1L << (b / 5);
        long r6 = rings / (1L << (b / 6));

        rings2 -= r4 * (1L<<a/4);
        rings2 -= r5 * (1L<<a/5);
        rings2 -= r6 * (1L<<a/6);
        long r1 = rings2 / (1L << a);
        rings2 %= 1L << a;
        long r2 = rings2 / (1L << (a / 2));
        rings2 %= 1L << (a / 2);
        long r3 = rings2 / (1L << (a / 3));
        return new long[]{r1, r2, r3, r4, r5, r6};
    }

    private static void test() {
        int n = 10000;
        TreeSet<Long> r3s = new TreeSet<>();
        long[] pow2 = new long[300];
        pow2[0] = 1;
        for (int i = 1; i < 300; i++) {
            pow2[i] = pow2[i - 1] * 2;
        }
        System.out.println(n + " " + 2);
        for (int i = 0; i < n; i++) {
            long[] r = new long[6];
            for (int j = 0; j < 6; j++) {
                r[j] = (long) (Math.random() * 101);
            }
            long ring1 = 0;
            long ring2 = 0;
            for (int j = 1; j <= r.length; j++) {
                ring1 += (r[j - 1] * pow2[215 / j]);
                ring2 += (r[j - 1] * pow2[54 / j]);
            }
            //System.out.println(Arrays.toString(solve(ring1,ring2)));
            //System.out.println(Arrays.toString(r));
            if (!Arrays.equals(solve(ring1, ring2), r)) {
                r3s.add(r[3]);
                //System.out.println(r[2] + " " + r[3]);
            }
        }
        System.out.println(r3s.size());
        for (long j : r3s) {
            System.out.print(j + " ");
        }
    }
}


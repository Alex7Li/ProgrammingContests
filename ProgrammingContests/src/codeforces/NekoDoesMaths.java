package codeforces;

import java.io.IOException;
import java.util.Scanner;
import java.util.TreeSet;

// http://codeforces.com/contest/1152/problem/C
public class NekoDoesMaths {
    public void solve() throws IOException {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int diff = Math.abs(a - b);
        TreeSet<Integer> factors = new TreeSet<>();
        for (int i = 1; i * i <= diff; i++) {
            if (diff % i == 0) {
                factors.add(i);
                factors.add(diff / i);
            }
        }
        int best = 0;
        long bestLCM = lcm(a, b);
        for (int i : factors) {
            long lcm = lcm(a + i - (a % i), b + i - (a % i));
            if (lcm < bestLCM) {
                bestLCM = lcm;
                best = i - (a % i);
            }
        }
        System.out.println(best);
    }

    public static void main(String[] args) throws IOException {
        NekoDoesMaths solution = new NekoDoesMaths();
        solution.solve();
    }

    /**
     * Return gcd(a,b)
     * O(log(a+b))
     */
    private static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    /**
     * Return lcm(a,b)
     * O(log(a+b))
     */
    private static long lcm(int a, int b) {
        return (long) (a) * b / gcd(b, a % b);
    }
}

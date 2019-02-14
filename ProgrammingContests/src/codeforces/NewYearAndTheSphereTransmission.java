package codeforces;

import java.io.*;
import java.util.*;

//https://codeforces.com/contest/1091/problem/C
public class NewYearAndTheSphereTransmission {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        sc.close();
        List<Long> divisors = new ArrayList<>();
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                divisors.add((long) i);
            }
        }
        int size = divisors.size();
        if (divisors.size() > 0) {
            if (divisors.get(divisors.size() - 1) *
                    divisors.get(divisors.size() - 1) != n) {
                divisors.add(n / divisors.get(divisors.size() - 1));
            }
        }
        for (int i = size - 2; i >= 0; i--) {
            divisors.add(n / divisors.get(i));
        }
        Collections.reverse(divisors);
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        pw.print(1);
        for (long d : divisors) {
            long ans = 2*(n / d) + (n / d - 1) * n;
            pw.print(" " + ans/2);
        }
        pw.println(" " + (n + (n * (n - 1)) / 2));
        pw.flush();

    }
}

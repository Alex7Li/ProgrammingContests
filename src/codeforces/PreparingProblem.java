package codeforces;

import java.util.Scanner;
//http://codeforces.com/problemsets/acmsguru/problem/99999/551
//a pretty gross solution
public class PreparingProblem {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int rate1 = sc.nextInt();
        int rate2 = sc.nextInt();
        int gcd = gcd(rate1, rate2);
        // num/denom = seconds per solution
        int numerator = (rate1 * rate2) / gcd;
        int denominator = (rate1 + rate2) / gcd;
        int time = (numerator * n) / denominator;
        int written = time / rate1 + time / rate2;
        if (n % denominator != 0) {
            time-=rate1+rate2;
            written = time / rate1 + time / rate2;
            while (written < n - 1) {
                time += Math.min(rate1 - time % rate1, rate2 - time % rate2);
                written = time / rate1 + time / rate2;
            }
            if (n % denominator != 0) {
                time += Math.max(rate1 - time % rate1, rate2 - time % rate2);
                written = n + 1;
            }
        }

        System.out.println(written + " " + time);
    }

    public static int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
}

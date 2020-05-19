package easy.interesting;

import java.util.Scanner;
//https://naq19.kattis.com/problems/diagonalcut
public class DiagCut {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long m = sc.nextLong();
        long g = gcd(n, m);
        n /= g;
        m /= g;
        if ((n + m) % 2 == 1) {
            System.out.println(0);
        } else{
            System.out.println(g);
        }
    }
    static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}

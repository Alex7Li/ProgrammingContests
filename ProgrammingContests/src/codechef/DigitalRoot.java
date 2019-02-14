package codechef;

import java.util.Scanner;

//https://codeforces.com/contest/1107/problem/B
public class DigitalRoot {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            long k = sc.nextLong();
            long x = sc.nextLong();
            System.out.println((k-1L)*9L+x);
        }
    }
}

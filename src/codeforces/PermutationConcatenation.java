package codeforces;

import java.util.Scanner;
//https://codeforces.com/contest/1091/problem/D
public class PermutationConcatenation {
    private static final int MOD = 998244353;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.close();
        long[] fact = new long[n+1];
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i-1]*i)%MOD;
        }
        long ans = 1;
        for (int i = 2; i <= n; i++) {
            ans = (((ans+fact[i-1]-1)%MOD)*i)%MOD;
        }
        System.out.println(ans);
    }
}

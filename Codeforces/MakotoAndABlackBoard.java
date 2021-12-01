package codeforces;

import java.util.*;

//https://codeforces.com/problemset/problem/1097/D
public class MakotoAndABlackBoard {
    private static final int MOD = 1000000007;

    private static long modInv(long a) {
        return modPow(a, MOD - 2);
    }

    private static long modPow(long a, long p) {
        if (p == 0) {
            return 1;
        }
        long half = modPow(a, p / 2);
        long ans = (half * half) % MOD;
        if (p % 2 == 1) {
            ans = (ans * a) % MOD;
        }
        return ans;
    }

    private static long factorial(int a) {
        long ans = 1;
        for (int i = 2; i <= a; i++) {
            ans = (ans * i) % MOD;
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        int k = sc.nextInt();
        //map factors to their power
        Map<Long, Integer> factors = new HashMap<>();
        for (long i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                factors.put(i, factors.getOrDefault(i, 0) + 1);
                n /= i;
                i--;
            }
        }
        //n should be prime
        factors.put(n, factors.getOrDefault(n, 0) + 1);
        //for quicker computation store common modInv
        long[] modInv = new long[52];
        for (int i = 1; i < 52; i++) {
            modInv[i] = modInv(i);
        }
        long ans = 1;
        for (long i : factors.keySet()) {
            int pow = factors.get(i);
            long fact = factorial(pow + 1);
            ans = (ans*modPow(modInv(fact), k))%MOD;
            long[] a = new long[pow + 1];
            for (int j = 0; j <= pow; j++) {
                a[j] = (fact * modInv[a.length]) % MOD;
            }
            for (int j = 1; j < k; j++) {
                long[] temp = new long[a.length];
                for (int l = pow; l >= 0; l--) {
                    for (int m = l; m < a.length; m++) {
                        temp[l] = (temp[l] + ((a[m] * fact) % MOD) * modInv[m + 1]) % MOD;
                    }
                }
                a = temp;
            }
            long sum = 0;
            for (int j = 0; j < a.length; j++) {
                sum = (sum + a[j] * modPow(i, j)) % MOD;
            }
            ans = (ans * sum) % MOD;
        }
        System.out.println(ans);
    }


}
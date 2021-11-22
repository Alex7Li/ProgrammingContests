package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
//http://codeforces.com/contest/1009/problem/E
public class InterCityTravelling {
    static final long MOD = 998244353L;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        long[] a = Arrays.stream(br.readLine().split(" ")).mapToLong(Long::parseLong).toArray();
        long[] twomodpow = new long[a.length + 1];
        twomodpow[0] = 1;
        for (int i = 0; i < a.length; i++) {
            twomodpow[i + 1] = (twomodpow[i] * 2) % MOD;
        }
        long answer = 0;
        for (int k = 1; k < a.length; k++) {
            long temp = (twomodpow[n - k] + ((n-k) * twomodpow[n - k - 1]) % MOD) % MOD;
            answer += (temp * a[k - 1]) % MOD;
            answer %= MOD;
        }
        System.out.println((answer+a[a.length-1])%MOD);
    }
}

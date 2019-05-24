package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

//https://codeforces.com/contest/1113/problem/C
public class SashaAndABitOfRelax {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] a = Arrays.stream(br.readLine().split(" "))
                .mapToInt(x -> Integer.parseInt(x)).toArray();
        int[] aXor = new int[n];
        Map<Integer, Integer> xorCountEven = new HashMap<>();
        Map<Integer, Integer> xorCountOdd = new HashMap<>();
        aXor[0] = a[0];
        for (int i = 1; i < a.length; i++) {
            aXor[i] = aXor[i - 1] ^ a[i];
        }
        xorCountOdd.put(0, 1);
        for (int i = 0; i < aXor.length; i++) {
            if (i % 2 == 0) {
                xorCountEven.put(aXor[i], xorCountEven.getOrDefault(aXor[i], 0) + 1);
            } else {
                xorCountOdd.put(aXor[i], xorCountOdd.getOrDefault(aXor[i], 0) + 1);
            }
        }
        long ans = 0;
        for (Map.Entry<Integer, Integer> e : xorCountEven.entrySet()) {
            ans += (long) (e.getValue()) * (e.getValue() - 1L);
        }
        for (Map.Entry<Integer, Integer> e : xorCountOdd.entrySet()) {
            ans += (long) (e.getValue()) * (e.getValue() - 1L);
        }
        System.out.println(ans/2);
        br.close();
    }
}

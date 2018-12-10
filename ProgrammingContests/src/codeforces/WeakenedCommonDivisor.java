package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

//http://codeforces.com/contest/1025/problem/B
public class WeakenedCommonDivisor {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] numStrFirst = br.readLine().split(" ");
        int n1 = Integer.parseInt(numStrFirst[0]);
        int n2 = Integer.parseInt(numStrFirst[1]);
        Set<Integer> primes = new HashSet<>();
        primes.add(n1);
        primes.add(n2);
        int max = (int) (Math.max(Math.sqrt(n1), Math.sqrt(n2)) + 3);
        for (int i = 2; i < max; i++) {
            if (n1 % i == 0 || n2 % i == 0) {
                primes.add(i);
                if (n1 % i == 0 && n1 / i > 1) {
                    primes.add(n1 / i);
                }
                if (n2 % i == 0 && n2 / i > 1) {
                    primes.add(n2 / i);
                }
            }
        }
        for (int i = 1; i < n; i++) {
            String[] numStr = br.readLine().split(" ");
            int num1 = Integer.parseInt(numStr[0]);
            int num2 = Integer.parseInt(numStr[1]);
            ArrayList<Integer> remove = new ArrayList<>();
            for (int p : primes) {
                if (num1 % p != 0 && num2 % p != 0) {
                    remove.add(p);
                }
            }
            for (int p : remove) {
                primes.remove(p);
            }
        }
        if (primes.size() == 0) {
            System.out.println(-1);
        } else {
            for (int p : primes) {
                System.out.println(p);
                return;
            }
        }
    }
}

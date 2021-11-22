package math.factoring;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

// http://codeforces.com/contest/1025/problem/B
public class WeakenedCommonDivisor {
public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(br.readLine());
    String[] numStrFirst = br.readLine().split(" ");
    int n1 = Integer.parseInt(numStrFirst[0]);
    int n2 = Integer.parseInt(numStrFirst[1]);
    Set<Integer> divisors = primeFactors(n1);
    divisors.addAll(primeFactors(n2));
    for (int i = 1; i < n; i++) {
        String[] numStr = br.readLine().split(" ");
        int num1 = Integer.parseInt(numStr[0]);
        int num2 = Integer.parseInt(numStr[1]);
        ArrayList<Integer> remove = new ArrayList<>();
        for (int d : divisors) {
            if (num1 % d != 0 && num2 % d != 0) {
                remove.add(d);
            }
        }
        divisors.removeAll(remove);
    }
    if (divisors.size() == 0) {
        System.out.println(-1);
    } else {
        System.out.println(divisors.iterator().next());
    }
}

/**
 * @param n The numbers to factor
 * @return a set of all the prime factors of n
 */
private static Set<Integer> primeFactors(int n) {
    Set<Integer> primes = new HashSet<>();
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            primes.add(i);
            n /= i;
            i--;
        }
    }
    if (n != 1) {
        primes.add(n);
    }
    return primes;
}
}

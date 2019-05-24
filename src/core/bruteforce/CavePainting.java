package core.bruteforce;

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

//http://codeforces.com/contest/922/problem/C
public class CavePainting {
public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long n = sc.nextLong();
    long k = sc.nextLong();
    sc.close();
    Set<Long> seen = new HashSet<Long>();
    for (int i = 1; i <= k; i++) {
        if (!seen.contains(n % i)) {
            seen.add(n % i);
        } else {
            System.out.println("No");
            return;
        }
    }
    System.out.println("Yes");
}
}

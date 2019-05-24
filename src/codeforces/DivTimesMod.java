package codeforces;

import java.util.Scanner;

//https://codeforces.com/contest/1087/problem/B
public class DivTimesMod {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int bestFact = -1;
        for (int i = k - 1;; i--) {
            if (n % i == 0) {
                bestFact = i;
                break;
            }
        }
        System.out.println(k * (n / bestFact) + bestFact);
    }
}

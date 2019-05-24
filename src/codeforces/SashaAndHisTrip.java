package codeforces;

import java.util.Scanner;

//https://codeforces.com/contest/1113/problem/A
public class SashaAndHisTrip {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int capacity = sc.nextInt();
        int cost = Math.min(capacity, n - 1);
        for (int i = 2; i <= n - capacity; i++) {
            cost += i;
        }
        System.out.println(cost);
        sc.close();
    }
}

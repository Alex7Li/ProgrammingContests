package codeforces;

import java.util.ArrayList;
import java.util.Scanner;
//http://codeforces.com/contest/1009/problem/A
public class GameShopping {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] costs = new int[n];
        ArrayList<Integer> bills = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            costs[i] = sc.nextInt();
        }
        for (int i = 0; i < m; i++) {
            bills.add(sc.nextInt());
        }
        int bought = 0;
        for (int i = 0; i < n && bills.size()>0; i++) {
            if(costs[i]<=bills.get(0)){
                bought++;
                bills.remove(0);
            }
        }
        System.out.println(bought);
    }
}

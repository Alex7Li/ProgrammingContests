package codeforces;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

//https://codeforces.com/problemset/problem/873/B
public class BalancedSubstring {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        char[] str = sc.nextLine().toCharArray();
        int[] a = new int[n + 1];
        a[0] = 0;
        for (int i = 0; i < n; i++) {
            if (str[i] == '0') {
                a[i + 1] = a[i] - 1;
            } else {
                a[i + 1] = a[i] + 1;
            }
        }

        // map from extra 0s -> first location
        Map<Integer, Integer> firstLoc = new HashMap<>();
        for (int i = 0; i < n; i++) {
            firstLoc.putIfAbsent(a[i], i);
        }
        // map from extra 0s -> last location
        Map<Integer, Integer> lastLoc = new HashMap<>();
        for (int i = n; i >= 0; i--) {
            lastLoc.putIfAbsent(a[i], i);
        }
        int maxDist = 0;
        for (int i : firstLoc.keySet()) {
            maxDist = Math.max(maxDist, lastLoc.get(i) - firstLoc.get(i));
        }
        System.out.println(maxDist);
        sc.close();
    }
}

package codeforces;

import java.util.Scanner;

//https://codeforces.com/problemset/problem/1096/B
public class SubstringRemoval {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        char[] c = sc.nextLine().toCharArray();
        char first = c[0];
        char last = c[n - 1];
        long count = 1;
        if (first != last) {
            int i = 0;
            while (c[i] == first) {
                i++;
                count++;
            }
            i = n - 1;
            while (c[i] == last) {
                i--;
                count++;
            }
        } else {
            int firstBadInd = 0;
            int lastBadInd = n - 1;
            while (firstBadInd < n && c[firstBadInd] == first) {
                firstBadInd++;
            }
            if (firstBadInd == n) {
                count = n * (n - 1);
            } else {
                while (c[lastBadInd] == last) {
                    lastBadInd--;
                }
                count = (firstBadInd + 1L) * (long) (n - lastBadInd);
            }
        }
        System.out.println(count % 998244353);
    }
}

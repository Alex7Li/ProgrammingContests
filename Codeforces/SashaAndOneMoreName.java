package codeforces;

import java.util.Scanner;

//https://codeforces.com/contest/1113/problem/D
public class SashaAndOneMoreName {
    public static void main(String[] args) {
        //answer is always at most 2 (or inf)
        Scanner sc = new Scanner(System.in);
        char[] str = sc.nextLine().toCharArray();
        int n = str.length;
        sc.close();

        //check if impossible
        if (n == 1) {
            System.out.println("Impossible");
            return;
        }
        boolean possible = false;
        int first = str[(n + 1) / 2];
        for (int i = 0; i < n / 2; i++) {
            if (str[i] != first) {
                possible = true;
            }
        }
        if (!possible) {
            System.out.println("Impossible");
            return;
        }
        // split the string, then glue it back together such that the new
        // middle is at newMid
        for (int newMid = 0; newMid < n; newMid++) {
            // check that this string is different
            boolean isDiff = false;
            for (int i = 0; i < n; i++) {
                if (str[(i + n / 2) % n] != str[(newMid + i) % n]) {
                    isDiff = true;
                }
            }
            if (!isDiff) {
                continue;
            }

            boolean works = true;
            if (n % 2 == 1) {
                for (int i = 1; i <= n / 2; i++) {
                    if (str[(newMid + i) % n] != str[(n + newMid - i) % n]) {
                        works = false;
                        break;
                    }
                }
            } else {
                for (int i = 0; i < str.length / 2; i++) {
                    if (str[(newMid + i) % n] != str[(n + newMid - i - 1) % n]) {
                        works = false;
                        break;
                    }
                }

            }
            if (works) {
                System.out.println(1);
                return;
            }
        }
        System.out.println(2);
    }
}

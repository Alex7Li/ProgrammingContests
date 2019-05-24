package codeforces;

import java.util.Scanner;

//http://codeforces.com/contest/1037/problem/C
public class Equalize {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        sc.nextLine();
        char[] a = sc.nextLine().toCharArray();
        char[] b = sc.nextLine().toCharArray();
        int cost = 0;
        for (int i = 0; i < a.length; i++) {
            if (a[i] != b[i]) {
                if (i < a.length - 1 && a[i] == b[i + 1] && a[i + 1] == b[i]) {
                    cost++;
                    i++;
                } else {
                    cost++;
                }
            }
        }

        System.out.println(cost);
    }
}

package codeforces;

import java.util.Scanner;

//https://codeforces.com/contest/1085/problem/A
public class RightLeftCipher {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[] a = sc.nextLine().toCharArray();
        sc.close();
        StringBuilder sb = new StringBuilder("");
        int d = 0;
        if (a.length % 2 == 0) {
            while (a.length - 1 - d > d) {
                sb.append(a[a.length - 1 - d]);
                sb.append(a[d]);
                d++;
            }
        } else {
            while (a.length - 1 - d > d) {
                sb.append(a[d]);
                sb.append(a[a.length - 1 - d]);
                d++;
            }
            sb.append(a[d]);
        }
        System.out.println(sb.reverse());
    }
}

package codeforces;

import java.util.Scanner;
//https://codeforces.com/contest/1093/problem/B
public class LettersRearranging {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        for (int i = 0; i < t; i++) {
            char[] c = sc.nextLine().toCharArray();
            int diff = -1;
            for (int j = 0; j < c.length; j++) {
                if (c[j] != c[0]) {
                    diff = j;
                    break;
                }
            }
            if (diff != -1) {
                char temp = c[c.length-1];
                c[c.length-1] = c[diff];
                c[diff] = temp;
                StringBuilder sb = new StringBuilder();
                for (int j = 0; j < c.length; j++) {
                    sb.append(c[j]);
                }
                System.out.println(sb);
            }else{
                System.out.println(-1);
            }
        }
    }
}

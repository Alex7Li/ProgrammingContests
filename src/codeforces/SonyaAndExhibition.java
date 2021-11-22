package codeforces;

import java.util.Scanner;
//http://codeforces.com/contest/1004/problem/B
public class SonyaAndExhibition {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        StringBuilder str = new StringBuilder();
        for (int i = 0; i < n; i++) {
            str.append(i%2);
        }
        System.out.println(str);
    }
}

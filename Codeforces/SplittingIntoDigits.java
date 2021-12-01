package codeforces;

import java.io.IOException;
import java.util.Scanner;

// https://codeforces.com/problemset/problem/1104/A
public class SplittingIntoDigits {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println(n);
        for (int i = 0; i < n-1; i++) {
            System.out.print(1 + " ");
        }
        System.out.println(1);
    }
}

package codeforces;

import java.io.IOException;
import java.util.Scanner;

//https://codeforces.com/problemset/problem/1106/A
public class LunarNewYearAndCrossCounting {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        char[][] M = new char[n][n];
        for (int i = 0; i < n; i++) {
            M[i] = sc.nextLine().toCharArray();
        }
        int count = 0;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (M[i][j] == 'X' && M[i - 1][j - 1] == 'X' && M[i + 1][j - 1] == 'X' &&
                M[i - 1][j + 1] == 'X' && M[i + 1][j + 1] == 'X'){
                    count++;
                }
            }
        }
        System.out.println(count);
        sc.close();
    }
}

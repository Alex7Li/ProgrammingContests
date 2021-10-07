package codeforces;

import java.util.Scanner;

//http://codeforces.com/contest/989/problem/C
public class MistofFlorescence {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int d = sc.nextInt();
        sc.close();
        a--;
        b--;
        System.out.println("50 50");
        for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 50; j++) {
                char flower = 'A';
                if (j % 2 == 0 && i % 2 == 0) {
                    if (b > 0) {
                        b--;
                        flower = 'B';
                    } else if (c > 0) {
                        c--;
                        flower = 'C';
                    }
                }
                System.out.print(flower);
            }
            System.out.println();
        }
        System.out.println("BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB");
        for (int i = 0; i < 24; i++) {
            for (int j = 0; j < 50; j++) {
                char flower = 'B';
                if (j % 2 == 0 && i % 2 == 0) {
                    if (a > 0) {
                        flower = 'A';
                        a--;
                    } else if (d > 0) {
                        flower = 'D';
                        d--;
                    }
                }
                System.out.print(flower);
            }
            System.out.println();
        }
    }
}

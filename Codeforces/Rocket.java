package codeforces;

import java.util.Scanner;
//http://codeforces.com/contest/1011/problem/D
public class Rocket {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int max = sc.nextInt();
        int min = 1;
        int n = sc.nextInt();
        int[] answers = new int[n];
        boolean[] truths = new boolean[n];
        for (int i = 0; i < n; i++) {
            System.out.println((max + min) / 2);
            System.out.flush();
            int res = sc.nextInt();
            if (res == 0 || res == -2) {
                return;
            }
            answers[i] = res;
        }
        System.out.println(min);
        System.out.flush();
        int res = sc.nextInt();
        if (res == 0 || res == -2) {
            return;
        }
        int corAns = answers[0] * res;
        for (int i = 0; i < truths.length; i++) {
            truths[i] = (answers[i] == corAns);
        }
        boolean tooLow = ((answers[0] == 1) == truths[0]);
        if (tooLow) {
            min = (max + min) / 2 + 1;
        } else {
            max = (max + min) / 2 - 1;
        }
        int cycleLoc = 1;
        while (max != min) {
            int guess = (max + min) / 2;
            System.out.println(guess);
            System.out.flush();
            int response = sc.nextInt();
            if (response == 0 || response == -2) {
                return;
            }
            tooLow = (response == 1) == truths[cycleLoc % n];
            if (tooLow) {
                min = guess + 1;
            } else {
                max = guess - 1;
            }
            cycleLoc++;
        }
        System.out.println(min);
    }
}

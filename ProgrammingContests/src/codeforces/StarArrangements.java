package codeforces;

import java.util.Scanner;

//https://codeforces.com/gym/101617
public class StarArrangements {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int stars = sc.nextInt();
        sc.close();
        for (int i = 2; i < stars; i++) {
            if (stars % (2 * i - 1) == 0) {
                System.out.println(i + " " + (i - 1));
            }
            if (stars % (2 * i - 1) == i) {
                System.out.println(i + " " + (i - 1));
            }
            if (stars % i == 0) {
                System.out.println(i + " " + i);
            }
        }
    }
}

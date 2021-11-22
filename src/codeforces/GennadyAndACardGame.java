package codeforces;

import java.util.Scanner;
//https://codeforces.com/problemset/problem/1097/A
public class GennadyAndACardGame {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String card = sc.nextLine();
        String[] hand = sc.nextLine().split(" ");
        sc.close();
        boolean pos = false;
        for (int i = 0; i < hand.length; i++) {
            for (int j = 0; j < 2; j++) {
                if (hand[i].charAt(j) == card.charAt(j)) {
                    pos = true;
                }
            }
        }
        System.out.println(pos?"YES":"NO");
    }
}

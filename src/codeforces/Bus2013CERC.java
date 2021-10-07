package codeforces;

import java.util.Scanner;
//https://codeforces.com/gym/100299
public class Bus2013CERC {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int test = 0; test < t; test++) {
            int n = sc.nextInt();
            int ans = 0;
            for (int i = 0; i < n; i++) {
                ans = ans*2+1;
            }
            System.out.println(ans);
        }
    }
}

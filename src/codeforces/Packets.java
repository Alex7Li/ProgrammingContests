package codeforces;

import java.util.Scanner;
//http://codeforces.com/contest/1037/problem/A
public class Packets {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int ans = 0;
        while(n!=0){
            n/=2;
            ans++;
        }
        System.out.println(ans);
    }
}

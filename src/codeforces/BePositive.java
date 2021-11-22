package codeforces;

import java.util.Scanner;

// https://codeforces.com/problemset/problem/1130/A
public class BePositive {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        int n = sc.nextInt();
        int neg = 0;
        int pos = 0;
        for (int i = 0; i < n; i++) {
            int v = sc.nextInt();
            if(v>0){
                pos++;
            }else if(v<0){
                neg++;
            }
        }
        if(pos>=(n+1)/2){
            System.out.println(1);
        }
        else if(neg>=(n+1)/2){
            System.out.println(-1);
        }else{
            System.out.println(0);
        }
}}

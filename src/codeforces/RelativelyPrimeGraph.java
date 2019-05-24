package codeforces;

import java.util.ArrayList;
import java.util.Scanner;
//http://codeforces.com/contest/1009/problem/D
public class RelativelyPrimeGraph {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        sc.close();
        StringBuilder sb = new StringBuilder();
        int count = 0;
        if(n-1>m){
            System.out.println("Impossible");
            return;
        }
        for (int i = 1; i <= n; i++) {
            boolean[] hascommondivisor = new boolean[n+1];
            ArrayList<Integer> ifact = new ArrayList<>();
            for (int j = 2; j <= i; j++) {
                if(i%j==0){
                    ifact.add(j);
                }
            }
            for(int fact:ifact){
                for (int j = i+fact; j <= n; j+=fact) {
                    hascommondivisor[j] = true;
                }
            }
            for (int j = i+1; j <= n; j++) {
                if(!hascommondivisor[j]){
                    sb.append(i + " " + j + System.lineSeparator());
                    count++;
                    if(count==m){
                        System.out.println("Possible");
                        System.out.println(sb);
                        return;
                    }
                }
            }
        }
        System.out.println("Impossible");
    }
}

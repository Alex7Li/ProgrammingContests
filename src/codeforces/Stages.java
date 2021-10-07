package codeforces;

import java.util.Arrays;
import java.util.Scanner;
//http://codeforces.com/contest/1011/problem/A
public class Stages {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        sc.nextLine();
        char[] c = sc.nextLine().toCharArray();
        Arrays.sort(c);
        int weight = 0;
        int last = c[0];
        weight+=(c[0]-'a'+1);
        k--;
        if(k==0){
            System.out.println(weight);
            return;
        }
        for (int i = 1; i < c.length; i++) {
            if(c[i]>last+1){
                k--;
                weight+=(c[i]-'a'+1);
                last = c[i];
                if(k==0){
                    System.out.println(weight);
                    return;
                }
            }
        }
        System.out.println(-1);
        sc.close();

    }
}

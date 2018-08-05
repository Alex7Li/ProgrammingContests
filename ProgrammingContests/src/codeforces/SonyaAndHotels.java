package codeforces;

import java.util.Arrays;
import java.util.Scanner;
//http://codeforces.com/contest/1004/problem/A
public class SonyaAndHotels {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int d = sc.nextInt();
        int[] locs = new int[n];
        for (int i = 0; i < n; i++) {
            locs[i] = sc.nextInt();
        }
        Arrays.sort(locs);
        int count = 2;
        for (int i = 0; i < locs.length-1; i++) {
            if(locs[i+1]-locs[i]==2*d){
                count++;
            }else if(locs[i+1]-locs[i]>2*d){
                count+=2;
            }
        }
        System.out.println(count);
    }
}

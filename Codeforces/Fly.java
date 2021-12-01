package codeforces;

import java.util.Scanner;
//http://codeforces.com/contest/1011/problem/C
public class Fly {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        int n = sc.nextInt();
        int w = sc.nextInt();
        int[] a = new int[n*2];
        for (int i = 0; i < n; i++) {
            a[2*i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            a[2*i+1] = sc.nextInt();
        }
        double max = Math.pow(10,10);
        double min = 0;
        while((max-min)/(max+min)>Math.pow(10,-9)){
            double fuel = (max+min)/2;
            boolean tooMuch = true;
            for (int i = 0; i < a.length; i++) {
                fuel -= (fuel+w)/a[i];
                if(fuel<0){
                    tooMuch=false;
                    break;
                }
            }
            if(tooMuch){
                max = (max+min)/2;
            }else{
                min = (max+min)/2;
            }
        }
        if(min>Math.pow(10,9.1)){
            System.out.println(-1);
        }else{
            System.out.println(min);
        }
    }
}

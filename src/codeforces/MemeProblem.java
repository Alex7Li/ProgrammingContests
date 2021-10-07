package codeforces;

import java.util.Scanner;

//http://codeforces.com/problemset/problem/1076/C
public class MemeProblem {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            int d = sc.nextInt();
            if(0<d&&d<4){
                System.out.println("N");
            }else{
                System.out.print("Y ");
                double det = Math.sqrt(d*d-4*d);
                double a = (d+det)/2;
                double b = (d-det)/2;
                System.out.println(a + " " + b);
            }
        }
    }

}

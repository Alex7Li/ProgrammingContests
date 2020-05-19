package medium.original;

import java.util.Scanner;
//https://naq19.kattis.com/problems/zipline
public class Zipline {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n =sc.nextInt();
        for (int t = 0; t < n; t++) {
            double w =sc.nextInt();
            double g =sc.nextInt();
            double h =sc.nextInt();
            double r =sc.nextInt();
            double w2 = Math.pow(w, 2);
            double big = Math.sqrt(Math.pow(g+h-2*r, 2) + w2);
            double small = Math.sqrt(Math.pow(g-h, 2) + w2);
            System.out.println(small + " " + big);
        }
    }
}

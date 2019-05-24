package codeforces;

import java.util.Scanner;

//https://codeforces.com/gym/102032
public class Innohorse {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[] a = sc.nextLine().toCharArray();
        char[] b = sc.nextLine().toCharArray();
        int x = Math.abs(a[0]-b[0]);
        int y = Math.abs(a[1]-b[1]);
        int min = Math.min(x,y);
        int max = Math.max(x,y);
        System.out.println(min + " " + max);
    }
}

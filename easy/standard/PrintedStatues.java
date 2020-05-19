package easy.standard;

import java.util.Scanner;
//https://open.kattis.com/contests/j47tpb/problems/3dprinter
public class PrintedStatues {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int printers = 1;
        int days = 1;
        while(printers<n){
            days++;
            printers*=2;
        }
        System.out.println(days);
    }
}

package codeforces;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Scanner;
//http://codeforces.com/contest/1011/problem/E
public class Border {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int greatestCommonDivisor = k;
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for (int i = 0; i < n; i++) {
            greatestCommonDivisor = gcd(sc.nextInt(),greatestCommonDivisor);
        }
        bw.write(k/greatestCommonDivisor + "");
        bw.newLine();
        bw.write("0");
        for (int i = greatestCommonDivisor; i < k; i+=greatestCommonDivisor) {
            bw.write(" " + i);
        }
        bw.newLine();
        bw.close();
    }
    public static int gcd(int a, int b){
       if(b==0){
           return a;
       }else{
           return gcd(b,a%b);
       }
    }

}

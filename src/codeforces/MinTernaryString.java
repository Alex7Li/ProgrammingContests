package codeforces;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Scanner;
//http://codeforces.com/contest/1009/problem/B
public class MinTernaryString {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        char[] s = sc.nextLine().toCharArray();
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int ones = 0;
        for (int i = 0; i < s.length; i++) {
            if (s[i] == '1') {
                ones++;
            }
        }
        boolean first = true;
        for (int i = 0; i < s.length; i++) {
            int zeros = 0;
            while (i < s.length && s[i] != '2') {
                if (s[i] == '0') {
                    zeros++;
                }
                i++;
            }
            for (int j = 0; j < zeros; j++) {
                bw.write('0');
            }
            if (first) {
                for (int j = 0; j < ones; j++) {
                    bw.write('1');
                }
                first = false;
            }
            if (i != s.length) {
                bw.write('2');
            }
        }
        bw.newLine();
        bw.close();
        sc.close();
    }
}

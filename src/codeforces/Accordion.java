package codeforces;

import java.util.Scanner;

//https://codeforces.com/problemset/problem/1101/B
public class Accordion {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[] s = sc.nextLine().toCharArray();
        int left = s.length;
        boolean seen = false;
        for (int i = 0; i < s.length; i++) {
            if (s[i] == '[') {
                seen = true;
            }
            if (seen && s[i] == ':') {
                left = i + 1;
                break;
            }
        }
        int right = 0;
        seen = false;
        for (int i = s.length-1; i >= 0; i--) {
            if (s[i] == ']') {
                seen = true;
            }
            if (seen && s[i] == ':') {
                right = i;
                break;
            }
        }
        if (right < left) {
            System.out.println(-1);
        } else {
            int count = 4;
            for (int i = left; i < right; i++) {
                if(s[i] == '|'){
                    count++;
                }
            }
            System.out.println(count);
        }
    }
}

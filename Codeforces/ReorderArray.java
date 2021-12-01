package codeforces;

import java.util.Arrays;
import java.util.Scanner;
//http://codeforces.com/problemset/problem/1007/A
public class ReorderArray {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Integer[] a = new Integer[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        Arrays.sort(a);
        int maxChain = 1;
        int curChain = 1;
        for (int i = 1; i < a.length; i++) {
            if (a[i].equals(a[i - 1])) {
                curChain++;
                maxChain = Math.max(curChain, maxChain);
            } else {
                curChain = 1;
            }
        }
        System.out.println(n - maxChain);
    }
}

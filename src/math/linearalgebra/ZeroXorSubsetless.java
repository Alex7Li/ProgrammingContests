package math.linearalgebra;

import java.util.Scanner;

// https://codeforces.com/problemset/problem/1101/G
public class ZeroXorSubsetless {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        int xor = 0;
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            xor^=a[i];
        }
        if(xor==0){
            System.out.println(-1);
            return;
        }
        int count = 0;
        for (int i = 1 << 30; i > 0; i >>= 1) {
            int val = -1;
            for (int j = 0; j < n; j++) {
                if ((i & a[j]) != 0) {
                    if (val == -1) {
                        val = a[j];
                        a[j] = i;
                        count++;
                    }else{
                        a[j] ^= val;
                    }
                }
            }
        }
        System.out.println(count);
    }
}

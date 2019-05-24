package codeforces;

import java.util.Scanner;
//http://codeforces.com/contest/981/problem/D
public class BookshelvesBruteRecursion {
    private static long bestCost = 0;
    private static long[] b;
    private static long[][] memo;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        b = new long[n];
        for (int i = 0; i < n; i++) {
            b[i] = sc.nextLong();
        }

        System.out.println(solve(n-1,k,Long.MAX_VALUE));
    }
    private static long solve(int n, int k, long curV){
        long ans = b[n];
        if(n==0&&k==0) {
            ans = curV;
        }else if(n+1<k){
            ans = 0;
        }else if (n+1==k){
            for (int i = 0; i < n; i++) {
                ans&=b[i];
            }
        }else if (k==1){
            for (int i = 0; i < n; i++) {
                ans+=b[i];
            }
        }else{
            long best = 0;
            for (int i = n-1; i >= 0; i--) {
                if( (ans&curV) > bestCost) {
                    long beauty = ans & solve(i, k - 1, ans & curV);
                    if (beauty > best) {
                        best = beauty;
                        bestCost = Math.max(bestCost, beauty);
                    }
                }
                ans+= b[i];
            }
            ans = best;
        }
        return ans&curV;
    }
}

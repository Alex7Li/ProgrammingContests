package codeforces;

import java.util.Scanner;

//http://codeforces.com/contest/981/problem/D
public class Bookshelves {
    private static long[] bookSum;
    private static int n;
    private static int k;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();
        bookSum = new long[n+1];
        bookSum[0]=0;
        for (int i = 1; i <= n; i++) {
            bookSum[i] = bookSum[i-1]+sc.nextLong();
        }
        long target = 0L;
        for (long i = 1L<<60; i > 0; i/=2) {
            if(isPossible(target|i)){
                target = target|i;
            }
        }
        System.out.println(target);
    }
    public static boolean isPossible(long target){
        // dp[i][j] = is it possible to split the first i books into j segments
        // such that the sum of each segment & target = target?
        boolean[][] dp = new boolean[n+1][k+1];
        dp[0][0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if(((bookSum[i]-bookSum[j])&target)==target){
                    for (int segments = 0; segments < k; segments++) {
                        if(dp[j][segments]){
                            dp[i][segments+1]=true;
                        }
                    }
                }
            }
        }
        return dp[n][k];
    }
}

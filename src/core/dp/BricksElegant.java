package core.dp;

import java.util.Scanner;

// solution adapted from https://codeforces.com/gym/101669/submission/37928621
// this may be the most elegant solution idea I've ever seen.
public class BricksElegant {

    private static final int MOD = 1_000_000_007;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] a = new int[n + 1];
        for (int i = 0; i < m; i++) {
            a[sc.nextInt() - 1]++;
        }
        // dp[diff] = the number of ways to fill the interval 1...i
        // as of the last time that i-sum_{j=0}^i(a[i])=diff.
        int[] dp = new int[n];
        dp[0] = 1;
        int diff = 0;
        for (int i = 0; i < n; i++) {
            diff = diff + 1 - a[i];
            if (a[i] == 0 && diff > 0) {
                // 2 cases: we can not use this square, adding dp[diff] ways.
                // Or, we can fill this square with a brick. In that case,
                // we will have to fill some interval [j,i] with bricks without.
                // having left over to fall to the left.
                // After finding the maximal such j, the answer will be the
                // number of ways to fill [1,j-1]: this is dp[diff-1]
                // Note that if two locations have the same value of diff,
                // then we can fill the interval [j,i] with bricks and have no
                // 'left over' to fall to the left.
                dp[diff] = (dp[diff] + dp[diff - 1])%MOD;
            }
        }
        System.out.println(dp[diff]);
    }
}

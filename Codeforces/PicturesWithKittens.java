package codeforces;

import java.util.*;

// https://codeforces.com/problemset/problem/1077/F1
// https://codeforces.com/contest/1077/problem/F2
public class PicturesWithKittens {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int d = sc.nextInt();
        int x = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        // dp[i][j]: using only elements of a up to a[i], and the element at a[i],
        // and using exactly j elements, what is the best beauty?
        long[][] dp = new long[n + 1][x + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= x; j++) {
                dp[i][j] = Long.MIN_VALUE;
            }
        }
        dp[0][0] = 0;
        for (int j = 0; j < x; j++) {
            MaxQueue Q = new MaxQueue();
            for (int i = j; i < n; i++) {
                Q.push(dp[i][j]);
                if (i - d >= j) {
                    Q.pop();
                }
                dp[i + 1][j + 1] = Q.getMax() + a[i];
            }
        }
        long max = -1;
        for (int i = n - d + 1; i <= n; i++) {
            max = Math.max(max, dp[i][x]);
        }
        System.out.println(max);
    }

    // https://stackoverflow.com/questions/4802038/implement-a-queue-in-which-push-rear-pop-front-and-get-min-are-all-consta
    static class MaxQueue {
        Deque<Pair> pushStack = new ArrayDeque<>();
        Deque<Pair> popStack = new ArrayDeque<>();

        void push(long val) {
            long max = val;
            if (!pushStack.isEmpty()) {
                max = Math.max(max, pushStack.peekFirst().max);
            }
            pushStack.addFirst(new Pair(val, max));
        }

        long pop() {
            if (popStack.isEmpty()) {
                if (pushStack.isEmpty()) {
                    throw new RuntimeException("Pop from empty queue");
                } else {
                    // move pushStack to popStack, updating the min values
                    // reset the max for each element.
                    // For the first element, the max will be the value.
                    long val = pushStack.removeFirst().val;
                    popStack.addFirst(new Pair(val, val));
                    // For the rest, the max is the max of (max so far, new value)
                    while (!pushStack.isEmpty()) {
                        val = pushStack.removeFirst().val;
                        long max = Math.max(popStack.peekFirst().max, val);
                        Pair pushV = new Pair(val, max);
                        popStack.addFirst(pushV);
                    }
                }
            }
            return popStack.removeFirst().val;
        }

        //return maxValue, or null if none exist
        Long getMax() {
            if (pushStack.isEmpty()) {
                if (popStack.isEmpty()) {
                    return null;
                } else {
                    return popStack.peekFirst().max;
                }
            } else if (popStack.isEmpty()) {
                return pushStack.peekFirst().max;
            } else {
                return Math.max(pushStack.peekFirst().max, popStack.peekFirst().max);
            }
        }

        static class Pair {
            long val;
            long max;

            Pair(long val, long max) {
                this.val = val;
                this.max = max;
            }
        }
    }
}

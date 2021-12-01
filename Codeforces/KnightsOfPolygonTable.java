package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
//http://codeforces.com/problemset/problem/994/B
public class KnightsOfPolygonTable {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] args1 = br.readLine().split(" ");
        int n = Integer.parseInt(args1[0]);
        int k = Integer.parseInt(args1[1]);
        int[] powers = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int[] coins = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        Knight[] knights = new Knight[n];
        for (int i = 0; i < n; i++) {
            knights[i] = new Knight(i, powers[i], coins[i]);
        }
        long[] ans = new long[n];
        if (k == 0) {
            for (int i = 0; i < coins.length; i++) {
                System.out.print(coins[i] + " ");
            }
        } else {
            Arrays.sort(knights);
            long[] coin = new long[k];
            ans[knights[0].index] = knights[0].coin;
            for (int i = 1; i < knights.length; i++) {
                if (knights[i - 1].coin > coin[0]) {
                    coin[0] = knights[i - 1].coin;
                    Arrays.sort(coin);

                }
                ans[knights[i].index] = Arrays.stream(coin).sum() + knights[i].coin;
            }

            for (int i = 0; i < ans.length; i++) {
                System.out.print(ans[i] + " ");
            }
        }
        System.out.println();
    }

    public static class Knight implements Comparable<Knight> {
        int power;
        int coin;
        int index;

        public Knight(int index, int power, int coin) {
            this.power = power;
            this.coin = coin;
            this.index = index;
        }

        @Override
        public int compareTo(Knight o) {
            return power - o.power;
        }
    }
}

package atcoder;

import java.io.IOException;
import java.util.Scanner;
//https://abc099.contest.atcoder.jp/tasks/abc099_c
public class StrangeBank {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nineCosts = new int[n + 1];
        int[] sixCosts = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            nineCosts[i] = getCost(i, 9);
            sixCosts[i] = getCost(i, 6);
        }
        int best = Integer.MAX_VALUE;
        for (int i = 0; i < nineCosts.length; i++) {
            best = Math.min(best, nineCosts[i] + sixCosts[n - i]);
        }
        System.out.println(best);
        sc.close();
    }

    private static int getCost(int x, int base) {
        int cost = 0;
        while (x != 0) {
            cost += x % base;
            x /= base;
        }
        return cost;
    }
}

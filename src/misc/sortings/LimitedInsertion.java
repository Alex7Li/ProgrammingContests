package misc.sortings;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// https://atcoder.jp/contests/agc032/tasks/agc032_a
public class LimitedInsertion {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Integer> operations = new ArrayList<>();
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            b[i] = sc.nextInt();
        }
        for (int i = 1; i <= n; i++) {
            int lower = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (b[j] == i) {
                    if (i + lower - 1 <= operations.size()) {
                        operations.add(i + lower - 1, b[j]);
                    } else {
                        System.out.println(-1);
                        return;
                    }
                }
                if (b[j] <= i) {
                    lower++;
                }
            }
        }
        for (int i : operations) {
            System.out.println(i);
        }
    }
}

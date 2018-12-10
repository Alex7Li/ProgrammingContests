package misc.googlecontest;

import java.util.Scanner;

// https://code.google.com/codejam/contest/1460488/dashboard#s=p1
public class DancingWithTheGooglers {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int cases = sc.nextInt();
        for (int t = 0; t < cases; t++) {
            int n = sc.nextInt();
            int s = sc.nextInt();
            int minBest = sc.nextInt();
            //count how many could have better than minBest
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
            int count = 0;
            for (int i = 0; i < n; i++) {
                if ((a[i] + 2) / 3 >= minBest) {
                    count++;
                } else if ((a[i] + 2) / 3 == minBest - 1 && a[i] % 3 != 1 && a[i] != 0) {
                    if (s > 0) {
                        s--;
                        count++;
                    }
                }
            }
            System.out.println("Case #" + (t + 1) + ": " + count);
        }
    }
}

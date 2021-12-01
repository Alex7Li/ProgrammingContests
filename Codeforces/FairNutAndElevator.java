package codeforces;

import java.util.Arrays;
import java.util.Scanner;

//https://codeforces.com/contest/1084/problem/A
public class FairNutAndElevator {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        int[] a = Arrays.stream(sc.nextLine().split(" ")).mapToInt((x -> Integer.parseInt(x))).toArray();
        int best = Integer.MAX_VALUE;
        for (int x = 0; x < n; x++) {
            int cur = 0;
            for (int i = 0; i < a.length; i++) {
                cur += 4 * Math.max(x, i) * a[i];
            }
            if (cur < best) {
                best = cur;
            }
        }
        System.out.println(best);
        sc.close();
    }
}

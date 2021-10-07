package codeforces;

import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

//https://codeforces.com/problemset/problem/1106/C
public class LunarNewYearAndNumberDivision {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        int[] a = Arrays.stream(sc.nextLine().split(" "))
                .mapToInt(x -> Integer.parseInt(x)).toArray();
        Arrays.sort(a);
        long cost = 0;
        for (int i = 0; i < n / 2; i++) {
            cost += (a[i] + a[n - i - 1]) * (a[i] + a[n - i - 1]);
        }
        System.out.println(cost);
    }
}

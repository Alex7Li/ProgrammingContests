package misc.constructive;

import java.io.IOException;
import java.util.Scanner;
//https://codeforces.com/contest/1158/problem/B
public class MinimalUniqueSubstring {
public static void main(String[] xx) throws IOException {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int k = sc.nextInt();
    StringBuilder sb = new StringBuilder();
    int diff = 1 + (n - k) / 2;
    for (int i = 0; i < n; i++) {
        if ((i+1) % diff == 0) {
            sb.append(1);
        } else {
            sb.append(0);
        }
    }
    System.out.println(sb);
}
}

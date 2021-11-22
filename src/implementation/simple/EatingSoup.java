package implementation.simple;

import java.io.IOException;
import java.util.Scanner;

//https://codeforces.com/contest/1163/problem/A
public class EatingSoup {
public static void main(String[] xx) throws IOException {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int m = sc.nextInt();
    System.out.println(Math.min(
            Math.max(1, m), n - m));
}
}

package core.dp;

import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

// https://naq15.kattis.com/problems/safepassage
// UHHH it's O(N) but the constraint is N<=15
public class SafePassage {
public static void main(String[] xx) throws IOException {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] a = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = sc.nextInt();
    }
    Arrays.sort(a);
    // cost[i] = cost to transport the fastest i people only
    int[] cost = new int[a.length];
    // send the fastest 2 down
    cost[1] = a[1];
    // we can prove that the 3rd fastest or slower will never go back
    for (int i = 2; i < a.length; i++) {
        cost[i] = Math.min(cost[i-1]+a[0]+a[i], // send fastest back, send fastest up with slowest
                cost[i-2] + 2*a[1]+a[0]+a[i]); // send fastest 2 back, slowest 2 up, fastest back, 2nd fastest up
    }
    System.out.println(cost[a.length-1]);
}
}

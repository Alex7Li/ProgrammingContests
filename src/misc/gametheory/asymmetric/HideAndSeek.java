package misc.gametheory.asymmetric;

import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

//http://codeforces.com/contest/1161/problem/A
public class HideAndSeek {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        sc.nextLine();
        int[] x = Arrays.stream(sc.nextLine().split(" "))
                .mapToInt(y -> Integer.parseInt(y)).toArray();
        boolean[][] seen = new boolean[n + 2][3];
        for (int i = 0; i < x.length; i++) {
            int nxt = x[i];
            seen[nxt][1] = true;
            if (seen[nxt - 1][1]) {
                seen[nxt][0] = true;
            }
            if (seen[nxt + 1][1]) {
                seen[nxt][2] = true;
            }
        }
        seen[1][0] = true;
        seen[n][2] = true;
        int count = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 3; j++) {
                if (!seen[i][j]) {
                    count++;
                }
            }
        }
        System.out.println(count);
    }
}

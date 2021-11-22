package codeforces;

import java.io.IOException;
import java.util.Scanner;

// https://codeforces.com/problemset/problem/1108/C
public class NiceGarland {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        char[] garland = sc.nextLine().toCharArray();
        char[][] perms = {{'B', 'R', 'G'}, {'B', 'G', 'R'}, {'R', 'B', 'G'}, {'R', 'G', 'B'}, {'G', 'R', 'B'}, {'G', 'B', 'R'}};
        int best = Integer.MAX_VALUE;
        int cur = 0;
        char [] bestPerm = new char[3];
        for (char[] perm : perms) {
            cur = 0;
            for (int i = 0; i < n; i++) {
                if (garland[i] != perm[i % 3]) {
                    cur++;
                }

            }
            if (cur < best){
                best = cur;
                bestPerm = perm;
            }
        }
        System.out.println(best);
        for(int i = 0; i < n; i++){
            System.out.print(bestPerm[i % 3]);
        }
        System.out.println();
    }
}

package codeforces;

import java.io.*;
import java.util.Scanner;
//https://codeforces.com/gym/100299
public class Crane {
    private static int[] perm;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        int cases = sc.nextInt();
        for (int t = 0; t < cases; t++) {
            int n = sc.nextInt();
            perm = new int[n];
            for (int i = 0; i < n; i++) {
                perm[i] = sc.nextInt();
            }
            StringBuilder moves = new StringBuilder();
            int moveCount = 0;
            for (int i = 0; i < n; i++) {
                int iLoc = 0;
                for (int j = i; j < n; j++) {
                    if (perm[j] == i + 1) {
                        iLoc = j;
                        break;
                    }
                }
                while (iLoc != i) {
                    int r = Math.min(n, i + 2 * (iLoc - i));
                    if ((r - i) % 2 == 0) {
                        moves.append((i + 1) + " " + r + System.lineSeparator());
                        iLoc = swapInterval(i, r, iLoc);
                    } else {
                        moves.append((i + 2) + " " + r + System.lineSeparator());
                        iLoc = swapInterval(i + 1, r, iLoc);
                    }
                    moveCount++;
                }
            }
            pw.println(moveCount);
            pw.print(moves);
            pw.flush();
        }
        pw.close();
    }

    //crane [l,r) l-r is even. return new position of element at iPos
    public static int swapInterval(int l, int r, int iPos) {
        int len = (r - l) / 2;
        for (int i = l; i < l + len; i++) {
            int temp = perm[i];
            perm[i] = perm[i + len];
            perm[i + len] = temp;
        }
        if (iPos >= l + len) {
            return iPos - len;
        } else {
            return iPos + len;
        }
    }
}

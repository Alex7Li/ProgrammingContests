package misc.gametheory.twoplayer;

import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

// https://naq15.kattis.com/problems/cuttingbrownies
public class CuttingBrownies {
// grundy number, assuming first player is H
private static int[][] grundy = new int[500][500];

public static void main(String[] xx) throws IOException {
    for (int[] a : grundy) {
        Arrays.fill(a, -1);
    }
    Scanner sc = new Scanner(System.in);
    int n = Integer.parseInt(sc.nextLine());
    for (int i = 0; i < n; i++) {
        String[] args = sc.nextLine().split(" ");
        int w = Integer.parseInt(args[0]);
        int h = Integer.parseInt(args[1]);
        boolean canWin;
        if (args[2].equals("Harry")) {
            canWin = getWinner(w, h);
        } else {
            canWin = getWinner(h, w);
        }
        System.out.println(args[2] + " can" + (canWin ? "" : "not") + " win");
    }
}

// if Harry wins, assuming he goes first
private static boolean getWinner(int w, int h) {
    while (true) {
        if (h == 1) {
            return false;
        }
        h /= 2;
        if (w == 1) {
            return true;
        }
        w /= 2;
    }
}
}

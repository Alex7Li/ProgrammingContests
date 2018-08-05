package codeforces;

import java.util.Arrays;
import java.util.Scanner;

//http://codeforces.com/contest/991/problem/D
public class Bishwock {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[] p1 = sc.nextLine().toCharArray();
        char[] p2 = sc.nextLine().toCharArray();
        char[][] pawns = new char[2][p1.length];
        pawns[0] = p1;
        pawns[1] = p2;
        if (p1.length == 1) {
            System.out.println(0);
            return;
        }
        //0 1 2 3
        //o o x x
        //o x o x
        int[] lastDP = {-1, -1, -1, 0};
        for (int i = 0; i < p1.length; i++) {
            int[] nextDP = {-1,-1,-1,-1};
            int pos = 0;
            if ((pawns[0][i] == 'X')) {
                pos += 2;
            }
            if ((pawns[1][i] == 'X')) {
                pos += 1;
            }
            // if you decide to add no block
            for (int j : lastDP) {
                nextDP[pos] = Math.max(nextDP[pos], j);
            }
            // if you add a block
            if (lastDP[0] != -1) {
                if (pos <= 2) {
                    nextDP[3] = Math.max(nextDP[3], lastDP[0] + 1);
                }
                if(pos ==0){
                    nextDP[1] = Math.max(nextDP[1], lastDP[0] + 1);
                    nextDP[2] = Math.max(nextDP[2], lastDP[0] + 1);
                }
            }
            if (lastDP[1] != -1) {
                if (pos == 0) {
                    nextDP[3] = Math.max(nextDP[3], lastDP[1] + 1);
                }
            }
            if (lastDP[2] != -1) {
                if (pos == 0) {
                    nextDP[3] = Math.max(nextDP[3], lastDP[2] + 1);
                }
            }
            lastDP = nextDP;
        }
        System.out.println(Arrays.stream(lastDP).max().getAsInt());
    }
}

package math.combinatorics;

import java.io.IOException;
import java.util.Scanner;

//https://naq15.kattis.com/problems/countcircuits
public class CircuitCounting {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] coordinates = new int[n][2];
        for (int i = 0; i < n; i++) {
            coordinates[i][0] = sc.nextInt();
            coordinates[i][1] = sc.nextInt();
        }
        int zero = 1 + 10 * (n / 2); // the index in ways that represents zero
        int[][] ways = new int[zero + 10 * (n / 2)][zero + 10 * (n / 2)];
        for (int i = 0; i < (1 << (n / 2)); i++) {
            int xCoord = 0;
            int yCoord = 0;
            for (int j = 0; j < n / 2; j++) {
                if ((i & (1 << j)) != 0) {
                    xCoord += coordinates[j][0];
                    yCoord += coordinates[j][1];
                }
            }
            ways[zero + xCoord][zero + yCoord]++;
        }
        long tWays = 0;
        for (int i = 0; i < (1 << (n - n / 2)); i++) {
            int xCoord = 0;
            int yCoord = 0;
            for (int j = 0; j < (n - n / 2); j++) {
                if ((i & (1 << j)) != 0) {
                    xCoord += coordinates[n / 2 + j][0];
                    yCoord += coordinates[n / 2 + j][1];
                }
            }
            tWays += ways[zero - xCoord][zero - yCoord];
        }
        // subtract the empty set
        System.out.println(tWays - 1);
    }
}

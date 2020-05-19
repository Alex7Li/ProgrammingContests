package medium.standard;

import java.util.Scanner;
//https://open.kattis.com/contests/j47tpb/problems/freeweights
public class FreeWeights {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        int[] top = new int[n];
        int[] bot = new int[n];
        for (int i = 0; i < n; i++) {
            top[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            bot[i] = sc.nextInt();
        }
        System.out.println(Math.max(maxOfRow(top), maxOfRow(bot)));
    }

    private static int maxOfRow(int[] row){
        int heaviest = 0;
        int heaviestUnpaired = 0;
        for (int value : row) {
            if (value <= heaviest) {
                continue;
            }
            if (heaviestUnpaired == 0) {
                heaviestUnpaired = value;
            } else {
                if (value == heaviestUnpaired) {
                    heaviestUnpaired = 0;
                } else if (value > heaviestUnpaired) {
                    heaviest = heaviestUnpaired;
                    heaviestUnpaired = value;
                } else {
                    heaviest = value;
                }
            }
        }
        heaviest = Math.max(heaviestUnpaired, heaviest);
        return heaviest;
    }
}

package codeforces;

import java.util.Scanner;

public class VeraAndABCDE {
    private static int[][] A = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}, {1, 0, 1}, {1, 0, 1}};
    private static int[][] B = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    private static int[][] C = {{1, 1, 1}, {1, 0, 0}, {1, 0, 0}, {1, 0, 0}, {1, 1, 1}};
    private static int[][] D = {{1, 1, 1}, {1, 0, 1}, {1, 0, 1}, {1, 0, 1}, {1, 1, 1}};
    private static int[][] E = {{1, 1, 1}, {1, 0, 0}, {1, 1, 1}, {1, 0, 0}, {1, 1, 1}};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        char[] letters = sc.nextLine().toCharArray();
        for (int i = 0; i < 5; i++) {
            for (int l = 0; l < n; l++) {
                for (int j = 0; j < 3; j++) {
                    switch (letters[l]){
                        case 'A': {
                            System.out.print(A[i][j] == 0 ? '.' : '*');
                            break;
                        }
                        case 'B': {
                            System.out.print(B[i][j] == 0 ? '.' : '*');
                            break;
                        }
                        case 'C':{
                            System.out.print(C[i][j]==0?'.':'*');
                            break;
                        }
                        case 'D':{
                            System.out.print(D[i][j]==0?'.':'*');
                            break;
                        }
                        case 'E':{
                            System.out.print(E[i][j]==0?'.':'*');
                            break;
                        }
                    }
                }
            }
            System.out.println();
        }
    }
}
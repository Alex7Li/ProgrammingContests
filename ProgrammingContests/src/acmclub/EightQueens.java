package acmclub;

import java.util.Scanner;

public class EightQueens {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		boolean[][] hasQueen = new boolean[8][8];
		int queens = 0;
		for (int i = 0; i < hasQueen.length; i++) {
			char[] row = sc.nextLine().toCharArray();
			for (int j = 0; j < hasQueen[0].length; j++) {
				if (row[j] == '*') {
					hasQueen[i][j] = true;
					queens++;
				}
			}
		}
		sc.close();
		boolean valid = true;
		if (queens != 8) {
			valid = false;
		}
		for (int i = 0; i < hasQueen.length; i++) {
			boolean queenFoundInRow = false;
			boolean queenFoundInCol = false;
			for (int j = 0; j < hasQueen[0].length; j++) {
				if (hasQueen[i][j]) {
					if (queenFoundInRow) {
						valid = false;
					} else {
						queenFoundInRow = true;
					}
				}
				if (hasQueen[j][i]) {
					if (queenFoundInCol) {
						valid = false;
					} else {
						queenFoundInCol = true;
					}
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			if (valid) {
				valid = checkTopRightDiagonals(hasQueen);
				rotate90Degrees(hasQueen);
			}
		}
		if (valid) {
			System.out.println("valid");
		} else {
			System.out.println("invalid");
		}
	}

	/**
	 * @requires a is a square matrix
	 */
	private static void rotate90Degrees(boolean[][] a) {
		// flipped over topright to botleft diagonal
		boolean[][] aFlipped = new boolean[a.length][a.length];
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a.length; j++) {
				aFlipped[i][j] = a[j][i];
			}
		}
		// now store in a aFlipped, flipped over it's horizontal midline
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a.length / 2; j++) {
				a[i][j] = aFlipped[i][a.length - j - 1];
				a[i][a.length - j - 1] = aFlipped[i][j];
			}
		}
	}

	private static boolean checkTopRightDiagonals(boolean[][] hasQueen) {
		for (int i = 0; i < 8; i++) {
			boolean queenFound = false;
			for (int j = 0; j <= i; j++) {
				if (hasQueen[j][i - j]) {
					if (queenFound) {
						return false;
					} else {
						queenFound = true;
					}
				}
			}
		}
		return true;
	}
}

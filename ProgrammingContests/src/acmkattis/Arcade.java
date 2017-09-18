package acmkattis;

import java.util.Scanner;

public class Arcade {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int h = n * (n + 1) / 2;
		int[] payouts = new int[h];
		for (int i = 0; i < h; i++) {
			payouts[i] = s.nextInt();
		}
		double[][] probabilites = new double[h][5];
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < 5; j++) {
				probabilites[i][j] = s.nextDouble();
			}
		}
		s.close();
		double[][] coefficents = new double[h][h];
		double[] solutions = new double[h];
		for (int i = 0; i < solutions.length; i++) {
			solutions[i] = probabilites[i][4] * payouts[i];
		}
		int curRow = 1;
		int curCol = 1;
		for (int i = 0; i < coefficents.length; i++) {
			coefficents[i][i] = 1;
			// top-left
			if (curCol != 1) {
				coefficents[i][i - curRow] = -probabilites[i][0];
			}
			// top-right
			if (curCol != curRow) {
				coefficents[i][i - curRow + 1] = -probabilites[i][1];
			}
			if (curRow != n) {
				// bottom-left
				coefficents[i][i + curRow] = -probabilites[i][2];
				// bottom-right
				coefficents[i][i + curRow + 1] = -probabilites[i][3];
			}
			if (curRow == curCol) {
				curRow++;
				curCol = 1;
			} else {
				curCol++;
			}
		}
		double[] Ex = GaussianElim(coefficents, solutions);
		System.out.println(Ex[0]);
	}

	private static double[] GaussianElim(double[][] coefficients, double[] solutions) {
		double[] Ex = new double[solutions.length];
		for (int curRow = 1; curRow < solutions.length; curRow++) {
			for (int i = 0; i < curRow; i++) {
				if (Math.abs(coefficients[curRow][i]) > 0.00001) { // nonzero
					double f = coefficients[curRow][i]/coefficients[i][i];
					coefficients[curRow] = minus(coefficients[curRow], coefficients[i], f);
					solutions[curRow] = solutions[curRow] - solutions[i]*f;
					assert(Math.abs(coefficients[curRow][curRow-1]) < 0.00001);
				}
			}
		}
		// fill in Ex array
		for (int row = Ex.length - 1; row >= 0; row--) {
			Ex[row] = solutions[row]/coefficients[row][row];
			for (int i = 0; i < row; i++) {
				solutions[i]-=coefficients[i][row]*Ex[row];
			}
		}
		return Ex;
	}

	/**
	 * @return a-b*scalar
	 */
	private static double[] minus(double[] a, double[] b, double scalar) {
		for (int i = 0; i < b.length; i++) {
			a[i] = a[i] - b[i] * scalar;
		}
		return a;
	}
}

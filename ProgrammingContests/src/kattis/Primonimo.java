package kattis;

//https://open.kattis.com/problems/primonimo
import java.util.ArrayList;
import java.util.Scanner;

public class Primonimo {
	private static boolean solved = true;

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int m = s.nextInt();
		int p = s.nextInt();
		int[][] grid = new int[n][m];
		for (int i = 0; i < grid.length; i++) {
			for (int j = 0; j < grid[0].length; j++) {
				grid[i][j] = s.nextInt() - 1;
			}
		}
		s.close();
		// System of n*m equations!!
		int[][] coeff = new int[n * m][n * m];
		int[] solutions = new int[n * m];
		for (int pos = 0; pos < n * m; pos++) {
			solutions[pos] = ((p - 1) - grid[pos / m][pos % m]);
			for (int i = 0; i < m; i++) {
				coeff[(pos / m) * m + i][pos] = 1;
			}
			for (int i = 0; i < n; i++) {
				coeff[m * i + pos % m][pos] = 1;
			}
		}
		int[] ans = gauss(coeff, solutions, p);
		if (solved) {
			ArrayList<Integer> moves = new ArrayList<Integer>();
			for (int i = 0; i < ans.length; i++) {
				for (int j = 0; j < ans[i]; j++) {
					moves.add(i + 1);
				}
			}
			System.out.println(moves.size());
			for (int i = 0; i < moves.size(); i++) {
				System.out.print(moves.get(i) + " ");
			}
			System.out.println();
		} else {
			System.out.println(-1);
		}
	}

	/**
	 * Returns solutions to a system of equations mod p
	 * 
	 * @return
	 */
	private static int[] gauss(int[][] c, int[] s, int p) {
		int[] modInv = modInv(p);
		int[] solutions = new int[s.length];
		for (int i = 0; i < c.length; i++) {
			//print(c,s);
			// find highest value in this column on or under this row
			int maxRowIndex = i;
			int maxVal = c[i][i];
			for (int j = i + 1; j < c[0].length; j++) {
				if (maxVal < c[j][i]) {
					maxVal = c[j][i];
					maxRowIndex = j;
				}
			}
			// swap max row with current row
			int[] temp = c[i];
			c[i] = c[maxRowIndex];
			c[maxRowIndex] = temp;
			int temp2 = s[i];
			s[i] = s[maxRowIndex];
			s[maxRowIndex] = temp2;
			// make all rows in the column below this 0.
			int n = c[i][i];
			for (int j = i + 1; j < c[0].length; j++) {
				// Let K and N be integer constants. Subtract
				// c[i]*K*(N)^-1 from c[j] such that c[i][j] == 0
				int k = c[j][i];
				int factor = (k * modInv[n]) % p;
				for (int l = 0; l < c.length; l++) {
					c[j][l] -= c[i][l] * factor;
					c[j][l] = ((c[j][l]) % p + p) % p;
					if (l == i) {
						assert c[j][l] == 0;
					}
				}
				s[j] -= s[i] * factor;
				s[j] = (s[j] % p + p) % p;
			}
		}
		//print(c,s);
		// reverse solve
		for (int i = c[0].length - 1; i >= 0; i--) {
			for (int j = i + 1; j < c.length; j++) {
				s[i] -= (c[i][j] * solutions[j]);
				s[i] = (s[i] % p + p) % p;
			}
			if (c[i][i] == 0) {
				if (s[i] != 0) {
					solved = false;
					return null;
				} else {
					solutions[i] = 0;
				}
			} else {
				solutions[i] = (s[i]*modInv[c[i][i]])%p;
			}
		}
		return solutions;
	}

	@SuppressWarnings("unused")
	private static void print(int[][] c, int[] s) {
		for (int i = 0; i < s.length; i++) {
			for (int j = 0; j < s.length; j++) {
				System.err.print(c[i][j] + " ");
			}
			System.err.println("= " + s[i]);
		}
		System.err.println();
	}

	/**
	 * Fills array with modular inverses mod p
	 * 
	 * @param n
	 * @param p
	 * @return
	 */
	private static int[] modInv(int p) {
		int[] inverses = new int[p];
		for (int i = 1; i < p; i++) {
			int j = 1;
			while ((i * j) % p != 1) {
				j++;
			}
			inverses[i] = j;
		}
		return inverses;
	}
}

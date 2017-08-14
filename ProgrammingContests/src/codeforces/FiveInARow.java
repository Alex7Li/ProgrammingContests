package codeforces;
import java.util.Scanner;

/**
 * 
 */

/**
 * @author 7Alex
 *
 */
public class FiveInARow {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		char[][] grid = new char[10][10];
		for (int i = 0; i < grid.length; i++) {
			grid[i] = s.nextLine().toCharArray();
		}
		s.close();
		if(canWin(grid)){
			System.out.println("YES");
		}else {
			System.out.println("NO");
		}
	}

	/**
	 * @param grid
	 */
	private static boolean canWin(char[][] grid) {
		for (int i = 0; i < grid.length; i++) {
			for (int j = 0; j < 6; j++) {
				if (FourofFive(grid[i][j], grid[i][j + 1], grid[i][j + 2], grid[i][j + 3], grid[i][j + 4])) {
					return true;
				}
			}
		}
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < grid.length; j++) {
				if (FourofFive(grid[i][j], grid[i + 1][j], grid[i + 2][j], grid[i + 3][j], grid[i + 4][j])) {
					return true;
				}
			}
		}
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				if (FourofFive(grid[i][j], grid[i + 1][j + 1], grid[i + 2][j + 2], grid[i + 3][j + 3],
						grid[i + 4][j + 4])) {
					return true;
				}
			}
		}
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				if (FourofFive(grid[i + 4][j], grid[i + 3][j + 1], grid[i + 2][j + 2], grid[i + 1][j + 3],
						grid[i][j + 4])) {
					return true;
				}
			}
		}
		return false;
	}

	private static boolean FourofFive(char a, char b, char c, char d, char e) {
		if (a + b + c + d + e == 398) {
			return true;
		} else {
			return false;
		}
	}
}

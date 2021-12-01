package codeforces;
import java.util.Scanner;

//http://codeforces.com/contest/980/problem/B
public class Marlin {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		boolean[][] grid = new boolean[4][n];
		if (k % 2 == 1) {
			grid[2][(n - 1) / 2] = true;
			k--;
		}
		int curPos = 0;
		while (k != 0) {
			if (1 + (curPos / 2) != n - 2 - (curPos / 2)) {
				grid[1 + (curPos % 2)][1 + (curPos / 2)] = true;
				grid[1 + (curPos % 2)][n - 2 - (curPos / 2)] = true;
			} else {
				grid[1][1 + (curPos / 2)] = true;
				grid[2][1 + (curPos / 2)] = true;
			}
			k -= 2;
			curPos++;
		}
		System.out.println("YES");
		for (int i = 0; i < grid.length; i++) {
			for (int j = 0; j < grid[0].length; j++) {
				if (!grid[i][j]) {
					System.out.print(".");
				} else {
					System.out.print("#");
				}
			}
			System.out.println();
		}
		sc.close();
	}
}

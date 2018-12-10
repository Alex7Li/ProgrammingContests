package misc.aoc;
//http://adventofcode.com/2017/day/3

import java.util.Scanner;

public class AOC2017Day3 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int st = 7;
		int size = 15;
		int[][] a = new int[size][size];
		a[st][st] = 1;
		int curX = st;
		int curY = st;
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 1 + 2 * i; j++) {
				curX++;
				a[curX][curY] = a[curX - 1][curY + 1] + a[curX][curY + 1] + a[curX + 1][curY + 1] + a[curX - 1][curY]
						+ a[curX + 1][curY] + a[curX - 1][curY - 1] + a[curX][curY - 1] + a[curX + 1][curY - 1];
			}
			for (int j = 0; j < 1 + 2 * i; j++) {
				curY--;
				a[curX][curY] = a[curX - 1][curY + 1] + a[curX][curY + 1] + a[curX + 1][curY + 1] + a[curX - 1][curY]
						+ a[curX + 1][curY] + a[curX - 1][curY - 1] + a[curX][curY - 1] + a[curX + 1][curY - 1];
			}
			for (int j = 0; j < 2 + 2 * i; j++) {
				curX--;

				a[curX][curY] = a[curX - 1][curY + 1] + a[curX][curY + 1] + a[curX + 1][curY + 1] + a[curX - 1][curY]
						+ a[curX + 1][curY] + a[curX - 1][curY - 1] + a[curX][curY - 1] + a[curX + 1][curY - 1];
			}
			for (int j = 0; j < 2 + 2 * i; j++) {
				curY++;
				a[curX][curY] = a[curX - 1][curY + 1] + a[curX][curY + 1] + a[curX + 1][curY + 1] + a[curX - 1][curY]
						+ a[curX + 1][curY] + a[curX - 1][curY - 1] + a[curX][curY - 1] + a[curX + 1][curY - 1];
			}
		}
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[0].length; j++) {
				System.out.print(a[j][i] + " ");
			}
			System.out.println();
		}
		s.close();
	}
}

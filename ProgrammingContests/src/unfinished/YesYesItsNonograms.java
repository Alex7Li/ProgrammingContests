package unfinished;

import java.util.Scanner;

//https://ecna16.kattis.com/problems/ecna16.yesyes
public class YesYesItsNonograms {
	static char[][] grid;

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int m = s.nextInt();
		grid = new char[n][m];
		NLine[] rows = getRows(n, s);
		NLine[] cols = getRows(m, s);
		// initialize grid
		for (int i = 0; i < rows.length; i++) {
			for (int j = 0; j < cols.length; j++) {
				grid[i][j] = '?';
			}
		}
		for (int i = 0; i < rows.length; i++) {
			char[] row = grid[i];
			rows[i].solve(row);
		}
		for (int i = 0; i < cols.length; i++) {
			char[] col = new char[cols.length];
			for (int j = 0; j < cols.length; j++) {
				col[j] = grid[i][j];
			}
			cols[i].solve(col);
		}
	}

	private static NLine[] getRows(int n, Scanner s) {
		NLine[] rows = new NLine[n];
		for (int i = 0; i < rows.length; i++) {
			int num = s.nextInt();
			int[] vals = new int[num];
			for (int j = 0; j < num; j++) {
				vals[j] = s.nextInt();
			}
			rows[i] = new NLine(vals);
		}
		return rows;
	}
}

class NLine {
	int[] vals;
	int valSum;
	boolean done = false;

	public NLine(int[] v) {
		vals = v;
		valSum = 0;
		for (int i = 0; i < v.length; i++) {
			valSum += vals[i];
		}
	}

	public void solve(char[] line) {
		if (done) {
			return;
		}
		// check basic conditions
		int unsure = 0;
		for (int i = 0; i < line.length; i++) {
			if (line[i] == '?') {
				unsure++;
			}
		}
		if (unsure == 0) {// already solved
			done = true;
			return;
		}
		int[] spaces = new int[vals.length + 1];
		int df = 8 - valSum - vals.length + 1;
		for (int i = 1; i < spaces.length - 1; i++) {
			spaces[i] = 1;
		}
		spaces[spaces.length - 1] = df;
	}
	public boolean compatible(char[] line1,char[] line2) {
		for (int i = 0; i < line1.length; i++) {
			if(line1[i] != line2[i]) {
				if(line1[i] != '?' && line2[i] != '?') {
					return false;
				}
			}
		}
		return true;
	}
}
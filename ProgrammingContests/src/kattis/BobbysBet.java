package kattis;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BobbysBet {
	private static int[][] xCy = new int[11][11];
	private static int[] fact = new int[11];

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		fact[0] = 1;
		StringBuilder s = new StringBuilder("");

		for (int i = 0; i < n; i++) {
			String[] in = br.readLine().split(" ");
			int minVal = Integer.parseInt(in[0]);
			int sides = Integer.parseInt(in[1]);
			int x = Integer.parseInt(in[2]);
			int y = Integer.parseInt(in[3]);
			double exRet = pWin(minVal, sides, x, y) * Integer.parseInt(in[4]);
			if (exRet > 1) {
				s.append("yes\n");
			} else {
				s.append("no\n");
			}
		}
		System.out.println(s);
	}

	private static int comb(int x, int y) {
		if (xCy[x][y] == 0) {
			xCy[x][y] = fact(x) / (fact(y) * fact(x - y));
		}
		return xCy[x][y];
	}

	private static int fact(int n) {
		if (fact[n] == 0) {
			fact[n] = n * fact(n - 1);
		}
		return fact[n];
	}

	private static double pow(double a, int b) {
		if(b==0) {
			return 1;
		}
		if (b % 2 == 0) {
			return pow(a * a, b / 2);
		} else {
			return a * pow(a * a, b / 2);
		}
	}

	private static double pWin(int minVal, int sides, int x, int y) {
		double exWin = (double) (sides - minVal + 1) / sides;
		double p = 0;
		for (int i = x; i <= y; i++) {
			p += pow(exWin, i) * pow(1 - exWin, y - i) * comb(y, i);
		}
		return p;
	}

}

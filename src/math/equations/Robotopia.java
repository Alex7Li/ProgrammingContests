package math.equations;

import java.util.Scanner;

public class Robotopia {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int testCases = s.nextInt();
		for (int i = 0; i < testCases; i++) {
			int[] legs = new int[3];
			int[] arms = new int[3];
			for (int j = 0; j < 3; j++) {
				legs[j] = s.nextInt();
				arms[j] = s.nextInt();
			}
			System.out.println(getBotCount(legs, arms));
		}
		s.close();
	}

	private static String getBotCount(int[] eq1, int[] eq2) {
		int[] solutions = new int[0];
		for (int x = eq1[2] / eq1[0]; x >= 0; x--) {
			int yb = eq1[2] - x * eq1[0];
			assert yb>=0;
			if (yb % eq1[1] == 0) {
				int y = yb / eq1[1];
				if (eq2[0] * x + eq2[1] * y == eq2[2]) {
					int[] t = { x, y };
					if (solutions.length == 0) {
						solutions = t;
					} else {
						assert solutions[0] != x;
						return "?";
					}
				}
			}
		}
		if (solutions.length == 0) {
			return "?";
		} else {
			return solutions[0] + " " + solutions[1];
		}
	}
}
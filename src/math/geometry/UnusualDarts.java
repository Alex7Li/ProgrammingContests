package math.geometry;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

//https://open.kattis.com/problems/unusualdarts
public class UnusualDarts {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int testCases = Integer.parseInt(br.readLine());
		for (int i = 0; i < testCases; i++) {
			double[] xPoints = new double[7];
			double[] yPoints = new double[7];
			for (int j = 0; j < 7; j++) {
				String[] next = br.readLine().split(" ");
				xPoints[j] = Double.parseDouble(next[0]);
				yPoints[j] = Double.parseDouble(next[1]);
			}
			double p = Double.parseDouble(br.readLine());
			double area = Math.cbrt(p) * 4;
			int[] curPermutation = { 1, 2, 3, 4, 5, 6, 7 };
			while (!valid(xPoints, yPoints, area, curPermutation)
					& !curPermutation.equals(new int[] { 7, 6, 5, 4, 3, 2, 1 })) {
				// iterate through to next permutation
				// 1. Move last element to the first position before the
				// maximal decreasing sequence at the end
				for (int j = curPermutation.length - 1; j > 0; j--) {
					if (curPermutation[j] > curPermutation[j - 1]) {
						int temp = curPermutation[j - 1];
						curPermutation[j - 1] = curPermutation[curPermutation.length - 1];
						curPermutation[curPermutation.length - 1] = temp;
						// 2. Switch the decreasing sequence to an increasing sequence
						for (int k = j; k < (curPermutation.length + j) / 2; k++) {
							int temp2 = curPermutation[k];
							curPermutation[k] = curPermutation[curPermutation.length - 1];
							curPermutation[curPermutation.length - 1] = temp2;
						}
						break;
					}
				}
				for (int j = 0; j < curPermutation.length; j++) {
					System.out.print(curPermutation[j] + " ");
				}
				System.out.println();

			}
		}
	}

	private static boolean valid(double[] xPoints, double[] yPoints, double area, int[] order) {
		return false;
		// for given permutation of points, check if they are valid

	}
}

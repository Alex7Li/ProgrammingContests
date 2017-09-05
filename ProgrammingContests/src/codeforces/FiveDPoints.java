package codeforces;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class FiveDPoints {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		// store input into points array
		int n = Integer.parseInt(br.readLine());
		boolean[] good = new boolean[n];
		Arrays.fill(good, true);
		int[][] points = new int[n][5];
		for (int i = 0; i < n; i++) {
			String[] input = br.readLine().split(" ");
			for (int j = 0; j < 5; j++) {
				points[i][j] = Integer.parseInt(input[j]);
			}
		}
		// compare each point to find it's angle
		int count = n;
		for (int i = 0; i < points.length; i++) {
			for (int j = i + 1; j < points.length; j++) {
				for (int k = j + 1; k < points.length; k++) {
					if (good[j] && acute(j, i, k, points)) {
						good[j] = false;
						count--;
					}
					if (good[k] && acute(k, j, i, points)) {
						good[k] = false;
						count--;
					}
					if (good[i] && acute(i, j, k, points)) {
						good[i] = false;
						count--;
					}
				}
			}

		}
		StringBuilder s = new StringBuilder();
		s.append(count + "\n");
		for (int i = 0; i < good.length; i++) {
			if (good[i]) {
				s.append((1 + i) + "\n");
			}
		}
		System.out.print(s);
	}

	/**
	 * tests if 2 points are acute
	 **/
	public static boolean acute(int i, int j, int k, int[][] points) {
		int dot = 0;
		int[] iToj = new int[5];
		int[] iTok = new int[5];
		for (int l = 0; l < 5; l++) {
			iToj[l] = points[j][l] - points[i][l];
			iTok[l] = points[k][l] - points[i][l];
		}
		for (int p = 0; p < iToj.length; p++) {
			dot += iToj[p] * iTok[p];
		}
		return dot > 0;
	}
}

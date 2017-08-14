package codeforces;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BlackSquare {
	public static void main(String[] args) throws IOException {
		System.out.println(solve());
	}

	public static int solve() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] dimensions = br.readLine().split(" ");
		int height = Integer.parseInt(dimensions[0]);
		int width = Integer.parseInt(dimensions[1]);
		// farthest N,E,W,S points
		int N = height + 1;
		boolean Nset = false;
		int S = -1;
		int E = -1;
		int W = width + 1;
		char[][] grid = new char[height][width];
		for (int i = 0; i < height; i++) {
			char[] gridLine = br.readLine().toCharArray();
			grid[i] = gridLine;
			for (int j = 0; j < width; j++) {
				if (gridLine[j] == 'B') {
					if (Nset) {
						S = i;
					} else {
						N = i;
						Nset = true;
					}
					if (j < W) {
						W = j;
					}
					if (j > E) {
						E = j;
					}
				}
			}
		}
		if (!Nset) { // No black squares
			return 1;
		} else {
			int sideLength = Math.max(S - N + 1, E - W + 1);
			if (sideLength > Math.min(height, width)) {
				return -1;
			}
			// position of top left of black square
			int squareX = Math.min(W, width - sideLength);
			int squareY = Math.min(N, height - sideLength);
			int result = 0;
			for (int i = squareX; i < squareX + sideLength; i++) {
				for (int j = squareY; j < squareY + sideLength; j++) {
					if (grid[j][i] == 'W') {
						result++;
					}
				}
			}
			return result;
		}
	}
}

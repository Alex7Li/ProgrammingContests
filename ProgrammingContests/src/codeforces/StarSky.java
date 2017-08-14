package codeforces;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class StarSky {
	public static void main(String[] args) throws IOException {
		StringBuilder s = new StringBuilder();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] data = br.readLine().split(" ");
		int n = Integer.parseInt(data[0]);
		int views = Integer.parseInt(data[1]);
		int maxBright = Integer.parseInt(data[2]);
		// getting star array data
		// stars[initial brightness][x][y] = number of stars with that initial
		// brightness and x and y.
		int[][][] stars = new int[maxBright+1][101][101];
		for (int b = 0; b < stars.length; b++) {
			for (int x = 1; x < stars[0].length; x++) {
				for (int y = 1; y < stars[0][0].length; y++) {
					stars[b][x][y] = 0;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			String[] starData = br.readLine().split(" ");
			stars[Integer.parseInt(starData[2])][Integer.parseInt(starData[0])][Integer.parseInt(starData[1])]++;
		}
		// later: precalculating number of stars in rectangle [1,1] to [x,y]
		// with initial brightness b

		int[][][] brightnesses = new int[maxBright+1][101][101];
		for (int b = 0; b < brightnesses.length; b++) {
			for (int x = 1; x < brightnesses[0].length; x++) {
				for (int y = 1; y < brightnesses[0][0].length; y++) {
					brightnesses[b][x][y] = stars[b][x][y] + brightnesses[b][x - 1][y] + brightnesses[b][x][y - 1]
							- brightnesses[b][x - 1][y - 1];
				}
			}
		}
		for (int i = 0; i < views; i++) {
			int totalBrightness = 0;
			String[] viewData = br.readLine().split(" ");
			int time = Integer.parseInt(viewData[0]);
			int minX = Integer.parseInt(viewData[1]);
			int minY = Integer.parseInt(viewData[2]);
			int maxX = Integer.parseInt(viewData[3]);
			int maxY = Integer.parseInt(viewData[4]);
			for (int j = 0; j <= maxBright; j++) {
				int numStars = brightnesses[j][maxX][maxY] - 
						brightnesses[j][minX-1][maxY] -
						brightnesses[j][maxX][minY-1] + 
						brightnesses[j][minX-1][minY-1];
				totalBrightness += numStars*((time+j) % (maxBright + 1));
			}		
			s.append(totalBrightness + "\n");
		}
		System.out.println(s);
	}
}
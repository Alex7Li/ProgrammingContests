package core.dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class EdgyBaking {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int cases = Integer.parseInt(br.readLine());
		for (int i = 1; i <= cases; i++) {
			int[] params = Arrays.stream(br.readLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
			int n = params[0];
			int p = params[1];
			int[][] cookiez = new int[n][2];
			int basePerim = 0;
			for (int j = 0; j < n; j++) {
				cookiez[j] = Arrays.stream(br.readLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
				basePerim += 2*(cookiez[j][0]+cookiez[j][1]);
			}
			double bestCut = cut(cookiez,p-basePerim);
			System.out.println("Case #" + i + ": " + (bestCut+basePerim));
		}
	}

	private static double cut(int[][] cookies, int p) {
		double min = Double.POSITIVE_INFINITY;
		double max = 0;
		double best = 0;
		for (int i = 0; i < cookies.length; i++) {
			min=Math.min(min,2*(Math.min(cookies[i][0], cookies[i][1])));
			max+=2*(Math.hypot(cookies[i][0], cookies[i][1]));
		}
		if(min<=p && min>best) {
			best = min;
		}
		if(max<=p && max>best) {
			best = max;
		}
		if(min<=p && max>p) {
			best = p;
		}
		return best;
	}
}

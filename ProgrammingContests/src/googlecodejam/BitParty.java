package googlecodejam;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

//https://codejam.withgoogle.com/2018/challenges/0000000000007883/dashboard/000000000002fff6
public class BitParty {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int cases = Integer.parseInt(br.readLine());
		for (int i = 1; i <= cases; i++) {
			int[] params = Arrays.stream(br.readLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
			int r = params[0];
			int b = params[1];
			int c = params[2];
			int[][] cashiers = new int[c][3];
			for (int j = 0; j < c; j++) {
				cashiers[j] = Arrays.stream(br.readLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
			}
			long earliestTime = earliestTime(r, b, c, cashiers);
			System.out.println("Case #" + i + ": " + earliestTime);
		}
	}

	private static long earliestTime(int r, int b, int c, int[][] cashiers) {
		long minTime = 0;
		long maxTime = Long.MAX_VALUE / 2;
		long guessTime = (minTime + maxTime) / 2;
		while (maxTime > minTime) {
			guessTime = (minTime + maxTime) / 2;
			if (timeIsValid(cashiers, guessTime, r, b)) {
				maxTime = guessTime;
			} else {
				minTime = guessTime + 1;
			}
		}
		return minTime;
	}

	private static boolean timeIsValid(int[][] cashiers, long time, int r, int b) {
		long[] bits = new long[cashiers.length];
		for (int i = 0; i < cashiers.length; i++) {
			bits[i] = Math.min(((time - cashiers[i][2]) / cashiers[i][1]), cashiers[i][0]);
			bits[i] = Math.max(bits[i], 0);
		}
		Arrays.sort(bits);
		long max = 0;
		for (int i = 0; i < r; i++) {
			max += bits[cashiers.length - (i + 1)];
		}
		return max >= b;
	}
}

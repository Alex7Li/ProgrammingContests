package acmkattis;
import java.util.Arrays;
import java.util.Scanner;

public class AQuestionOfIngestion {
	// https://open.kattis.com/problems/ingestion
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int m = s.nextInt();
		s.nextLine();
		String nl = s.nextLine() + " 0 0 0 0";
		int[] a = Arrays.stream(nl.split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
		s.close();
		int length = (int) (Math.log(m) / Math.log(3.0 / 2.0) + 2);
		int[] mVals = new int[length];
		mVals[0] = m;
		for (int i = 1; i < mVals.length; i++) {
			mVals[i] = (mVals[i - 1] * 2) / 3;
		}
		int[][] dp = new int[n + 3][mVals.length];
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j < mVals.length - 1; j++) {
				if (dp[i][j] != 0 || j == 0) {
					if (dp[i + 1][j + 1] < dp[i][j] + Math.min(a[i], mVals[j])) {
						dp[i + 1][j + 1] = dp[i][j] + Math.min(a[i], mVals[j]);
					}
					//It's j-1, not just j!!!! 
					//This was very hard for me to notice for some reason, but I did it (:
					//...with a bit of cheating  :P
					if (j != 0 && dp[i + 1][j - 1] < dp[i][j]) {
						dp[i + 1][j - 1] = dp[i][j];
					}
					if (dp[i + 2][0] < dp[i][j]) {
						dp[i + 2][0] = dp[i][j];
					}
				}
			}
		}
		System.out.println(dp[n + 2][0]);
	}
}

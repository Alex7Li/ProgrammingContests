package math.combinatorics;
//https://www.codechef.com/ZCOPRAC/problems/ZCO15002
import java.util.Arrays;
import java.util.Scanner;

public class Variation {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int k = s.nextInt();
		s.nextLine();
		int[] a = Arrays.stream(s.nextLine().split(" ")).mapToInt(x->Integer.parseInt(x)).toArray();
		int[] numberWithVal = new int[100000002];
		for (int i = 0; i < n; i++) {
			numberWithVal[a[i]+1]++;
		}
		// there are dp[i] numbers less than or equal to i.
		int[] dp = new int[100000001];
		for (int i = 1; i < dp.length; i++) {
			dp[i] = dp[i - 1] + numberWithVal[i];
		}
		//plus all pairs, including with itself, no order
		long count = (long)(a.length)*a.length;
		for (int i : a) {
			i++;
			int top = Math.min(dp.length - 1, i + k - 1);
			int bot = Math.max(0, i - k);
			//minus all pairs that don't work (in range [i-k,i+k])
			count -= dp[top] - dp[bot];
		}
		count/=2;
		s.close();
		System.out.println(count);
	}
}

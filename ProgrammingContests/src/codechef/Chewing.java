package codechef;

import java.util.Arrays;
import java.util.Scanner;

//https://www.codechef.com/ZCOPRAC/problems/ZCO13003
public class Chewing {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int k = s.nextInt();
		s.nextLine();
		int[] a = Arrays.stream(s.nextLine().split(" ")).mapToInt(x->Integer.parseInt(x)).toArray();
		int[] numberWithVal = new int[1000001];
		for (int i = 0; i < n; i++) {
			numberWithVal[a[i]]++;
		}
		// there are dp[i] numbers less than or equal to i.
		int[] dp = new int[1000001];
		dp[0] = numberWithVal[0];
		for (int i = 1; i < dp.length; i++) {
			dp[i] = dp[i - 1] + numberWithVal[i];
		}
		long count = 0;
		for (int i : a) {
			if(i>=k) {
				continue;
			}else {
				count += dp[k-i-1];
				//can't be a pair with itself
				if(i<=k-i-1) {
					count--;
				}
			}
		}
		count/=2;
		s.close();
		System.out.println(count);
	}
}

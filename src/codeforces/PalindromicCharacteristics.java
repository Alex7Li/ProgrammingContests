package codeforces;
import java.util.Scanner;

public class PalindromicCharacteristics {
	//dp[l][r] is the maximum k such that the substring built from characters from l to r is k-palindrome.
	static int[][] dp;
	static StringBuilder sb;
	public static void main(String[] args) {
		//get input
		Scanner s = new Scanner(System.in);
		char[] str = s.nextLine().toCharArray();
		s.close();
		//set starting variables
		dp = new int[str.length][str.length];
		sb = new StringBuilder();
		//fill in dp
		//trivial values
		for (int l = 0; l < dp.length; l++) {
					dp[l][l] = 1;
		}
		int[] count = new int[str.length+1];
		count[1] += dp.length;
		//dynamic values
		for (int len = 2; len <= str.length; len++) {
			for (int l = 0; l <= str.length-len; l++) {
				int r = l + len - 1;
				if(str[r]==str[l] && (l + 1 > r - 1 || dp[l+1][r-1]!=0)) {
					dp[l][r] = 1+Math.min(dp[l][l+len/2-1],dp[r-len/2+1][r]);
				}
				for (int i = 1; i <= dp[l][r]; i++) {
					count[i]++;	
				}
			}
		}
		for (int i = 1; i <= str.length; i++) {
			sb.append(count[i] + " ");
		}
		System.out.println(sb);
	}
}

package codeforces;
import java.util.Scanner;
//http://codeforces.com/contest/940/problem/C

public class PhoneNumbers2 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		sc.nextLine();
		char[] str = sc.nextLine().toCharArray();
		sc.close();
		char[] ans = new char[k];
		int max = str[0];
		int min = str[0];
		for (int i = 0; i < str.length; i++) {
			max = Math.max(str[i], max);
			min = Math.min(str[i], min);

		}
		if (k <= n) {
			int l = str.length;
			for (int i = k - 1; i >= 0; i--) {
				if (str[i] != max) {
					l = i;
					break;
				}
			}
			int minOverl = max;
			for (int i = 0; i < str.length; i++) {
				if (str[i] > str[l]) {
					minOverl = Math.min(str[i], minOverl);
				}
			}
			for (int i = 0; i < l; i++) {
				ans[i] = str[i];
			}
			ans[l] = (char) minOverl;
			for (int i = l + 1; i < k; i++) {
				ans[i] = (char) min;
			}
		} else {// k>n
			for (int i = 0; i < n; i++) {
				ans[i] = str[i];
			}
			for (int i = n; i < k; i++) {
				ans[i] = (char) min;
			}
		}
		StringBuilder out = new StringBuilder();
		for (int i = 0; i < ans.length; i++) {
			out.append(ans[i]);
		}
		System.out.println(out);
	}
}

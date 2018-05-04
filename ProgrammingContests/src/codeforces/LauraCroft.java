package codeforces;
import java.util.Scanner;

//http://codeforces.com/contest/976/problem/B
public class LauraCroft {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		long k = sc.nextLong() + 1;
		sc.close();
		if (k <= n) {
			System.out.println(k + " 1");
			return;
		}
		k = k - n - 1;
		long rowsFromBot = k / (m - 1);
		long col = 0;
		if (rowsFromBot % 2 == 0) {
			col = 2 + (k % (m - 1));
		} else {
			col = m - (k % (m - 1));
		}
		long row = n - rowsFromBot;
		System.out.println(row + " " + col);
	}
}

package codeforces;
import java.util.Scanner;
//http://codeforces.com/contest/935/problem/A
public class FafaAndHisCompany {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int ans = 0;
		for (int i = 1; i < n; i++) {
			if (n % i == 0) {
				ans++;
			}
		}
		System.out.println(ans);
		sc.close();
	}
}

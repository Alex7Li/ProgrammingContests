package codeforces;
import java.util.Scanner;
//http://codeforces.com/contest/922/problem/B
public class MagicForest {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int count = 0;
		for (int c = 1; c <= n; c++) {
			for (int b = 1; b <= c; b++) {
				int a = c ^ b;
				if (a <= b && c < b + a) {
					count++;
				}
			}
		}
		sc.close();
		System.out.println(count);
	}
}

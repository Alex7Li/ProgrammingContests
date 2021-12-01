package codeforces;
import java.util.Scanner;

//http://codeforces.com/contest/898/problem/B
public class ProperNutrition {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a = sc.nextInt();
		int b = sc.nextInt();
		int max = n / b;
		sc.close();
		for (int y = 0; y <= max; y++) {
			if ((n - (y * b)) % a == 0) {
				System.out.println("YES");
				int x = (n - y * b) / a;
				System.out.println(x + " " + y);
				return;
			}
		}
		System.out.println("NO");
	}
}

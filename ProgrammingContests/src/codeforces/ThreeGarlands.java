package codeforces;
import java.util.Arrays;
import java.util.Scanner;
//http://codeforces.com/contest/911/problem/C
public class ThreeGarlands {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] k = { sc.nextInt(), sc.nextInt(), sc.nextInt() };
		sc.close();
		if (1.0 / k[1] + 1.0 / k[2] + 1.0 / k[0] < .98) {
			System.out.println("NO");
		} else {
			Arrays.sort(k);
			if (k[1] == 2 || (k[0] == 2 && k[1] == 4 && k[2] == 4)) {
				System.out.println("YES");
			} else {
				for (int i = 0; i < k[0] * k[1] * k[2]; i++) {
					if (i % k[0] != 0 && (i - 1) % k[1] != 0 && (i - 2) % k[2] != 0) {
						System.out.println("NO");
						return;
					}
				}
				System.out.println("YES");
			}
		}
	}
}

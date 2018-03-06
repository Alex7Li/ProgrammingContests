package codeforces;
import java.util.Scanner;

//http://codeforces.com/problemset/problem/932/C
public class PermCycle {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a = sc.nextInt();
		int b = sc.nextInt();
		sc.close();
		for (int x = 0; x <= n / a; x++) {
			if ((n - a * x) % b == 0) {
				int y = (n - a * x) / b;
				if (y >= 0) {
					System.out.println(generatePerm(a, x, b, y, n));
					return;
				}
			}
		}
		System.out.println(-1);
	}

	private static String generatePerm(int a, int x, int b, int y, int n) {
		int[] perm = new int[n];
		for (int i = 0; i < perm.length; i++) {
			perm[i] = i;
		}
		for (int i = 0; i < x; i++) {
			makeCycle(i * a, (i + 1) * a - 1, perm);
		}
		for (int i = 0; i < y; i++) {
			makeCycle(i * b + a * x, (i + 1) * b + a * x - 1, perm);
		}
		StringBuilder out = new StringBuilder();
		for (int i = 0; i < perm.length - 1; i++) {
			out.append((perm[i] + 1) + " ");
		}
		out.append(perm[perm.length - 1] + 1);
		return out.toString();
	}

	private static void makeCycle(int i, int j, int[] perm) {
		int temp = perm[i];
		for (int x = i; x < j; x++) {
			perm[x] = perm[x + 1];
		}
		perm[j] = temp;
	}
}

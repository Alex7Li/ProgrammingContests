package codeforces;
import java.util.Scanner;

//http://codeforces.com/problemset/problem/932/B
public class RecursiveQueries {
	private static int[] f = new int[1000001];
	private static int[] g = new int[1000001];
	private static int[][] count = new int[1000001][10];

	public static void main(String[] args) {
		// precompute all f,g
		for (int i = 1; i < f.length; i++) {
			int ans = 1;
			int x = i;
			while (x > 0) {
				if (x % 10 != 0) {
					ans *= x % 10;
				}
				x /= 10;
			}
			f[i] = ans;
		}
		for (int x = 0; x < g.length; x++) {
			setG(x);
		}
		for (int i = 0; i < count[0].length; i++) {
			count[0][i] = 0;
		}
		for (int i = 1; i < count.length; i++) {
			for (int j = 0; j < count[0].length; j++) {
				count[i][j] = count[i - 1][j];
				if (g[i] == j) {
					count[i][j]++;
				}
			}
		}
		Scanner sc = new Scanner(System.in);
		int q = sc.nextInt();
		StringBuilder ans = new StringBuilder();
		for (int i = 0; i < q; i++) {
			int l = sc.nextInt();
			int r = sc.nextInt();
			int k = sc.nextInt();
			ans.append(count[r][k] - count[l - 1][k]);
			ans.append("\r\n");
		}
		System.out.println(ans);
		sc.close();
	}

	private static void setG(int x) {
		if (x < 10) {
			g[x] = x;
		} else {
			g[x] = g[f[x]];
		}
	}

}

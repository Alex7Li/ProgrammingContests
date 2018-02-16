package codechef;
import java.util.Scanner;
//https://www.codechef.com/KOL17ROL/problems/ZUBTRCNT
public class TriangleCount {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i = 1; i <= t; i++) {
			int l = sc.nextInt();
			int k = sc.nextInt();
			int ans = 0;
			for (int j = 1; j <= l - k + 1; j++) {
				ans += j;
			}
			System.out.println("Case " + i + ": " + ans);
		}
		sc.close();
	}
}

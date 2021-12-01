package codeforces;
import java.util.Scanner;

//http://codeforces.com/contest/937/problem/B
public class VileGrasshoppers {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int p = sc.nextInt();
		int y = sc.nextInt();
		int best = -1;
		for (int i = y; i > p; i--) {
			boolean pos = true;
			for (int j = 2; j <= p && j * j <= i; j++) {
				if (i % j == 0) {
					pos = false;
					break;
				}
			}
			if (pos) {
				best = i;
				break;
			}
		}

		System.out.println(best);
		sc.close();
	}
}

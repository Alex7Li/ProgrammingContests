package codeforces;
import java.util.Scanner;
//http://codeforces.com/contest/980/problem/A
public class LinksAndPearls {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		char[] c = sc.nextLine().toCharArray();
		int pearls = 0;
		for (int i = 0; i < c.length; i++) {
			if (c[i] == 'o') {
				pearls++;
			}
		}
		if (pearls == 0 || c.length % pearls == 0) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
		sc.close();
	}
}

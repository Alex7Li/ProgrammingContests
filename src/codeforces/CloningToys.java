package codeforces;
import java.util.Scanner;
//http://codeforces.com/contest/922/problem/A
public class CloningToys {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();
		int y = sc.nextInt();
		boolean ans = true;
		if (y == 0 || x + 1 < y || ((x + y) & 1) == 0) {
			ans = false;
		} else if (y == 1 && x != 0) {
			ans = false;
		}
		if (ans) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
		sc.close();
	}
}

package codeforces;
import java.util.Scanner;

//http://codeforces.com/contest/898/problem/A
public class Rounding {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		System.out.println(10 * ((s.nextInt() + 5) / 10));
		s.close();
	}
}

package codeforces;
import java.util.Scanner;

public class Segments {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();
		if (n % 2 == 1) {
			System.out.println(c2(n) - 2*c2(n / 2));
		} else {
			System.out.println(c2(n) - c2(n/2 - 1) - c2(n/2));

		}
	}

	public static int c2(int n) {
		return n * (n + 1) / 2;
	}
}

package codeforces;
import java.util.Scanner;

public class EhabAndMex {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int x = s.nextInt();
		int count = x;
		for (int i = 0; i < n; i++) {
			int a = s.nextInt();
			if (a == x) {
				count++;
			} else if (a < x) {
				count--;
			}
		}
		System.out.println(count);
		s.close();
	}
}

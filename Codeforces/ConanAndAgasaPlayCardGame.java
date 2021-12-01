package codeforces;
import java.util.Scanner;

//http://codeforces.com/contest/914/problem/B
public class ConanAndAgasaPlayCardGame {
	public static void main(String[] args) {
		int[] counts = new int[100001];
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for (int i = 0; i < n; i++) {
			int val = sc.nextInt();
			counts[val]++;
		}
		boolean conanWins = false;
		for (int i = counts.length - 1; i >= 0; i--) {
			if (counts[i] % 2 == 1) {
				conanWins = true;
				break;
			}
		}
		if (conanWins) {
			System.out.println("Conan");
		} else {
			System.out.println("Agasa");
		}
		sc.close();
	}
}

package codeforces;
import java.util.Scanner;
//http://codeforces.com/contest/948/problem/A
public class ProtectSheep {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		char[][] animals = new char[n][m];
		sc.nextLine();
		for (int i = 0; i < animals.length; i++) {
			animals[i] = sc.nextLine().toCharArray();
		}

		boolean possible = true;
		for (int i = 0; i < animals.length; i++) {
			for (int j = 0; j < animals[0].length; j++) {
				if (animals[i][j] == 'S') {
					if (i > 0 && animals[i - 1][j] == 'W') {
						possible = false;
					}
					if (i < n - 1 && animals[i + 1][j] == 'W') {
						possible = false;
					}
					if (j > 0 && animals[i][j - 1] == 'W') {
						possible = false;
					}
					if (j < m - 1 && animals[i][j + 1] == 'W') {
						possible = false;
					}
				}
			}
		}
		if (possible) {
			System.out.println("Yes");
			for (int i = 0; i < animals.length; i++) {
				StringBuilder sb = new StringBuilder();
				for (int j = 0; j < animals[i].length; j++) {
					if (animals[i][j] == '.') {
						sb.append('D');
					} else {
						sb.append(animals[i][j]);
					}
				}
				System.out.println(sb);
			}
		} else {
			System.out.println("No");
		}
		sc.close();

	}
}

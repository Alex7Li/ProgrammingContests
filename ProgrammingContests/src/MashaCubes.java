import java.util.Scanner;

public class MashaCubes {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int[][] cubes = new int[n][6];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 6; j++) {
				cubes[i][j] = s.nextInt();
			}
		}
		s.close();
		boolean[] canMake = new boolean[1000];
		// 1dig
		for (int i = 0; i < cubes.length; i++) {
			for (int j = 0; j < cubes[0].length; j++) {
				canMake[cubes[i][j]] = true;
			}
		}
		// 2dig
		for (int a = 0; a < n; a++) {
			for (int b = a + 1; b < n; b++) {
				for (int i = 0; i < 6; i++) {
					for (int j = 0; j < 6; j++) {
						canMake[10 * cubes[a][j] + cubes[b][i]] = true;
						canMake[10 * cubes[b][i] + cubes[a][j]] = true;
					}
				}
			}
		}
		// 3dig is impossible
		for (int i = 1; i < canMake.length; i++) {
			if (!canMake[i]) {
				System.out.println(i - 1);
				return;
			}
		}

	}
}

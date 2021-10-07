package codeforces;
import java.util.Arrays;
import java.util.Scanner;

//http://codeforces.com/problemset/problem/509/B
public class PaintingPebbles {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		sc.close();
		int min = Arrays.stream(a).min().getAsInt();
		int max = Arrays.stream(a).max().getAsInt();
		if (max > k + min) {
			System.out.println("NO");
		} else {
			System.out.println("YES");
			for (int i = 0; i < a.length; i++) {
				for (int j = 0; j < min; j++) {
					System.out.print(1 + " ");
				}
				for (int j = 0; j < a[i] - min; j++) {
					System.out.print(j+1 + " ");
				}
				System.out.println();
			}
		}
	}
}

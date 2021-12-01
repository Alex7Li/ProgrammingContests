package codeforces;
import java.util.Arrays;
import java.util.Scanner;

//http://codeforces.com/problemset/problem/920/A
public class WaterTheGarden {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int tests = sc.nextInt();
		for (int t = 0; t < tests; t++) {
			int n = sc.nextInt();
			int k = sc.nextInt();
			int[] taps = new int[k];
			int[] beds = new int[n];
			for (int i = 0; i < taps.length; i++) {
				taps[i] = sc.nextInt() - 1;
			}
			for (int i = 0; i < beds.length; i++) {
				beds[i] = Integer.MAX_VALUE;
				for (int j = 0; j < taps.length; j++) {
					beds[i] = Math.min(beds[i], Math.abs(i - taps[j]) + 1);
				}
			}
			System.out.println(Arrays.stream(beds).max().getAsInt());
		}
		sc.close();
	}
}

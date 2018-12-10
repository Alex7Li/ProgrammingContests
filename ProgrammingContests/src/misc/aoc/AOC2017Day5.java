package misc.aoc;

import java.util.Scanner;

public class AOC2017Day5 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int lines = 1033;
		int count = 0;
		int[] a = new int[1033];
		for (int i = 0; i < lines; i++) {
			a[i] = s.nextInt();
		}
		int curIndex = 0;
		while (curIndex < a.length) {
			if (a[curIndex] >= 3) {
				a[curIndex]--;
				curIndex += a[curIndex] + 1;
			} else {
				a[curIndex]++;
				curIndex += a[curIndex] - 1;
			}
			count++;
		}
		System.out.println(count);
		s.close();
	}
}

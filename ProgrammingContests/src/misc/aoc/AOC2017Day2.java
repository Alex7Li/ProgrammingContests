package misc.aoc;

import java.util.Arrays;
import java.util.Scanner;

//https://adventofcode.com/2017/day/2
public class AOC2017Day2 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int sum = 0;
		for (int i = 0; i < 16; i++) {
			String[] nl = s.nextLine().split("\t");
			int[] a = new int[nl.length];
			for (int j = 0; j < nl.length; j++) {
				a[j] = Integer.parseInt(nl[j]);
			}
			Arrays.sort(a);
			for (int j = 0; j < a.length; j++) {
				for (int k = j + 1; k < a.length; k++) {
					if (a[k] % a[j] == 0) {
						sum += a[k]/a[j];
						j = a.length;
						k = a.length;
					}
				}
			}
		}
		System.out.println(sum);
		s.close();
	}
}

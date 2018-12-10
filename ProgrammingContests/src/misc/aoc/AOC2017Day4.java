package misc.aoc;

import java.util.Arrays;
import java.util.Scanner;

public class AOC2017Day4 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int count = 512;
		for (int i = 0; i < 512; i++) {
			String[] a = s.nextLine().split(" ");
			for (int j = 0; j<a.length; j++) {
				 char[] x = a[j].toCharArray();
				 Arrays.sort(x);
				 String made = "";
				 for (char c:x) {
					made = made + c;
				}
				 a[j] = made;
			}
			for (int j = 0; j < a.length; j++) {
				for (int k = j + 1; k < a.length; k++) {
					if (a[j].equals(a[k])) {
						count--;
						j = a.length;
						k = a.length;
					}
				}
			}
		}
		System.out.println(count);
		s.close();
	}
}

package adventofcode;

import java.util.Scanner;

public class Template {
	// Line Counting Tool
	// https://www.tools4noobs.com/online_tools/count_lines/
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int lines = 0;
		int count = 0;
		for (int i = 0; i < lines; i++) {
			String[] inputLine = s.nextLine().split(" ");
			int[] a = new int[inputLine.length];
			for (int j = 0; j < a.length; j++) {
				a[j] = Integer.parseInt(inputLine[j]);
			}
			count++;

		}
		System.out.println(count);
		s.close();
	}
}

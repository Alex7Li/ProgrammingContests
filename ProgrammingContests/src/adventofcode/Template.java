package adventofcode;

import java.util.Arrays;
import java.util.Scanner;

public class Template {
	// Line Counting Tool
	// https://www.tools4noobs.com/online_tools/count_lines/
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int lines = 0;
		int count = 0;
		for (int i = 0; i < lines; i++) {
			int[] a = Arrays.stream(s.nextLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
			for (int j = 0; j < a.length; j++) {
				count++;
			}
		}
		System.out.println(count);
		s.close();
	}
}

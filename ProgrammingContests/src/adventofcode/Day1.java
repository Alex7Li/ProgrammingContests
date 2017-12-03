package adventofcode;

import java.util.Scanner;

//http://adventofcode.com/2017/day/1
public class Day1 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		char[] digits = s.nextLine().toCharArray();
		int sum = 0;
		if (digits[digits.length - 1] == digits[0]) {
			sum += Character.getNumericValue(digits[digits.length - 1]);
		}
		for (int i = 0; i < digits.length - 1; i++) {
			if (digits[i] == digits[i + 1]) {
				sum += Character.getNumericValue(digits[i]);
			}
		}
		System.out.println(sum);
		s.close();
	}

}

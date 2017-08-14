package codeforces;
import java.util.Scanner;

public class NumberOnBoard {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int k = s.nextInt();
		char[] n = s.next().toCharArray();
		s.close();
		int[] digitCount = new int[10];
		int totalSum = 0;
		for (int i = 0; i < n.length; i++) {
			digitCount[Character.getNumericValue(n[i])]++;
		}
		int differ = 0;
		for (int i = 0; i < digitCount.length; i++) {
			totalSum += i * digitCount[i];
		}
		int difference = k-totalSum;
		for (int i = 0; i < digitCount.length; i++) {
			if (difference - ((9-i) * digitCount[i]) > 0) {
				differ += digitCount[i];
				difference -= (9-i) * digitCount[i];
			} else {
				while(difference> 0) {
					difference -= (9-i);
					differ++;
				}
			}
		}
		System.out.println(differ);
	}
}

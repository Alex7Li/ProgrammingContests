package codeforces;
import java.util.Scanner;

public class PalindromicCharacteristicsRecursive {
	static int[] palindromes;

	public static void main(String[] args) {
		@SuppressWarnings("resource")
		char[] string = new Scanner(System.in).nextLine().toCharArray();
		palindromes = new int[string.length];
		getPalindromes(string);
		StringBuilder s = new StringBuilder();
		for (int i = 0; i < string.length; i++) {
			s.append(palindromes[i] + " ");
		}
		System.out.println(s);
	}

	private static void getPalindromes(char[] str) {
		for (int i = 0; i < str.length; i++) {
			for (int j = i + 1; j <= str.length; j++) {
				char[] string = new char[j - i];
				for (int k = i; k < j; k++) {
					string[k - i] = str[k];
				}
				int depth = testPalindrome(string, 0);
				for (int k = 0; k <= depth; k++) {
					palindromes[k]++;
				}
			}
		}
	}
	private static int testPalindrome(char[] str, int depth) {
		if (str.length / 2 == 0) {
			return depth;
		}
		char[] strLeft = new char[str.length / 2];
		char[] strRight = new char[str.length / 2];
		for (int k = 0; k < strLeft.length; k++) {
			strLeft[k] = str[k];
		}
		for (int k = str.length - 1; k >= str.length - strRight.length; k--) {
			int index = strRight.length + k - str.length;
			strRight[index] = str[k];
		}
		if (areSame(strRight, strLeft)) {
			return Math.min(testPalindrome(strRight, depth + 1), testPalindrome(strLeft, depth + 1));
		}
		return depth-1;
	}

	private static boolean areSame(char[] strRight, char[] strLeft) {
		boolean areSame = true;
		for (int k = 0; k < strRight.length; k++) {
			if (strLeft[k] != strRight[strRight.length - k - 1]) {
				areSame = false;
				break;
			}
		}
		return areSame;
	}
}

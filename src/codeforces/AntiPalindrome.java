package codeforces;

import java.util.Scanner;
//http://codeforces.com/contest/981/problem/0
public class AntiPalindrome {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		String word = s.nextLine();
		int maxLen = 0;
		for (int i = 0; i < word.length(); i++) {
			for (int j = i+1; j <= word.length(); j++) {
				if(j-i>maxLen && !isPalindrome(word.substring(i,j))){
					maxLen = j-i;
				}
			}
		}
		System.out.println(maxLen);
		s.close();
	}
	static boolean isPalindrome(String s){
		char[] c = s.toCharArray();
		for (int i = 0; i < s.length()/2; i++) {
			if(c[i]!=c[s.length()-i-1]){
				return false;
			}
		}
		return true;
	}
}
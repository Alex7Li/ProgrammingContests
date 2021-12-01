package codeforces;
import java.util.ArrayList;
import java.util.Scanner;

//http://codeforces.com/contest/864/problem/B
public class PolycarpaAndLetters {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		s.nextLine();
		char[] c = s.nextLine().toCharArray();
		s.close();;
		ArrayList<ArrayList<Character>> substrings = new ArrayList<ArrayList<Character>>();
		int maxLength = 0;
		ArrayList<Character> next = new ArrayList<Character>();
		for (int i = 0; i < c.length; i++) {
			if (Character.isUpperCase(c[i])) {
				substrings.add(next);
				// check to see if it screws up
				next = new ArrayList<Character>();
			} else {
				next.add(c[i]);
			}
		}
		substrings.add(next);
		for (int i = 0; i < substrings.size(); i++) {
			ArrayList<Character> seen = new ArrayList<Character>();
			for (int j = 0; j < substrings.get(i).size(); j++) {
				boolean seenBefore = false;
				for (Character ch : seen) {
					if (ch == substrings.get(i).get(j)) {
						seenBefore = true;
						break;
					}
				}
				if (!seenBefore) {
					seen.add(substrings.get(i).get(j));
				}
			}
			maxLength = Math.max(maxLength, seen.size());
		}
		System.out.println(maxLength);
	}
}

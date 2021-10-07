package codeforces;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
//http://codeforces.com/contest/931/problem/E
public class GameWithString {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		char[] s = sc.nextLine().toCharArray();
		sc.close();
		double totalProb = 0;
		for (int i = 'a'; i <= 'z'; i++) {
			double curProb = 0;
			ArrayList<Integer> instances = new ArrayList<Integer>();
			for (int j = 0; j < s.length; j++) {
				if (s[j] == i) {
					instances.add(j);
				}
			}
			if (!instances.isEmpty()) {
				for (int j = 1; j < s.length; j++) {
					Map<Character, Integer> seen = new HashMap<Character, Integer>();
					for (int start : instances) {
						char nextLetter = s[(start + j) % s.length];
						seen.put(nextLetter, seen.getOrDefault(nextLetter, 0) + 1);
					}
					int goodLetters = 0;
					for (int k : seen.values()) {
						if (k == 1) {
							goodLetters++;
						}
					}
					curProb = Math.max(curProb, (double)goodLetters / s.length);
				}
			}
			totalProb += curProb;
		}
		System.out.println(totalProb);
	}
}

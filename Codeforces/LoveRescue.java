package codeforces;
import java.util.ArrayList;
import java.util.Scanner;

//http://codeforces.com/contest/939/problem/D
public class LoveRescue {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		sc.nextLine();
		char[] strA = sc.nextLine().toCharArray();
		char[] strB = sc.nextLine().toCharArray();
		ArrayList<Character> aDiff = new ArrayList<Character>();
		ArrayList<Character> bDiff = new ArrayList<Character>();
		for (int i = 0; i < strA.length; i++) {
			if (strA[i] != strB[i]) {
				aDiff.add(strA[i]);
				bDiff.add(strB[i]);
			}
		}
		int count = 0;
		StringBuilder ans = new StringBuilder();
		while (!aDiff.isEmpty()) {
			count++;
			char from = aDiff.get(aDiff.size() - 1);
			char to = bDiff.get(bDiff.size() - 1);
			ans.append(from + " ");
			ans.append(to + "\r\n");
			aDiff.remove(aDiff.size() - 1);
			bDiff.remove(bDiff.size() - 1);
			for (int i = 0; i < aDiff.size(); i++) {
				if ((bDiff.get(i) == from && aDiff.get(i) == to) ||
						(aDiff.get(i) == from && bDiff.get(i) == to)) {
					aDiff.remove(i);
					bDiff.remove(i);
					i--;
				} else {
					if (aDiff.get(i) == from) {
						aDiff.set(i, to);
					}
					if (bDiff.get(i) == from) {
						bDiff.set(i, to);
					}
				}
			}

		}
		System.out.println(count);
		System.out.println(ans);
		sc.close();
	}
}

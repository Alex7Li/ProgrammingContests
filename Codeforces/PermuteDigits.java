package codeforces;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;
//http://codeforces.com/problemset/problem/915/C
public class PermuteDigits {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		char[] a = s.nextLine().toCharArray();
		char[] b = s.nextLine().toCharArray();
		s.close();
		Arrays.sort(a);
		ArrayList<Character> a2 = new ArrayList<Character>();
		ArrayList<Character> b2 = new ArrayList<Character>();
		for (int i = 0; i < a.length; i++) {
			a2.add(a[i]);
		}
		for (int i = 0; i < b.length; i++) {
			b2.add(b[i]);
		}
		if (b.length > a.length) {
			System.out.println(maxOf(a2));
		} else {
			System.out.println(solve(a2, b2));
		}
	}

	public static String solve(ArrayList<Character> a, ArrayList<Character> b) {
		if (b.size() == 0) {
			return "";
		}
		String ret;
		char b0 = b.remove(0);
		//location of digit in a with value b0, negative if it does not exist
		int ind = Collections.binarySearch(a, b0);
		if (ind >= 0) {
			char el = a.remove(ind);
			ret = el + solve(a, b);
			b.add(0, b0);
			if (ret.compareTo(intString(b)) > 0) {
				//this route is not possible. Go through the second route instead.
				a.add(ind, el);
				int ind2 = Collections.binarySearch(a, (char) (b0 - 1));
				if (ind2 == -1) {
					return "" + ((char) (58));
				} else if (ind2 < 0) {
					//location of largest digit of a less than b0
					ind2 = -(ind2 + 2);
				}
				char el2 = a.remove(ind2);
				ret = el2 + maxOf(a);
				a.add(ind2, el2);
				return ret;
			}
		} else if (ind == -1) {
			b.add(0, b0);
			return "" + ((char) (58));
		} else {
			b.add(0, b0);
			//location of largest digit of a less than b0
			ind = -(ind + 2);
			char el = a.remove(ind);
			ret = el + maxOf(a);
			a.add(ind, el);
		}
		return ret;

	}

	private static String intString(ArrayList<Character> b) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < b.size(); i++) {
			sb.append(b.get(i));
		}
		return sb.toString();
	}

	public static String maxOf(ArrayList<Character> a) {
		Collections.sort(a);
		Collections.reverse(a);
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < a.size(); i++) {
			sb.append(a.get(i));
		}
		return sb.toString();
	}
}

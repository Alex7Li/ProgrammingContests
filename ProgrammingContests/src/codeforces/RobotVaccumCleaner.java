package codeforces;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;
//http://codeforces.com/contest/922/problem/D
public class RobotVaccumCleaner {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.nextLine();
		String[] shStrings = new String[n];
		for (int i = 0; i < n; i++) {
			shStrings[i] = sc.nextLine();
		}
		sc.close();
		Arrays.sort(shStrings, new shComparator());
		StringBuilder finStr = new StringBuilder();
		for (int i = 0; i < shStrings.length; i++) {
			finStr.append(shStrings[i]);
		}
		System.out.println(count(finStr.toString()));
	}

	public static class shComparator implements Comparator<String> {
		@Override
		public int compare(String a, String b) {
			return (int) Math.signum(count(b+a) - count(a+b));
		}
	}
	
	public static long count(String shStr) {
		char[] sh = shStr.toCharArray();
		int sSoFar = 0;
		long count = 0;
		for (int i = 0; i < sh.length; i++) {
			if (sh[i] == 's') {
				sSoFar++;
			} else {
				count += sSoFar;
			}
		}
		return count;
	}
}

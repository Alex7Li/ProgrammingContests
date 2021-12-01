package codeforces;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

//http://codeforces.com/problemset/problem/920/C
public class SwapAdjElements {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < a.length; i++) {
			a[i] = s.nextInt();
		}
		boolean[] canSwap = new boolean[n - 1];
		s.nextLine();
		String inputLine = s.nextLine();
		for (int i = 0; i < canSwap.length; i++) {
			canSwap[i] = (inputLine.charAt(i) == '1');
		}
		int[] sorted = Arrays.copyOf(a, n);
		Arrays.sort(sorted);
		Set<Integer> given = new HashSet<Integer>();
		Set<Integer> goal = new HashSet<Integer>();
		boolean canSort = true;
		for (int i = 0; i < canSwap.length; i++) {
			given.add(a[i]);
			goal.add(sorted[i]);
			if(!canSwap[i]) {
				if(!given.equals(goal)) {
					canSort = false;
					i = a.length;
				}
				given.clear();
				goal.clear();
			}
		}
		given.add(a[canSwap.length]);
		goal.add(sorted[canSwap.length]);
		if(!given.equals(goal)) {
			canSort = false;
		}
		given.clear();
		goal.clear();
		if(canSort) {
			System.out.println("YES");
		}else {
			System.out.println("NO");
		}
		s.close();
	}
}

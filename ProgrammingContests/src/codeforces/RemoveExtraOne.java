package codeforces;
import java.util.ArrayList;
import java.util.Scanner;
//http://codeforces.com/problemset/problem/900/C
public class RemoveExtraOne {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int[] a = new int[n];
		ArrayList<Integer> recLoc = new ArrayList<Integer>();
		int max = 0;
		for (int i = 0; i < n; i++) {
			a[i] = s.nextInt();
			if (a[i] > max) {
				recLoc.add(i);
				max = a[i];
			}
		}
		s.close();
		int[] switchGain = new int[n];
		int bestSwitchIn = -1;
		int bestSwitch = -2;
		for (int i = 0; i < recLoc.size(); i++) {
			int upperBound;
			if (i + 1 < recLoc.size()) {
				upperBound = recLoc.get(i + 1);
			} else {
				upperBound = a.length;
			}
			int curMax;
			int thisSwitch = -1;
			if (i <= 0) {
				curMax = 0;
			} else {
				curMax = a[recLoc.get(i - 1)];
			}
			for (int j = recLoc.get(i) + 1; j < upperBound; j++) {
				if (a[j] > curMax) {
					curMax = a[j];
					thisSwitch++;
				}
			}
			switchGain[a[recLoc.get(i)] - 1] = thisSwitch;
			if (thisSwitch > bestSwitch) {
				bestSwitch = thisSwitch;
				bestSwitchIn = i;
			}
		}
		if (bestSwitch <= 0) {
			for (int i = 0; i < switchGain.length; i++) {
				if (switchGain[i] != -1) {
					System.out.println(i + 1);
					return;
				}
			}
			System.out.println(1);
		} else {
			System.out.println(a[recLoc.get(bestSwitchIn)]);
		}
		s.close();
	}
}

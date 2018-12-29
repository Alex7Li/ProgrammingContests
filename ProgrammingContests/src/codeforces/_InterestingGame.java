package codeforces;
import java.util.ArrayList;
import java.util.Scanner;

//http://codeforces.com/problemset/problem/87/C
//this does not work, but IG2 does (:
public class _InterestingGame {
	private static int[] winning;
	//minimal failing case : n = 30
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		winning = new int[n + 1];
		SequenceList[] waysToSum = new SequenceList[n + 1];
		for (int i = 0; i < waysToSum.length; i++) {
			waysToSum[i] = new SequenceList();
		}
		for (int startEl = 1; startEl <= n / 2; startEl++) {
			int max = startEl + 1;
			int sum = startEl + max;
			while (sum <= n) {
				waysToSum[sum].addSeq(startEl, max);
				max++;
				sum += max;
			}
		}
		for (int i = 0; i < winning.length; i++) {
			winning[i] = minWinning(i, waysToSum[i]);
		}
		System.out.println(minWinning(n,waysToSum[n]));
		s.close();
	}

	private static int minWinning(int n, SequenceList s) {
		int minPileSplit = Integer.MAX_VALUE;
		for (int i = 0; i < s.min.size(); i++) {
			int winningSubPositions = 0;
			for (int j = s.min.get(i); j <= s.max.get(i); j++) {
				if (winning[j]>=0) {
					winningSubPositions++;
				}
			}
			if (winningSubPositions % 2 == 0) {
				minPileSplit = Math.min(minPileSplit, s.max.get(i) - s.min.get(i) + 1);
			}
		}
		if (minPileSplit == Integer.MAX_VALUE) {
			minPileSplit = -1;
		}
		return minPileSplit;
	}

	public static class SequenceList {
		ArrayList<Integer> min = new ArrayList<Integer>();
		ArrayList<Integer> max = new ArrayList<Integer>();

		public void addSeq(int min, int max) {
			this.min.add(min);
			this.max.add(max);
		}
		@Override
		public String toString() {
			String ret = "{";
			for (int i = 0; i < min.size(); i++) {
				ret = ret + min.get(i) + " " + max.get(i) + ", ";
			}
			return ret + "}";
		}
	}
}

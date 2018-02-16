package codeforces;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

//http://codeforces.com/problemset/problem/87/C
public class InterestingGame2 {
	private static int[] grundy;
	// xorGrundy[i] contains grundy[0]^grundy[1]^grundy[2]^...^grundy[i]
	private static int[] xorGrundy;
	private static SequenceList[] waysToSumTo;

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		grundy = new int[n + 1];
		xorGrundy = new int[n + 1];
		grundy[0] = 0;
		xorGrundy[0] = 0;
		waysToSumTo = new SequenceList[n + 1];
		for (int i = 0; i < waysToSumTo.length; i++) {
			waysToSumTo[i] = new SequenceList();
		}
		// add in each way that you can sum up to a number
		for (int startEl = 1; startEl <= n / 2; startEl++) {
			int max = startEl + 1;
			int sum = startEl + max;
			while (sum <= n) {
				waysToSumTo[sum].addSeq(startEl, max);
				max++;
				sum += max;
			}
		}
		for (int i = 1; i < grundy.length; i++) {
			grundy[i] = getGrundy(i);
			xorGrundy[i] = xorGrundy[i - 1] ^ grundy[i];
		}
		if (grundy[n] == 0) {
			System.out.println(-1);
		} else {
			SequenceList waysToSum = waysToSumTo[n];
			int minLength = Integer.MAX_VALUE;
			for (int i = 0; i < waysToSum.length; i++) {
				if (waysToSum.seqLength(i) < minLength && waysToSum.xorSequence(i) == 0) {
					minLength = waysToSum.seqLength(i);
				}
			}
			System.out.println(minLength);
		}
		s.close();
	}

	private static int getGrundy(int n) {
		SequenceList waysToSum = waysToSumTo[n];
		Set<Integer> posGrundy = new HashSet<>();
		for (int i = 0; i < waysToSum.length; i++) {
			posGrundy.add(waysToSum.xorSequence(i));
		}
		return MEX(posGrundy);
	}

	private static int MEX(Set<Integer> vals) {
		for (int i = 0; i <= vals.size(); i++) {
			if (!vals.contains(i)) {
				return i;
			}
		}
		return -1;
	}

	public static class SequenceList {
		private ArrayList<Integer> min = new ArrayList<Integer>();
		private ArrayList<Integer> max = new ArrayList<Integer>();
		int length = 0;

		public void addSeq(int min, int max) {
			this.min.add(min);
			this.max.add(max);
			length++;
		}

		public int seqLength(int i) {
			return max.get(i) - min.get(i) + 1;
		}

		public int xorSequence(int i) {
			int seqMin = min.get(i);
			int seqMax = max.get(i);
			return xorGrundy[seqMax] ^ xorGrundy[seqMin - 1];
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

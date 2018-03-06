package codeforces;
import java.util.Arrays;
import java.util.Scanner;

//http://codeforces.com/contest/930/problem/C
public class TeodorIsNotALiar {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int segments = sc.nextInt();
		int points = sc.nextInt();
		int[] segStarts = new int[points + 1];
		for (int i = 0; i < segments; i++) {
			segStarts[sc.nextInt() - 1]++;
			segStarts[sc.nextInt()]--;
		}
		sc.close();
		int[] pointCount = new int[points];
		int curSegs = 0;
		for (int i = 0; i < pointCount.length; i++) {
			curSegs += segStarts[i];
			pointCount[i] = curSegs;
		}
		int[] maxIncSeqLen = getMaxIncreasingSequencesForEachLength(pointCount);
		flip(pointCount);
		int[] maxRevIncSeqLen = getMaxIncreasingSequencesForEachLength(pointCount);
		flip(maxRevIncSeqLen);
		int best = maxIncSeqLen[0] + maxRevIncSeqLen[1];
		for (int i = 0; i < pointCount.length - 1; i++) {
			best = Math.max(best, maxIncSeqLen[i] + maxRevIncSeqLen[i + 1]);
		}
		System.out.println(best);
	}

	private static void flip(int[] a) {
		for (int i = 0; i < a.length / 2; i++) {
			int temp = a[i];
			a[i] = a[a.length - i - 1];
			a[a.length - i - 1] = temp;
		}
	}

	private static int[] getMaxIncreasingSequencesForEachLength(int[] pointCount) {
		int[] incSeqLen = new int[pointCount.length];
		incSeqLen[0] = 1;
		double[] minForLen = new double[pointCount.length + 1];
		minForLen[0] = 0;
		minForLen[1] = pointCount[0];
		for (int i = 2; i < minForLen.length; i++) {
			minForLen[i] = Double.POSITIVE_INFINITY;
		}
		int highestNonInf = 1;
		for (int i = 1; i < incSeqLen.length; i++) {
			// ensures no duplicates
			double valToSearchFor = pointCount[i] + (double) (i) / 1000000;
			int lowInd = Math.abs(Arrays.binarySearch(minForLen, valToSearchFor) + 1);
			minForLen[lowInd] = Math.min(minForLen[lowInd], valToSearchFor);
			highestNonInf = Math.max(highestNonInf, lowInd);
			incSeqLen[i] = highestNonInf;
		}
		return incSeqLen;
	}
}

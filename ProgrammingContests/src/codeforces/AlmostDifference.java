package codeforces;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;
//http://codeforces.com/problemset/problem/903/D
public class AlmostDifference {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		ArrayList<Pair> a = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			a.add(new Pair(sc.nextInt(), i));
		}
		Collections.sort(a);
		long sum = 0;
		BigInteger ans = BigInteger.valueOf(0);
		// let ans = (y-x) for all pairs (x,y)
		for (int i = 0; i < a.size(); i++) {
			ans = ans.add(BigInteger.valueOf((long)(a.get(i).val) * a.get(i).index - sum));
			sum += a.get(i).val;
		}
		// now subtract all cases where y-x = 1 and add all cases where x-y = 1
		Collections.sort(a, new compByVal());
		// a list of the indexes of the current values in question.
		ArrayList<Integer> iCur = new ArrayList<>();
		int curVal = a.get(0).val;
		for (int i = 0; i < a.size(); i++) {
			if (curVal == a.get(i).val) {
				iCur.add(a.get(i).index);
			} else {
				if (a.get(i).val == curVal + 1) {
					iCur.sort(new Comparator<Integer>() {
						@Override
						public int compare(Integer a, Integer b) {
							return a - b;
						}
					});
					int ind = i;
					while (ind < a.size() && a.get(ind).val == curVal + 1) {
						int loc = Collections.binarySearch(iCur, a.get(ind).index);
						int smallerInd = (loc * -1) - 1;
						int largerInd = iCur.size() - smallerInd;
						int net = largerInd - smallerInd;
						ans = ans.add(BigInteger.valueOf(net));
						ind++;
					}
				}
				iCur.clear();
				curVal = a.get(i).val;
				i--;
			}
		}
		System.out.println(ans.toString());
		sc.close();
	}

	public static class Pair implements Comparable<Pair> {
		int val;
		int index;

		public Pair(int v, int i) {
			index = i;
			val = v;
		}

		@Override
		public int compareTo(Pair b) {
			return this.index - b.index;
		}

		public String toString() {
			return val + " " + index;
		}
	}

	public static class compByVal implements Comparator<Pair> {

		@Override
		public int compare(Pair a, Pair b) {
			return a.val - b.val;
		}

	}
}

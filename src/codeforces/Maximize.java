package codeforces;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

//http://codeforces.com/problemset/problem/939/E
public class Maximize {
	private static long maxV;
	private static ArrayList<Long> sums;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int q = Integer.parseInt(br.readLine());
		sums = new ArrayList<Long>();
		String[] line1 = br.readLine().split(" ");
		long val = Long.parseLong(line1[1]);
		sums.add(0L);
		sums.add(val);
		maxV = val;
		for (int i = 1; i < q; i++) {
			String[] in = br.readLine().split(" ");
			int type = Integer.parseInt(in[0]);
			if (type == 1) {
				int v = Integer.parseInt(in[1]);
				maxV = v;
				sums.add(sums.get(sums.size() - 1) + v);
			} else {
				double minMean = ternSearch(0, sums.size() - 1);
				sb.append(maxV - minMean + "\r\n");
			}
		}
		System.out.println(sb);
	}

	// finds a local min of the function f(x) = (sums(x)+maxV)/(sums.length+1)
	private static double ternSearch(int min, int max) {
		int mid = (min + max) / 2;
		// If middle element is larger than element to it's right, search right subtree
		if (mid < sums.size() - 2 && f(mid) > f(mid + 1)) {
			return ternSearch(mid + 1, max);
			// If middle element is larger than element to it's left, search left subtree
		} else if (mid > 0 && f(mid) > f(mid - 1)) {
			return ternSearch(min, mid - 1);
		} else {// it is a local minima
			return f(mid);
		}
	}

	private static double f(int ind) {
		return ((double) sums.get(ind) + maxV) / (ind + 1);
	}
}

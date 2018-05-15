package codeforces;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.TreeSet;
//http://codeforces.com/contest/980/problem/C
public class Posterized {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] params = br.readLine().split(" ");
		int n = Integer.parseInt(params[0]);
		int k = Integer.parseInt(params[1]);
		int[] a = new int[n];
		String[] aline = br.readLine().split(" ");
		for (int i = 0; i < a.length; i++) {
			a[i] = Integer.parseInt(aline[i]);
		}
		TreeSet<Range> ranges = new TreeSet<Range>();
		ranges.add(new Range(-1000, -1));
		for (int pi : a) {
			Range bel = ranges.floor(new Range(pi, 1000));
			if (bel.e < pi) {
				if (pi - bel.s < k) {
					bel.e = pi;
				} else {
					ranges.add(new Range(Math.max(bel.e + 1, pi - k + 1), pi));
				}
			}
		}
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		bw.write("" + ranges.floor(new Range(a[0], 0)).s);
		for (int i = 1; i < a.length; i++) {
			bw.write(" " + ranges.floor(new Range(a[i], 0)).s);
		}
		bw.flush();
		bw.close();
		br.close();
	}

	public static class Range implements Comparable<Range> {
		int s;
		int e;

		public Range(int l, int r) {
			s = l;
			e = r;
		}

		@Override
		public int compareTo(Range o) {
			return s - o.s;
		}
	}

}

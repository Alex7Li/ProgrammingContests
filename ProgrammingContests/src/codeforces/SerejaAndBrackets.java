package codeforces;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
//http://codeforces.com/blog/entry/15890
//codeforces.com/contest/380/problem/PlasticineZebra
public class SerejaAndBrackets {
	/**
	 * The sequence of characters
	 */
	private static char[] seq;
	/**
	 * answer for a given interval
	 **/
	private static int[] t;
	
	/**
	 *  The number of ('s after deleting the brackets who belong to the correct
	 * bracket sequence in this interval.
	 **/
	private static int[] o;
	
	/**
	 * The number of )'s after deleting the brackets who belong to the correct
	 * bracket sequence in this interval.
	 **/
	private static int[] c;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		seq = br.readLine().toCharArray();
		t = new int[seq.length*4];
		o = new int[seq.length*4];
		c = new int[seq.length*4];
		build(1, 0, seq.length);
		int queries = Integer.parseInt(br.readLine());
		for (int i = 0; i < queries; i++) {
			String[] s = br.readLine().split(" ");
			int l = Integer.parseInt(s[0])-1;
			int r = Integer.parseInt(s[1]);
			System.out.println(ans(l,r));
		}
	}

	public static void build(int x, int l, int r) {
		if (l + 1 == r) {
			if (seq[l] == '(') {
				o[x] = 1;
			} else {
				c[x] = 1;
			}
		} else {
			int mid = (l + r) / 2;
			build(x * 2, l, mid);
			build(x * 2 + 1, mid, r);
			int temp = Math.min(o[2 * x], c[2 * x + 1]);
			t[x] = t[x * 2] + t[x * 2 + 1] + temp * 2;
			o[x] = o[x * 2] + o[x * 2 + 1] - temp;
			c[x] = c[x * 2] + c[x * 2 + 1] - temp;

		}
	}

	public static int ans(int x, int y) {
		return segQuery(x, y, 1, 0, seq.length)[0];
	}

	public static int[] segQuery(int x, int y, int id, int l, int r) {
		if (l >= y || x >= r)
			return new int[] { 0, 0, 0 };
		if (x <= l && r <= y)
			return new int[] { t[id], o[id], c[id] };
		int mid = (l + r) / 2;
		int[] a = segQuery(x, y, 2 * id, l, mid);
		int[] b = segQuery(x, y, 2 * id + 1, mid, r);
		int temp = Math.min(a[1], b[2]);
		int T = a[0] + b[0] + temp*2;
		int O = a[1] + b[1] - temp;
		int C = a[2] + b[2] - temp;
		return new int[] { T, O, C };
	}
}

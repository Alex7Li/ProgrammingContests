package codeforces;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

//http://codeforces.com/contest/976/problem/C
public class NestedSegments {
	public static void main(String[] a) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		PriorityQueue<Segment> Q = new PriorityQueue<>();
		for (int i = 0; i < n; i++) {
			String[] args = br.readLine().split(" ");
			Q.add(new Segment(Integer.parseInt(args[0]), Integer.parseInt(args[1]), i + 1));
		}
		br.close();
		Segment last = Q.poll();
		while (!Q.isEmpty()) {
			Segment next = Q.poll();
			if (next.r <= last.r) {
				System.out.println(next.ind + " " + last.ind);
				return;
			}
			last = next;
		}
		System.out.println("-1 -1");
	}

	public static class Segment implements Comparable<Segment> {
		int l;
		int r;
		int ind;

		public Segment(int l, int r, int ind) {
			this.l = l;
			this.r = r;
			this.ind = ind;
		}

		@Override
		public int compareTo(Segment o) {
			if (Integer.compare(this.l, o.l)!= 0) {
				return Integer.compare(this.l, o.l);
			} else {
				return Integer.compare(o.r, this.r);
			}
		}
	}
}

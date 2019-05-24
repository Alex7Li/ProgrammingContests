package codeforces;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Fishes {
	// http://codeforces.com/contest/912/problem/D
	private static int n;
	private static int m;
	private static int r;

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		n = s.nextInt();
		m = s.nextInt();
		r = s.nextInt();
		int k = s.nextInt();
		s.close();
		double tWays = 0;
		PriorityQueue<Point> Q = new PriorityQueue<Point>();
		int mid = (m + 1) / 2;
		for (int i = 1; i <= n; i++) {
			Q.add(new Point(i, mid));
			if (m > 1) {
				Q.add(new Point(i, mid + 1));
			}
		}
		Point p;
		for (int i = 0; i < k; i++) {
			p = Q.poll();
			tWays += p.ways;
			if (p.y > mid) {// add top
				if (p.y + 1 <= m) {
					Q.add(new Point(p.x, p.y + 1));
				}
			} else {// add bottom
				if (p.y - 1 >= 1) {
					Q.add(new Point(p.x, p.y - 1));
				}
			}
		}
		System.out.println(tWays / (((long)n - r + 1) * (m - r + 1)));
	}

	public static class Point implements Comparable<Point> {
		long ways;
		int x;
		int y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
			setWays();
		}

		private void setWays() {
			long horizontalFreedom = Math.min(n+1-r, x) - Math.max(0, x-r);
			long verticalFreedom =Math.min(m+1-r, y) - Math.max(0, y-r);
			ways = horizontalFreedom * verticalFreedom;
		}

		@Override
		public int compareTo(Point p) {
			return Long.compare(p.ways, this.ways);
		}
	}
}

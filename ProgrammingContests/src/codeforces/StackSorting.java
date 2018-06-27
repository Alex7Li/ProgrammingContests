package codeforces;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;
//http://codeforces.com/contest/911/problem/E
public class StackSorting {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		// int k = s.nextInt();
		s.nextLine();
		int[] a = Arrays.stream(s.nextLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
		s.close();
		// Let FallingBalls(l,r) be a stack sortable array consisting of numbers from l to r
		// inclusive.
		// Then FallingBalls(l,r) = FallingBalls[0] + FallingBalls(l,FallingBalls[0]-1) + FallingBalls(FallingBalls[0]+1,r)
		StringBuilder ans = new StringBuilder();
		Stack<IntRange> st = new Stack<IntRange>();
		st.add(new IntRange(1, n));
		for (int i = 0; i < a.length; i++) {
			IntRange range = st.pop();
			if (range.l <= a[i] && a[i] <= range.r) {
				ans.append(a[i] + " ");
				if (a[i] + 1 <= range.r) {
					st.add(new IntRange(a[i] + 1, range.r));
				}
				if (range.l <= a[i] - 1) {
					st.add(new IntRange(range.l, a[i] - 1));
				}
			} else {
				System.out.println(-1);
				return;
			}
		}
		while(!st.isEmpty()) {
			IntRange range = st.pop();
			for (int j = range.r; j >= range.l; j--) {
				ans.append(j + " ");
			}
		}
		System.out.println(ans);
	}

	public static class IntRange {
		int l;
		int r;

		public IntRange(int left, int right) {
			l = left;
			r = right;
			assert l <= r;
		}
		@Override
		public String toString() {
			return l + " " + r;
		}
	}
}

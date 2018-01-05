package acmkattis;

//http://codeforces.com/problemset/problem/877/E
public class DanilAndPartTimeJob {
	class BinSegTree {
		private int size;
		private int[] t;

		void build() {
			for (int i = size - 1; i > 0; i--) {
				t[i] = t[i << 1] + t[i << 1 | 1];
			}
		}
	}
}

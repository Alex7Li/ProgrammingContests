package codeforces;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

//http://codeforces.com/contest/915/problem/E
public class PhysicalEducationLessons {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int[] a = new int[Integer.parseInt(br.readLine())];
		SegmentTree st = new SegmentTree(a);
		int q = Integer.parseInt(br.readLine());
		for (int i = 0; i < q; i++) {
			int[] in = Arrays.stream(br.readLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
			st.update(in[0] - 1, in[1], in[2]);
			System.out.println(st.tree[1]);
		}
	}

	public static class SegmentTree {
		int[] tree;
		int[] lazVal;
		int aLen;

		/**
		 * Constructs a new segment Tree from the given array
		 */
		public SegmentTree(int[] a) {
			aLen = a.length;
			int size = Math.max(1, Integer.highestOneBit(aLen - 1) * 4);
			tree = new int[size];
			lazVal = new int[size];
			tree[1] = aLen;
			lazVal[1] = 2;

		}

		public void update(int min, int max, int val) {
			update(min, max, val, 0, tree.length / 2, 1);
		}

		private void update(int min, int max, int val, int left, int right, int ind) {
			if (min <= left && right <= max) {// completely inside range
				tree[ind] = (val - 1) * (Math.min(right, aLen) - Math.min(left, aLen));
				lazVal[ind] = val;
			} else if (right <= min || max <= left) {// not in range
				if (left + 1 == right && lazVal[ind] != 0) {
					tree[ind] = (lazVal[ind] - 1) * (Math.min(right, aLen) - Math.min(left, aLen));
				} else {
					propagate(left, right, ind);
				}
			} else {
				int mid = (left + right) / 2;
				propagate(left, right, ind);
				update(min, max, val, left, mid, ind * 2);
				update(min, max, val, mid, right, ind * 2 + 1);
				tree[ind] = tree[ind * 2] + tree[ind * 2 + 1];
			}
		}

		private void propagate(int left, int right, int ind) {
			// elements should be 1
			if (lazVal[ind] == 2) {
				int mid = (left + right) / 2;
				tree[ind * 2] = (Math.min(mid, aLen) - Math.min(left, aLen));
				tree[ind * 2 + 1] = (Math.min(right, aLen) - Math.min(mid, aLen));
				lazVal[ind * 2] = 2;
				lazVal[ind * 2 + 1] = 2;
			} else if (lazVal[ind] == 1) {// elements should be 0
				tree[ind * 2] = 0;
				tree[ind * 2 + 1] = 0;
				lazVal[ind * 2] = 1;
				lazVal[ind * 2 + 1] = 1;
			}
			lazVal[ind] = 0;// updated
		}

	}
}
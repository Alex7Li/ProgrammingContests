package tools;

/**
 * Segment Tree implementation.
 * 
 * @author 7Alex
 *
 */
public class SegmentTree {
	int[] tree;
	int[] a;

	/**
	 * Constructs a new segment Tree from the given array
	 */
	public SegmentTree(int[] a) {
		this.a = a;
		if (a.length == 0) {
			tree = new int[0];
		} else {
			int size = Math.max(1,Integer.highestOneBit(a.length-1) * 4);
			tree = new int[size];
			construct(0, size / 2, 1);
		}
	}

	private void construct(int start, int end, int index) {
		if (start + 1 == end) {
			if (start < a.length) {
				tree[index] = a[start];
			} else {
				tree[index] = 0;
			}
		} else {
			int mid = (start + end) / 2;
			construct(start, mid, index * 2);
			construct(mid, end, index * 2 + 1);
			tree[index] = tree[index * 2] + tree[index * 2 + 1];
		}
	}

	/**
	 * returns sum of numbers in a within range [min,max);
	 */
	public int get(int min, int max) {
		return get(min, max, 0, tree.length / 2, 1);
	}

	private int get(int min, int max, int left, int right, int ind) {
		if (min <= left && right <= max) {// completely inside range
			return tree[ind];
		} else if (right <= min || max <= left) {// not in range
			return 0;
		} else {
			int mid = (left + right) / 2;
			int x1 = get(min, max, left, mid, ind * 2);
			int x2 = get(min, max, mid, right, ind * 2 + 1);
			return x1 + x2;
		}
	}

	/**
	 * updates a[i] to be x
	 */
	public void update(int i, int x) {
		int change = x - a[i];
		int ind = i + tree.length / 2;
		while (ind != 0) {
			tree[ind] += change;
			ind /= 2;
		}
	}
}

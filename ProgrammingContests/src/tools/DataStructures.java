package tools;

import java.util.HashMap;
import java.util.Map;

public class DataStructures {


    /**
     * Segment Tree implementation.
     * https://codeforces.com/blog/entry/18051
     */
    public class SegmentTree {
        int[] tree;
        int n;

        /**
         * Constructs a new segment Tree from the given array
         */
        public SegmentTree(int[] a) {
            n = a.length;
            tree = new int[a.length * 2];
            for (int i = 0; i < n; i++) {
                tree[n + i] = a[i];
            }
            build();
        }

        /**
         * build the tree from child elements
         */
        private void build() {
            for (int i = n - 1; i > 0; i--) {
                tree[i] = tree[i << 1] + tree[(i << 1) + 1];
            }
        }

        /**
         * returns sum of numbers in a within range [l, r);
         */
        public int get(int l, int r) {
            int sum = 0;
            for (l = n + l, r = n + r; l < r; l >>= 1, r >>= 1) {
                if (l % 2 == 1) {
                    sum += tree[l++];
                }
                if (r % 2 == 1) {
                    sum += tree[--r];
                }
            }
            return sum;
        }

        /**
         * updates a[i] to be x
         */
        public void update(int i, int x) {
            tree[n + i] = x;
            for (i = (n + i) >> 1; i > 0; i >>= 1) {
                tree[i] = tree[i << 1] + tree[(i << 1) ^ 1];
            }
        }
    }

    /*
     * Bag/Multiset class for integers
     */
    private class MultiSet {
        Map<Integer, Integer> mSet = new HashMap<>();
        int size = 0;

        /*
         * Adds a single element to the multiset
         */
        void add(int element) {
            mSet.put(element, mSet.getOrDefault(element, 0) + 1);
            size++;
        }

        /*
         * Removes a single element from the multiset
         */
        void remove(int element) {
            int curCount = mSet.get(element);
            if (curCount <= 0) {
                throw new RuntimeException();
            } else if (curCount == 1) {
                mSet.remove(element);
            } else {
                mSet.put(element, curCount - 1);
            }
            size--;
        }

        /**
         * return any int corresponding to a given key
         */
        Integer getAny() {
            return mSet.keySet().iterator().next();
        }

    }
}

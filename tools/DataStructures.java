package tools;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashMap;
import java.util.Map;

/*
 * CLASS LIST:
 * SegmentTree: An array supporting range sum operations
 * MultiSet: A set that can hold the same element several times
 * MaxQueue: A queue supporting a getMax operation
 * DisjointSetUnion: A node supporting DSU operations
 * */
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

/*
 * A queue supporting an additional constant time operation: getMax.
 * getMax returns the largest element in the queue.
 * Copied from https://stackoverflow.com/questions/4802038
 */
static class MaxQueue {
    Deque<Pair> pushStack = new ArrayDeque<>();
    Deque<Pair> popStack = new ArrayDeque<>();
    
    /*
     * Add an element into the queue
     */
    void push(long val) {
        long max = val;
        if (!pushStack.isEmpty()) {
            max = Math.max(max, pushStack.peekFirst().max);
        }
        pushStack.addFirst(new Pair(val, max));
    }
    
    /*
     * Remove an element from the queue
     */
    long pop() {
        if (popStack.isEmpty()) {
            if (pushStack.isEmpty()) {
                throw new RuntimeException("Pop from empty queue");
            } else {
                // move pushStack to popStack, updating the max values
                // reset the max for each element.
                // For the first element, the max will be the value.
                long val = pushStack.removeFirst().val;
                popStack.addFirst(new Pair(val, val));
                // For the rest, the max is the max of (max so far, new value)
                while (!pushStack.isEmpty()) {
                    val = pushStack.removeFirst().val;
                    long max = Math.max(popStack.peekFirst().max, val);
                    Pair pushV = new Pair(val, max);
                    popStack.addFirst(pushV);
                }
            }
        }
        return popStack.removeFirst().val;
    }
    
    /*
     * return maxValue, or null if none exist
     */
    Long getMax() {
        if (pushStack.isEmpty()) {
            if (popStack.isEmpty()) {
                return null;
            } else {
                return popStack.peekFirst().max;
            }
        } else if (popStack.isEmpty()) {
            return pushStack.peekFirst().max;
        } else {
            return Math.max(pushStack.peekFirst().max, popStack.peekFirst().max);
        }
    }
    
    static class Pair {
        long val;
        long max;
        
        Pair(long val, long max) {
            this.val = val;
            this.max = max;
        }
    }
}

/**
 * Fraction class implementation.
 */
private static class Fraction implements Comparable<Fraction> {
    /**
     * the numerator and denominator of this fraction. Both will be coprime. The denominator will always be non-negative.
     * If the denominator is 0, the numerator is 1. If the numerator is 0, the denominator is 1. 0/0 will become 1/0.
     **/
    long num;
    long denom; //always positive by convention
    
    Fraction(int numerator) {
        num = numerator;
        denom = 1;
    }
    
    Fraction(long numerator, long denominator) {
        int sgn = denominator >= 0 ? 1 : -1;
        denom = denominator * sgn;
        num = numerator * sgn;
        if (denominator == 0) { // if one of denom or num = 0, make the other be 1.
            num = 1;            // this is so equality checks work. (making the other be 0 breaks compareTo)
        } else if (numerator == 0) {
            denom = 1;
        } else {
            long gcd = Math.abs(gcd(denom, num));
            denom /= gcd;
            num /= gcd;
        }
    }
    
    
    private Fraction multiply(Fraction subtrahend) {
        return new Fraction(num * subtrahend.num, denom * subtrahend.denom);
    }
    
    private Fraction divide(Fraction dividend) {
        return new Fraction(num * dividend.denom, denom * dividend.num);
    }
    
    private Fraction subtract(Fraction subtrahend) {
        return new Fraction(num * subtrahend.denom - subtrahend.num * denom, denom * subtrahend.denom);
    }
    
    private Fraction add(Fraction addend) {
        return new Fraction(num * addend.denom + addend.num * denom, denom * addend.denom);
    }
    
    private static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
    
    @Override
    public boolean equals(Object other) {
        if (!(other instanceof Fraction)) {
            return false;
        }
        Fraction o = (Fraction) (other);
        return (num == o.num && denom == o.denom);
    }
    
    @Override
    public int hashCode() {
        return (int) (num + (denom << 20));
    }
    
    @Override
    public String toString() {
        return num + "/" + denom;
    }
    
    @Override
    public int compareTo(Fraction o) {
        // might overflow with big numbers
        return Long.compare(num * o.denom, denom * o.num);
    }
}

    // Disjoint Set Union
    // currently this is pretty bad, you shouldn't need an external class at all
    private static class Node {
        Node groupRep;
        int groupSize;
        Node() {
            groupRep = this;
            groupSize = 1;
        }

        private static Node findRep(Node o){
            while(o.groupRep != o){
                o.groupRep = o.groupRep.groupRep;
                o = o.groupRep;
            }
            return o;
        }

        // return if there was a merge
        private boolean merge(Node o){
            Node thisGroup = findRep(this);
            Node otherGroup = findRep(o);
            if(thisGroup==otherGroup){
                return false;
            }
            if(thisGroup.groupSize < otherGroup.groupSize){
                Node temp = thisGroup;
                thisGroup = otherGroup;
                otherGroup = temp;
            }

            otherGroup.groupRep = thisGroup;
            thisGroup.groupSize = thisGroup.groupSize + otherGroup.groupSize;
            return true;
        }
    }
}

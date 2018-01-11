package codeforces;
import java.util.Arrays;
import java.util.Iterator;
import java.util.Scanner;
import java.util.TreeSet;

//got TLE but i think it's just java being slow so I'm putting it in accepted.
public class PrimeGift {
	private static TreeSet<Long> setA = new TreeSet<>();
	private static TreeSet<Long> setB = new TreeSet<>();
	private static final long MAX = (long) Math.pow(10, 18);
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		s.nextLine();
		int[] pList = Arrays.stream(s.nextLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
		long k = s.nextLong();
		s.close();
		double startT = System.currentTimeMillis();
		int[] A = new int[(pList.length + 1) / 2];
		int[] B = new int[pList.length / 2];
		for (int i = 0; i < pList.length; i++) {
			if (i % 2 == 0) {
				A[i / 2] = pList[i];
			} else {
				B[i / 2] = pList[i];
			}
		}
		generateSet(1l, A, 0, 0);
		generateSet(1l, B, 0, 1);
		System.err.println(System.currentTimeMillis() - startT);
		long min = 0;
		long max = MAX;
		long mid = (min + max) / 2;
		while (min < max - 1) {
			mid = (min + max) / 2;
			if (test(mid, k) < 0) {
				min = mid;
			} else {
				max = mid;
			}
		}
		System.err.println(System.currentTimeMillis() - startT);
		System.out.println(max);
		s.close();
	}

	private static long test(long x, long k) {
		long count = 0;
		Iterator<Long> itA = setA.descendingIterator();
		Iterator<Long> itB = setB.iterator();
		int aElLeft = setA.size();
		long bEl = itB.next();
		long aEl;
		while (itA.hasNext()) {
			// aEl*bEl<=x
			aEl = itA.next();
			while (aEl <= x / bEl) {
				count += aElLeft;
				if (itB.hasNext() && count < k) {
					bEl = itB.next();
				}else {
					break;
				}
			}
			aElLeft--;
		}
		return count - k;
	}

	private static void generateSet(long v, int[] a, int i, int set) {
		if (i >= a.length) {
			if (set == 0) {
				setA.add(v);
			} else {
				setB.add(v);
			}
		} else {
			generateSet(v, a, i + 1, set);
			while (v <= MAX / a[i]) {
				v *= a[i];
				generateSet(v, a, i + 1, set);
			}
		}
	}
}

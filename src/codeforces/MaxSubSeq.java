package codeforces;
import java.util.Iterator;
import java.util.Scanner;
import java.util.TreeSet;

public class MaxSubSeq {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int m = s.nextInt();
		int x = 0;
		if (n % 2 != 0) {
			x = 1;
		}
		int[] a = new int[n / 2];
		int[] b = new int[n / 2 + x];
		for (int i = 0; i < a.length; i++) {
			a[i] = s.nextInt();
		}
		for (int i = 0; i < b.length; i++) {
			b[i] = s.nextInt();
		}
		s.close();
		TreeSet<Integer> posA = getSums(a, m);
		TreeSet<Integer> posB = getSums(b, m);
		Iterator<Integer> it = posA.iterator();
		Iterator<Integer> bit = posB.descendingIterator();
		int max = 0;
		int bEl = bit.next();
		while (it.hasNext()) {
			int aEl = it.next();
			while (aEl + bEl >= m) {
				bEl = bit.next();
			}
			max = Math.max((aEl + bEl) % m, max);
		}
		System.out.println(max);

	}

	private static TreeSet<Integer> getSums(int[] a, int m) {
		TreeSet<Integer> obtained = new TreeSet<>();
		obtained.add(0);
		for (int i = 0; i < a.length; i++) {
			Integer[] copy = obtained.toArray(new Integer[0]);
			for (int j : copy) {
				obtained.add((j + a[i]) % m);
			}
		}
		return obtained;
	}
}

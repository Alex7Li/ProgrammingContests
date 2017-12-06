package unfinished;

import java.util.ArrayList;
import java.util.Scanner;

//http://codeforces.com/problemset/problem/878/B
public class TeamsFormation {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int k = s.nextInt();
		int m = s.nextInt();
		ArrayList<Integer> a = new ArrayList<Integer>();
		for (int i = 0; i < n; i++) {
			a.add(s.nextInt());
		}
		s.close();
		long count = 0;
		count += (long) m * countPairs(a, k);
		// exactly the same method as countPairs, just kinda concatenates a with
		// itself first and stores first and last sep.
		ArrayList<Integer> front = new ArrayList<Integer>(a);
		ArrayList<Integer> end = new ArrayList<Integer>(a);
		int selfPairs = 0;
		//elements removed from the 'end' list.
		int endRem = 0;
		for (int i = 0; (i <= a.size() * 2 && a.size() >= k); i++) {
			boolean canPair = true;
			int star = i;
			int city = a.get(i % a.size());
			while (i - star < k) {
				if (a.get(i % a.size()) != city) {
					canPair = false;
					break;
				}
				i++;
			}
			if (canPair) {
				selfPairs++;
				i = star;
				// error is here
				// 8 3 3
				// 2 1 1 3 3 1 2 2
				for (int j = star + k - 1; j >= star; j--) {
					if (i % a.size() == i) {
						front.remove(i+endRem);
						a.remove(i);
					} else {
						end.remove(0);
						a.remove(0);
						endRem++;
					}
				}
				// go back to check if we've made a
				// new pair by removing this one
				i = Math.max(i - k - 2, -1);
			} else {
				i--;
			}
		}
		count += (long) (m - 1) * selfPairs;

		if (allElementsSame(a) && m > 1) {
			// combine all the elements you can
			int totalSameEl = a.size() * (m - 2);
			while (!front.isEmpty() && front.get(front.size() - 1) == a.get(0)) {
				front.remove(front.size() - 1);
				totalSameEl++;
			}
			while (!end.isEmpty() && end.get(0) == a.get(0)) {
				end.remove(0);
				totalSameEl++;
			}
			count += totalSameEl / k;
			// if they have all been removed,
			// count the pairs of front + uncombined + end
			if (totalSameEl % k == 0) {
				ArrayList<Integer> comb = new ArrayList<>(front);
				comb.addAll(end);
				count += countPairs(comb, k);
			}
		}

		System.out.println(m * n - count * k);

	}

	private static boolean allElementsSame(ArrayList<Integer> a) {
		if (a.size() == 0) {
			return true;
		} else {
			int el = a.get(0);
			for (int i : a) {
				if (el != i) {
					return false;
				}
			}
		}
		return true;
	}

	private static int countPairs(ArrayList<Integer> a, int k) {
		int count = 0;
		for (int i = 0; i <= a.size() - k; i++) {
			boolean canPair = true;
			int star = i;
			int city = a.get(i);
			while (i - star < k) {
				if (a.get(i) != city) {
					canPair = false;
					break;
				}
				i++;
			}
			if (canPair) {
				count++;
				i = star;
				for (int j = 0; j < k; j++) {
					a.remove(i);
				}
				// go back to check if we've made a
				// new pair by removing this one
				i = Math.max(i - k - 2, -1);
			} else {
				i--;
			}
		}
		return count;
	}
}
package codeforces;

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
		if (m != 1) {
			// exactly the same method as countPairs, just kinda concatenates a with
			// itself first and stores first and last sep.
			ArrayList<Integer> front = new ArrayList<Integer>(a);
			ArrayList<Integer> end = new ArrayList<Integer>(a);
				int selfPairs = 0;
				for (int i = 0; i < a.size() * 2; i++) {
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
						for (int j = 0; j < k; j++) {	
							if (i % a.size() == i) {
								front.remove(i);
							} else {
								end.remove(i % a.size());
							}
							a.remove(i % a.size());
						}

						// go back to check if we've made a
						// new pair by removing this one
						i = Math.max(i - k - 1, 0);
					} else {
						i--;
					}
				}
				count += (long) (m - 1) * selfPairs;
			
			if (allElementsSame(a)) {
				// combine all the elements you can
				count += a.size() * (m - 2) / k;
				// finally, count the pairs of front + uncombined + end
				ArrayList<Integer> comb = new ArrayList<>(front);
				if (a.size() != 0) {
					for (int i = 0; i < a.size() * (m - 2) % k; i++) {
						comb.add(a.get(0));
					}
				}
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
		for (int i = 0; i < a.size() - k; i++) {
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
				i = Math.max(i - k - 1, 0);
			} else {
				i--;
			}
		}
		return count;
	}
}
package math.constructive;

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

//most BS solution eva
//https://www.codechef.com/JAN18/problems/PRTITION
public class ParitionTheNumbers {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int tests = s.nextInt();
		for (int t = 0; t < tests; t++) {
			int x = s.nextInt();
			int n = s.nextInt();
			long sum = (long) (n) * (n + 1) / 2 - x;
			if (sum % 2 == 1 || n < 4) {
				System.out.println("impossible");
				continue;
			}
			// greedily parition the numbers
			Set<Integer> s1 = new HashSet<Integer>();
			long s1sum = 0;
			long s2sum = 0;
			for (int i = n; i > 0; i--) {
				if (i != x) {
					if (s1sum > s2sum) {
						s2sum += i;
					} else {
						s1.add(i);
						s1sum += i;
					}
				}
			}
			int diff = (int) (s2sum - s1sum) / 2;
			int tries = 0;
			while (diff != 0 && tries < 100) {
				int sign = (int) Math.signum(diff);
				// fix it by switching 2 numbers that reduce the difference until it works :P
				for (int i = Math.max(1, 1 + diff); i <= Math.min(n, n + diff); i++) {
					if (x != i) {
						for (int j = sign; Math.abs(j) <= Math.abs(diff); j += sign) {
							if (x != i + j) {
								if (s1.contains(i) && !s1.contains(i + j)) {
									s1.remove(i);
									s1.add(i + j);
									s1sum += j;
									s2sum -= j;
									diff = (int) (s2sum - s1sum) / 2;
									i = Math.max(1, 1 + diff);
									if (diff == 0) {
										i = n;
									}
								}
							}
						}
					}
				}
				if (diff != 0) {
					// ok, it didn't work. let's switch some random numbers & try again
					for (int i = 0; i < 10000; i++) {
						int rand = (int) (Math.random() * n + 1);
						if (s1.contains(rand)) {
							s1.remove(rand);
							s1sum -= rand;
							s2sum += rand;
						} else {
							s1.add(i);
							s1sum += rand;
							s2sum -= rand;
						}
					}
				}
				tries++;
			}
			if (diff == 0) {
				printAns(x, n, s1);
			} else {
				System.out.println("impossible");
			}
		}
		s.close();
	}

	private static void printAns(int x, int n, Set<Integer> s1) {
		StringBuilder sb = new StringBuilder();
		for (int i = 1; i <= n; i++) {
			if (x == i) {
				sb.append(2);
			} else if (s1.contains(i)) {
				sb.append(1);
			} else {
				sb.append(0);
			}
		}
		System.out.println(sb);
	}
}

package adventofcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Day6 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		String[] line = s.nextLine().split("\t");
		Integer[] a = new Integer[line.length];
		for (int i = 0; i < a.length; i++) {
			a[i] = Integer.parseInt(line[i]);
		}
		System.out.println("Part 1 " + countCycles(a));
		System.out.println("Part 2 " + countCycles(a));
		s.close();
	}

	public static int countCycles(Integer[] a) {
		int count = 0;
		ArrayList<Integer[]> seen = new ArrayList<>();
		seen.add(a.clone());
		boolean done = false;
		while (!done) {
			count++;
			int max = a[0];
			int maxIn = 0;
			for (int i = 1; i < a.length; i++) {
				if (a[i] > max) {
					max = a[i];
					maxIn = i;
				}
			}
			a[maxIn] = 0;
			for (int i = 0; i < a.length; i++) {
				if (max % a.length <= i) {
					a[(i + maxIn + 1) % a.length] += max / a.length;
				} else {
					a[(i + maxIn + 1) % a.length] += 1 + max / a.length;
				}
			}
			for (Integer[] ar : seen) {
				if (Arrays.deepEquals(ar, a)) {
					done = true;
				}
			}
			seen.add(a.clone());
		}
		return count;
	}
}

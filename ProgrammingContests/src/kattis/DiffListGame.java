package kattis;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class DiffListGame {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		long l = s.nextLong();
		s.close();
		ArrayList<Long> factors = factor(l);
		Collections.sort(factors);
		
	}

	private static ArrayList<Long> factor(long l) {
		ArrayList<Long> factors = new ArrayList<Long>();
		for (long i = 2; i * i <= l; i++) {
			if (l % i == 0) {
				factors.add(i);
				l = l / i;
			}
		}
		return factors;
	}
}

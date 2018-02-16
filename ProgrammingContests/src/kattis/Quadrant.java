package kattis;

import java.util.Scanner;

public class Quadrant {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		boolean x = s.nextInt() > 0;
		boolean y = s.nextInt() > 0;
		s.close();
		if (x && y) {
			System.out.println(1);
		} else if (x) {
			System.out.println(4);
		} else if (y) {
			System.out.println(2);
		} else {
			System.out.println(3);
		}

	}
}

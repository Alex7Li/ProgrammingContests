package other.googlecontest;

import java.util.Scanner;

public class NumberGuessing {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int cases = Integer.parseInt(sc.nextLine());
		for (int i = 0; i < cases; i++) {
			//inclusive
			int max = Integer.parseInt(sc.nextLine());
			//exclusive
			int min = 1;
			while (true) {
				int guess = (max + min) / 2;
				System.out.println(guess);
				System.out.flush();
				String result = sc.nextLine();
				if (result.equals("TOO_BIG")) {
					max = guess;
				} else if (result.equals("TOO_SMALL")) {
					min = guess + 1;
				} else {
					break;
				}
			}
		}
		sc.close();
	}
}

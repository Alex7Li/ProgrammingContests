package codeforces;
import java.util.Scanner;

//http://codeforces.com/contest/452/problem/A
public class Eevee {
	public static void main(String[] args) {
		String[] possible = { "vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon" };
		Scanner s = new Scanner(System.in);
		s.nextLine();
		String regrex = s.nextLine();
		for (int i = 0; i < possible.length; i++) {
			if (possible[i].matches(regrex)) {
				System.out.println(possible[i]);
			}
		}
		s.close();
	}
}

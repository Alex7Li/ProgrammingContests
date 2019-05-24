package core.string.implementation;

import java.util.Scanner;

public class Autori {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		String[] names = s.nextLine().split("-");
		s.close();
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < names.length; i++) {
			sb.append(names[i].charAt(0));
		}
		System.out.println(sb);
	}
}

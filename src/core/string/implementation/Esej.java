package core.string.implementation;

import java.util.Scanner;
//https://open.kattis.com/problems/esej
public class Esej {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		s.nextInt();
		int b = s.nextInt();
		final int aPos = 'a';
		s.close();
		StringBuilder sentence = new StringBuilder();
		for (int i = 0; i < b; i++) {
			for (int j = 0; j < 15; j++) {
				char next = (char) (Math.random()*26 + aPos);
				sentence.append(next);
			}
			sentence.append(" ");
		}
		System.out.println(sentence);
	}
}

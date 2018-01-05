package codeforces;

import java.util.Scanner;

//http://codeforces.com/problemset/problem/457/A
public class GoldenSystem {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		String str1 = "0" + s.nextLine();
		String str2 = "0" + s.nextLine();
		s.close();
		StringBuilder zeroPad = new StringBuilder();
		for (int i = 0; i < Math.abs(str1.length() - str2.length()); i++) {
			zeroPad.append("0");
		}
		if (str1.length() < str2.length()) {
			str1 = zeroPad + str1;
		} else {
			str2 = zeroPad + str2;
		}
		assert str1.length() == str2.length();
		int[] num1 = new int[str1.length()];
		int[] num2 = new int[str2.length()];
		for (int i = 0; i < num2.length; i++) {
			num1[i] = Integer.parseInt(str1.substring(i, i + 1));
			num2[i] = Integer.parseInt(str2.substring(i, i + 1));
		}
		for (int i = 0; i < num1.length - 2; i++) {
			num1[i] = num1[i] - num2[i];
			num2[i] = 0;
			// using 2phi^(n+1)>phi^n+phi^(n-1)+...+1
			if (num1[i] > 2) {
				System.out.println(">");
				return;
			} else if (num1[i] < -2) {
				System.out.println("<");
				return;
			}
			// using phi^(n+2)=phi^(n+1)+phi^n
			num1[i + 1] = num1[i] + num1[i + 1];
			num1[i + 2] = num1[i] + num1[i + 2];
			num1[i] = 0;
		}
		int last = num1.length - 1;
		if (num1[last - 1] == num2[last - 1] && num1[last] == num2[last]) {
			System.out.println("=");
		} else {
			double q = (Math.sqrt(5) + 1) / 2;
			double n1 = q * num1[last - 1] + num1[last];
			double n2 = q * num2[last - 1] + num2[last];
			if (n1 > n2) {
				System.out.println(">");
			} else if (n1 < n2) {
				System.out.println("<");
			}
		}
	}
}

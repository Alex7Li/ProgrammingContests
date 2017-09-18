package acmkattis;

import java.math.BigInteger;
import java.util.Scanner;

public class QuickEstimate {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		for (int i = 0; i < n; i++) {
			int digits = 0;
			BigInteger num = s.nextBigInteger();
			if (num.equals(BigInteger.ZERO)) {
				System.out.println(1);
			} else {
				while(!num.equals(BigInteger.ZERO)) {
					num = num.divide(BigInteger.valueOf(10));
					digits++;
				}
				System.out.println(digits);
			}
		}
		s.close();
	}
}

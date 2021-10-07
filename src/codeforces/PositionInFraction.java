package codeforces;
import java.math.BigDecimal;
import java.util.Scanner;
//http://codeforces.com/problemset/problem/900/B
public class PositionInFraction {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		BigDecimal a = s.nextBigDecimal();
		BigDecimal b = s.nextBigDecimal();
		int c = s.nextInt();
		s.close();
		BigDecimal res = a.divide(b, 100000, 1);
		res.subtract(BigDecimal.valueOf((a.intValue()/b.intValue())));
		char[] chars = String.valueOf(res).toCharArray();
		for (int i = 2; i< chars.length-1;i++) {
			if(c == Character.getNumericValue(chars[i])) {
				System.out.println(i-1);
				return;
			}
		}
		System.out.println(-1);
	}
}

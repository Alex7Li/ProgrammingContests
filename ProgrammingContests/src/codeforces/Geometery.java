package codeforces;

import java.util.Scanner;
//http://codeforces.com/contest/851/problem/B

public class Geometery {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int x1 = s.nextInt();
		int y1 = s.nextInt();
		int x2 = s.nextInt();
		int y2 = s.nextInt();
		int x3 = s.nextInt();
		int y3 = s.nextInt();
		s.close();
		// dist from point 1 to 2 squared'
		long x12 = (x1-x2);
		long y12 = (y1-y2);
		long d12 = x12*x12 + y12*y12;
		// dist from point 2 to 3 squared
		long x23 = (x2-x3);
		long y23 = (y2-y3);
		long d23 = x23*x23 + y23*y23;
		if (d12 == d23) {
			// test for collinearity (parallel vector cross product=0)
			long temp1 =((long)x1 - x2) * (y2 - y3);
			long temp2 =((long)y1 - y2) * (x2 - x3);
			if (temp1==temp2) {
				System.out.println("NO");
			} else {
				System.out.println("YES");
			}
		} else {
			System.out.println("NO");
		}
	}
}

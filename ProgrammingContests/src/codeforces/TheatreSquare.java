package codeforces;
import java.util.*;
//http://codeforces.com/problemset/status/1/problem/A
public class TheatreSquare {
	public static void main(String[] e) {
		Scanner s = new Scanner(System.in);
		int a = s.nextInt();
		int b = s.nextInt();
		double c = s.nextDouble();
		System.out.println((long) (Math.ceil(a / c) * Math.ceil(b / c)));
		s.close();
	}
}
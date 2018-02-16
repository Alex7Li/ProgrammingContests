package codeforces;
import java.util.Scanner;
//http://codeforces.com/contest/915/problem/B
public class Browser {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int pos = s.nextInt();
		int l = s.nextInt();
		int r = s.nextInt();
		if (l == 1) {
			if (r == n) {
				System.out.println(0);
			}else {
				if( r < pos) {
					System.out.println(pos - r + 1);
				}else {
					System.out.println(r - pos + 1);
				}
			}
		} else if(r==n) {
			if( l < pos) {
				System.out.println(pos - l + 1);
			}else {
				System.out.println(l - pos + 1);
			}
		} else if (pos < l) {
			System.out.println(r-pos+2);
		} else if (r < pos) {
			System.out.println(pos-l+2);
		} else {
			int p1 = Math.min(pos-l, r-pos);
			System.out.println(p1 + (r - l) + 2);
		}
		s.close();
	}
}

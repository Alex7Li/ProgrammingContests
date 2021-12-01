package codeforces;
import java.util.Scanner;
//http://codeforces.com/contest/915/problem/A
public class Garden {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int k = s.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < a.length; i++) {
			a[i] = s.nextInt();
		}
		int minH = Integer.MAX_VALUE;
		for (int i = 0; i < a.length; i++) {
			if (k % a[i] == 0) {
				minH = Math.min(k / a[i], minH);
			}
		}
		System.out.println(minH);
		s.close();
	}
}

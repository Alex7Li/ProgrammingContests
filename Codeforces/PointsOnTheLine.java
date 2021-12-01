package codeforces;
import java.util.Arrays;
import java.util.Scanner;

//http://codeforces.com/contest/940/problem/A

public class PointsOnTheLine {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int d = sc.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		Arrays.sort(a);
		int maxValid = 1;
		for (int i = 1; i < a.length; i++) {
			for (int j = 0; j + i < a.length; j++) {
				if (a[i+j] - a[j] <= d) {
					maxValid = i+1;
					break;
				}
			}
		}
		System.out.println(n - maxValid);
		sc.close();
	}
}

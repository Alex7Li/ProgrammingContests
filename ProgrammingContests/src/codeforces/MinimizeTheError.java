package codeforces;
import java.util.Arrays;
import java.util.Scanner;

//http://codeforces.com/contest/960/problem/B
public class MinimizeTheError {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		sc.nextInt();
		int k = sc.nextInt() + sc.nextInt();
		sc.nextLine();
		int[] a = Arrays.stream(sc.nextLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
		int[] b = Arrays.stream(sc.nextLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
		int[] c = new int[a.length];
		for (int i = 0; i < c.length; i++) {
			c[i] = Math.abs(a[i] - b[i]);
		}
		for (int i = 0; i < k; i++) {
			int maxInd = 0;
			for (int j = 0; j < c.length; j++) {
				if (c[j] > c[maxInd]) {
					maxInd = j;
				}
			}
			c[maxInd] = Math.abs(c[maxInd] - 1);
		}
		long totalSum = 0;
		for (int i = 0; i < c.length; i++) {
			totalSum += (long) (c[i]) * c[i];
		}
		sc.close();
		System.out.println(totalSum);
	}
}

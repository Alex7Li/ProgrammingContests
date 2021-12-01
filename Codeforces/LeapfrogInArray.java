package codeforces;
import java.util.Scanner;

//http://codeforces.com/contest/949/problem/B
public class LeapfrogInArray {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong() * 2;
		int q = sc.nextInt();
		StringBuilder sb = new StringBuilder();
		for (int testCase = 0; testCase < q; testCase++) {
			long x = sc.nextLong();
			long y = n - x;
			int hops = 0;
			while (y % 2 == 0) {
				y /= 2;
				hops++;
			}
			long ans = (n - (n - x) / (long) (Math.pow(2, hops)) + 1) / 2;
			sb.append(ans + "\r\n");
		}
		System.out.println(sb);
		sc.close();
	}
}

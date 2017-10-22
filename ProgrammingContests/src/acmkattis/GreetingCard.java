package acmkattis;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Hashtable;

public class GreetingCard {
	public static void main(String[] args) throws IOException {
		long[] search = new long[6];
		search[0] = 2018<<31;
		search[1] = 2018;
		search[2] = 1118 + (1680<<31);
		search[3] = -1118 + (1680<<31);
		search[4] = 1680 + (1118<<31);
		search[5] = -1680 + (1118<<31);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		Hashtable<Long, Long> ht = new Hashtable<Long, Long>();
		long[] points = new long[n];
		for (int i = 0; i < n; i++) {
			String[] pointS = br.readLine().split(" ");
			long x = Integer.parseInt(pointS[0]);
			long y = Integer.parseInt(pointS[1]);
			long point = y + (x << 31);
			points[i] = point;
		}
	}
}

package codeforces;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;
//http://codeforces.com/problemset/problem/886/B
public class VladAndCafes {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		s.nextLine();
		int[] a = Arrays.stream(s.nextLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
		s.close();
		HashMap<Integer, Integer> lastTime = new HashMap<Integer, Integer>();
		for (int j = 0; j < a.length; j++) {
			lastTime.put(a[j], j);
		}
		int min = Integer.MAX_VALUE;
		for (int t : lastTime.values()) {
			if (t < min) {
				min = t;
			}
		}
		System.out.println(a[min]);
	}
}

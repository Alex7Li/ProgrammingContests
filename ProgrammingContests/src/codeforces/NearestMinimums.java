package codeforces;
import java.util.Arrays;
import java.util.Scanner;
//http://codeforces.com/problemset/problem/911/A
public class NearestMinimums {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
	Integer.parseInt(sc.nextLine());
		int[] a = Arrays.stream(sc.nextLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
		int min = Arrays.stream(a).min().getAsInt();
		int minDist = Integer.MAX_VALUE;
		int curDist = 1000000;
		for (int i = 0; i < a.length; i++) {
			if (a[i] == min) {
				if (curDist < minDist) {
					minDist = curDist;
				}
				curDist = 0;
			}
			curDist++;
		}
		System.out.println(minDist);
		sc.close();
	}
}

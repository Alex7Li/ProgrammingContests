package codeforces;
import java.util.Arrays;
import java.util.Scanner;
//http://codeforces.com/contest/914/problem/0
public class PerfectSquares {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		s.nextLine();
		int[] a = Arrays.stream(s.nextLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
		int max = Integer.MIN_VALUE;
		for (int i = 0; i < a.length; i++) {
			if(a[i]>max && !isSquare(a[i])) {
				max = a[i];
			}
		}
		System.out.println(max);
		s.close();
	}
	public static boolean isSquare(int a) {
		for (int i = 0; i*i <= a ; i++) {
			if(i*i == a) {
				return true;
			}
		}
		return false;
	}
}

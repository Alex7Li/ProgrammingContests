package codeforces;
import java.util.Arrays;
import java.util.Scanner;
//http://codeforces.com/contest/931/problem/C
public class LaboratoryWork {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < a.length; i++) {
			a[i] = sc.nextInt();
		}
		sc.close();
		int min = Arrays.stream(a).min().getAsInt();
		int max = Arrays.stream(a).max().getAsInt();
		int[] count = new int[3];
		for (int i = 0; i < n; i++) {
			if (a[i] == min) {
				count[0]++;
			} else if (a[i] == max) {
				count[2]++;
			} else {
				count[1]++;
			}
		}
		if (max != min + 2) {
			System.out.println(n);
			StringBuilder out = new StringBuilder();
			out.append(a[0]);
			for (int j = 1; j < n; j++) {
				out.append(" " + (a[j]));
			}
			System.out.println(out);
			return;
		}
		int minExt = Math.min(count[0], count[2]);
		int same = n;
		if (minExt * 2 >= count[1]) {
			count[1] += minExt * 2;
			count[0] -= minExt;
			count[2] -= minExt;
			same-= minExt*2;
		} else {
			int diff = count[1] - count[1] % 2;
			count[1] -= diff;
			count[2] += diff/2;
			count[0] += diff/2;
			same-= diff;
		}
		System.out.println(same);
		StringBuilder out = new StringBuilder("");
		for (int i = 0; i < count[0]; i++) {
			out.append(min+ " ");
		}
		for (int i = 0; i < count[1]; i++) {
			out.append((min+1)+ " ");
		}
		for (int i = 0; i < count[2]; i++) {
			out.append((min+2)+ " ");
		}
		System.out.println(out.toString().substring(0, out.length()-1));
	}
}

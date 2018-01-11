package codechef;

import java.util.Arrays;
import java.util.Scanner;

//https://www.codechef.com/JAN18/problems/CHEFPALS
public class ChefAndPalindromes {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = Integer.parseInt(s.nextLine());
		int[] l = Arrays.stream(s.nextLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
		int[] b = Arrays.stream(s.nextLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
		int[] diff = new int[l.length];
		for (int i = 0; i < diff.length; i++) {
			diff[i] = l[i] - b[i];
		}
		s.close();
		StringBuilder out = new StringBuilder();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < b[i]; j++) {
				out.append('b');
			}
			for (int j = 0; j < diff[i]; j++) {
				out.append('w');
			}
			out.append("\r\n");
		}
		for (int i = 1; i <= n; i++) {
			out.append(i + " ");
		}
		System.out.println(out);
	}
}

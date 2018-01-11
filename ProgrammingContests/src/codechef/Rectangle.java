package codechef;

import java.util.Arrays;
import java.util.Scanner;
//https://www.codechef.com/JAN18/problems/RECTANGL
public class Rectangle {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		s.nextLine();
		for (int i = 0; i < n; i++) {
			int[] a = Arrays.stream(s.nextLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).sorted().toArray();
			if (a[0] == a[1] && a[2] == a[3]) {
				System.out.println("YES");
			} else {
				System.out.println("NO");
			}
		}
		s.close();
	}
}

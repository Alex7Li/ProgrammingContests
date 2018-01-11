package codeforces;
import java.util.Arrays;
import java.util.Scanner;

public class PizzaSeparation {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		s.nextLine();
		int[] a = Arrays.stream(s.nextLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
		s.close();
		int sum;
		int min = 180;
		for (int i = 0; i < a.length; i++) {
			sum = 0;
			for (int j = 0; j < a.length; j++) {
				sum += a[(i + j) % a.length];
				min = Math.min(min, Math.abs(180 - sum));
			}
		}
		System.out.println(min * 2);
	}
}

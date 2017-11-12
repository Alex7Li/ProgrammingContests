package codeforces;
import java.util.Scanner;

public class LocalExtrema {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int[] arr = new int[n];
		int count = 0;
		for (int i = 0; i < n; i++) {
			arr[i] = s.nextInt();
		}
		for (int i = 1; i < n - 1; i++) {
			if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
				count++;
			} else if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
				count++;
			}
		}
		System.out.println(count);
		s.close();
	}
}

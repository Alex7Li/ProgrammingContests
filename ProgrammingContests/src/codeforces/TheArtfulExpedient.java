package codeforces;
import java.util.Arrays;
import java.util.Scanner;

public class TheArtfulExpedient {
	//http://codeforces.com/problemset/problem/869/A
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = Integer.parseInt(s.nextLine());
		int[] a = Arrays.stream(s.nextLine().split(" ")).mapToInt(x->Integer.parseInt(x)).toArray();
		int[] b = Arrays.stream(s.nextLine().split(" ")).mapToInt(x->Integer.parseInt(x)).toArray();
		s.close();
		int[] ab = new int[2*n];
		for (int i = 0; i < a.length; i++) {
			ab[i] = a[i];
			ab[i+n] = b[i];
		}
		Arrays.sort(ab);
		boolean even = true;
		for (int i = 0; i < b.length; i++) {
			for (int j = 0; j < b.length; j++) {
				if(Arrays.binarySearch(ab, a[i]^b[j])>=0) {
					even = !even;
				}
			}
		}
		if(even) {
			System.out.println("Karen");
		}else {
			System.out.println("Koyomi");
		}
	}
}

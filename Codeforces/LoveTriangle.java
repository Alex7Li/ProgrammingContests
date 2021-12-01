package codeforces;
import java.util.Scanner;
//http://codeforces.com/contest/939/problem/A
public class LoveTriangle {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		for (int i = 0; i <n; i++) {
			a[i] = sc.nextInt()-1;
		}
		sc.close();
		boolean triFound = false;
		for (int i = 0; i < a.length; i++) {
			if(a[a[a[i]]] == i && a[i] != i) {
				triFound = true;
			}
		}
		if(triFound) {
			System.out.println("YES");
		}else {
			System.out.println("NO");
		}
	}
}

package codeforces;
import java.util.ArrayList;
import java.util.Scanner;
//http://codeforces.com/problemset/problem/952/C
public class RaviolliSort {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int size = sc.nextInt();
		ArrayList<Integer> a = new ArrayList<Integer>();
		for (int i = 0; i < size; i++) {
			a.add(sc.nextInt());
		}
		sc.close();
		for (int i = 0; i < a.size() - 1; i++) {
			if (Math.abs(a.get(i) - a.get(i + 1)) > 1) {
				System.out.println("NO");
				return;
			}
		}
		while (!a.isEmpty()) {
			int max = a.get(0);
			int ind = 0;
			for (int i = 0; i < a.size(); i++) {
				if (a.get(i) > max) {
					ind = i;
					max = a.get(i);
				}
			}
			if (ind != 0 && ind != a.size() - 1 && Math.abs(a.get(ind + 1) - a.get(ind - 1)) > 1) {
				System.out.println("NO");
				return;
			}
			a.remove(ind);
		}
		System.out.println("YES");
	}
}

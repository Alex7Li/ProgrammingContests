package codeforces;
import java.util.LinkedList;
import java.util.Scanner;

//http://codeforces.com/problemset/problem/855/A
public class TomRiddleDiary {
	public static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int n = sc.nextInt();
		sc.nextLine();
		LinkedList<String> list = new LinkedList<String>();
		for (int i = 0; i<n; i++) {
			String name = sc.nextLine();
			if(list.contains(name)) {
				System.out.println("YES");
			}else {
				list.add(name);
				System.out.println("NO");
			}
		}
	}
}

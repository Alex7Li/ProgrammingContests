package codeforces;
import java.util.Scanner;
//http://codeforces.com/contest/976/problem/A
public class MinimumBinaryNumber {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		sc.nextLine();
		char[] c = sc.nextLine().toCharArray();
		sc.close();
		if(c.length==1 && c[0] == '0') {
			System.out.println("0");
			return;
		}
		int count0 = 0;
		for (int i = 0; i < c.length; i++) {
			if (c[i] == '0') {
				count0++;
			}
		}
		System.out.print("1");
		for (int i = 0; i < count0; i++) {
			System.out.print("0");
		}
		System.out.println();
	}
}

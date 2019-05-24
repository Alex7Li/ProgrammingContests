package codeforces;
import java.util.Scanner;
//http://codeforces.com/problemset/problem/932/A
public class PalindromicSupersequence {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		char[] a = sc.nextLine().toCharArray();
		char[] aRev = new char[a.length];
		sc.close();
		for (int i = a.length-1; i >=0; i--) {
			aRev[a.length-1-i] = a[i];
		}
		for (int i = 0; i < a.length; i++) {
			System.out.print(a[i]);
		}
		for (int i = 0; i < aRev.length; i++) {
			System.out.print(aRev[i]);
		}
		
	}
}

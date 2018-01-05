package codeforces;
import java.util.Arrays;
import java.util.Scanner;
//http://codeforces.com/contest/902/problem/C
public class HashingTrees {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		sc.nextLine();
		int[] a = Arrays.stream(sc.nextLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
		sc.close();
		int loc = -1;
		for (int i = 0; i < a.length; i++) {
			if (a[i] != 1) {
				if (i + 1 < a.length && a[i + 1] != 1) {
					loc = i+1;
					break;
				}
			}
		}
		if (loc == -1) {
			System.out.println("perfect");
		} else {
			System.out.println("ambiguous");
			StringBuilder treeA = new StringBuilder();
			StringBuilder treeB = new StringBuilder();
			int vert = 0;
			for (int i = 0; i < a.length; i++) {
				if (loc != i) {
					for (int j = 0; j < a[i]; j++) {
						treeA.append(vert + " ");
						treeB.append(vert + " ");
					}
				} else {
					treeA.append((vert - 1) + " ");
					treeB.append(vert + " ");
					for (int j = 1; j < a[i]; j++) {
						treeA.append(vert + " ");
						treeB.append(vert + " ");
					}
				}
				vert += a[i];
			}
			System.out.println(treeA);
			System.out.println(treeB);
		}
	}
}

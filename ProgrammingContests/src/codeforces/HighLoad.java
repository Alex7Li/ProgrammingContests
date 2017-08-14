package codeforces;
import java.util.Scanner;

public class HighLoad {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int nodes = scan.nextInt();
		int exitNodes = scan.nextInt();
		scan.close();
		if (nodes - exitNodes == 2) {
			System.out.println(3);
			System.out.println(1 + " " + 2);
			System.out.println(2 + " " + 3);
			exitNodes--;
		} else {
			System.out.println(2);
			for (int i = 1; i < nodes - exitNodes; i++) {
				System.out.println(i + " " + (i + 1));
			}
			if (nodes - exitNodes != 1) {
				System.out.println(1 + " " + (nodes - exitNodes));
			}
		}
		// normal nodes = 1,2...nodes-exitNodes
		// ignore 3
		for (int i = nodes - exitNodes + 1; i <= nodes; i++) {
			System.out.println(1 + " " + i);
		}
	}
}

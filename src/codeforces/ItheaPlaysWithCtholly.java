package codeforces;

import java.util.Scanner;

//http://codeforces.com/problemset/problem/896/B
public class ItheaPlaysWithCtholly {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		s.nextInt();
		int c = s.nextInt();
		boolean hasWon = false;
		int[] a = new int[n];
		while (!hasWon) {
			int nextInstruction = s.nextInt();
			int addedInd = -1;
			if (nextInstruction <= c / 2) {
				// add element to the left
				for (int i = 0; i < a.length; i++) {
					if (a[i] == 0 || a[i] > nextInstruction) {
						a[i] = nextInstruction;
						addedInd = i+1;
						break;
					}
				}
			} else {
				// add to the right
				for (int i = a.length - 1; i >= 0; i--) {
					if (a[i] == 0 || a[i] < nextInstruction) {
						a[i] = nextInstruction;
						addedInd = i+1;
						break;
					}
				}
			}
			System.out.println(addedInd);			
			//check if Chtolly has won
			hasWon = true;
			for (int i = 0; i < a.length-1; i++) {
				if(a[i] == 0 || a[i]>a[i+1]) {
					hasWon=false;
				}
			}
		}
		s.close();
	}
}

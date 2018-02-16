package codeforces;
import java.util.Arrays;
import java.util.Scanner;
//http://codeforces.com/problemset/problem/756/A
public class PavelAndBarbeque {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		sc.nextLine();
		//int n = Integer.parseInt(sc.nextLine());
		int[] perm = Arrays.stream(sc.nextLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
		int bCount = Arrays.stream(sc.nextLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).sum();
		sc.close();
		int changesNeeded = (bCount + 1) % 2;
		// loop[i] = the loop that the skewer in location i is in
		int[] loop = new int[perm.length];
		int loopsFound = 0;
		for (int i = 0; i < loop.length; i++) {
			if (loop[i] == 0) {
				loopsFound++;
				loop[i] = loopsFound;
				int nextEl = perm[i]-1;
				while(nextEl != i) {
					loop[nextEl] = loopsFound;
					nextEl = perm[nextEl]-1;
				}
			}
		}
		if(loopsFound!=1) {
			changesNeeded += loopsFound;
		}
		System.out.println(changesNeeded);
	}
}

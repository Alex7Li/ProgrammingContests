package kattis;
import java.util.Arrays;
import java.util.Scanner;

public class Kayaking {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int[] weights = new int[n * 2];
		for (int i = 0; i < 2 * n; i++) {
			weights[i] = s.nextInt();
		}
		s.close();
		Arrays.sort(weights);
		int bestInst = Integer.MAX_VALUE;
		for (int i = 0; i < weights.length; i++) {
			for (int j = i + 1; j < weights.length; j++) {
				int inst = 0;
				int[] weights2 = new int[2 * (n - 1)];
				int skipped = 0;
				for (int k = 0; k < 2 * n; k++) {
					if (k != i && k != j) {
						weights2[k-skipped] = weights[k];
					}else {
						skipped++;
					}
				}
				for (int k = 0; k < weights2.length; k+=2) {
					inst += (weights2[k+1]-weights2[k]);
				}
				if(inst<bestInst) {
					bestInst = inst;
				}
			}
		}
		System.out.println(bestInst);
	}
}

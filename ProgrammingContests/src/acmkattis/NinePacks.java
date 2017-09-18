package acmkattis;

import java.util.Scanner;

public class NinePacks {
	public static void main(String[] args) {
		@SuppressWarnings("resource")
		Scanner s = new Scanner(System.in);
		int H = s.nextInt();
		int[] hotdogs = new int[H];
		int hSum = 0;
		for (int i = 0; i < H; i++) {
			hotdogs[i] = s.nextInt();
			hSum += hotdogs[i];
		}
		int B = s.nextInt();
		int bSum = 0;
		int[] buns = new int[B];
		for (int i = 0; i < B; i++) {
			buns[i] = s.nextInt();
			bSum += buns[i];
		}
		// minH[i][j] = min number of packs needed to buy
		// i hotdogs of total price j.
		int[][] minH = new int[H + 1][hSum+1];
		int[][] minB = new int[B + 1][bSum+1];
		minB[0][0]=0;
		minH[0][0]=0;
		for (int i = 1; i <= hSum; i++) {
			minH[0][i] = Integer.MAX_VALUE - 1;
		}
		for (int i = 1; i <= H; i++) {
			minH[i][0] = 0;
			for (int j = 1; j <= hSum; j++) {
				if (j - hotdogs[i-1] >= 0) {
					minH[i][j] = Math.min(minH[i - 1][j], minH[i-1][j - hotdogs[i-1]] + 1);
				} else {
					minH[i][j] = minH[i - 1][j];
				}
			}
		}
		for (int i = 1; i <= bSum; i++) {
			minB[0][i] = Integer.MAX_VALUE - 1;
		}
		for (int i = 1; i <= B; i++) {
			minB[i][0] = 0;
			for (int j = 1; j <= bSum; j++) {
				if (j - buns[i-1] >= 0) {
					minB[i][j] = Math.min(minB[i - 1][j], minB[i-1][j - buns[i-1]] + 1);
				} else {
					minB[i][j] = minB[i - 1][j];
				}
			}
		}
		int min = Integer.MAX_VALUE;
		for (int i = 1; i <= Math.min(bSum, hSum); i++) {
			if (minB[B][i] != Integer.MAX_VALUE - 1 && minH[H][i] != Integer.MAX_VALUE - 1) {
				if (minB[B][i] + minH[H][i] < min) {
					min = minB[B][i] + minH[H][i];
				}
			}
		}
		if (min == Integer.MAX_VALUE) {
			System.out.println("impossible");
		} else {
			System.out.println(min);
		}
	}
}

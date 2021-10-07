package math.equations;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

//https://www.codechef.com/DEC17/problems/VK18

public class TotalDiamonds {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		int[] dVal = new int[2000001];
		for (int i = 0; i < dVal.length; i++) {
			dVal[i] = Math.abs(getDVal(i));
		}
		long[] firstDiag = new long[1000002];
		long sum = 0;
		for (int i = 1; i < firstDiag.length; i++) {
			sum += i * dVal[i+1];
			firstDiag[i] = sum;
		}
		for (int ct = 0; ct < t; ct++) {
			int n = Integer.parseInt(br.readLine());
			long count = firstDiag[n];
			for (int i = n - 1; i > 0; i--) {
				count += i * dVal[2 * n - i + 1];
			}
			System.out.println(count);
		}
	}

	private static int getDVal(int i) {
		int digitContrib;
		if (i % 2 == 0) {
			digitContrib = i % 10;
		} else {
			digitContrib = -i % 10;
		}
		if (i > 9) {
			return getDVal(i / 10) + digitContrib;
		} else {
			return digitContrib;
		}
	}
}

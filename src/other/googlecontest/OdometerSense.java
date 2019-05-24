package other.googlecontest;

import java.util.Arrays;

//https://brilliant.org/discussions/thread/odometer-sense/
public class OdometerSense {
	final static int digits = 4;
	public static void main(String[] args) {
		final int max = (int) Math.pow(10, digits+1);
		int count = 0;
		for (int i = 0; i < max; i++) {
			for (int j = 0; j < max; j++) {
				int[] iDigits = getDigitListNoLeadingZeros(i);
				int[] jDigits = getDigitListNoLeadingZeros(j);
				if(Arrays.equals(iDigits, jDigits)) {
					count++;
				}
			}
		}
		System.out.println((double)count/(max*max));
	}
	public static int[] getDigitListNoLeadingZeros(int val) {
		int[] a = new int[digits];
		for (int i = 0; i < digits; i++) {
			a[i] = val%10;
			val/=10;
		}
		Arrays.sort(a);
		return a;
	}
}

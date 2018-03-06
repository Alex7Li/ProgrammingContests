package codeforces;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;
//http://codeforces.com/contest/935/problem/D
public class FafaAndAncientAlphabet {
	private static long MOD = 1000000007;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] word1 = new int[n];
		int[] word2 = new int[n];
		for (int i = 0; i < n; i++) {
			word1[i] = sc.nextInt();
		}
		for (int i = 0; i < n; i++) {
			word2[i] = sc.nextInt();
		}
		sc.close();
		boolean word1Greater = false;
		// let's shorten the words if we can
		int[] a1 = new int[n];
		int[] a2 = new int[n];
		int trimLen = 0;
		for (int i = 0; i < word2.length; i++) {
			if (word1[i] == 0 || word2[i] == 0) {
				trimLen++;
				a1[i] = word1[i];
				a2[i] = word2[i];
			} else {
				if (word2[i] != word1[i]) {
					word1Greater = word1[i] > word2[i];
					break;
				}
			}
		}
		if (trimLen == 0) {
			if (word1Greater) {
				System.out.println(1);
			} else {
				System.out.println(0);
			}
			return;
		}
		a1 = Arrays.copyOf(a1, trimLen);
		a2 = Arrays.copyOf(a2, trimLen);
		long[] denoms = new long[trimLen + 1];
		denoms[0] = 1;
		for (int i = 1; i < denoms.length; i++) {
			denoms[i] = (denoms[i - 1] * m) % MOD;
		}
		// all the numerators will be doubled, denoms will be
		// doubled at the end
		long curNum = 0;
		if (word1Greater) {
			curNum += 2;
		}
		long finalNumerator = curNum;
		for (int i = trimLen - 1; i >= 0; i--) {
			if (a1[i] == 0 && a2[i] == 0) {
				curNum = m - 1;
			} else if (a1[i] == 0) {
				curNum = 2 * (m - a2[i]);
			} else {// a2[i] == 0
				curNum = 2 * (a1[i] - 1);
			}
			curNum *= denoms[trimLen - i - 1];
			finalNumerator = (curNum + finalNumerator) % MOD;
		}
		long Q = modInverse(denoms[denoms.length - 1] * 2);
		System.out.println((finalNumerator * Q) % MOD);
	}

	public static long modInverse(long a) {
		BigInteger num = BigInteger.valueOf(a);
		num =num.modInverse(BigInteger.valueOf(MOD));
		return num.intValue();
	}
}

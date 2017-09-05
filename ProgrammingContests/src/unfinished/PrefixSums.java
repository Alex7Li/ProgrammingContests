package unfinished;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class PrefixSums {
	static long k;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		k = Long.parseLong(br.readLine().split(" ")[1]);
		String[] arrayStr = br.readLine().split(" ");
		long[] arr = new long[arrayStr.length];
		for (int i = 0; i < arr.length; i++) {
			long val = Long.parseLong(arrayStr[i]);
			{
				arr[i] = val;
				if (val >= k) {
					System.out.println(0);
					return;
				}
			}
		}
			bruteForce(arr);
	}

	private static void bruteForce(long[] arr) {
		int arrNum = 0;
		while (true) {
			arrNum++;
			long[] arrNext = new long[arr.length];
			arrNext[0] = arr[0];
			for (int i = 1; i < arrNext.length; i++) {
				arrNext[i] = arrNext[i-1] + arr[i];
				if (arrNext[i] >= k) {
					System.out.println(arrNum);
					return;
				}
			}
			arr = arrNext;
		}
	}
}

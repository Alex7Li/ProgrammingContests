package codeforces;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
//http://codeforces.com/contest/953/problem/C
public class IsThisZebra {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		br.readLine();
		int[] a = Arrays.stream(br.readLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
		int stripeLen = a.length;
		for (int i = 0; i < a.length; i++) {
			if (a[i] != a[0]) {
				stripeLen = i;
				break;
			}
		}
		if (a.length % stripeLen == 0) {
			for (int i = stripeLen; i < a.length; i += stripeLen) {
				for (int j = i; j < (i+stripeLen); j++) {
					if (a[j] == a[i - 1]) {
						System.out.println("NO");
						return;
					}
				}
			}
			System.out.println("YES");
			return;
		}
		System.out.println("NO");
		return;
	}
}

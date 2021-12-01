package codeforces;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

//http://codeforces.com/contest/911/problem/D
public class InversionCounting {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		br.readLine();
		int[] a = Arrays.stream(br.readLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
		boolean evenInv = true;
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a.length - 1; j++) {
				if (a[j] > a[j + 1]) {
					int temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
					evenInv = !evenInv;
				}
			}
		}
		int q = Integer.parseInt(br.readLine());
		for (int i = 0; i < q; i++) {
			int[] sw = Arrays.stream(br.readLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
			int len = sw[1] - sw[0];
			if ((len) * (len + 1) % 4 != 0) {
				evenInv = !evenInv;
			}
			if (evenInv) {
				System.out.println("even");
			} else {
				System.out.println("odd");
			}
		}

	}
}

package codeforces;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

////http://codeforces.com/contest/940/problem/D
public class AlenaAndHeater {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		br.readLine();
		int[] a = Arrays.stream(br.readLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
		char[] b = br.readLine().toCharArray();
		int minL = -1000000000;
		int maxR = 1000000000;
		for (int i = 4; i < b.length; i++) {
			if (b[i] - b[i - 1] == 1) {
				minL = Math.max(minL, maxLast5(i, a) + 1);
				i += 3;
			} else if (b[i] - b[i - 1] == -1) {
				maxR = Math.min(maxR, minLast5(i, a) - 1);
				i += 3;
			}
		}
		System.out.println(minL + " " + maxR);
	}

	private static int minLast5(int index, int[] a) {
		int min = a[index - 4];
		for (int i = index - 3; i <= index; i++) {
			min = Math.min(min, a[i]);
		}
		return min;
	}

	private static int maxLast5(int index, int[] a) {
		int max = a[index - 4];
		for (int i = index - 3; i <= index; i++) {
			max = Math.max(max, a[i]);
		}
		return max;
	}
}

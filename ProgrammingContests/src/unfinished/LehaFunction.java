package unfinished;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.logging.Level;
import java.util.logging.Logger;

//http://codeforces.com/contest/841/problem/C
public class LehaFunction {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Logger.getGlobal().setLevel(Level.ALL);
		Logger.getGlobal().info("Testing");
		br.readLine();
		String[] in1 = br.readLine().split(" ");
		String[] in2 = br.readLine().split(" ");
		ArrayList<Integer> A = new ArrayList<Integer>();
		ArrayInt[] B = new ArrayInt[in1.length];
		for (int i = 0; i < in1.length; i++) {
			A.add(Integer.parseInt(in1[i]));
			// original
			B[i] = new ArrayInt(i, Integer.parseInt(in2[i]));
		}
		int[] ans = new int[in1.length];
		Collections.sort(A);
		// decending order
		Arrays.sort(B);
		int marker = A.size() - 1;
		for (int i = 0; i < B.length; i++) {
			for (int j = marker; j >= 0; j--) {
				if (B[i].value > A.get(j)) {
					ans[B[i].index] = A.get(j - 1);
					A.remove(j - 1);
					break;
				} else {
					marker--;
				}
			}
			if (marker == -1) {
				ans[B[i].index] = A.get(0);
				A.remove(0);
			}
		}

		StringBuilder s = new StringBuilder();
		for (int i = 0; i < ans.length; i++) {
			s.append(ans[i] + " ");
		}
		System.out.println(s);
	}
}

class ArrayInt implements Comparable<ArrayInt> {
	int index;
	int value;

	public ArrayInt(int i, int v) {
		index = i;
		value = v;
	}

	@Override
	public int compareTo(ArrayInt a) {
		return a.value - value;
	}

	@Override
	public String toString() {
		return value + "";
	}
}

package codeforces;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.TreeSet;

//http://codeforces.com/contest/915/problem/E
//model solution: http://codeforces.com/contest/915/submission/34229183
//I DIIIIDDD ITTTTTT!!!!!!!! YESSSSSSSSSSSS!!!!!!!!!!!!
public class PhysicalEducationLessons2 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		TreeSet<int[]> segments = new TreeSet<int[]>(new Comparator<int[]>() {
			@Override
			public int compare(int[] seg1, int[] seg2) {
				// sorted by right border
				return Integer.compare(seg1[1], seg2[1]);
			}
		});
		int n = Integer.parseInt(br.readLine());
		int q = Integer.parseInt(br.readLine());
		int workingDays = n;
		StringBuilder ans = new StringBuilder();
		for (int i = 0; i < q; i++) {
			String[] input = br.readLine().split(" ");
			int[] in = new int[input.length];
			for (int j = 0; j < in.length; j++) {
				in[j] = Integer.parseInt(input[j]);
			}
			int left = in[0];
			int right = in[1];
			int[] next = segments.ceiling(new int[] { 0, left });
			int leftBound = left;
			int rightBound = right;
			while (next != null) {
				if (next[0] > right) {
					break;
				}
				workingDays += (next[1] - next[0] + 1);
				segments.remove(next);
				if (next[0] < left) {
					leftBound = next[0];
				}
				if (next[1] > right) {
					rightBound = next[1];
					break;
				}
				next = segments.ceiling(next);
			}
			if (in[2] == 1) {
				workingDays -= (rightBound - leftBound + 1);
				segments.add(new int[] { leftBound, rightBound });
			} else {
				workingDays -= (left - leftBound);
				workingDays -= rightBound - right;
				if (leftBound != left) {
					segments.add(new int[] { leftBound, left - 1 });
				}
				if (rightBound != right) {
					segments.add(new int[] { right + 1, rightBound });
				}
			}
			ans.append(workingDays + "\r\n");
		}
		System.out.println(ans);
	}
}
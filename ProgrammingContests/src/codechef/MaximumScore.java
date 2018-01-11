package codechef;
//https://www.codechef.com/JAN18/problems/MAXSC

import java.util.Arrays;
import java.util.Scanner;

public class MaximumScore {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int t = s.nextInt();
		s.nextLine();
		for (int i = 0; i < t; i++) {
			int n = s.nextInt();
			boolean possible = true;
			s.nextLine();
			double[][] arrays = new double[n][];
			for (int j = 0; j < n; j++) {
				arrays[j] = Arrays.stream(s.nextLine().split(" ")).mapToDouble(x -> Double.parseDouble(x)).sorted()
						.toArray();
			}
			double max = arrays[n-1][arrays[n-1].length-1];
			long sum = (long) (max+.01);
			for (int j = n - 2; j >= 0; j--) {
				int ind = Arrays.binarySearch(arrays[j], max-.5);
				int loc =-(ind+2);
				if(loc < 0) {
					possible = false;
				}else {
					max = arrays[j][loc];
					sum += (long)(max+.01);
				}
			}
			if(possible) {
				System.out.println(sum);
			}else {
				System.out.println(-1);
			}
		}
		s.close();
	}
}

package codeforces;
import java.util.Arrays;
import java.util.Scanner;
//http://codeforces.com/contest/948/problem/C
public class ProducingSnow {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int days = sc.nextInt();
		sc.nextLine();
		long[] pileSizes = Arrays.stream(sc.nextLine().split(" ")).mapToLong(x -> Long.parseLong(x)).toArray();
		long[] temp = Arrays.stream(sc.nextLine().split(" ")).mapToLong(x -> Long.parseLong(x)).toArray();
		// amount of melted snow from an infinite pile from the start day to the end
		// day.
		double[] totalMelt = new double[days + 1];
		for (int i = 1; i < days + 1; i++) {
			totalMelt[i] = totalMelt[i - 1] + temp[i - 1];
		}
		// amount of extra melting each day
		long[] rem = new long[days + 1];
		// amount of change in piles fully melting each day
		long[] fullMelt = new long[days + 2];
		// amount of piles melting for the day
		long curMelt = 0;
		StringBuilder res = new StringBuilder();
		for (int i = 0; i < pileSizes.length; i++) {
			// find end melt time
			int meltTime = Arrays.binarySearch(totalMelt, pileSizes[i] + totalMelt[i] + .5);
			fullMelt[i]++;
			meltTime = -(meltTime + 1);
			if (meltTime - 1 != days) {
				long end = (pileSizes[i] + (long)(totalMelt[i])) - (long)(totalMelt[meltTime - 1]);
				fullMelt[meltTime - 1]--;
				rem[meltTime - 1] += end;
			}

			curMelt += fullMelt[i];
			long dayMelt = (temp[i] * curMelt + rem[i]);
			res.append(dayMelt + " ");
		}
		sc.close();
		System.out.println(res.substring(0, res.length() - 1));

	}
}

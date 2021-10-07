package codeforces;
import java.util.Scanner;

//http://codeforces.com/contest/939/problem/C
/**
 * WARNING: this code is really messy because I started this problem in a rush
 * and didn't know what I was trying to find. Then when I realized I tried to
 * slightly modify the code, and kept getting strange errors. Because I didn't
 * want to fix the code, I spent an hour or two trying to figure out what
 * formula to do on line 42 to fix indicies, at first out of laziness, then
 * later because I was frustrated and really wanted to know. I finally got it,
 * but then realized I also needed to output the smallest, meaning my approach
 * sucked. However, I was so excited to get the formula at last that I decided
 * it was worth it to make the code a bit messy so I could get the satisfaction
 * of correctly submitting my more difficult bad approach.
 **/
public class ConvienentForEverybody {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] times = new int[n];
		for (int i = 0; i < n; i++) {
			times[i] = sc.nextInt();
		}
		int s = sc.nextInt();
		int f = sc.nextInt();
		sc.close();
		int dist = f - s;
		long cur = 0;
		for (int i = 0; i < dist; i++) {
			cur += times[i];
		}
		long bestAttendance = cur;
		int bestInd = 0;
		for (int i = dist; i < n + dist; i++) {
			cur -= times[(i - dist) % n];
			cur += times[i % n];
			if (bestAttendance < cur) {
				bestAttendance = cur;
				bestInd = i - dist + 1;
			}
		}
		int minans = (s - bestInd + n) % n;
		if (minans == 0) {
			minans += n;
		}
		for (int i = dist; i < n + dist - 1; i++) {
			cur -= times[(i - dist) % n];
			cur += times[i % n];
			if (bestAttendance == cur) {
				if (((s - (i - dist + 1) + n) % n) != 0) {
					minans = Math.min(minans, (s - (i - dist + 1) + n) % n);
				}
			}
		}
		System.out.println(minans);
	}
}

package codeforces;
import java.util.PriorityQueue;
import java.util.Scanner;
//http://codeforces.com/contest/967/problem/A
public class MindTheGap {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int s = sc.nextInt();
		PriorityQueue<Integer> times = new PriorityQueue<>();
		for (int i = 0; i < n; i++) {
			times.add(sc.nextInt() * 60 + sc.nextInt());			
		}
		int lastT = -(s+1);
		int ans = -1;
		while (!times.isEmpty()) {
			int next = times.poll();
			if (next - lastT > 2 * s + 1) {
				ans = lastT + s + 1;
				break;
			}
			lastT = next;
		}
		if (ans == -1) {
			ans = lastT + s + 1;
		}
		System.out.println(ans / 60 + " " + ans % 60);
		sc.close();
	}
}

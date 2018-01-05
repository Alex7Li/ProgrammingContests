package codeforces;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
//http://codeforces.com/problemset/problem/903/C
public class BoxesPacking {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Map<Integer,Integer> boxesOfSize = new HashMap<>();
		int n = sc.nextInt();
		for (int i = 0; i < n; i++) {
			int val = sc.nextInt();
			boxesOfSize.put(val, boxesOfSize.getOrDefault(val, 0)+1);
		}
		int max = -1;
		for(int i:boxesOfSize.keySet()) {
			max = Math.max(max, boxesOfSize.get(i));
		}
		System.out.println(max);
		sc.close();
	}
}

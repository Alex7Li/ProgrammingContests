package codeforces;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeMap;

public class TwoTVs {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		TreeMap<Integer, Integer> events = new TreeMap<Integer, Integer>();
		for (int i = 0; i < n; i++) {
			String[] input = br.readLine().split(" ");
			int start = Integer.parseInt(input[0]);
			int end = Integer.parseInt(input[1]);
			events.put(start, events.getOrDefault(start, 0) + 1);
			events.put(end + 1, events.getOrDefault(end + 1, 0) - 1);
		}
		int curTVs = 0;
		boolean canWatch = true;
		for (Integer e : events.values()) {
			curTVs = curTVs + e;
			if (curTVs > 2) {
				canWatch = false;
			}
		}
		if (canWatch) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
	}
}

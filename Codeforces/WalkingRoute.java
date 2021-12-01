package codeforces;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.Stack;
//http://codeforces.com/contest/979/problem/C
public class WalkingRoute {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int[] params = Arrays.stream(br.readLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
		int n = params[0];
		int x = params[1];
		int y = params[2];
		List<List<Integer>> roads = new ArrayList<>();
		Set<Integer> visited = new HashSet<>();
		for (int i = 0; i <= n; i++) {
			roads.add(new ArrayList<Integer>());
		}
		for (int i = 0; i < n - 1; i++) {
			int[] cities = Arrays.stream(br.readLine().split(" ")).mapToInt(xa -> Integer.parseInt(xa)).toArray();
			roads.get(cities[0]).add(cities[1]);
			roads.get(cities[1]).add(cities[0]);
		}
		Stack<Integer> st = new Stack<Integer>();
		int xCount = 1;
		int yCount = 0;
		visited.add(x);
		for (int cit : roads.get(x)) {
			boolean seenY = false;
			boolean seenYAgain = false;
			st.push(cit);
			int count = 0;
			while (!st.isEmpty()) {
				int cur = st.pop();
				if (!visited.contains(cur)) {
					visited.add(cur);
					count++;
					if (cur == y) {
						seenY = true;
						st.push(y);
					}
					if (!seenYAgain && seenY) {
						yCount++;
					}
					for (int city : roads.get(cur)) {
						if (!visited.contains(city)) {
							st.push(city);
						}
					}
				} else if (cur == y) {
					seenYAgain = true;
				}
			}
			if (seenY) {
				seenY = false;
				seenYAgain = false;
			} else {
				xCount += count;
			}
		}
		// System.out.println(xCount + " " + yCount);
		System.out.println((long)(n) * (n - 1) - (long)(yCount) * xCount);
	}
}
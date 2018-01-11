package temp;

import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Scanner;

//http://codeforces.com/problemset/problem/144/D
public class MissleSilos {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int m = s.nextInt();
		int capLoc = s.nextInt() - 1;
		City[] cities = new City[n];
		// O(n)
		for (int i = 0; i < n; i++) {
			cities[i] = new City();
		}
		int[][] roads = new int[m][3];
		// O(m)
		for (int i = 0; i < m; i++) {
			int u = s.nextInt() - 1;
			int v = s.nextInt() - 1;
			int d = s.nextInt();
			roads[i] = new int[] { u, v, d };
			cities[u].connected.put(cities[v], d);
			cities[v].connected.put(cities[u], d);
		}
		int siloDist = s.nextInt();
		s.close();
		if (siloDist == 0) {
			System.out.println(1);
			return;
		}
		int count = 0;
		PriorityQueue<City> Q = new PriorityQueue<>();
		Q.add(cities[capLoc]);
		cities[capLoc].distToCapital = 0;
		// O(m + nlogn)
		while (!Q.isEmpty()) {
			City next = Q.poll();
			for (City connectedCity : next.connected.keySet()) {
				if (!connectedCity.checked) {
					if (connectedCity.distToCapital > next.distToCapital + next.connected.get(connectedCity)) {
						connectedCity.distToCapital = next.distToCapital + next.connected.get(connectedCity);
					}
					if (!Q.contains(connectedCity)) {
						Q.add(connectedCity);
					}
				}
			}
			next.checked = true;
		}
		// O(n)
		for (int i = 0; i < cities.length; i++) {
			if (cities[i].distToCapital == siloDist) {
				count++;
			}
		}
		// O(m)
		for (int i = 0; i < roads.length; i++) {
			int u = cities[roads[i][0]].distToCapital;
			int v = cities[roads[i][1]].distToCapital;
			int d = roads[i][2];
			if (v > u) {
				int temp = v;
				v = u;
				u = temp;
			}
			assert u >= v;
			if (u - v == d) {// max dist is at an edge
				if (siloDist > v && siloDist < u) {// silo is on this road
					count++;
				}
			} else if (siloDist > v) { // max dist on this road and a silo could be on this road
				// max dist = u + x = v + (d-x)
				// u - v = d-2x;
				// d - (u-v) = 2x
				int x2 = d - (u - v);
				int maxDist = u + x2 / 2;
				if (x2 % 2 == 0) {
					if (siloDist < maxDist) {
						if (siloDist <= u) {
							count++;
						} else {
							count += 2;
						}
					} else if (siloDist == maxDist) {
						count++;
					}
				} else {// x2 is odd
					if (siloDist <= maxDist) {
						if (siloDist <= u) {
							count++;
						} else {
							count += 2;
						}
					}
				}
			}
		}
		System.out.println(count);
	}

	public static class City implements Comparable<City> {

		Map<City, Integer> connected = new HashMap<City, Integer>();
		int distToCapital = Integer.MAX_VALUE;
		boolean checked = false;

		@Override
		public int compareTo(City other) {
			return distToCapital - other.distToCapital;
		}

		@Override
		public String toString() {
			return distToCapital + "";
		}
	}
}

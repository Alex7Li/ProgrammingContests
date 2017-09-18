package acmkattis;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class BigTruck {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		City[] cities = new City[n];
		String[] weightArr = br.readLine().split(" ");
		for (int i = 0; i < n; i++) {
			cities[i] = new City(i + 1, Integer.parseInt(weightArr[i]));
		}
		int m = Integer.parseInt(br.readLine());
		for (int i = 0; i < m; i++) {
			String[] desc = br.readLine().split(" ");
			City city1 = cities[Integer.parseInt(desc[0]) - 1];
			City city2 = cities[Integer.parseInt(desc[1]) - 1];
			int dist = Integer.parseInt(desc[2]);
			city1.connectedCities.put(city2, dist);
			city2.connectedCities.put(city1, dist);
		}
		cities[0].minDist = 0;
		cities[0].maxPacks = cities[0].packages;
		cities[0].travel();
		if (cities[n - 1].minDist == Integer.MAX_VALUE) {
			System.out.println("impossible");
		} else {
			System.out.println(cities[n - 1].minDist + " " + cities[n - 1].maxPacks);
		}
	}
}

class City {
	int loc;
	int packages;
	int maxPacks;
	int minDist = Integer.MAX_VALUE;
	HashMap<City, Integer> connectedCities = new HashMap<City, Integer>();

	public City(int loc, int packages) {
		this.loc = loc;
		this.packages = packages;
	}

	public void travel() {
		for (City c : connectedCities.keySet()) {
			if (c.minDist > minDist + connectedCities.get(c)) {
				c.minDist = minDist + connectedCities.get(c);
				c.maxPacks = maxPacks + c.packages;
			} else if (c.minDist == minDist + connectedCities.get(c)) {
				c.maxPacks = Math.max(c.maxPacks, maxPacks + c.packages);
			}
		}
		for (City c : connectedCities.keySet()) {
			if (c.minDist >= minDist + connectedCities.get(c)) {
				c.travel();
			}
		}
	}

}
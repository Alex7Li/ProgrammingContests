package unfinished;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

//http://codeforces.com/problemset/problem/839/C

public class Journey {
	public static City[] cities;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int cityNum = Integer.parseInt(br.readLine());
		cities = new City[cityNum];
		for (int i = 0; i < cities.length; i++) {
			cities[i] = new City(i);
		}
		Road[] roads = new Road[cityNum-1];
		for (int i = 0; i < cityNum-1; i++) {
			String[] in = br.readLine().split(" ");
			int start = Integer.parseInt(in[0]);
			int end = Integer.parseInt(in[1]);
			roads[i] = new Road(cities[start - 1], cities[end - 1]);
			cities[start - 1].addRoad(roads[i]);
			cities[end - 1].addRoad(roads[i]);
		}
		double ex = 0;
		if (cities[0].connectingRoads.isEmpty()) {
			System.out.println(0);
			return;
		}
		for (Road path : cities[0].connectingRoads) {
			City next = path.leadsTo(cities[0]);
			ex += next.expectedValueFrom(path);
		}
		ex /= cities[0].connectingRoads.size();
		System.out.println(1+ex);
	}
}

class Road {
	City s;
	City e;

	public Road(City start, City end) {
		s = start;
		e = end;
	}

	/**
	 * Assuming input city connects to a road
	 */
	public City leadsTo(City start) {
		if (start == s) {
			return e;
		} else { // (start == e)
			return s;
		}

	}

}

class City {
	int number;
	ArrayList<Road> connectingRoads = new ArrayList<Road>();

	public City(int num) {
		number = num;
	}

	public double expectedValueFrom(Road r) {
		connectingRoads.remove(r);
		if (connectingRoads.isEmpty()) {
			return 0;
		}
		double ex = 0;
		for (Road path : connectingRoads) {
			City next = path.leadsTo(this);
			ex += next.expectedValueFrom(path);
		}
		ex /= connectingRoads.size();
		return 1 + ex;

	}

	public void addRoad(Road r) {
		connectingRoads.add(r);
	}

}
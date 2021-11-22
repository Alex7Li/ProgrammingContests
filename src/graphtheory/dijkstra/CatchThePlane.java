package graphtheory.dijkstra;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

//https://icpc.kattis.com/problems/catch
//DAMN this was hard! Woo!
public class CatchThePlane {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] stParams = br.readLine().split(" ");
		int m = Integer.parseInt(stParams[0]);
		int n = Integer.parseInt(stParams[1]);
		br.readLine();
		Station[] stations = new Station[n];
		PriorityQueue<Event> events = new PriorityQueue<Event>();
		for (int i = 0; i < stations.length; i++) {
			stations[i] = new Station(i);
		}
		for (int i = 0; i < m; i++) {
			String[] busArgs = br.readLine().split(" ");
			Station start = stations[Integer.parseInt(busArgs[0])];
			Station end = stations[Integer.parseInt(busArgs[1])];
			long dTime = Long.parseLong(busArgs[2]);
			long aTime = Long.parseLong(busArgs[3]);
			double p = Double.parseDouble(busArgs[4]);
			Event dep = new Event(dTime, start, p);
			events.add(dep);
			events.add(new Event(aTime, end, dep));
		}
		while(!events.isEmpty()) {
			events.poll().update();
		}
		System.out.println(stations[0].p);
	}

	static class Event implements Comparable<Event> {
		long t;
		Station s;
		Station e;
		Event dep;
		boolean isArrival;
		double prob;
		double endProb;

		Event(long time, Station end, Event departure) {
			isArrival = true;
			t = time;
			e = end;
			dep = departure;
		}

		Event(long time, Station start, double prob) {
			isArrival = false;
			t = time;
			s = start;
			this.prob = prob;
		}

		public void update() {
			if (isArrival) {
				dep.endProb = e.p;
			} else {
				if (s.p < endProb) {
					if (s.lastUpd != t) {
						s.lastUpd = t;
						s.lastp = s.p;
						s.p = prob * endProb + (1 - prob) * s.p;
					}else {
						s.p = Math.max(s.p, prob * endProb + (1 - prob) * s.lastp);
					}
				}
			}
		}

		@Override
		public int compareTo(Event o) {
			int lComp = Long.compare(o.t, this.t);
			if(lComp == 0 && o.isArrival!=this.isArrival) {
				if(this.isArrival) {
					return -1;
				}else {
					return 1;
				}
			}else {
				return lComp;
			}
		}
	}

	static class Station {
		double p = 0.0;
		long lastUpd = -1;
		double lastp = 0.0;

		Station(int index) {
			if (index == 1) {
				p = 1.0;
			}
		}
	}
}

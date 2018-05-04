package kattis;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Iterator;
import java.util.SortedSet;
import java.util.TreeMap;
import java.util.TreeSet;

//https://icpc.kattis.com/problems/catch
//Currently wrong because it gets stackoverflowerror.
public class CatchThePlaneRecursive {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] stParams = br.readLine().split(" ");
		int m = Integer.parseInt(stParams[0]);
		int n = Integer.parseInt(stParams[1]);
		br.readLine();
		// long k = Long.parseLong(br.readLine());
		Station[] stations = new Station[n];
		for (int i = 0; i < stations.length; i++) {
			stations[i] = new Station(i);
		}
		for (int i = 0; i < m; i++) {
			String[] busParams = br.readLine().split(" ");
			Bus b = new Bus(stations[Integer.parseInt(busParams[1])], Long.parseLong(busParams[2]),
					Long.parseLong(busParams[3]), Double.parseDouble(busParams[4]));
			TreeSet<Bus> busSet = stations[Integer.parseInt(busParams[0])].buses;
			busSet.add(b);
		}
		System.out.println(stations[0].calcProb(-1));
	}

	public static class Station {
		int index;
		TreeSet<Bus> buses = new TreeSet<Bus>();
		//probabilities that have been calculated already through other recursive calls.
		TreeMap<Long,Double> probStartingAt = new TreeMap<Long,Double>();
		public Station(int ind) {
			index = ind;
		}

		// get best probablity to reach station 1 on time
		public double calcProb(long stTime) {
			if (this.index == 1) {
				return 1;
			}
			double curP = 0;
			// b has all buses that are catchable
			SortedSet<Bus> b = buses.tailSet(new Bus(new Station(-1), stTime + 1, 0, 0));
			//perhaps we've already calcuated some, though.
			if(probStartingAt.ceilingKey(stTime) != null) {
				long knownTime = probStartingAt.ceilingKey(stTime);
				b = b.headSet(new Bus(new Station(-1),knownTime,0,0));
				curP = probStartingAt.get(knownTime);
			}
			Bus[] busArr = new Bus[b.size()];
			Iterator<Bus> it = b.iterator();
			for (int i = 0; i < b.size(); i++) {
				busArr[b.size() - i - 1] = it.next(); // reversed for convinence
			}
			for (int i = 0; i < busArr.length; i++) {
				Bus bus = busArr[i];
				if (i != busArr.length - 1 && bus.sTime == busArr[i + 1].sTime) {
					// since sTime is the same, we can only try 1 bus, so find the best
					Bus bus2 = busArr[i + 1];
					double bus1P = bus.pCatch * bus.getPGood() + (1 - bus.pCatch) * curP;
					double bus2P = bus2.pCatch * bus2.getPGood() + (1 - bus2.pCatch) * curP;
					if (bus1P > bus2P) {// bus 1 is the best so use it next iteration instead
						busArr[i + 1] = busArr[i];
					}
					// update probability
				} else if (bus.getPGood() > curP) {
					curP = bus.pCatch * bus.getPGood() + (1 - bus.pCatch) * curP;
					probStartingAt.put(bus.sTime-1, curP);
				}
			}
			return curP;
		}
	}

	public static class Bus implements Comparable<Bus> {
		Station end;
		long sTime;
		long eTime;
		double pCatch;
		// best probability of success given that this bus is taken
		private double pGood = -1;

		public Bus(Station end, long stTime, long endTime, double p) {
			this.end = end;
			sTime = stTime;
			eTime = endTime;
			this.pCatch = p;
		}

		public double getPGood() {
			if (pGood == -1) {
				pGood = end.calcProb(eTime);
			}
			return pGood;
		}

		@Override
		public int compareTo(Bus o) {
			int lComp = Long.compare(sTime, o.sTime);
			if (lComp != 0) {
				return lComp;
			}
			int eComp = Integer.compare(end.index, o.end.index);
			if (eComp != 0) {
				return eComp;
			}
			int tComp = Long.compare(eTime, o.eTime);
			if (tComp != 0) {
				return tComp;
			} else {
				return Double.compare(pCatch, o.pCatch);
			}
		}
	}
}

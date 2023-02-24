package BuckeyeProgrammingContest;
import java.io.*;
import java.util.*;
 
class QueueEntry implements Comparable<QueueEntry> {
	int index;
  long distance;
	boolean checked = false;

	public QueueEntry(int index, long distance) {
    this.index = index;
    this.distance = distance;
	}

	@Override
	public int compareTo(QueueEntry o2) {
    if (this.distance < o2.distance) {
      return -1;
    } else if(this.distance > o2.distance){
      return 1;
    } else {
      return 0;
    }
	}
}
public class EightBitTollRoad {
  public static class Road {
    int index;
    long length;
    public Road(int index, long length) {
      this.index = index;
      this.length = length;

    }
  }
  public static int roadInd(int index, long distance) {
    return index * 256 + (int)distance % 256;
  }
  public static void main(String[] args) throws IOException {
    Scanner sc = new Scanner(System.in);
    int n_cities = 256 * 1000;
    ArrayList<ArrayList<Road>> roads = new ArrayList<>(n_cities);
    for(int i = 0; i < n_cities; i++) {
      ArrayList<Road> r = new ArrayList<>();
      roads.add(r);
    }
    int n = sc.nextInt();
    for(int i = 0; i < n; i++){
      int s = sc.nextInt() - 1;
      int t = sc.nextInt() - 1;
      long l = sc.nextLong();
        for(int d = 0; d < 256; d++){
        Road newRoad = new Road(roadInd(t, d + l), l);
        roads.get(roadInd(s, d)).add(newRoad);
      }
    }
    Long[] dist = new Long[n_cities];
    for(int i = 0; i < n_cities; i++){
      dist[i] = -1L;
    }
    dist[0] = 0L;
    // dijistra time
    PriorityQueue<QueueEntry> Q = new PriorityQueue<>();
    Q.add(new QueueEntry(0, 0L));
    while(!Q.isEmpty()) {
      QueueEntry qe = Q.poll();
      if(dist[qe.index] != -1) {
        continue;
      }
      dist[qe.index] = qe.distance;
      for(Road r : roads.get(qe.index)) {
        Q.add(new QueueEntry(r.index, qe.distance + r.length));
      }
    }

    for(int i = 0; i < 256; i ++) {
      Long d = dist[roadInd(1, i)];
      if (d != -1) {
        System.out.println(d);
        break;
      }
    }
    sc.close();
  }
}

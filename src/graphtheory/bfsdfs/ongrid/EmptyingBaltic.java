package graphtheory.bfsdfs.ongrid;

import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;
//https://open.kattis.com/problems/emptyingbaltic
public class EmptyingBaltic {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int h = s.nextInt();
		int w = s.nextInt();
		WaterHole[][] lake = new WaterHole[h][w];
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				lake[i][j] = new WaterHole(i, j, s.nextInt());
			}
		}
		int iloc = s.nextInt()-1;
		int jloc = s.nextInt()-1;
		s.close();
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				lake[i][j].depth = Math.max(lake[iloc][jloc].depth, lake[i][j].depth);
				lake[i][j].depth = Math.min(0, lake[i][j].depth);
			}
		}
		Queue<WaterHole> toCheck = new PriorityQueue<WaterHole>(h * w, new WaterHole(0, 0, 0));
		lake[iloc][jloc].drained -= lake[iloc][jloc].depth;
		toCheck.add(lake[iloc][jloc]);
		while (!toCheck.isEmpty()) {
			WaterHole wat = toCheck.poll();
			if(wat.checked) {
				continue;
			}
			wat.checked=true;
			if (wat.r != 0) {
				wat.drain(lake[wat.r - 1][wat.c]);
				toCheck.add(lake[wat.r - 1][wat.c]);
				if (wat.c != 0) {
					wat.drain(lake[wat.r - 1][wat.c - 1]);
					toCheck.add(lake[wat.r - 1][wat.c - 1]);
				}
				if (wat.c != w - 1) {
					wat.drain(lake[wat.r - 1][wat.c + 1]);
					toCheck.add(lake[wat.r - 1][wat.c + 1]);
				}
			}
			if (wat.r != h - 1) {
				wat.drain(lake[wat.r + 1][wat.c]);
				toCheck.add(lake[wat.r + 1][wat.c]);
				if (wat.c != 0) {
					wat.drain(lake[wat.r + 1][wat.c - 1]);
					toCheck.add(lake[wat.r + 1][wat.c - 1]);
				}
				if (wat.c != w - 1) {
					wat.drain(lake[wat.r + 1][wat.c + 1]);
					toCheck.add(lake[wat.r + 1][wat.c + 1]);
				}
			}
			if (wat.c != 0) {
				wat.drain(lake[wat.r][wat.c - 1]);
				toCheck.add(lake[wat.r][wat.c - 1]);
			}
			if (wat.c != w - 1) {
				wat.drain(lake[wat.r][wat.c + 1]);
				toCheck.add(lake[wat.r][wat.c + 1]);
			}
		}
		long drained = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				drained += lake[i][j].drained;
			}
		}
		System.out.println(drained);
	}
}

class WaterHole implements Comparator<WaterHole> {
	int depth;
	int drained = 0;
	int r;
	int c;
	boolean checked = false;

	public WaterHole(int x, int y, int d) {
		depth = d;
		r = x;
		c = y;
	}

	public void drain(WaterHole wh) {
		wh.drained = Math.max(wh.drained, Math.min(-wh.depth, drained));
	}

	@Override
	public int compare(WaterHole o1, WaterHole o2) {
		return o1.depth - o2.depth;
	}
	@Override
	public String toString() {
		return depth +"";
	}
}
package unfinished;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.HashMap;
import java.util.PriorityQueue;

public class Bumped {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] line1 = br.readLine().split(" ");
		int n = Integer.parseInt(line1[0]);
		int m = Integer.parseInt(line1[1]);
		int f = Integer.parseInt(line1[2]);
		int s = Integer.parseInt(line1[3]);
		int t = Integer.parseInt(line1[4]);
		// create nodes
		NodeBumped[] nodes = new NodeBumped[n];
		for (int i = 0; i < n; i++) {
			nodes[i] = new NodeBumped();
		}
		// add edge weights
		for (int i = 0; i < m; i++) {
			String[] line = br.readLine().split(" ");
			int a = Integer.parseInt(line[0]);
			int b = Integer.parseInt(line[1]);
			int c = Integer.parseInt(line[2]);
			nodes[a].addPath(b, c);
			nodes[b].addPath(a, c);
		}
		long[] distFromStart = Djistras(s, nodes);
		long[] distFromEnd = Djistras(t, nodes);
		// create flights array
		int[][] flights = new int[f][2];
		for (int i = 0; i < f; i++) {
			String[] line = br.readLine().split(" ");
			int a = Integer.parseInt(line[0]);
			int b = Integer.parseInt(line[1]);
			flights[i][0] = a;
			flights[i][1] = b;
		}
		long minC = distFromStart[t];
		for (int i = 0; i < f; i++) {
			long dist = distFromStart[flights[i][0]] + distFromEnd[flights[i][1]];
			minC = Math.min(dist, minC);
		}
		System.out.println(minC);
	}

	public static long[] Djistras(int s, NodeBumped[] narr) {
		NodeBumped[] nodes = new NodeBumped[narr.length];
		for (int i = 0; i < narr.length; i++) {
			nodes[i] = new NodeBumped(narr[i].connectedNodes);
		}
		long[] distances = new long[nodes.length];
		PriorityQueue<NodeBumped> Q = new PriorityQueue<NodeBumped>(nodes.length, new NodeBumped());
		nodes[s].cost = 0;
		Q.add(nodes[s]);
		while (!Q.isEmpty()) {
			NodeBumped N = Q.remove();
			if (N.checked) {
				continue;
			}
			N.check();
			for (int nodeIndex : N.connectedNodes.keySet()) {
				NodeBumped dest = nodes[nodeIndex];
				if (!dest.checked) {
					int dist = N.connectedNodes.get(nodeIndex);
					if (N.cost + dist < dest.cost) {
						dest.cost = dist + N.cost;
						Q.add(dest);
					}
				}
			}
		}
		for (int i = 0; i < distances.length; i++) {
			distances[i] = nodes[i].cost;
		}
		return distances;
	}
}

class NodeBumped implements Comparator<NodeBumped> {
	long cost = Long.MAX_VALUE;
	boolean checked = false;
	// node, cost
	HashMap<Integer, Integer> connectedNodes = new HashMap<Integer, Integer>();

	public NodeBumped() {

	}

	public NodeBumped(HashMap<Integer, Integer> hm) {
		connectedNodes = hm;
	}

	public void addPath(int node, int cost) {
		connectedNodes.put(node, cost);
	}

	public void check() {
		checked = true;
	}

	@Override
	public int compare(NodeBumped a, NodeBumped b) {
		if (a.cost - b.cost > 0) {
			return 1;
		} else if (a.cost - b.cost < 0) {
			return -1;
		} else {
			return 0;
		}
	}

}
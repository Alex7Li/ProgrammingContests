import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

//http://codeforces.com/contest/937/problem/D
public class SleepyGame {
	private static int n;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] parameters = br.readLine().split(" ");
		n = Integer.parseInt(parameters[0]);
		// 0th node: nothing
		// [0-n)th node: Petya's turn
		// [n-2n)th node: Vasya's turn
		Node[] nodes = new Node[2 * n];
		for (int i = 0; i < nodes.length; i++) {
			nodes[i] = new Node();
			nodes[i].index = i;
		}
		for (int i = 0; i < n; i++) {
			String[] edges = br.readLine().split(" ");
			for (int j = 1; j < edges.length; j++) {
				int toNode = Integer.parseInt(edges[j]) - 1;
				nodes[i + n].edges.add(nodes[toNode]);
				nodes[i].edges.add(nodes[n + toNode]);
			}
		}
		int start = Integer.parseInt(br.readLine()) - 1;
		Node startNode = nodes[start];
		StringBuilder path = findWinning(startNode);
		if (path.length() != 0) {
			System.out.println(path.reverse());
		}
	}

	private static StringBuilder findWinning(Node startNode) {
		startNode.seen = true;
		if (startNode.edges.isEmpty()) {
			if (startNode.index < n) {
				return new StringBuilder();
			} else {
				return new StringBuilder(startNode.index % n + 1);
			}
		} else {
			for (Node next : startNode.edges) {
				if (!next.seen) {
					StringBuilder path = findWinning(startNode);
					if (path.length() != 0) {
						return path.append(" " + ((startNode.index) % n + 1));
					}
				}
			}
			return new StringBuilder();
		}
	}

	public static class Node {
		List<Node> edges = new ArrayList<Node>();
		int index;
		boolean seen;

		@Override
		public String toString() {
			String ret = index + " { ";
			for (int i = 0; i < edges.size(); i++) {
				ret += edges.get(i).index + " ";
			}
			ret = ret + "}";
			return ret;
		}
	}
}

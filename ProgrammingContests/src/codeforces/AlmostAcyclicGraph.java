package codeforces;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

//Problem: http://codeforces.com/problemset/problem/915/D
//Model GracefulChainsawJugglers: http://codeforces.com/contest/915/submission/34154383
public class AlmostAcyclicGraph {
	private static List<List<Integer>> adj = new ArrayList<>();

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		for (int i = 0; i < n; i++) {
			adj.add(new ArrayList<>());
		}
		for (int i = 0; i < m; i++) {
			int s = sc.nextInt() - 1;
			int e = sc.nextInt() - 1;
			adj.get(s).add(e);
		}
		sc.close();
		State[] nodes = new State[n];
		for (int i = 0; i < nodes.length; i++) {
			nodes[i] = State.NOT_VISITED;
		}
		List<int[]> edgesInCycle = new ArrayList<int[]>();
		for (int i = 0; i < n; i++) {
			if (nodes[i] == State.NOT_VISITED && findCycle(i, nodes, edgesInCycle)) {
				break;
			}
		}
		// no cycles
		if (edgesInCycle.size() == 0) {
			System.out.println("YES");
		} else {
			for (int[] edge : edgesInCycle) {
				if (traverse(n, edge)) {
					System.out.println("YES");
					return;
				}
			}
			System.out.println("NO");
		}
	}

	public static enum State {
		NOT_VISITED, VISITED, NO_CYCLE;
	}

	/**
	 * Looks for a cycle in the adj matrix that contains start. If it finds one, it
	 * adds every edge in the cycle to edgesInCycles. Returns true if a cycle is
	 * found, and false otherwise.
	 */
	private static boolean findCycle(int start, State[] nodes, List<int[]> edgesInCycles) {
		nodes[start] = State.VISITED;
		for (int end : adj.get(start)) {
			if (nodes[end] == State.VISITED) {
				edgesInCycles.add(new int[] { start, end });
				return true;
			} else if (nodes[end] == State.NOT_VISITED && findCycle(end, nodes, edgesInCycles)) {
				edgesInCycles.add(new int[] { start, end });
				return true;
			}
		}
		nodes[start] = State.NO_CYCLE;
		return false;
	}

	/**
	 * Looks for a cycle in the adj matrix that contains start. Does not use the
	 * given edge. Returns true if a cycle is found, and false otherwise.
	 */
	private static boolean checkCycle(int start, State[] nodes, int[] edge) {
		nodes[start] = State.VISITED;
		for (int end : adj.get(start)) {
			// ignore given cycle.
			if (start != edge[0] || end != edge[1]) {
				if (nodes[end] == State.VISITED) {
					return true;
				} else if (nodes[end] == State.NOT_VISITED && checkCycle(end, nodes, edge)) {
					return true;
				}
			}
		}
		nodes[start] = State.NO_CYCLE;
		return false;
	}

	/**
	 * @return true if removing the given edge will cause the graph to have no
	 *         cycles.
	 */
	private static boolean traverse(int n, int[] edge) {
		State[] nodes = new State[n];
		for (int i = 0; i < nodes.length; i++) {
			nodes[i] = State.NOT_VISITED;
		}
		for (int i = 0; i < n; i++) {
			if (nodes[i] == State.NOT_VISITED && checkCycle(i, nodes, edge)) {
				return false;
			}
		}
		return true;
	}
}

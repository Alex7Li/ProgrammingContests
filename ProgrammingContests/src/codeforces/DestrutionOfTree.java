package codeforces;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

//http://codeforces.com/contest/963/problem/B
public class DestrutionOfTree {
	private static int[] subtreeSizes;
	private static ArrayList<Set<Integer>> children;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		br.readLine();
		int[] parents = Arrays.stream(br.readLine().split(" ")).mapToInt(x -> Integer.parseInt(x) - 1).toArray();
		if (parents.length % 2 == 0) {
			System.out.println("NO");
			return;
		} else {
			System.out.println("YES");
		}

		children = new ArrayList<>();
		for (int i = 0; i < parents.length; i++) {
			children.add(new HashSet<Integer>());
		}
		int root = -1;
		for (int i = 0; i < parents.length; i++) {
			if (parents[i] != -1) {
				children.get(parents[i]).add(i);
			} else {
				root = i;
			}
		}

		subtreeSizes = new int[parents.length];
		calcSubtreeSizes(root);

		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
		search(root, out);
		out.flush();
	}

	private static void calcSubtreeSizes(int root) {
		int size = 1;
		for (int child : children.get(root)) {
			calcSubtreeSizes(child);
			size += subtreeSizes[child];
		}
		subtreeSizes[root] = size;
	}

	private static void search(int start, BufferedWriter out) throws IOException {
		Iterator<Integer> it = children.get(start).iterator();
		while (it.hasNext()) {
			int child = it.next();
			if (subtreeSizes[child] % 2 == 0) {
				search(child, out);
				it.remove();
			}
		}
		out.write((1 + start) + System.lineSeparator());
		for (int child : children.get(start)) {
			search(child, out);
		}
		children.get(start).clear();
	}
}

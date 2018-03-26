import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
//Absolutely horrible problem statement
//http://codeforces.com/problemset/problem/932/D
public class Tree {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder solution = new StringBuilder();
		int q = Integer.parseInt(br.readLine());
		int last = 0;
		ArrayList<Node> nodes = new ArrayList<Node>();
		nodes.add(new Node());
		for (int query = 0; query < q; query++) {
			String[] nextLine = br.readLine().split(" ");
			Node node = nodes.get(Integer.parseInt(nextLine[1]) ^ last);
			long X = Integer.parseInt(nextLine[2]) ^ last;
			switch (nextLine[0]) {
			case "1":
				nodes.add(new Node(node,X));
				break;
			case "2":
				solution.append(node.getMaxLenSeq() + "/r/n");
				break;
			}
		}
	}

	public static class Node {
		// ancestors (starting with 1st, then 2nd, 4th, 8th, etc.)
		private ArrayList<Node> ancestors = new ArrayList<Node>();
		// largest weight up to that ancestor
		private ArrayList<Long> lWeight = new ArrayList<Long>();
		// sum of weights up to that ancestor
		private ArrayList<Long> sumWeight = new ArrayList<Long>();
		private int totalAncestors;
		private long weight;
		public Node() {}
		public Node(Node ancestor, long weight) {
			this.weight = weight;
			ancestors.add(ancestor);
			lWeight.add(ancestor.weight);
			sumWeight.add(weight+ancestor.weight);
			totalAncestors = ancestor.totalAncestors+1;
			int size = Integer.numberOfTrailingZeros(Integer.highestOneBit(totalAncestors));
			for (int i = 1; i <= size; i++) {
				ancestors.add(ancestors.get(i-1).ancestors.get(i-1));
				lWeight.add(ancestors.get(i).weight);
				sumWeight.add(weight+ancestors.get(i).weight);
			}
		}
		public long getMaxLenSeq() {
			return 0;
		}

	}
}

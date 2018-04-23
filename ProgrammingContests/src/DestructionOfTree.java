import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

//http://codeforces.com/contest/963/problem/B
public class DestructionOfTree {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		br.readLine();
		int[] parents = Arrays.stream(br.readLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
		Tree[] trees = new Tree[parents.length + 1];
		trees[0] = new Tree(trees[0], 0);
		int root = 0;
		// i don't like the input format because makes my code disgusting ):
		@SuppressWarnings("unchecked")
		ArrayList<Integer>[] children = (ArrayList<Integer>[]) new ArrayList[parents.length + 1];
		for (int i = 0; i < children.length; i++) {
			children[i] = new ArrayList<Integer>();
		}
		for (int i = 1; i <= parents.length; i++) {
			if (parents[i - 1] == 0) {
				root = i;
			} else {
				children[parents[i - 1]].add(i);
			}
			trees[i] = new Tree(trees[parents[i - 1]], i);
		}
		for (int i = 1; i < children.length; i++) {
			for (int j : children[i]) {
				trees[i].addChild(trees[j]);
			}
		}
		ArrayList<Integer> result = trees[root].isType(0);
		if (result.size() == 0) {
			System.out.println("NO");
		} else {
			System.out.println("YES");
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < result.size(); i++) {
				sb.append(result.get(i) + "\r\n");
			}
			System.out.println(sb);
		}
	}

	public static class Tree {
		int index;
		Tree parent;
		ArrayList<Tree> subTrees = new ArrayList<Tree>();

		public Tree(Tree parent, int index) {
			this.parent = parent;
			this.index = index;
		}

		public void addChild(Tree tree) {
			subTrees.add(tree);
		}

		// type A(0): can be destroyed without top node.
		// type B(1): can be destroyed with top node.
		// all trees are either type A or type B.
		public ArrayList<Integer> isType(int type) {
			ArrayList<Integer> ret = new ArrayList<Integer>();
			// 1 node is destroyable
			if (subTrees.isEmpty()) {
				if (type == 0) {
					ret.add(index);
				}
				return ret;
			}
			Map<Tree, ArrayList<Integer>> typeA = new HashMap<>();
			Map<Tree, ArrayList<Integer>> typeB = new HashMap<>();
			ArrayList<Integer> bothPath = null;
			for (Tree kid : subTrees) {
				ArrayList<Integer> aPath = kid.isType(0);
				if (aPath.isEmpty()) {
					typeB.put(kid, kid.isType(1));
				} else {
					typeA.put(kid, aPath);
				}
			}
			if ((subTrees.size() - typeB.size() + type) % 2 != 0) {
				// it is impossible unless we can find a subtree that is type A and type B
				for (Tree kid : typeA.keySet()) {
					ArrayList<Integer> bPath = kid.isType(1);
					if (bPath.size() > 0) {
						typeA.remove(kid);
						bothPath = bPath;
						break;
					}
				}
				if (bothPath == null) {
					return ret;
				}
			}
			// destroy all type B while you can
			for (ArrayList<Integer> path : typeB.values()) {
				ret.addAll(path);
			}
			// ensure top node can be removed
			if ((subTrees.size() - typeB.size() + type) % 2 != 0) {
				ret.addAll(bothPath);
				bothPath = null;
			}
			// remove top node
			ret.add(index);
			// remove type A
			for (ArrayList<Integer> path : typeA.values()) {
				ret.addAll(path);
			}
			// remove type both
			if (bothPath != null) {
				ret.addAll(bothPath);
			}

			return ret;
		}
	}
}

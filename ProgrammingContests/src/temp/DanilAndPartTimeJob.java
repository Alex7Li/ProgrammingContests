package temp;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;

//http://codeforces.com/problemset/problem/877/E
public class DanilAndPartTimeJob {
	private static boolean[] lazy;

	private static int[] segTree;

	private static ArrayList<Integer> tour;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder ans = new StringBuilder("");
		int n = Integer.parseInt(br.readLine());
		Light[] lights = new Light[n];
		//create lights
		lights[0] = new Light();
		if (n > 1) {
			int[] parents = Arrays.stream(br.readLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
			for (int i = 1; i < n; i++) {
				int parent = parents[i - 1] - 1;
				lights[i] = new Light();
				lights[parent].children.add(lights[i]);
			}
		}else {
			//only 1 light
			br.readLine();
		}
		//set lights to on or off
		int[] isOn = Arrays.stream(br.readLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
		for (int i = 0; i < lights.length; i++) {
			lights[i].isOn = isOn[i];
		}
		//dfs through the nodes, 0 if off, 1 if on
		tour = lights[0].tour(0);
		assert tour.size() == n;
		
		int nextPow2 = Math.max(1, 2 * Integer.highestOneBit(tour.size() - 1));
		//create segment Tree
		segTree = new int[2 * nextPow2];
		lazy = new boolean[2 * nextPow2];
		build(0, nextPow2, 1);
		int q = Integer.parseInt(br.readLine());
		for (int i = 0; i < q; i++) {
			String[] nextLine = br.readLine().split(" ");
			Light l = lights[Integer.parseInt(nextLine[1]) - 1];
			if (nextLine[0].equals("get")) {
				ans.append(get(l) + "\r\n");
			} else {
				pow(l);
			}
		}
		System.out.println(ans);
		br.close();
	}

	private static void build(int start, int end, int ind) {
		if (start + 1 == end) {
			if (start < tour.size()) {
				segTree[ind] = tour.get(start);
			} else {
				segTree[ind] = 0;
			}
		} else {
			int mid = (start + end) / 2;
			build(start, mid, ind * 2);
			build(mid, end, ind * 2 + 1);
			segTree[ind] = segTree[ind * 2] + segTree[ind * 2 + 1];
		}
	}

	private static int get(Light l) {
		int st = l.start;
		int end = l.end;
		return get(0, segTree.length / 2, 1, st, end);
	}

	private static int get(int l, int r, int ind, int st, int end) {
		if (r <= st || l >= end) {
			// no intersection
			return 0;
		} else if (st <= l && end >= r) {
			// total intersection
			return segTree[ind];
		} else {
			// partial intersection
			propagate(l, r, ind);
			int mid = (l + r) / 2;
			int ans = get(l, mid, ind * 2, st, end);
			ans += get(mid, r, ind * 2 + 1, st, end);
			return ans;
		}
	}

	private static void pow(Light l) {
		int st = l.start;
		int end = l.end;
		pow(0, segTree.length / 2, 1, st, end);
	}

	private static void pow(int l, int r, int ind, int st, int end) {
		if (r <= st || l >= end) {
			// no intersection
		} else if (st <= l && end >= r) {
			// total intersection
			segTree[ind] = (r - l) - segTree[ind];
			lazy[ind] = !lazy[ind];
		} else {
			// partial intersection
			propagate(l, r, segTree[ind]);
			int mid = (r + l) / 2;
			pow(l, mid, ind * 2, st, end);
			pow(mid, r, ind * 2 + 1, st, end);
			segTree[ind] = segTree[2 * ind] + segTree[2 * ind + 1];
		}
	}

	private static void propagate(int l, int r, int ind) {
		if (lazy[ind]) {
			int mid = (l + r) / 2;
			segTree[ind * 2] = (mid - l) - segTree[ind * 2];
			lazy[ind * 2] = !lazy[ind * 2];
			segTree[ind * 2 + 1] = (r - mid) - segTree[ind * 2 + 1];
			lazy[ind * 2 + 1] = !lazy[ind * 2 + 1];
			lazy[ind] = false;
		}
	}

	public static class Light {
		int start;
		int end;
		int isOn;
		LinkedList<Light> children = new LinkedList<Light>();

		public ArrayList<Integer> tour(int loc) {
			start = loc;
			ArrayList<Integer> ans = new ArrayList<Integer>();
			ans.add(this.isOn);
			loc++;
			for (Light l : children) {
				ArrayList<Integer> childAns = l.tour(loc);
				ans.addAll(childAns);
				loc += childAns.size();
			}
			end = loc;
			return ans;
		}
	}
}
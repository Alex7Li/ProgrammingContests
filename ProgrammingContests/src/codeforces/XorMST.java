package codeforces;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

//Mostly copied from shhuan (http://codeforces.com/contest/888/submission/32209912)
//for learning purposes
public class XorMST {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		br.readLine();
		int[] a = Arrays.stream(br.readLine().split(" ")).mapToInt(v -> Integer.parseInt(v)).toArray();
		Trie t = makeTrie(a);
		System.out.println(spanTree(t));
	}

	private static long spanTree(Trie t) {
		long cost = 0;
		if (t != null) {
			cost = spanTree(t.left) + spanTree(t.right) + xorTrie(t.left, t.right) % Integer.MAX_VALUE;
		}
		return cost;
	}

	public static int xorTrie(Trie a, Trie b) {
		int cost = Integer.MAX_VALUE;
		if (a != null && b != null) {
			//Note that if a is a left, b must be a leaf, and vice versa.
			//Because all values are on the bottom level of the trie,
			//and a and b are always on the same level
			if (a.isLeaf) {
				cost = a.val ^ b.val;
			}else {
				//very important optimization here. We check the same direction first as it is
				//sure to be lower by properties of xor. Only if that fails do we check the other
				//directions, greatly reducing recursive calls.
				cost = Math.min(xorTrie(a.left, b.left), xorTrie(a.right, b.right));
				if (cost == Integer.MAX_VALUE) {
					cost = Math.min(xorTrie(a.right, b.left), xorTrie(a.left, b.right));
				}

			}
		}
		return cost;
	}

	private static Trie makeTrie(int[] a) {
		Trie top = new Trie();
		for (int i : a) {
			Trie t = top;
			for (int j = 31; j >= 0; j--) {// go through each bit
				if (((i >> j) & 1) == 0) {// if current bit is 0
					if (t.left == null) {
						t.left = new Trie();
					}
					t = t.left;
				} else {// current bit is 1
					if (t.right == null) {
						t.right = new Trie();
					}
					t = t.right;
				}
			}
			t.val = i;
			t.isLeaf = true;
		}
		return top;
	}

	private static class Trie {
		Trie left;
		Trie right;
		int val;
		boolean isLeaf;
	}
}

package core.datastructures.trie;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
//https://open.kattis.com/problems/prefixfreecode
public class PrefixFreeCode {
	public static final long MOD = 1000000007;
	private static long[] fact;
 
	public static class FenwickTree {
		int[] array;
		int arrLen;

		public FenwickTree(int size) {
			// using size+1 to be safe
			int height = (int) (Math.log(size + 1) / Math.log(2)) + 2;
			arrLen = (int) Math.pow(2, height);
			array = new int[arrLen];
			for (int i = arrLen / 2; i < arrLen; i++) {
				array[i] = 1;
			}
			build(1);
		}

		public void build(int ind) {
			if (ind < arrLen / 2) {
				build(2 * ind);
				build(2 * ind + 1);
				array[ind] = array[2 * ind] + array[2 * ind + 1];
			}
		}

		public void remove(int x) {
			x = x + arrLen / 2;
			array[x]--;
			assert array[x] == 0;
			rem(x / 2);
		}

		private void rem(int x) {
			array[x]--;
			if (x != 1) {
				rem(x / 2);
			}
		}

		public long get(int x) {
			return sumTo(x + 1, 1, 0, arrLen / 2) - 1;
		}

		// get sum of array indexes [0,indToGet]. Search in range [l,r)
		private int sumTo(int indToGet, int ind, int l, int r) {
			int value = 0;
			int mid = (l + r) / 2;
			if (l > indToGet) {
				return 0;
			} else if (indToGet >= r) {
				return array[ind];
			} else {
				value += sumTo(indToGet, ind * 2, l, mid);
				value += sumTo(indToGet, ind * 2 + 1, mid + 1, r);
			}
			return value;
		}
	}

	public static class Trie {
		Trie[] children;
		Trie() {
			children = new Trie[26];
		}

		public void add(char[] str) {
			Trie curTrie = this;
			for (int i = 0; i < str.length; i++) {
				int index = str[i] -'a';
				if(curTrie.children[index]==null) {
					curTrie.children[index] = new Trie();
				}
				curTrie = curTrie.children[index];
			}
		}

		String findNext(char[] str, int startPos) {
			Trie curTrie = this;
			StringBuilder ret = new StringBuilder();
			for (int i = startPos; i < str.length; i++) {
				int index = str[i]-'a';
				if(curTrie.children[index]==null) {
					break;
				}else {
					curTrie = curTrie.children[index];
					ret.append(str[i]);
				}
			}
			return ret.toString();
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] initParams = br.readLine().split(" ");
		int n = Integer.parseInt(initParams[0]);
		int k = Integer.parseInt(initParams[1]);
		generateFact(n, k);
		Trie strings = new Trie();
		String[] listStr = new String[n];
		FenwickTree indexes = new FenwickTree(n);
		for (int i = 0; i < n; i++) {
			String nxtStr = br.readLine();
			strings.add(nxtStr.toCharArray());
			listStr[i] = nxtStr;
		}
		Arrays.sort(listStr);
		char[] inputStr = br.readLine().toCharArray();
		long result = 1;
		int x = n;
		int startPos = 0;
		for (int i = 0; i < k; i++) {
			String str = strings.findNext(inputStr, startPos);
			startPos += str.length();
			x--;
			int ind = Arrays.binarySearch(listStr, str);
			result += indexes.get(ind) * fact[x];
			result %= MOD;
			indexes.remove(ind);
		}
		assert x == n - k : x;
		System.out.println(result);
	}

	private static void generateFact(int n, int k) {
		fact = new long[n];
		fact[n - k] = 1;
		for (int i = n - k + 1; i < fact.length; i++) {
			fact[i] = (i * fact[i - 1]) % MOD;
		}
	}
}

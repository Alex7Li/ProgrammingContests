package acmkattis;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class LostInTranslation {
	static String[] languages;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] parameters = br.readLine().split(" ");
		int n = Integer.parseInt(parameters[0]);
		int m = Integer.parseInt(parameters[1]);
		String[] lnew = br.readLine().split(" ");
		languages = Arrays.copyOf(lnew, lnew.length + 1);
		languages[lnew.length] = "English";
		int[][] costs = new int[n + 1][n + 1];
		for (int i = 0; i < m ; i++) {
			String[] nextLine = br.readLine().split(" ");
			int lang1 = getLangIndex(nextLine[0]);
			int lang2 = getLangIndex(nextLine[1]);
			int cost = Integer.parseInt(nextLine[2]);
			costs[lang1][lang2] = cost;
			costs[lang2][lang1] = cost;
		}
		int[] extraCost = new int[languages.length];
		int[] transDist = new int[n + 1];
		for (int i = 0; i < extraCost.length - 1; i++) {
			extraCost[i] = Integer.MAX_VALUE;
			transDist[i] = Integer.MAX_VALUE;
		}
		Queue<Integer> Q = new LinkedList<Integer>();
		transDist[n] = 0;
		Q.add(n);
		while (!Q.isEmpty()) {
			int E = Q.poll();
			for (int i = 0; i < transDist.length; i++) {
				if (costs[E][i] == 0 || transDist[i] <= transDist[E]) {
					continue;
				} else {
					if (extraCost[i] > costs[E][i]) {
						extraCost[i] = costs[E][i];
						transDist[i] = transDist[E] + 1;
						Q.add(i);
					}
				}
			}
		}

		int sum = 0;
		for (int i = 0; i < extraCost.length; i++) {
			if(extraCost[i] == Integer.MAX_VALUE) {
				System.out.println("Impossible");
				return;
			}
			sum += extraCost[i];
		}
		System.out.println(sum);
	}

	private static int getLangIndex(String lang) {
		for (int i = 0; i < languages.length; i++) {
			if (lang.equals(languages[i])) {
				return i;
			}
		}
		return -1;
	}
}
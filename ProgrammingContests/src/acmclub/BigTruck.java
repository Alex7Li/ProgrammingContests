package acmclub;

import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

//https://open.kattis.com/problems/bigtruck
public class BigTruck {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] items = new int[n];
		int[] maxItems = new int[n];
		int[][] adj = new int[n][n];
		for (int i = 0; i < n; i++) {
			items[i] = sc.nextInt();
		}
		maxItems[0] = items[0];
		int roads = sc.nextInt();
		for (int i = 0; i < roads; i++) {
			int a = sc.nextInt()-1;
			int b = sc.nextInt()-1;
			int d = sc.nextInt();
			adj[a][b] = d;
			adj[b][a] = d;
		}
		sc.close();
		int[] distances = new int[n];
		for (int i = 0; i < n; i++) {
			distances[i] = Integer.MAX_VALUE;
		}
		distances[0] = 0;
		 Comparator<Integer> comparator = new Comparator<Integer>() {
		      @Override
		      public int compare(Integer o1, Integer o2) {
		        return distances[o1]-distances[o2];
		      }
		    };
		Queue<Integer> cities = new PriorityQueue<>(comparator);
		cities.add(0);
		while (!cities.isEmpty()) {
			int c = cities.poll();
			for (int i = 0; i < adj[c].length; i++) {
				if (adj[c][i] != 0) {
					int dist = adj[c][i] + distances[c];
					if (distances[i] > dist) {
						distances[i] = dist;
						maxItems[i] = maxItems[c] + items[i];
						if(cities.contains(i)) {
							cities.remove(i);
						}
						cities.add(i);
					} else if (distances[i] == dist) {
						maxItems[i] = Math.max(maxItems[i], maxItems[c] + items[i]);
					}
				}
			}
		}
		if (distances[n - 1] == Integer.MAX_VALUE) {
			System.out.println("impossible");
		} else {
			System.out.println(distances[n - 1] + " " + maxItems[n - 1]);
		}
	}
}

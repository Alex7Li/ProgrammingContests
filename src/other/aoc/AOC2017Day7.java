package other.aoc;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

//https://adventofcode.com/2017/day/7
public class AOC2017Day7 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int lines = 1241;
		Map<String, Tower> towers = new HashMap<>();
		for (int i = 0; i < lines; i++) {
			String[] input = s.nextLine().split(" ");
			String name = input[0];
			int weight = Integer.parseInt(input[1].substring(1, input[1].length() - 1));
			String[] children = new String[0];
			if (input.length > 3) {
				children = new String[input.length - 3];
				for (int j = 3; j < input.length; j++) {
					children[j - 3] = input[j];
					if (j != input.length - 1) {// remove comma
						children[j - 3] = children[j - 3].substring(0, children[j - 3].length() - 1);
					}
				}
			}
			Tower t = new Tower(name, weight, children);
			towers.put(name, t);
		}
		for (Tower t : towers.values()) {
			t.claimChildren(towers);
		}
		Tower randTow = towers.values().iterator().next();
		Tower bottom = randTow.getGreatestParent(towers);
		System.out.println("Part 1: " + bottom.name);
		System.out.println("Part 2: Look through data structure in debug mode."
				+ "It was too hard )))):");
		bottom.getTotalWeight();
		for (int i = 0; i < bottom.children[3].children[2].children.length; i++) {
			System.out.println(i + " " + bottom.children[3].children[2].children[i].getTotalWeight());
		}
		s.close();
	}

	public static class Tower {
		String name;
		int weight;
		int totalWeight = -1;
		String[] childrenNames;
		Tower[] children;
		Tower parent;

		public Tower(String n, int w, String[] c) {
			name = n;
			weight = w;
			childrenNames = c;
			children = new Tower[c.length];
		}

		/**
		 * I GAVE UP
		 */
//		public boolean isBalanced() {
//			int neededWeight = (this.totalWeight - this.weight) / this.children.length;
//
//			if ((this.totalWeight - this.weight) % this.children.length != 0 || children[0].weight != neededWeight) {
//				// a child is unbalanced
//				for (int i = 0; i < children.length; i++) {
//					if (!children[i].isBalanced()) {
//						if(i==0) {
//							return false;
//						}
//					}
//				}
//			}
//			if (children[0].weight == neededWeight) {
//				// This tower is the unbalanced tower. It's children are all
//				// balanced.
//				return false;
//
//			}
//			return false;
//		}

		public int getTotalWeight() {
			if (children.length == 0) {
				totalWeight = weight;
			} else if (totalWeight == -1) {
				totalWeight = weight;
				for (int i = 0; i < children.length; i++) {
					totalWeight += children[i].getTotalWeight();
				}
			}
			return totalWeight;
		}

		public Tower getGreatestParent(Map<String, Tower> towers) {
			if (this.parent == null) {
				return this;
			} else {
				return this.parent.getGreatestParent(towers);
			}
		}

		public void claimChildren(Map<String, Tower> towers) {
			for (int i = 0; i < childrenNames.length; i++) {
				towers.get(childrenNames[i]).setParent(this);
				children[i] = towers.get(childrenNames[i]);
			}
		}

		private void setParent(Tower tower) {
			this.parent = tower;
		}
	}
}

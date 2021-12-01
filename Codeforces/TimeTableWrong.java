package codeforces;

import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.TreeSet;

//Greedy (and incorrect) solution
//http://codeforces.com/problemset/problem/946/D
public class TimeTableWrong {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int days = sc.nextInt();
		sc.nextInt();
		int skip = sc.nextInt();
		sc.nextLine();
		PriorityQueue<Schedule> schedules = new PriorityQueue<>();
		for (int i = 0; i < days; i++) {
			schedules.add(new Schedule(sc.nextLine().toCharArray()));
		}
		sc.close();
		for (int i = 0; i < skip; i++) {
			Schedule next = schedules.remove();
			next.remove();
			schedules.add(next);
		}
		long totalTime = 0;
		while (!schedules.isEmpty()) {
			totalTime += schedules.remove().sumHours;
		}
		System.out.println(totalTime);
	}

	public static class Schedule implements Comparable<Schedule> {
		TreeSet<Integer> positions = new TreeSet<Integer>();
		int gainFromNextRemoval;
		int sumHours;
		boolean nextRemIsMin;

		public Schedule(char[] input) {
			for (int i = 0; i < input.length; i++) {
				if (input[i] == '1') {
					positions.add(i + 1);
				}
			}
			if (positions.size() == 0) {
				sumHours = 0;
			} else {
				sumHours = positions.last() - positions.first() + 1;
			}
			setGain();
		}

		public void remove() {
			if (!positions.isEmpty()) {
				if (nextRemIsMin) {
					positions.remove(positions.first());
				} else {
					positions.remove(positions.last());
				}
				sumHours -= gainFromNextRemoval;
				setGain();
			}
		}

		private void setGain() {
			if (positions.size() == 1) {
				gainFromNextRemoval = 1;
			} else if (positions.size() == 0) {
				gainFromNextRemoval = 0;
			} else {
				int remLastGain = positions.last() - positions.lower(positions.last());
				int remFirstGain = positions.higher(positions.first()) - positions.first();
				if (remFirstGain >= remLastGain) {
					nextRemIsMin = true;
					gainFromNextRemoval = remFirstGain;
				} else {
					nextRemIsMin = false;
					gainFromNextRemoval = remLastGain;
				}
			}
		}

		@Override
		public int compareTo(Schedule o) {
			return o.gainFromNextRemoval - gainFromNextRemoval;
		}
	}

}

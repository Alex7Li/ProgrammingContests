package codeforces;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import java.util.TreeSet;

//http://codeforces.com/contest/949/problem/A
public class Zebras {
	public static void main(String[] args) throws IOException {
		// gather input
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		char[] input = br.readLine().toCharArray();
		br.close();
		TreeSet<Integer> zeroLocations = new TreeSet<Integer>();
		TreeSet<Integer> oneLocations = new TreeSet<Integer>();
		for (int i = 0; i < input.length; i++) {
			if (input[i] == '0') {
				zeroLocations.add(i + 1);
			} else {
				oneLocations.add(i + 1);
			}
		}
		Queue<Stack<Integer>> subSequences = new LinkedList<Stack<Integer>>();
		// add sequences, greedily searching for the longest ones
		while (!oneLocations.isEmpty()) {
			// there must be more 0s than 1s, and the first element remaining has to be a
			// zero.
			if (oneLocations.size() >= zeroLocations.size()
					|| oneLocations.last() > zeroLocations.last()) {
				System.out.println(-1);
				return;
			}
			Stack<Integer> sequence = new Stack<Integer>();
			int lastZero = zeroLocations.last();
			sequence.add(lastZero);
			zeroLocations.remove(lastZero);
			while (true) {
				Integer oneInd = oneLocations.lower(lastZero);
				if (oneInd != null) {
					Integer zeroInd = zeroLocations.lower(oneInd);
					if (zeroInd != null) {
						lastZero = zeroInd;
						sequence.add(oneInd);
						sequence.add(zeroInd);
						zeroLocations.remove(zeroInd);
						oneLocations.remove(oneInd);
					} else {
						break;
					}
				} else {
					break;
				}
			}
			subSequences.add(sequence);
		}
		while (!zeroLocations.isEmpty()) {
			Stack<Integer> next = new Stack<Integer>();
			next.add(zeroLocations.pollFirst());
			subSequences.add(next);
		}
		StringBuilder answer = new StringBuilder();
		System.out.println(subSequences.size());
		while (!subSequences.isEmpty()) {
			Stack<Integer> next = subSequences.poll();
			answer.append(next.size());
			while (!next.isEmpty()) {
				Integer ind = next.pop();
				answer.append(" " + ind);
			}
			answer.append("\r\n");
		}
		System.out.println(answer);
	}
}

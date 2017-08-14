package codeforces;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;

/**
 * 
 */

/**
 * @author 7Alex
 *
 */
public class SuitableReplacement {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		char[] input = br.readLine().toCharArray();
		char[] goal = br.readLine().toCharArray();
		System.out.println(solve(input, goal));
	}

	/**
	 * @param input
	 * @param goal
	 * @param optimalSolution
	 */
	private static String solve(char[] input, char[] goal) {
		HashMap<Character, Integer> goalValues = new HashMap<Character, Integer>();
		for (int i = 0; i < goal.length; i++) {
			goalValues.put(goal[i], goalValues.getOrDefault(goal[i], 0)+1);
		}
		HashMap<Character, Integer> inputValues = new HashMap<Character, Integer>();
		for (int i = 0; i < input.length; i++) {
			inputValues.put(input[i], inputValues.getOrDefault(input[i], 0) + 1);
		}
		int wild = inputValues.getOrDefault('?',0);
		ArrayList<Character> toPut = new ArrayList<Character>();
		for (int i = 1; i <= input.length / goal.length+1; i++) {
			int wildRequisite = 0;
			for (Character key : goalValues.keySet()) {
				wildRequisite += Math.max(0, i * goalValues.get(key) - inputValues.getOrDefault(key, 0));
			}
			if (wildRequisite > wild) {
				for (Character key : goalValues.keySet()) {
					int val = 0;
					val += Math.max(0, (i - 1) * goalValues.get(key) - inputValues.getOrDefault(key, 0));
					for (int j = 0; j < val; j++) {
						toPut.add(key);
					}
				}
				break;
			}
		}
		while (toPut.size() != wild) {
			toPut.add('b');
		}
		StringBuilder returnValue = new StringBuilder();
		int curPos = 0;
		for (int j = 0; j < input.length; j++) {
			if (input[j] != '?') {
				returnValue.append(input[j] + "");
			} else {
				returnValue.append(toPut.get(curPos) + "");
				curPos++;
			}
		}
		return returnValue.toString();
	}
}

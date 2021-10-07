package codeforces;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

/**
 * 
 */

/**
 * @author 7Alex
 *
 */
public class MultiJudgeSolving {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] input = br.readLine().split(" ");
		int k = Integer.parseInt(input[1]);
		String[] probDiff = br.readLine().split(" ");
		// preprocessing
		ArrayList<Integer> difficulties = new ArrayList<Integer>();
		for (int i = 0; i < probDiff.length; i++) {
			int diff = Integer.parseInt(probDiff[i]);
			if (diff > k) {
				difficulties.add(diff);
			}
		}
		Collections.sort(difficulties);
		System.out.println(solve(difficulties, k));
	}

	/**
	 * @param sorted
	 *            array of integers difficulties
	 * 
	 * @param k
	 *            solving power
	 */
	private static int solve(ArrayList<Integer> difficulties, int k) {
		int highestSolvable = 2 * k;
		int last = k;
		int otherProblemSolved = 0;
		while(0 != difficulties.size()) {
			if (difficulties.get(0) > highestSolvable) {
				highestSolvable = 2 * last;
				while (difficulties.get(0) > highestSolvable) {
					otherProblemSolved++;
					highestSolvable *= 2;
				}
			}
			last = difficulties.get(0);
			difficulties.remove(0);
		}

		return otherProblemSolved;
	}
}

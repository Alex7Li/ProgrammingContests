package codeforces;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.TreeSet;
//http://codeforces.com/contest/967/problem/C
public class StairsAndElevators {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] inArgs = br.readLine().split(" ");
		int nStair = Integer.parseInt(inArgs[2]);
		int nEle = Integer.parseInt(inArgs[3]);
		int speed = Integer.parseInt(inArgs[4]);
		TreeSet<Integer> stairs = new TreeSet<Integer>();
		TreeSet<Integer> elevators = new TreeSet<Integer>();
		int[] stairPos = new int[0];
		if (nStair != 0) {
			stairPos = Arrays.stream(br.readLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
		}else {
			br.readLine();
		}
		int[] elePos = new int[0];
		if(nEle!=0) {
			elePos = Arrays.stream(br.readLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
		}else {
			br.readLine();
		}
		for (int stair : stairPos) {
			stairs.add(stair);
		}
		for (int ele : elePos) {
			elevators.add(ele);
		}
		int q = Integer.parseInt(br.readLine());
		StringBuilder ans = new StringBuilder();
		// switched x and y so it makes more sense
		for (int i = 0; i < q; i++) {
			int[] inParams = Arrays.stream(br.readLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
			int x1 = inParams[1];
			int x2 = inParams[3];
			if (x1 > x2) { // ensure x2>=x1
				int temp = x1;
				x1 = x2;
				x2 = temp;
			}
			int y = Math.abs(inParams[0] - inParams[2]);
			if (y == 0) {
				ans.append((x2 - x1) + System.lineSeparator());
			} else {
				// handle edge case: no elevator/stair
				Integer eL = elevators.higher(x1);
				Integer eR = elevators.lower(x2);
				Integer stL = stairs.higher(x1);
				Integer stR = stairs.lower(x2);
				long eleLeft = Integer.MAX_VALUE;
				long eleRight = Integer.MAX_VALUE;
				long stLeft = Integer.MAX_VALUE;
				long stRight = Integer.MAX_VALUE;
				if (eL != null) {
					eleLeft = Math.max(0, elevators.higher(x1) - x2);
				}
				if (eR != null) {
					eleRight = Math.max(0, x1 - elevators.lower(x2));
				}
				if (stL != null) {
					stLeft = Math.max(0, stairs.higher(x1) - x2);
				}
				if (stR != null) {
					stRight = Math.max(0, x1 - stairs.lower(x2));
				}
				long eleExtra = Math.min(eleLeft, eleRight) * 2;
				long stExtra = Math.min(stLeft, stRight) * 2;
				eleExtra += (y + speed - 1) / speed;
				stExtra += y;
				
				ans.append((x2 - x1 + Math.min(eleExtra, stExtra)) + System.lineSeparator());
			}
		}
		System.out.println(ans);
	}
}

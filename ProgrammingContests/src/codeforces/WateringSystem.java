package codeforces;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
//http://codeforces.com/contest/967/problem/B
public class WateringSystem {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] inArgs = br.readLine().split(" ");
		int a = Integer.parseInt(inArgs[1]);
		int b = Integer.parseInt(inArgs[2]);
		int[] sizes = Arrays.stream(br.readLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
		int hole1 = sizes[0];
		Arrays.sort(sizes);
		int sumSize = Arrays.stream(sizes).sum();
		int holesCovered = 0;
		boolean seenFirstHole = false;
		while ((a * hole1) < (long)(b)*sumSize) {
			holesCovered++;
			if (sizes[sizes.length-holesCovered] == hole1 && !seenFirstHole) {
				seenFirstHole = true;
			} else {
				sumSize -= sizes[sizes.length - holesCovered];
			}
		}
		if(seenFirstHole) {
			holesCovered--;
		}
		System.out.println(holesCovered);
	}
}

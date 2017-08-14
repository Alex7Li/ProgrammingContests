package codeforces;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class ColoredBalls {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		String[] temp = br.readLine().split(" ");
		br.close();
		int[] colorCount = new int[n];
		for (int i = 0; i < colorCount.length; i++) {
			colorCount[i] = Integer.parseInt(temp[i]);
		}
		System.out.println(getSets(colorCount));
	}

	private static long getSets(int[] colorCount) {
		Arrays.sort(colorCount);
		// all sets must be of size setSize or setSize+1
		int setSize = colorCount[0];
		int[] pointers = new int[colorCount.length];
		for (int i = 0; i < pointers.length; i++) {
			pointers[i] = 1;
		}
		boolean done = false;
		while (!done) {
			for (int i = 0; i < colorCount.length; i++) {
				int minSetSizeNeeded = colorCount[i] / pointers[i];
				// too small to fit in set
				if (setSize > minSetSizeNeeded) {
					setSize = minSetSizeNeeded;
					break;
					// too large to fit in set
				} else if (setSize + 1 < minSetSizeNeeded || (
						setSize + 1 == minSetSizeNeeded && colorCount[i] % pointers[i] != 0)) {
					// try again with larger pointer
					pointers[i] = Math.max(colorCount[i]/(setSize+1),pointers[i]+1); 
					i--;
					// all sets have been checked
				}else if(i == colorCount.length - 1){
					done = true;
				}
			}
		}
		long totalSets = 0;
		for (int i = 0; i < pointers.length; i++) {
			totalSets += pointers[i];
		}
		return totalSets;
	}
}

package unfinished;
import java.util.ArrayList;
import java.util.Scanner;

public class Fire {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		ArrayList<Integer> toSave = new ArrayList<Integer>(n);
		ArrayList<Integer> toBurn = new ArrayList<Integer>(n);
		ArrayList<Integer> value = new ArrayList<Integer>(n);
		ArrayList<Integer> originalPos = new ArrayList<Integer>(n);
		// add sorted by toBurn
		for (int i = 0; i < n; i++) {
			int index = i;
			int save = s.nextInt();
			int burn = s.nextInt();
			for (int j = 0; j < toBurn.size(); j++) {
				if (burn < toBurn.get(j)) {
					index = j;
				}
			}
			toSave.add(index, save);
			toBurn.add(index, burn);
			value.add(index, s.nextInt());
			originalPos.add(index, i);
		}
		s.close();
		// In time[1] seconds, what is the optimal value that can be saved with only the
		// first[0] items?
		int[][] dp = new int[n + 1][toBurn.get(n - 1)];
		// Using only the first [0] items, At time[1], has item[2] been saved?
		boolean[][][] saved = new boolean[n + 1][toBurn.get(n - 1)][n + 1];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < dp[0].length; j++) {
				dp[i + 1][j] = dp[i][j];
				saved[i + 1][j] = saved[i][j].clone();
			}
			for (int j = 0; j < dp[0].length; j++) {
				// this item can be saved at this time
				if (toSave.get(i) + j < toBurn.get(i)) {
					//and it is beneficial to save it
					if (dp[i][j] + value.get(i) > dp[i][toSave.get(i) + j]) {
						dp[i + 1][toSave.get(i) + j] = dp[i][j] + value.get(i);
						saved[i + 1][toSave.get(i) + j] = saved[i][j].clone();
						saved[i + 1][toSave.get(i) + j][i + 1] = true;
					}

				} else if  (saved[i+1][j-1][i+1]) { //this item has already been saved 
					// this item has already been saved and it is not beneficial to switch to another combination
					if(dp[i + 1][toBurn.get(i) - 1] > dp[i + 1][j]) {
					saved[i + 1][j] = saved[i + 1][toBurn.get(i) - 1].clone();
					dp[i + 1][j] = dp[i + 1][toBurn.get(i) - 1];
					}
				}
			}
		}
		System.out.println(dp[n][dp[0].length - 1]);
		for (int i = 1; i < dp.length; i++) {
			for (int j = 0; j < dp[0].length; j++) {
				assert dp[i][j] >= dp[i - 1][j];
			}
		}
		for (int i = 0; i < dp.length; i++) {
			for (int j = 1; j < dp[0].length; j++) {
				assert dp[i][j] >= dp[i][j-1];
			}
		}
		int count = 0;
		ArrayList<Integer> itemsSaved = new ArrayList<Integer>();
		for (int i = 0; i < saved[n][toBurn.get(n - 1) - 1].length; i++) {
			if (saved[n][toBurn.get(n - 1) - 1][i]) {
				count++;
				itemsSaved.add(originalPos.get(i - 1) + 1);
			}
		}
		System.out.println(count);
		for (int i = 0; i < count; i++) {
			System.out.print(itemsSaved.get(i) + " ");
		}
		System.out.println();
	}
}
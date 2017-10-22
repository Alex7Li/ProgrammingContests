package codeforces;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BipartateEhabEasy {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		// 0 == unassigned
		// 1 == right
		// 2 == left
		byte[] side = new byte[n + 1];
		for (int i = 0; i < n - 1; i++) {
			String[] input = br.readLine().split(" ");
			int r = Integer.parseInt(input[0]);
			int l = Integer.parseInt(input[1]);
			if(side[r] == 0 && side[l] == 0) {
				side[r] = 1;
			}else if (side[r] == 0) {
				if (side[l] == 1) {
					side[r] = 2;
				} else {// side l = 2
					side[r] = 1;
				}
			} else{
				assert side[l] == 0;
				if (side[r] == 1) {
					side[l] = 2;
				} else {// side r = 2
					side[l] = 1;
				}
			}
		}
		int l = 0;
		int r = 0;
		for (int i = 1; i < side.length; i++) {
			assert side[i] != 0;
			if (side[i] == 1) {
				l++;
			} else {
				r++;
			}
		}
		System.out.println(1 + l * r - n);
	}
}

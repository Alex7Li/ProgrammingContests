package codechef;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

//https://www.codechef.com/DEC17/problems/CPLAY
public class PenaltyShootOut {
	public static void main(String[] args) throws IOException {
		// 0 = tie, 1 = team-A, 2 = team-B
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		char[] input = br.readLine().toCharArray();
		while (true) {
			// first 5 shots
			int winner = 0;
			int i = 1;
			int t1 = 0;
			int t2 = 0;
			while (i <= 20) {
				if (i % 2 == 1) {
					t1 += Character.getNumericValue(input[i - 1]);
				} else {
					t2 += Character.getNumericValue(input[i - 1]);
					if (i >= 10) {
						if (t1 > t2) {
							winner = 1;
							break;
						} else if (t1 < t2) {
							winner = 2;
							break;
						}
					}
				}
				if (i < 10) {
					if (t1 - t2 > (11 - i) / 2) {
						winner = 1;
						break;
					} else if (t2 - t1 > (10 - i) / 2) {
						winner = 2;
						break;
					}
				}
				i++;
			}
			if (winner == 1) {
				System.out.println("TEAM-A" + " " + i);
			} else if (winner == 2) {
				System.out.println("TEAM-B" + " " + i);
			} else {
				System.out.println("TIE");
			}
			if (br.ready()) {
				input = br.readLine().toCharArray();
			}else {
				return;
			}
		}
	}
}

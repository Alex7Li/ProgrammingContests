package codeforces;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class RestaurantTables {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] input = br.readLine().split(" ");
		int oneSeat = Integer.parseInt(input[1]);
		int twoSeat = Integer.parseInt(input[2]);
		int halfFullTwoSeat = 0;
		String[] customers = br.readLine().split(" ");
		int denied = 0;
		for (int i = 0; i < customers.length; i++) {
			int num = Integer.parseInt(customers[i]);
			if (num == 2) {
				if (twoSeat == 0) {
					denied += 2;
				} else {
					twoSeat--;
				}
			} else {// 1 person
				if (oneSeat == 0) {
					if (twoSeat == 0) {
						if (halfFullTwoSeat == 0) {
							denied++;
						} else {
							halfFullTwoSeat--;
						}
					} else {
						halfFullTwoSeat++;
						twoSeat--;
					}
				} else {
					oneSeat--;
				}
			}
		}
		System.out.println(denied);
	}
}

package codeforces;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class DivideByThree {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		char[] numStr = br.readLine().split(" ")[0].toCharArray();
		int mod3 = 0;
		for (int i = 0; i < numStr.length; i++) {
			mod3 += numStr[i];
			mod3 %= 3;
		}
		found: if (mod3 == 0) {
			printNum(numStr);
		} else {
			int first = -1;
			int second = -1;
			for (int i = numStr.length - 1; i >= 0; i--) {
				if (Character.getNumericValue(numStr[i]) % 3 == mod3) {
					if (i == 0 && numStr.length > 1 && numStr[1] == '0' && second != -1) {
						numStr[first] = 'R';
						numStr[second] = 'R';
					} else {
						numStr[i] = 'R';
					}
					printNum(numStr);
					break found;
				} else if (Character.getNumericValue(numStr[i]) % 3 != 0
						&& Character.getNumericValue(numStr[i]) % 3 != mod3) {
					if (first == -1) {
						first = i;
					} else if(second == -1){
						second = i;
					}
				}
			}
			if (second == -1) {
				System.out.println(-1);
			} else {
				numStr[first] = 'R';
				numStr[second] = 'R';
				printNum(numStr);
			}
		}

	}

	public static void printNum(char[] numStr) {
		StringBuilder s = new StringBuilder();
		int i = 0;
		boolean hadR = false;
		int had0 = 0;
		boolean done = false;
		while (i < numStr.length) {
			if (Character.getNumericValue(numStr[i]) != 0 && numStr[i] != 'R') {
				done = true;
				break;
			}
			if (numStr[i] == 'R' && i != 0) {
				hadR = true;
			}
			if (numStr[i] == '0') {
				had0++;
			}
			i++;
		}
		if (done == false) {
			if (had0 != 0 && hadR) {
				System.out.println(0);
			} else if (had0 > 0) {
				System.out.println(0);
			} else {
				System.out.println(-1);
			}
		} else {
			while (i < numStr.length) {
				if (numStr[i] != 'R') {
					s.append(numStr[i]);
				}
				i++;
			}
			System.out.println(s);
		}
	}
}

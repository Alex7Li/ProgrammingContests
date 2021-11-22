package codeforces;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

//http://codeforces.com/contest/841/problem/B
public class Godsend {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		br.readLine();
		String[] strinput = br.readLine().split(" ");
		int[] array = new int[strinput.length];
		int oddNums = 0;
		for (int i = 0; i < array.length; i++) {
			array[i] = Integer.parseInt(strinput[i]);
			if (array[i] % 2 == 1) {
				oddNums++;
			}
		}
		if (oddNums == 0) {
			System.out.println("Second");
		} else {
			System.out.println("First");
		}
	}
}

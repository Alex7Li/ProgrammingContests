package codeforces;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class PathsInBinaryTree {
	public static void main(String[] args) throws IOException {
		//get first line of input
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] data = br.readLine().split(" ");
		long n = Long.parseLong(data[0]);
		long queries = Long.parseLong(data[1]);
		//iterate through each query
		for (int q = 0; q < queries; q++) {
			long v = Long.parseLong(br.readLine());
			char[] commands = br.readLine().toCharArray();
			long lowestBit = Long.lowestOneBit(v);
			for (int i = 0; i < commands.length; i++) {
				if (commands[i] == 'U') {
					if (lowestBit < (n + 1) / 2) {
						v -= lowestBit;
						if (Long.lowestOneBit(v) != 2 * lowestBit) {
							v += 2 * lowestBit;
						}
						lowestBit *= 2;
					}
				} else if (lowestBit != 1) {
					if (commands[i] == 'R') {
						lowestBit /= 2;
						v += lowestBit;
					} else{// (commands[i] == 'L')
						lowestBit /= 2;
						v -= lowestBit;
					}
				}
			}
			System.out.println(v);
		}
	}
}
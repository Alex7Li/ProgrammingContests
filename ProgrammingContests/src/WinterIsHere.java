import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

//http://codeforces.com/problemset/problem/839/D
public class WinterIsHere {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		br.readLine();
		String[] data = br.readLine().split(" ");
		ArrayList<Integer> strengths = new ArrayList<Integer>();
		for (int i = 0; i < data.length; i++) {
			int str = Integer.parseInt(data[i]);
			if (str != 0) {
				strengths.add(str);
			}
		}
		//the total number of numbers seen so far with factor i is tFactors[i]
		int[] tFactors = new int[Integer.MAX_VALUE];
		for (int i = 0; i < tFactors.length; i++) {
			tFactors[i] = 0;
		}
		
	}
}

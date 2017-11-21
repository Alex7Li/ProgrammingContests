package temp;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class VladAndCafes {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		s.nextLine();
		int[] a = Arrays.stream(s.nextLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
		s.close();
		HashMap<Integer, Integer> l = new HashMap<Integer, Integer>();
		for (int j = 0; j < a.length; j++) {
			l.put(a[j], j);
		}
		int min = Integer.MAX_VALUE;
		for (int t : l.values()) {
			if (t < min) {
				min = t;
			}
		}
		System.out.println(a[min]);
	}
}

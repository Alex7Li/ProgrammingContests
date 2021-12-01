package codeforces;
import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeSet;

public class PetyaAndCatacombs {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		s.nextLine();
		int[] a = Arrays.stream(s.nextLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
		s.close();
		TreeSet<Integer> visitT = new TreeSet<>();
		visitT.add(0);
		for (int i = 1; i <= a.length; i++) {
			if(visitT.contains(a[i-1])) {
				visitT.remove(a[i-1]);
			}
			visitT.add(i);
		}
		System.out.println(visitT.size());
	}
}

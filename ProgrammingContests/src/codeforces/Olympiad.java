package codeforces;
import java.util.Arrays;
import java.util.Scanner;
//http://codeforces.com/contest/937/problem/A
public class Olympiad {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		sc.nextLine();
		int[] participants = Arrays.stream(sc.nextLine().split(" ")).mapToInt(x->Integer.parseInt(x)).toArray();
		Arrays.sort(participants);
		int last = 0;
		int ways = 0;
		for (int i = 0; i < participants.length; i++) {
			if(participants[i]>last) {
				ways++;
				last = participants[i];
			}
		}
		System.out.println(ways);
		sc.close();
	}
}

package codechef;
//https://www.codechef.com/ZCOPRAC/problems/ZCO13001
import java.util.Scanner;

public class Tournament {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int[] teamsOfStrength = new int[1001];
		for (int i = 0; i < n; i++) {
			teamsOfStrength[s.nextInt()]++;
		}
		s.close();
		long ans = 0;
		for (int i = 0; i < teamsOfStrength.length; i++) {
			for (int j = i + 1; j < teamsOfStrength.length; j++) {
				ans += teamsOfStrength[j] * teamsOfStrength[i] * (j - i);
			}
		}
		System.out.println(ans);
	}
}

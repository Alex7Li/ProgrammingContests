package codeforces;
import java.util.Scanner;

public class MexicanWave {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int k = s.nextInt();
		int t = s.nextInt();
		if (t - n > 0) {
			System.out.println(Math.max(0,k - (t - n)));
		} else {
			System.out.println(Math.min(t, k));
		}
		s.close();
	}
}

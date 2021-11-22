package implementation.simulation;
import java.util.Scanner;

//https://www.codechef.com/LTIME57/problems/HILLS
public class JumpingInTheHills {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		for (int i = 0; i < cases; i++) {
			int parachutes = 1;
			int n = sc.nextInt();
			int u = sc.nextInt();
			int d = sc.nextInt();
			int curH = sc.nextInt();
			int ans = 1;
			for (int j = 1; j < n; j++) {
				int nxtH = sc.nextInt();
				int fallDist = curH - nxtH;
				if (u < -fallDist || fallDist > d) {
					if (fallDist > d && parachutes > 0) {
						parachutes--;
					} else {
						sc.nextLine();
						break;
					}
				}
				ans++;
				curH = nxtH;
			}
			System.out.println(ans);
		}
		sc.close();
	}
}

package codeforces;
import java.util.Scanner;
//http://codeforces.com/contest/912/problem/A
public class TrickyAlchemy {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		long yel = s.nextLong();
		long blue = s.nextLong();
		long yReq = 0;
		long bReq = 0;
		long yBall = s.nextLong();
		yReq += yBall * 2;
		long gBall = s.nextLong();
		yReq += gBall;
		bReq += gBall;
		long bBall = s.nextLong();
		bReq += 3 * bBall;
		long ans = Math.max(0, yReq - yel);
		ans += Math.max(0, bReq - blue);
		System.out.println(ans);
		s.close();
	}
}

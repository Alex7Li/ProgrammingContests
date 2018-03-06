package codeforces;
import java.util.Scanner;
//http://codeforces.com/contest/935/problem/C
public class FifaAndFafa {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		double flatR = sc.nextDouble();
		double flatX = sc.nextDouble();
		double flatY = sc.nextDouble();
		double lapX = sc.nextDouble() - flatX;
		double lapY = sc.nextDouble() - flatY;
		sc.close();
		double d = Math.hypot(lapX, lapY);
		double maxSigRad = (d + flatR) / 2;
		double x = flatX;
		double y = flatY;
		if (maxSigRad > flatR) {
			maxSigRad = flatR;
		} else {
			if (Math.abs(d) < 0.1) {
				x += (flatR / 2);
			//	y += flatR;
			} else {
				x += lapX - (maxSigRad) * (lapX / d);
				y += lapY - (maxSigRad) * (lapY / d);
			}
		}
		System.out.println(x + " " + y + " " + maxSigRad);
	}
}

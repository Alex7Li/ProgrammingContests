package codeforces;
import java.util.Scanner;

public class Bus {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int a = s.nextInt();
		int b = s.nextInt();
		int f = s.nextInt();
		int k = s.nextInt();
		s.close();
		// starting at position of station
		int journeys = 0;
		int curTank = b - f;
		int refills = 0;
		int curDist;
		boolean goingRight = true;
		while (journeys < k - 1) {
			if (goingRight) {
				curDist = a - f;
			} else {
				curDist = f;
			}
			if (curTank < 2 * curDist) {
				curTank = b;
				refills++;
			}
			curTank -= 2 * curDist;
			if (0 > curTank) {
				journeys = k;
				refills = -1;
			}
			goingRight = !goingRight;
			journeys++;
		}
		if (goingRight) {
			curDist = a - f;
		} else {
			curDist = f;
		}
		if (0 > curTank || b<curDist) {
			journeys = k;
			refills = -1;
		}else if (curTank < curDist) {
			curTank = b;
			refills++;
		}
		System.out.println(refills);
	}
}

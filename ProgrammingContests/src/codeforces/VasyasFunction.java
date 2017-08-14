package codeforces;
import java.util.ArrayList;
import java.util.Scanner;

public class VasyasFunction {
	public static void main(String[] args) {
		VasyasFunction vf = new VasyasFunction();
		Scanner s = new Scanner(System.in);
		long a = s.nextLong();
		long b = s.nextLong();
		s.close();
		ArrayList<Long> factorsA = new ArrayList<Long>();
		long end = (long) Math.sqrt(a);
		long atemp = a;
		for (long i = 2; i <= end; i++) {
			if (atemp % i == 0) {
				factorsA.add(i);
				atemp /= i;
				i = 1;
				end = (long) Math.sqrt(atemp);
			}
		}
		 if (atemp != 1) {
			factorsA.add(atemp);
		}
		System.out.println(b / a + vf.solve(a, b % a, factorsA));
	}

	private long solve(long a, long b, ArrayList<Long> factorsA) {
		long rem = b;
		long gcd = 1;
		for (int i = 0; i < factorsA.size(); i++) {
			if (rem % factorsA.get(i) == 0) {
				rem /= factorsA.get(i);
				gcd *= factorsA.get(i);
				factorsA.remove(i);
				i--;
			}
		}
		long count = 0;
		while (1 < factorsA.size()) {
			b -= gcd;
			count++;
			rem = b/gcd;
			//rem--;
			for (int i = 0; i < factorsA.size(); i++) {
				if (rem % factorsA.get(i) == 0) {
					rem /= factorsA.get(i);
					gcd *= factorsA.get(i);
					factorsA.remove(i);
					i--;
				}
			}
		}
		return count + b/gcd;
	}
}

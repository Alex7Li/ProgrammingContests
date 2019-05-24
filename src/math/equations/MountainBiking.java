package math.equations;

import java.util.Scanner;
// https://open.kattis.com/problems/mountainbiking
public class MountainBiking {
	// V^2=2gh
	// h=50
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		double[] distances = new double[s.nextInt()];
		double grav = s.nextDouble();
		for (int i = 0; i < distances.length; i++) {
			distances[i] = s.nextDouble() * Math.cos(s.nextDouble()*Math.PI/180.0);
		}
		s.close();
		for (int i = distances.length - 2; i >= 0; i--) {
			distances[i] += distances[i + 1];
		}
		for (int i = 0; i < distances.length; i++) {
			System.out.println(Math.sqrt(2 * grav * distances[i]));
		}
	}
}

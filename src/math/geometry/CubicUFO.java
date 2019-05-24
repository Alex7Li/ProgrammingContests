package math.geometry;
import java.util.Scanner;
// https://codingcompetitions.withgoogle.com/codejam/round/00000000000000cb/00000000000079cc
public class CubicUFO {
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int tests = sc.nextInt();
		for (int t = 1; t <= tests; t++) {
			double h =sc.nextDouble();
			double a = (h+Math.sqrt(2-h*h))/2;
			double b = h-a;//(h-Math.sqrt(2-h*h))/2;
			//ax, ay, az
			System.out.println("Case #" + t + ":");
			System.out.println((h/2-a/2)+ " " + (h/2-b/2) + " " + 0);
			//bx, by, bz
			System.out.println((h/2-a-b/2)+ " " + (h/2-a/2) + " " + 0);
			System.out.println(0 + " " + 0 + " " + .5);
		}
		sc.close();
	}
}

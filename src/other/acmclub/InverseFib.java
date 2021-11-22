package other.acmclub;
import java.util.Scanner;

public class InverseFib {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		double[] fibNum = new double[100000000];
		double ans = s.nextDouble();
		s.close();
		int n = 2;
		fibNum[0] = 1;
		fibNum[1] = 1;
		while (ans > Math.pow(10, 9)) {
			ans/=10;
		}
		ans = Math.floor(ans);
		for (n = 2; Math.floor(fibNum[n - 1]) != ans; n++) {
			fibNum[n] = fibNum[n - 2] + fibNum[n - 1];
			while (fibNum[n] > Math.pow(10, 9)) {
				fibNum[n - 1]/=10;
				fibNum[n]/=10;
			}
		}
		System.out.println(n);
	}
}

package math.optimalpartition;
//https://www.codechef.com/ZCOPRAC/problems/ZCO14003
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class SmartPhone {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		ArrayList<Integer> custs = new ArrayList<>();
		long buyers = n;
		for (int i = 0; i < n; i++) {
			int v = s.nextInt();
			custs.add(v);
		}
		Collections.sort(custs);
		long max = 0;
		for (int i: custs) {
			long price = i;
			long profit = buyers*price;
			if(profit>max) {
				max = profit;
			}
			buyers--;
		}
		System.out.println(max);
		s.close();
	}
}

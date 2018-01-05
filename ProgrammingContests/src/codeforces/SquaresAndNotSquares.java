package codeforces;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
//http://codeforces.com/contest/898/problem/E
public class SquaresAndNotSquares {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		ArrayList<Integer> perfSquareDist = new ArrayList<Integer>();
		ArrayList<Integer> squareDist = new ArrayList<Integer>();
		for (int i = 0; i < n; i++) {
			int val = s.nextInt();
			int sqrt = (int) Math.sqrt(val);
			if(sqrt*sqrt==val) {
				if(val == 0) {
					squareDist.add(2);
				}else {
					squareDist.add(1);
				}
			}else {
				int dist = Math.min(val-sqrt*sqrt,(sqrt+1)*(sqrt+1)-val);
				perfSquareDist.add(dist);
			}
		}
		s.close();
		long ans = 0;
		if(squareDist.size()>=n/2) {
			Collections.sort(squareDist);
			for (int i = 0; i < squareDist.size()-n/2; i++) {
				ans+= squareDist.get(i);
			}
		}else {
			Collections.sort(perfSquareDist);
			for (int i = 0; i < n/2-squareDist.size(); i++) {
				ans+= perfSquareDist.get(i);
			}
		}
		System.out.println(ans);
	}
}

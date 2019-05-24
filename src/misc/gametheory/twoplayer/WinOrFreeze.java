package misc.gametheory.twoplayer;
import java.util.Scanner;
import java.util.Stack;

// http://codeforces.com/problemset/problem/151/C
public class WinOrFreeze {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long q = sc.nextLong();
		sc.close();
		Stack<Long> pFactors = new Stack<Long>();
		for (long i = 2; i*i <= q; i++) {
			if(q%i == 0) {
				q/=i;
				pFactors.add(i);
				i=1;
			}
		}
		if(pFactors.size() == 0) {
			System.out.println(1);
			System.out.println(0);
		}else if(pFactors.size()==1) {
			System.out.println(2);
		}else {
			System.out.println(1);
			System.out.println(pFactors.pop()*q);
		}
	}
}

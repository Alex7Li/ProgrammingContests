package googlecodejam;
import java.util.Scanner;
//https://codejam.withgoogle.com/2018/challenges/00000000000000cb/dashboard
public class SavingTheUniverseAgain {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int testCases = sc.nextInt();
		for (int i = 1; i <= testCases; i++) {
			int def = sc.nextInt();
			char[] str = sc.next().toCharArray();
			int count = 0;
			for (int j = 0; j < str.length; j++) {
				if(str[j] =='S') {
					count++;
				}
			}
			System.out.print("Case #" + i+ ": ");
			if(count>def) {
				System.out.println("IMPOSSIBLE");
			}else {
				System.out.println(solve(def,str));
			}
		}
		sc.close();
	}

	private static int solve(int def, char[] str) {
		long dmg = 0;
		long pow = 1;
		for (int i = 0; i < str.length; i++) {
			if(str[i]=='C') {
				pow*=2;
			}else {
				dmg+=pow;
			}
		}
		if(dmg<=def) {
			return 0;
		}else {
			for (int i = str.length-1; true; i--) {
				if(str[i]=='S' && str[i-1]=='C') {
					str[i] = 'C';
					str[i-1] = 'S';
					break;
				}
			}
			return 1+solve(def,str);			
		}
	}
}

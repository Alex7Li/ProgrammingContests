package codeforces;
import java.util.Scanner;
//http://codeforces.com/contest/935/problem/B
public class FafaAndTheGate {
public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	sc.nextLine();
	char[] moves = sc.nextLine().toCharArray();
	int cost = 0;
	boolean topSide = moves[0] == 'U';
	int northDist = 0;
	for (int i = 0; i < moves.length; i++) {
		if(moves[i] =='U') {
			northDist++;
		}else {
			northDist--;
		}
		if(northDist<0 && topSide) {
			topSide = !topSide;
			cost++;
		}else if(northDist>0 && !topSide){
			topSide = !topSide;
			cost++;
		}
	}
	System.out.println(cost);
	sc.close();
}
}

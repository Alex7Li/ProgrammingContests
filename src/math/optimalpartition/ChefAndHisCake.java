package math.optimalpartition;

import java.util.Scanner;

//https://www.codechef.com/DEC17/problems/GIT01
public class ChefAndHisCake {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int t = s.nextInt();
		for (int ct = 0; ct < t; ct++) {
			int n = s.nextInt();
			int m = s.nextInt();
			s.nextLine();
			char[][] cake = new char[n][m];
			for (int i = 0; i < n; i++) {
					cake[i] = s.nextLine().toCharArray();
			}
			System.out.println(findMinCost(cake));
		}
		s.close();
	}

	private static int findMinCost(char[][] cake) {
		int cR = 0;//start with R
		for (int i = 0; i < cake.length; i++) {
			for (int j = 0; j < cake[0].length; j++) {
				if((i+j)%2==0 && cake[i][j] == 'G') {
					cR+=3;
				}else if((i+j)%2==1 && cake[i][j] == 'R'){
					cR+=5;
				}
			}
		}
		int cG = 0;//start with G
		for (int i = 0; i < cake.length; i++) {
			for (int j = 0; j < cake[0].length; j++) {
				if((i+j)%2==1 && cake[i][j] == 'G') {
					cG+=3;
				}else if((i+j)%2==0 && cake[i][j] == 'R'){
					cG+=5;
				}
			}
		}
		return Math.min(cR, cG);
	}
}

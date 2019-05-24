package implementation.simulation;
//https://www.codechef.com/ZCOPRAC/problems/ZCO14001
import java.util.Arrays;
import java.util.Scanner;

public class VideoGame {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		s.nextInt();
		int h = s.nextInt();
		s.nextLine();
		int[] a = Arrays.stream(s.nextLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
		int[] commands = Arrays.stream(s.nextLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
		s.close();
		int curLoc = 0;
		boolean holdingBox = false;
		for (int i : commands) {
			switch (i) {
			case 1: // move left
				curLoc = Math.max(0, curLoc-1);
				break;
			case 2: // move right
				curLoc = Math.min(a.length-1,curLoc+1);
				break;
			case 3: //pick up Box
				if(!holdingBox && a[curLoc]>0) {
					holdingBox = true;
					a[curLoc]--;
				}
				break;
			case 4: // drop Box
				if(holdingBox && a[curLoc]<h) {
					holdingBox = false;
					a[curLoc]++;
				}
				break;
			}
		}
		for (int i = 0; i < a.length; i++) {
			System.out.print(a[i] + " ");
		}
		System.out.println();
	}
}

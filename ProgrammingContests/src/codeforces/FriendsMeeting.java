package codeforces;
import java.util.Scanner;
//http://codeforces.com/contest/931/problem/A
public class FriendsMeeting {
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		sc.close();
		int diff = Math.abs(b-a);
		int aDist = (diff)/2;
		int bDist = (diff+1)/2;
		int tiredA  =(aDist)*(1+aDist)/2;
		int tiredB  =(bDist)*(1+bDist)/2;
		System.out.println(tiredA+tiredB);
	}
}

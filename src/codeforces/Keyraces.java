package codeforces;
import java.util.Scanner;

public class Keyraces {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int length = s.nextInt();
		int time1 = length*s.nextInt();
		int time2 = length*s.nextInt();
		time1 += 2*s.nextInt();
		time2 += 2*s.nextInt();
		if(time1==time2) {
			System.out.println("Friendship");
		}else if(time1<time2) {
			System.out.println("First");
		}else {
			System.out.println("Second");
		}
		s.close();
	}
}

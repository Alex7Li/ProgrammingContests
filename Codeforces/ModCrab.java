package codeforces;
import java.util.Scanner;

//http://codeforces.com/contest/903/problem/B
public class ModCrab {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int h1 = sc.nextInt();
		int a1 = sc.nextInt();
		int c1 = sc.nextInt();
		int h2 = sc.nextInt();
		int a2 = sc.nextInt();
		int atkTurns = (int) Math.ceil((double)(h2)/a1);
		int healTurns = 0;
		if(a2*(atkTurns-1)>=h1) {
			int hpGain = c1-a2;
			//a2*(atkTurns-1) > h1+hpGain*(healTurns)
			//(a2*(atkTurns-1) - h1)/hpGain > healTurns
			healTurns = (a2*(atkTurns-1) - h1)/(hpGain) + 1;
		}
		System.out.println(healTurns+atkTurns);
		for (int i = 0; i <healTurns; i++) {
			System.out.println("HEAL");
		}
		for (int i = 0; i < atkTurns; i++) {
			System.out.println("STRIKE");
		}
		sc.close();
	}
}

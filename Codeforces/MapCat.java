package codeforces;
import java.util.Scanner;
//http://codeforces.com/problemset/problem/952/B
public class MapCat {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int noCount = 0;
		for (int i = 0; i < 10; i++) {
			System.out.println(i);
			System.out.flush();
			String nl = sc.nextLine();
			if(nl.equals("no")){
				noCount++;
				if(noCount>3) {
					System.out.println("normal");
					break;
				}
			}
			if(nl.equals("terrible")||nl.equals("are you serious?")||
			nl.equals("go die in a hole")|| nl.equals("worse")||
			nl.equals("don't even")||nl.equals("no way")) {
				System.out.println("grumpy");
				break;
			}else if(nl.equals("cool")||nl.equals("don't think so")||
					nl.equals("not bad")|| nl.equals("great!")||
					nl.equals("don't touch me!")) {
				System.out.println("normal");
				break;
			}
		}
		System.out.flush();
		sc.close();
	}
}
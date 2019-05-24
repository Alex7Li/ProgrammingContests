package codeforces;
import java.io.IOException;
import java.util.Scanner;
//http://codeforces.com/problemset/problem/903/A
public class HungryStudent {
	public static void main(String[] args) throws IOException{
		Scanner sc = new Scanner(System.in);
		String[] pos = new String[101];
		pos[0] = "YES";
		for (int i = 1; i < pos.length; i++) {
			pos[i] = "NO";
			if(i>=3 && pos[i-3]=="YES") {
				pos[i] = "YES";
			}
			if(i>=7 && pos[i-7]=="YES") {
				pos[i] = "YES";
			}
		}
		int n = sc.nextInt();
		for (int i = 0; i < n; i++) {
			System.out.println(pos[sc.nextInt()]);
		}
		sc.close();
	}
}

package codeforces;
import java.util.Arrays;
import java.util.Scanner;

public class GenerateLogin {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		String f = s.next();
		String l = s.next().substring(0, 1);
		String[] pos = new String[f.length()];
		for (int i = 0; i < f.length(); i++) {
			pos[i] = f.substring(0, i+1) + l;
		}
		Arrays.sort(pos);
		System.out.println(pos[0]);
		s.close();
	}
}

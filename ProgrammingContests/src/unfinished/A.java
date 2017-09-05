package unfinished;
import java.io.IOException;
import java.util.Scanner;

public class A {
	public static void main(String[] args) throws IOException {
		@SuppressWarnings("resource")
		Scanner s = new Scanner(System.in);
		s.nextInt();
		int k = s.nextInt();
		s.nextLine();
		char[] colors = s.nextLine().toCharArray();
		for (int i = 0; i < colors.length; i++) {
			int count = 1;
			for (int j = i+1; j < colors.length; j++) {
				if(colors[j] == colors[i]) {
					count++;
					if(count>k) {
						System.out.println("NO");
						return;
					}
				}
			}
		}
		System.out.println("YES");
	}
}

package codeforces;
import java.util.Arrays;
import java.util.Scanner;

public class ACMTeams {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int[] a = Arrays.stream(s.nextLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
		int sum = 0;
		for (int i = 0; i < a.length; i++) {
			sum+=a[i];
		}
		boolean pos = false;
		for (int i = 0; i < a.length; i++) {
			for (int j = i+1; j < a.length; j++) {
				for (int k = j+1; k < a.length; k++) {
					if(2*(a[i]+a[j]+a[k])==sum) {
						pos = true;
					}
				}
			}
		}
		if(pos){
			System.out.println("YES");
		}else {
			System.out.println("NO");
		}
		s.close();
	}
}

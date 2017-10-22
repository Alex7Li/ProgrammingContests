package codeforces;
import java.util.Scanner;

public class FairGame {
public static void main(String[] args) {
	Scanner s =new Scanner(System.in);
	int n = s.nextInt();
	int type1 = s.nextInt();
	boolean result = true;
	int count1 = 1;
	int type2 = -1;
	int count2 = 0;
	for (int i = 1; i < n; i++) {
		int next = s.nextInt();
		if(next == type1) {
			count1++;
		}else if(next == type2 || type2 == -1){
			type2 = next;
			count2++;
		}else {
			result = false;
			break;
		}
	}
	if(count1 != count2) {
		result = false;
	}
	if(result) {
		System.out.println("YES");	
		System.out.print(type1 + " " + type2);
	}else {
		System.out.println("NO");
	}
	s.close();
}
}

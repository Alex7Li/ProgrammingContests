package codeforces;
import java.util.Scanner;
//http://codeforces.com/contest/960/problem/A
public class CheckTheString {
public static void main(String[] args) {
	int a = 0;
	int b =0;
	int c = 0;
	Scanner sc = new Scanner(System.in);
	int cur = 0;
	char[] input = sc.nextLine().toCharArray();
	sc.close();
	for (int i = 0; i < input.length; i++) {
		switch(cur) {
		case 0:
			if(input[i]=='a') {
				a++;
			}else{
				i--;
				cur++;
			}
			break;
		case 1:
			if(input[i]=='b') {
				b++;
			}else {
				i--;
				cur++;
			}
			break;
		case 2:
			if(input[i]=='c') {
				c++;
			}else {
				System.out.println("NO");
				return;
			}
			break;
		}
	}
	if(a!=0&& b!=0&&(c==a || c==b)) {
		System.out.println("YES");
	}else {
		System.out.println("NO");
	}
}
}

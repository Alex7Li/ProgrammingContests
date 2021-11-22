package codeforces;
import java.util.ArrayList;
import java.util.Scanner;
//http://codeforces.com/contest/960/problem/C
public class SubsequenceCounting {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		sc.close();
		ArrayList<Long> answer = new ArrayList<Long>();
		int size = 0;
		long curVal = 1;
		int count = 0;
		while(n!=0) {
			if(n%2==1) {
				for (int i = 0; i < size; i++) {
					answer.add(curVal);
				}
				curVal+=k+1;
				count++;
			}
			n/=2;
			size++;
		}
		for (int i = 0; i < count; i++) {
			answer.add(curVal);
			curVal+=k+1;
		}
		System.out.println(answer.size());
		StringBuilder arr = new StringBuilder(answer.get(0)+"");
		for (int i = 1; i < answer.size(); i++) {
			arr.append(" " + answer.get(i));
		}
		System.out.println(arr);
	}
}

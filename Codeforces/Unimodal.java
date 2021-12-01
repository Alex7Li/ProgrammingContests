package codeforces;

import java.util.Scanner;

//determines is an array is unimodal, defined as
//strictly increasing at the beginning, then constant, then strictly decreasing/
public class Unimodal {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		if(n==1) {
			System.out.println("YES");
			s.close();
			return;
		}
		int currElement = s.nextInt();
		int nextElement = s.nextInt();
		int i = 1;
		boolean unimodal = true;
		while (i < n) {
			if (nextElement <= currElement) {
				break;
			}
			i++;
			if(i == n) {
				break;
			}
			currElement = nextElement;
			nextElement = s.nextInt();
		}
		while (i < n) {
			if (nextElement != currElement) {
				break;
			}
			i++;
			if(i == n) {
				break;
			}
			currElement = nextElement;
			nextElement = s.nextInt();
		}
		while (i < n) {
			if (nextElement >= currElement) {
				unimodal = false;
				break;
			}
			i++;
			if(i == n) {
				break;
			}
			currElement = nextElement;
			nextElement = s.nextInt();

		}
		s.close();
		if (unimodal) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
	}
}

package codeforces;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class FindExtraOne {
	//http://codeforces.com/problemset/problem/900/A
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] a = new int[n];
		int negCount = 0;
		int posCount = 0;
		for (int i = 0; i < n; i++) {
			a[i]  = Integer.parseInt(br.readLine().split(" ")[0]);
			if(a[i]>0) {
				posCount++;
			}else if(a[i]<0) {
				negCount++;
			}else {
				negCount++;
				posCount++;
			}
		}
		if(posCount>1 && negCount>1) {
			System.out.println("No");
		}else {
			System.out.println("Yes");
		}
		br.close();
	}
}

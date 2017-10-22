package codeforces;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class MakeAPermutation {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] a = new int[n];
		int[] seen = new int[n+1];
		boolean[] skipped = new boolean[n+1];
		int seenMin = 1;
		int changes = 0;
		String[] aStr = br.readLine().split(" ");
		for (int i = 0; i < n; i++) {
			a[i] = Integer.parseInt(aStr[i]);
			seen[a[i]]+=1;
		}
		for (int i = seenMin; i <= n; i++) {
			if(seen[i] == 0) {
				seenMin = i;
				break;
			}
		}
		for (int i = 0; i < n; i++) {
			if(seen[a[i]]>1 || skipped[a[i]]) {
				if(seenMin<a[i] || skipped[a[i]]) {
					changes++;
					seen[a[i]]--;
					a[i] = seenMin;
					for (int j = seenMin+1; j <= n; j++) {
						if(seen[j] == 0) {
							seenMin = j;
							break;
						}
					}	
				}else {
					skipped[a[i]]=true;
				}
			}
		}
		System.out.println(changes);
		for (int i = 0; i < a.length; i++) {
			System.out.print(a[i] + " ");
		}
		System.out.println();
	}
}

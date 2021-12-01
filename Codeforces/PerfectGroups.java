package codeforces;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashSet;

//http://codeforces.com/contest/980/problem/D
//works but problem has bad time constraints
public class PerfectGroups {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] params = br.readLine().split(" ");
		int n = Integer.parseInt(params[0]);
		int[] a = new int[n];
		String[] aline = br.readLine().split(" ");
		for (int i = 0; i < a.length; i++) {
			a[i] = Integer.parseInt(aline[i]);
			for (int j = 2; j * j <= a[i]; j++) {
				if (a[i] % (j * j) == 0) {
					a[i] /= (j * j);
					j = 1;
				}
			}
		}
		int[] ans = new int[n+1];
		for (int i = 0; i < n; i++) {
			HashSet<Integer> seen = new HashSet<Integer>();
			for (int j = i; j < a.length; j++) {
				seen.add(a[j]);
				if(seen.contains(0)){
					ans[Math.max(1,seen.size()-1)]++;
				}else {
					ans[seen.size()]++;
				}
			}
		}
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		bw.write("" + ans[1]);
		for (int i = 2; i < ans.length; i++) {
			bw.write(" " + ans[i]);
		}
		bw.flush();
		bw.close();
		br.close();
	}

}

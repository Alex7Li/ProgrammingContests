package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
//http://codeforces.com/contest/981/problem/B
public class BusinessmanProblems {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n1 = Integer.parseInt(br.readLine());
		Map<Integer,Integer> ans = new HashMap<Integer, Integer>();
		for (int i = 0; i < n1; i++) {
			String[] in = br.readLine().split(" ");
			ans.put(Integer.parseInt(in[0]),Integer.parseInt(in[1]));
		}
		int n2 = Integer.parseInt(br.readLine());
		for (int i = 0; i < n2; i++) {
			String[] in = br.readLine().split(" ");
			int key = Integer.parseInt(in[0]);
			ans.put(key, Math.max(Integer.parseInt(in[1]),ans.getOrDefault(key,0)));
		}
		long sum = 0;
		for(Integer i: ans.values()){
			sum+=i;
		}
		System.out.println(sum);
	}
}
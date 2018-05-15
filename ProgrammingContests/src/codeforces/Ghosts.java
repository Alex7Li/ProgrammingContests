package codeforces;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
//http://codeforces.com/problemset/problem/975/D
public class Ghosts {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] line = br.readLine().split(" ");
		int n = Integer.parseInt(line[0]);
		int a = Integer.parseInt(line[1]);
		Map<Long,Integer> vals = new HashMap<>();
		Map<Long,Integer> seen = new HashMap<>();
		long count = 0;
		for (int i = 0; i < n; i++) {
			String[] params = br.readLine().split(" ");
			long dx = Long.parseLong(params[1]);
			long dy = Long.parseLong(params[2]);
			long hash = ((long)Math.signum(dx)<<62)+((long)Math.signum(dy)<<61)+(Math.abs(dx)<<30) + Math.abs(dy);
			seen.put(hash, seen.getOrDefault(hash, 0)+1);
			long val = dy-a*dx;
			vals.put(val, vals.getOrDefault(val, 0)+1);
			count+=vals.get(val)-seen.get(hash);
		}
		System.out.println(2*count);
	}
}

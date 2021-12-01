package codeforces;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
//http://codeforces.com/contest/931/problem/D
public class PeculiarAppleTree {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] parent = Arrays.stream(br.readLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
		int[] distances = new int[n];
		distances[0] = 0;
		for (int i = 0; i < n-1; i++) {
			distances[i+1] = distances[parent[i]-1]+1;
		}
		int[] count = new int[n];
		for (int i = 0; i < distances.length; i++) {
			count[distances[i]]++;
		}
		int sum = 0;
		for (int i = 0; i < count.length; i++) {
			if(count[i]%2==1) {
				sum++;
			}
		}
		System.out.println(sum);
	}
}

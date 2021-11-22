package codeforces;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

public class NumberList {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] line1 = br.readLine().split(" ");
		int n = Integer.parseInt(line1[0]);
		int x = Integer.parseInt(line1[1]);
		int y = Integer.parseInt(line1[2]);
		String[] in = br.readLine().split(" ");
		int[] list = new int[n];
		for (int i = 0; i < n; i++) {
			list[i] = Integer.parseInt(in[i]);
		}
		ArrayList<Integer> primes = primeSieve();
		int[] costs = new int[primes.size()];
		for (int i = 0; i < list.length; i++) {
			for (int j = 0; j < primes.size(); j++) {
				costs[j]+=Math.min(x, y*list[i]%primes.get(j));
			}
		}
		System.out.println(Arrays.stream(list).min());
	}

	// returns an int ArrayList of primes up to 10^8
	public static ArrayList<Integer> primeSieve() {
		int max = 100000001;
		boolean[] isPrime = new boolean[max];
		Arrays.fill(isPrime, true);
		for (int i = 2; i < isPrime.length; i++) {
			if (isPrime[i]) {
				for (int j = 2 * i; j < isPrime.length; j += i) {
					isPrime[j] = false;
				}
			}
		}
		ArrayList<Integer> primes = new ArrayList<Integer>();
		for (int i = 2; i < isPrime.length; i++) {
			if (isPrime[i]) {
				primes.add(i);
			}
		}
		return primes;
	}
}

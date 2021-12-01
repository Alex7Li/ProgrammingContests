package codeforces;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class NewBusRoute {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		br.readLine();
		String[] cityStr = br.readLine().split(" ");
		Integer[] cities = new Integer[cityStr.length];
		for (int i = 0; i < cities.length; i++) {
			cities[i] = Integer.parseInt(cityStr[i]);
		}
		Arrays.sort(cities);
		int min = Integer.MAX_VALUE;
		int count = 0;
		for (int i = 0; i < cities.length-1; i++) {
			int diff = cities[i + 1] - cities[i];
			if (diff <= min) {
				if (diff == min) {
					count++;
				} else {
					min = diff;
					count = 1;
				}
			}
		}
		System.out.print(min + " " + count);
	}
}

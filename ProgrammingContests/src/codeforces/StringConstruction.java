package codeforces;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class StringConstruction {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		double n = System.nanoTime();
		char[] string = new char[2000000];
		for (int i = 0; i < string.length; i++) {
			string[i] = 'a';
		}
		double n2 = System.nanoTime();
		System.out.println(n2-n);
		int strings = Integer.parseInt(br.readLine());
		int maxLength = 0;
		for (int i = 0; i < strings; i++) {
			String[] input = br.readLine().split(" ");
			char[] str = input[0].toCharArray();
			for (int j = 2; j < Integer.parseInt(input[1])+2; j++) {
				for (int k = 0; k < str.length; k++) {
					string[Integer.parseInt(input[j])+k] = str[k];	
				}
				maxLength = Math.max(maxLength, Integer.parseInt(input[j])+str.length-1);
			}
		}
		System.out.println(new String(string).substring(1, maxLength+1));
	}
}

package kattis;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class CantinaOfBabel {
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		Person[] characters = new Person[n];
		for (int i = 0; i < n; i++) {
			String[] charInfo = br.readLine().split(" ");
			String[] understands = new String[charInfo.length-2];
			for (int j = 0; j < understands.length; j++) {
				understands[j] = charInfo[j+2];
			}
			characters[i] = new Person(charInfo[1],understands);
		}
		boolean flag = true;
		while(flag) {
			
		}
	}
}

class Person{
	String speaks;
	String[] understands;
	public Person(String speaks, String[] understands) {
		this.speaks = speaks;
		this.understands = understands;
	}
	
}
package unfinished;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
//https://open.kattis.com/problems/brackets
public class Brackets {
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		char[] line = br.readLine().toCharArray();
		boolean valid = false;
		int start = -1;
		int end = -1;
		int count = 0;
		for (int i = 0; i < line.length; i++) {
			if(line[i] == '(') {
				count++;
			}else{
				count--;
				if(count<0) {
					start = i;
					break;
				}
			}
		}
		if(start != -1 && count == 0) {
			for (int i = line.length-1; i>=0; i--) {
				if(line[i] == ')') {
					count++;
				}else{
					count--;
					if(count<0) {
						end = i;
						break;
					}
				}
			}
			
			for (int i = start; i <= end; i++) {
				if(line[i] == ')') {
					line[i] = '(';
				}else {
					line[i] = ')';
				}
			}
			for (int i = 0; i < line.length; i++) {
				if(line[i] == '(') {
					count++;
				}else{
					count--;
					if(count<0) {
						break;
					}
				}
			}
			if(count == 0) {
				valid = true;
			}
		}
		if(valid) {
			System.out.println("possible");
		}else {
			System.out.println("impossible");
		}
	}
}

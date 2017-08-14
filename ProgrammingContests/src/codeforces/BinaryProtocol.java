package codeforces;
import java.util.Scanner;

/**
 * 
 */

/**
 * @author 7Alex
 *
 */
public class BinaryProtocol {
public static void main(String[] args) {
	Scanner s = new Scanner(System.in);
	s.nextLine();
	s.close();
	char[] encoded = s.nextLine().toCharArray();
	String number = "";
	int ones = 0;
	for (int i = 0; i < encoded.length; i++) {
		if(encoded[i] == '1'){
			ones++;
		}else {
			number += "" +ones;
			ones = 0;
		}
	}
	number += "" +ones;
	ones = 0;
	System.out.println(number);
}
}

package codeforces;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
//http://codeforces.com/contest/898/problem/C
public class PhoneNumbers {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		Map<String,ArrayList<String>> numbers = new HashMap<String,ArrayList<String>>();
		for (int i = 0; i < n; i++) {
			String name = sc.next();
			int m = sc.nextInt();
			for (int j = 0; j < m; j++) {
				String number = sc.next();
				ArrayList<String> curDir = numbers.getOrDefault(name, new ArrayList<String>());
				ArrayList<String> toRemove = new ArrayList<String>();;
				boolean add = true;
				for (String val: curDir) {
					if(number.endsWith(val)) {
						toRemove.add(val);
					}else if(val.endsWith(number)) {
						add = false;
					}
				}
				if(add) {
					curDir.add(number);
				}
				for (String s:toRemove) {
					curDir.remove(s);
				}
				numbers.put(name, curDir);
			}
		}
		sc.close();
		System.out.println(numbers.size());
		for(String key:numbers.keySet()) {
			System.out.print(key + " " + numbers.get(key).size());
			for (String number:numbers.get(key)) {
				System.out.print(" " + number);
			}
			System.out.println();
		}
	}
}

package codeforces;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class JamieAndBinSequence {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		long k = sc.nextLong();
		sc.close();
		List<Integer> a = new ArrayList<>();
		String binaryString = Long.toBinaryString(n);
		for (int i = 1; i <= binaryString.length(); i++) {
			if (binaryString.charAt(i - 1) == '1') {
				a.add(binaryString.length() - i);
				k--;
			}
		}
		if (k < 0) {
			System.out.println("No");
		} else {
			while (k != 0) {
				int highest = a.get(0);
				int numHighest = 1;
				while (numHighest<a.size() && a.get(numHighest) == highest) {
					numHighest++;
				}
				if (numHighest <= k) {
					a = a.subList(numHighest, a.size());
					List<Integer> toAdd = new ArrayList<Integer>();
					for (int i = 0; i < numHighest; i++) {
						toAdd.add(highest-1);
						toAdd.add(highest-1);
					}
					toAdd.addAll(a);
					a = toAdd;
					k -= numHighest;
				} else {
					while (k != 0) {
						int minVal = a.remove(a.size()-1);
						a.add(minVal - 1);
						a.add(minVal - 1);
						k--;
					}
				}
			}
			System.out.println("Yes");
			for (int i = 0; i < a.size(); i++) {
				System.out.print(a.get(i) + " ");
			}
			k = 1+1;
		}
	}
}

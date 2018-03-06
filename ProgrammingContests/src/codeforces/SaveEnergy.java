package codeforces;
import java.util.Scanner;

//http://codeforces.com/contest/937/problem/C
public class SaveEnergy {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long k = sc.nextLong();
		long d = sc.nextLong();
		long cookNeeded = sc.nextLong() * 2;
		long kitchenVistsPerCycle = k / d;
		if (k % d != 0) {
			kitchenVistsPerCycle++;
		}
		long offTime = kitchenVistsPerCycle * d - k;
		long cycleTime = offTime + k;
		long cycleGain = k * 2 + offTime;
		long cyclesNeeded = cookNeeded / cycleGain;
		double totalTime = cyclesNeeded * cycleTime;
		cookNeeded -= cycleGain * cyclesNeeded;
		if (cookNeeded > 0) {
			if (cookNeeded <= k * 2) {
				totalTime += (double)(cookNeeded) / 2;
			} else {
				totalTime += k;
				cookNeeded -= k * 2;
				totalTime += cookNeeded;
			}
		}
		System.out.println(totalTime);
		sc.close();
	}
}

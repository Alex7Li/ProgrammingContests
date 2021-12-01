package codeforces;
import java.util.HashMap;
import java.util.Scanner;

public class KDomChar {
public static void main(String[] args) {
	Scanner s = new Scanner(System.in);
	char[] line = s.nextLine().toCharArray();
	s.close();
	HashMap<Character,Integer> longestDist = new HashMap<Character,Integer>();
	HashMap<Character,Integer> lastSeen = new HashMap<Character,Integer>();
	int index = 1;
	for (char c:line) {
		int distSinceLast = index - lastSeen.getOrDefault(c, 0);
		lastSeen.put(c, index);
		if(distSinceLast>longestDist.getOrDefault(c, -1)) {
			longestDist.put(c, distSinceLast);
		}
		index++;
	}
	for (Character c:longestDist.keySet()) {
		int distSinceLast = index - lastSeen.get(c);
		if(distSinceLast>longestDist.get(c)) {
			longestDist.put(c, distSinceLast);
		}
	}
	int minLongestDist = Integer.MAX_VALUE;
	for(int i: longestDist.values()) {
		if(i<minLongestDist) {
			minLongestDist = i;
		}	
	}
	System.out.println(minLongestDist);
}
}

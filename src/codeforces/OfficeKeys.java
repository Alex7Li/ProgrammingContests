package codeforces;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

/**
 * 
 */

/**
 * @author 7Alex
 *
 */
public class OfficeKeys {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	public static void main(String[] args) throws IOException {

		String[] line1 = br.readLine().split(" ");
		int nPeople = Integer.parseInt(line1[0]);
		int nKeys = Integer.parseInt(line1[1]);
		int officeLoc = Integer.parseInt(line1[2]);
		
		int[] people = new int[nPeople];
		int[] keys = new int[nKeys];
		String[] pepString = br.readLine().split(" ");
		String[] keyString = br.readLine().split(" ");

		for (int i = 0; i < nPeople; i++) {
			people[i] = Integer.parseInt(pepString[i]);
		}
		for (int i = 0; i < nKeys; i++) {
			keys[i] = Integer.parseInt(keyString[i]);
		}
		Arrays.sort(people);
		Arrays.sort(keys);
		System.out.println(getBestTime(people,keys,officeLoc));
	}

	/**
	 * Best time for every person to get a key and return to the office.
	 * Since all used keys should lie in a line the length of people,
	 * where the nth of that line will be the key obtained by the nth
	 * person, one only needs to find the start of the line.
	 */
	private static int getBestTime(int[] people, int[] keys, int officeLoc) {

		int choices = (keys.length-people.length+1);
		int bestTime = Integer.MAX_VALUE;
		if(choices == 1) {
			return getTime(people, keys, officeLoc, 0);
		}
		int min = 0;
		int max = choices-1;
		while(min < max) {
			int mid = (min+max)/2;
			int timeLow = getTime(people, keys, officeLoc, mid);
			int timeHigh = getTime(people, keys, officeLoc, mid+1);
			if(timeLow>timeHigh) {
				min = mid+1;
			}else if(timeLow<timeHigh) {
				max = mid;
			}else {//timeLow==timeHigh
				return timeLow;
			}
			bestTime = Math.min(bestTime, Math.min(timeLow, timeHigh));
		}
		return bestTime;
		
	}

	/**
	 * Time if the lowest key is indexed at index.
	 */
	private static int getTime(int[] people, int[] keys, int officeLoc, int index) {
		int slowest = 0;
		for (int i = 0; i < people.length; i++) {
			int timeToKey = Math.abs(people[i]-keys[i+index]);
			int timeToOffice = Math.abs(officeLoc-keys[i+index]);
			int tTime = timeToKey+timeToOffice;
			if(tTime > slowest) {
				slowest = tTime;
			}
		}
		return slowest;
		
	}
}

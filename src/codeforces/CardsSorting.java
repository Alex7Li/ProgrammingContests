package codeforces;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class CardsSorting {
	//O(n) solution!
	public static void main(String[] args) throws IOException {
		// get Input
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int startingCards = n;
		String[] cardsStr = br.readLine().split(" ");
		//input is in the form of an array of arrayLists.
		//The values in each arrayList are the positions of the elements
		//with value equal to the arrayList's index in the array of arrayLists.
		@SuppressWarnings("unchecked")
		ArrayList<Integer>[] positions = (ArrayList<Integer>[]) new ArrayList[100001];
		for (int i = 0; i < positions.length; i++) {
			positions[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < n; i++) {
			int value = Integer.parseInt(cardsStr[i]);
			positions[value].add(i);
		}
		//So solution will be the total times we've looked at cards
		//curPos is the position in the card array we're at.
		long solution = 0;
		int curPos = 0;
		//so we're looking for the positions of the smallest numbers.
		//this is why the data is structured like so, we can iterate through the
		//array of positions from lowest value to highest.
		for (int i = 1; i < positions.length; i++) {
			//We'll eventually need endPos to change curPos
			int endPos = curPos;
			int worst = -1;
			//For each number, we want to find the one farthest from curPos. (worst)
			for (int j = 0; j < positions[i].size(); j++) {
				//How many times do we need to check cards to get to the next
				//position? This number note is not exact because when numbers
				//are deleted positions[i].get(j) - curPos will actually overestimate
				//the value by calculating the deleted numbers too, however this is not
				//important, as long as we can find which one is the worst so endPos
				//is correct.
				int pos = positions[i].get(j);
				int checks = (pos - curPos) % startingCards;
				if (checks < 0)
				{
				    checks += startingCards;
				}
				//counting positions that are before curPos because they will later
				//be removed and therefore not counted.
				if (curPos > pos) {
					solution++;
				}
				if (checks > worst) {
					worst = checks;
					endPos = pos;
				}
			}
			if (curPos > endPos) {
				//Went through whole deck - so add each card to the count.
				solution += n;
			}else {
				//counting positions that we just counted because they will later
				//be removed and therefore not counted.
				solution += positions[i].size();
			}
			n -= positions[i].size();
			curPos = endPos;
		}
		System.out.println(solution);
	}
}
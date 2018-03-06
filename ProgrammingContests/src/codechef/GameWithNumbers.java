package codechef;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

//https://www.codechef.com/LTIME57/problems/GAMENUMB
public class GameWithNumbers {
	public static class CardRow implements Comparable<CardRow> {
		long val;
		long num;

		public CardRow(long value, long number) {
			val = value;
			num = number;
		}

		@Override
		public int compareTo(CardRow other) {
			return Long.compare(val, other.val);
		}

	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int testCases = Integer.parseInt(br.readLine());
		for (int i = 0; i < testCases; i++) {
			br.readLine();
			int[] cardValues = Arrays.stream(br.readLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
			int[] cardCounts = Arrays.stream(br.readLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
			long[] moves = Arrays.stream(br.readLine().split(" ")).mapToLong(x -> Long.parseLong(x)).toArray();
			long cardsLeft = 0;
			for (int j = 0; j < cardCounts.length; j++) {
				cardsLeft += cardCounts[j];
			}
			long cardSum = 0;
			for (int j = 0; j < cardValues.length; j++) {
				cardSum += (long) (cardValues[j]) * cardCounts[j];
			}
			int leftInd = 0;
			int rightInd = cardValues.length - 1;
			// sorting the cards
			CardRow[] cards = new CardRow[cardValues.length];
			for (int j = 0; j < cards.length; j++) {
				cards[j] = new CardRow(cardValues[j], cardCounts[j]);
			}
			Arrays.sort(cards);
			for (int j = 0; j < moves.length; j++) {
				long cardsToRemove = cardsLeft - moves[j];
				cardsLeft -= cardsToRemove;
				if (j % 2 == 0) {
					// remove minimal elements
					while (cardsToRemove > 0) {
						if (cardsToRemove >= cards[leftInd].num) {
							cardSum -= cards[leftInd].num * cards[leftInd].val;
							cardsToRemove -= cards[leftInd].num;
							leftInd++;
						} else {
							cardSum -= cardsToRemove * cards[leftInd].val;
							cards[leftInd].num -= cardsToRemove;
							;
							cardsToRemove = 0;
						}
					}
				} else {
					// remove maximal elements
					while (cardsToRemove > 0) {
						if (cardsToRemove >= cards[rightInd].num) {
							cardSum -= cards[rightInd].num * cards[rightInd].val;
							cardsToRemove -= cards[rightInd].num;
							rightInd--;
						} else {
							cardSum -= cardsToRemove * cards[rightInd].val;
							cards[rightInd].num -= cardsToRemove;
							cardsToRemove = 0;
						}
					}
				}
			}
			System.out.println(cardSum);
		}
	}
}

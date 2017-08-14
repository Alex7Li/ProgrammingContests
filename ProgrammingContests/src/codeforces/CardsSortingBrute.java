package codeforces;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;

import tools.FastIO;

public class CardsSortingBrute {
	public static void main(String[] args) throws IOException {
		FastIO fio = new FastIO();
		int n = fio.readInt();
		ArrayList<Integer> cards = new ArrayList<Integer>();
		ArrayList<Integer> cardsSorted = new ArrayList<Integer>();
		for (int i = 0; i < n; i++) {
			cards.add(fio.readInt());
			cardsSorted.add(cards.get(i));
		}
		fio.close();
		Collections.sort(cardsSorted);
		long count = 0;
		while (cards.size() > 0) {
			for (int i = 0; i < cards.size(); i++) {
				count++;
				if (cards.get(i) == cardsSorted.get(0)) {
					cards.remove(i);
					i--;
					cardsSorted.remove(0);
				}
			}
		}
		System.out.println(count);
	}
}
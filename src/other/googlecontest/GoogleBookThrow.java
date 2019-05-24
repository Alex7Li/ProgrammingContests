package other.googlecontest;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Arrays;
import java.util.Scanner;

//https://ggpuzzles.appspot.com/web/puzzle/throw-the-book-at-him
public class GoogleBookThrow {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new FileReader("src/misc/39Steps.txt"));
		StringBuilder book = new StringBuilder();
		int[][] triples = new int[52][3];
		for (int i = 0; i < triples.length; i++) {
			triples[i] = Arrays.stream(sc.nextLine().split(", ")).mapToInt(x -> Integer.parseInt(x)).toArray();
		}
		while (sc.hasNext()) {
			String nl = sc.nextLine();
			 if(nl.contains("CHAPTER")){
			 sc.nextLine();
			 sc.nextLine();
			 }
			if (nl.length() > 0) {
				nl = nl.replaceAll("  ", " ");
				book.append(nl + " ");
			}
		}
		sc.close();
		String[] chapters = book.toString().split("CHAPTER ");
		for (int i = 0; i < triples.length; i++) {
			int chapter = triples[i][0];
			int word = triples[i][1];
			int letter = triples[i][2] - 1;
			String[] chapterWords = chapters[chapter].split(" ");
			String wordStr = chapterWords[word];
			if (wordStr.length() <= letter) {
				System.out.print(" ");
			} else {
				System.out.print(wordStr.charAt(letter));
			}
		}
	}
}

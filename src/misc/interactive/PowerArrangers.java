package misc.interactive;

import java.io.PrintWriter;
import java.util.*;

// https://codingcompetitions.withgoogle.com/codejam/round/00000000000516b9/0000000000134e91
// I hate interactive problems ):
// this guy, and me ignoring C easy, wrecked my chances for codeforces round 2 2019
class PowerArrangers {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int cases = sc.nextInt();
        sc.nextInt();
        for (int i = 1; i <= cases; i++) {
            int val = 119;
            List<Integer> goodNums = new ArrayList<Integer>();
            Set<Character> unusedLetters = new HashSet<>();
            for (char j = 'A'; j <= 'E'; j++) {
                unusedLetters.add(j);
            }
            for (int j = 0; j < val; j++) {
                goodNums.add(j * 5);
            }
            StringBuilder ans = new StringBuilder();
            for (int loop = 1; loop <= 3; loop++) {
                assert val == goodNums.size();
                for (int j : goodNums) {
                    pw.println(loop + j);
                }
                pw.flush();
                Map<Character, Integer> counts = new HashMap<>();
                List<Character> letters = new ArrayList<>();
                for (int j = 0; j < val; j++) {
                    char letter = sc.next().charAt(0);
                    counts.put(letter, counts.getOrDefault(letter, 0) + 1);
                    letters.add(letter);
                }
                val /= 6 - loop;
                char letter = 'A';
                for (char j = 'A'; j <= 'E'; j++) {
                    if (counts.containsKey(j) && counts.get(j) == val) {
                        letter = j;
                        unusedLetters.remove(letter);
                    }
                }
                ans.append(letter);
                List<Integer> newGoodNums = new ArrayList<>();
                for (int j = 0; j < letters.size(); j++) {
                    if (letters.get(j) == letter) {
                        newGoodNums.add(goodNums.get(j));
                    }
                }
                goodNums = newGoodNums;
            }
            for (int j : goodNums) {
                pw.println(4 + j);
            }
            pw.flush();
            char letter = sc.next().charAt(0);
            unusedLetters.remove(letter);
            ans.append(unusedLetters.iterator().next());
            ans.append(letter);
            pw.println(ans);
            pw.flush();
            char correct = sc.next().charAt(0);
            if (correct == 'N') {
                return;
            }
        }

    }
}



package codeforces;

import java.util.*;

//https://codeforces.com/gym/102004
public class WeakerThanPlanned {
    private static char[][] words;
    private static char[][] cipher;
    private static Map<Character, Character> solutionMap = null;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        while (n != 0) {
            sc.nextLine();
            solutionMap = null;
            words = new char[n][];
            for (int i = 0; i < n; i++) {
                words[i] = sc.nextLine().toCharArray();
            }
            String[] cipherWords = sc.nextLine().split(" ");
            cipherWords[cipherWords.length - 1] = cipherWords[cipherWords.length - 1].substring(0, cipherWords[cipherWords.length - 1].length() - 1);
            cipher = new char[cipherWords.length][];
            char[][] cipherNoSort = new char[cipherWords.length][];
            for (int i = 0; i < cipherWords.length; i++) {
                cipher[i] = cipherWords[i].toCharArray();
                cipherNoSort[i] = cipher[i];
            }
            //sort by most distinct letters for speed
            Arrays.sort(cipher, new Comparator<char[]>() {
                @Override
                public int compare(char[] o1, char[] o2) {
                    Set<Character> distinct1 = new HashSet<>();
                    Set<Character> distinct2 = new HashSet<>();
                    for (char c : o1) {
                        distinct1.add(c);
                    }
                    for (char c : o2) {
                        distinct2.add(c);
                    }
                    return distinct2.size() - distinct1.size();
                }
            });
            Map<Character, Character> code = new HashMap<>();
            decode(0, code);

            if (solutionMap == null || solutionMap.containsKey('-')) {
                System.out.println("-.");
            } else {
                for (int i = 0; i < cipherNoSort.length; i++) {
                    for (char letter : cipherNoSort[i]) {
                        System.out.print(solutionMap.get(letter));
                    }
                    if (i != cipherNoSort.length - 1) {
                        System.out.print(" ");
                    }
                }
                System.out.println(".");
            }
            n = sc.nextInt();
        }
    }

    public static void decode(int wordInd, Map<Character, Character> code) {
        if(solutionMap != null && solutionMap.containsKey('-')){
            return;
        }
        char[] word = cipher[wordInd];
        // for each possible word
        for (int i = 0; i < words.length; i++) {
            if (word.length == words[i].length) {
                Map<Character, Character> extra = new HashMap<>();
                boolean works = true;
                for (int j = 0; j < word.length; j++) {
                    if (code.containsKey(word[j]) && code.get(word[j]) == words[i][j]) {
                        continue;
                    } else if (!code.containsKey(word[j]) && word[j] == words[i][j]) {
                        code.put(word[j], words[i][j]);
                        extra.put(word[j], words[i][j]);
                    } else if (!code.containsKey(word[j]) && !code.containsKey(words[i][j])) {
                        code.put(word[j], words[i][j]);
                        code.put(words[i][j], word[j]);
                        extra.put(word[j], words[i][j]);
                        extra.put(words[i][j], word[j]);
                    } else {
                        works = false;
                        break;
                    }
                }
                if (works) {
                    if (wordInd + 1 == cipher.length) {
                        if (solutionMap == null) {
                            solutionMap = new HashMap<>();
                            for(Map.Entry<Character,Character> e: code.entrySet()) {
                                solutionMap.put(e.getKey(),e.getValue());
                            }
                        } else {
                            solutionMap.put('-', '-');
                        }
                    } else {
                        decode(wordInd + 1, code);
                    }
                }
                for (Character c : extra.keySet()) {
                    code.remove(c);
                }
            }
        }
    }
}

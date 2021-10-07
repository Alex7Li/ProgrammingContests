package codeforces;

import java.util.*;

//https://codeforces.com/gym/102004
public class SorcerersDonut {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt();
        int w = sc.nextInt();
        while(!(h==0 && w==0)) {
            sc.nextLine();
            char[][] letters = new char[h][w];
            for (int i = 0; i < h; i++) {
                letters[i] = sc.nextLine().toCharArray();
            }
            Trie trie = new Trie();
            List<Character> str = new ArrayList<>();
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    str.add(letters[i][j]);
                }
                trie.addWord(str);
                for (int j = w - 1; j >= 0; j--) {
                    str.add(letters[i][j]);
                }
                trie.addWord(str);
            }
            for (int i = 0; i < w; i++) {
                for (int j = 0; j < h; j++) {
                    str.add(letters[j][i]);
                }
                trie.addWord(str);
                for (int j = h - 1; j >= 0; j--) {
                    str.add(letters[j][i]);
                }
                trie.addWord(str);
            }
            int gcd = gcd(w, h);
            for (int i = 0; i < gcd; i++) {
                int x = i;
                int y = 0;
                do {
                    x++;
                    y++;
                    str.add(letters[x % h][y % w]);
                } while (!(x % h == i && y % w == 0));
                trie.addWord(str);
                do {
                    x += h - 1;
                    y += w - 1;
                    str.add(letters[x % h][y % w]);
                } while (!(x % h == i && y % w == 0));
                trie.addWord(str);
                do {
                    x += h - 1;
                    y++;
                    str.add(letters[x % h][y % w]);
                } while (!(x % h == i && y % w == 0));
                trie.addWord(str);
                do {
                    x++;
                    y += w - 1;
                    str.add(letters[x % h][y % w]);
                } while (!(x % h == i && y % w == 0));
                trie.addWord(str);
            }
            String word = trie.findBestWord().reverse().toString();
            if(word.length()>1){
                System.out.println(word);
            }else{
                System.out.println("0");
            }
            h = sc.nextInt();
            w = sc.nextInt();
        }
    }

    private static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}

class Trie {
    private Trie[] nxt = null;
    int count = 0;

    //clear letters and add every substring to the Trie
    public void addWord(List<Character> letters) {
        for (int i = 0; i < letters.size(); i++) {
            addWord2(letters, i, letters.size());
        }
        count++;
        letters.clear();
    }

    public void addWord2(List<Character> letters, int stInd, int len) {
        if (len > 0) {
            if (nxt == null) {
                nxt = new Trie[26];
                for (int i = 0; i < 26; i++) {
                    nxt[i] = new Trie();
                }
            }
            nxt[letters.get(stInd % letters.size()) - 'A'].addWord2(letters, stInd + 1, len - 1);
        }
        count += 1;
    }

    // return "0" if no word is seen more than twice
    // otherwise, return the lexographically minimal longest word seen, backwards
    public StringBuilder findBestWord() {
        if (count < 2) {
            return new StringBuilder("0");
        }
        StringBuilder best = new StringBuilder();
        if(nxt==null){
            return best;
        }
        int bestLen = -1;
        for (int i = 0; i < 26; i++) {
                StringBuilder word = nxt[i].findBestWord();
                if (!word.toString().equals("0")) {
                    if (word.length() > bestLen) {
                        bestLen = word.length();
                        best = word.append((char) (i + 'A'));
                    }
                }
        }
        return best;
    }
}
